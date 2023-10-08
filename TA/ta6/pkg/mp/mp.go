package mp

import (
	"fmt"
	"log"
	"strings"
)

const (
	ActionTransfer  = "ЗАМЕНИТЬ"
	ActionRecognize = "ОПОЗНАНИЕ"
	EndLineSymbol   = "⊣"
	EndStackSymbol  = "∆"
)

type MPAction struct {
	Action string
}

var (
	MPRecognize MPAction = MPAction{Action: ActionRecognize}
	MPTransfer  MPAction = MPAction{Action: ActionTransfer}
)

var Table map[string]map[string]MPAction = map[string]map[string]MPAction{
	"S": {
		";":           MPTransfer,
		"]":           MPTransfer,
		EndLineSymbol: MPRecognize,
	},
	"O": {
		";":           MPRecognize,
		"]":           MPRecognize,
		EndLineSymbol: MPRecognize,
	},
	"Y": {
		";":           MPRecognize,
		"[":           MPTransfer,
		"]":           MPRecognize,
		")":           MPTransfer,
		"}":           MPTransfer,
		"|":           MPTransfer,
		"&":           MPTransfer,
		EndLineSymbol: MPRecognize,
	},
	"Z": {
		";": MPTransfer,
	},
	";": {
		";":           MPRecognize,
		"]":           MPRecognize,
		"(":           MPTransfer,
		"{":           MPTransfer,
		"a":           MPTransfer,
		"!":           MPTransfer,
		EndLineSymbol: MPRecognize,
	},
	"[": {
		"(": MPTransfer,
		"{": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	"]": {
		";":           MPRecognize,
		"]":           MPRecognize,
		"[":           MPTransfer,
		"}":           MPTransfer,
		"a":           MPTransfer,
		"(":           MPTransfer,
		"!":           MPTransfer,
		EndLineSymbol: MPRecognize,
	},
	"(": {
		"(": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	")": {
		";":           MPRecognize,
		"[":           MPRecognize,
		"]":           MPRecognize,
		")":           MPRecognize,
		"}":           MPRecognize,
		"|":           MPRecognize,
		"&":           MPRecognize,
		EndLineSymbol: MPRecognize,
	},
	"{": {
		"[": MPTransfer,
		"(": MPTransfer,
		"{": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	"}": {
		";":           MPRecognize,
		"]":           MPRecognize,
		EndLineSymbol: MPRecognize,
	},
	"a": {
		";":           MPRecognize,
		"[":           MPRecognize,
		"]":           MPRecognize,
		")":           MPRecognize,
		"}":           MPRecognize,
		"=":           MPTransfer,
		"|":           MPRecognize,
		"&":           MPRecognize,
		EndLineSymbol: MPRecognize,
	},
	"=": {
		"(": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	"|": {
		"(": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	"&": {
		"(": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
	"!": {
		"(": MPTransfer,
	},
	EndStackSymbol: {
		"(": MPTransfer,
		"{": MPTransfer,
		"a": MPTransfer,
		"!": MPTransfer,
	},
}

var (
	Rules map[int][]string = map[int][]string{
		1:  {"S", "S;O"},
		2:  {"S", "Z;"},
		3:  {"O", "Y[S]"},
		4:  {"O", "Y[S][S]"},
		5:  {"O", "{[S]Y}"},
		6:  {"O", "{Y[S]}"},
		7:  {"O", "a=Y"},
		8:  {"Y", "(Y|Y)"},
		9:  {"Y", "(Y&Y)"},
		10: {"Y", "!(Y)"},
		11: {"Y", "a"},
		12: {"Z", "O"},
	}
)

type MP struct {
	stack      string
	Steps      []int
	CurrPos    int
	ScanLogger *log.Logger
}

func (mp *MP) Init(ScanLogger *log.Logger) {
	mp.stack = EndStackSymbol
	mp.ScanLogger = ScanLogger
}

func (mp *MP) Pop() error {
	runes := []rune(mp.stack)
	if mp.Pick() == EndStackSymbol {
		return fmt.Errorf("try of pop from the end of the stack")
	}
	mp.stack = string(runes[:len(runes)-1])
	return nil
}

type recognitionUnit struct {
	R int
	S string
}

var recognitionTable map[string]map[string]recognitionUnit = map[string]map[string]recognitionUnit{
	"]": {
		"Y": {R: R3, S: "Y"},
		"]": {R: R4, S: "]S[Y"},
	},
	"}": {
		"]": {R: R6, S: "]S[Y{"},
		"Y": {R: R5, S: "Y]S[{"},
	},
	")": {
		"|": {R: R8, S: "|Y("},
		"(": {R: R10, S: "(!"},
		"&": {R: R9, S: "&Y("},
	},
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func LastReplace(s string, old string, new string, n int) string {
	return reverse(strings.Replace(reverse(s), reverse(old), reverse(new), n))
}

func (mp *MP) Pick() string {
	return string([]rune(mp.stack)[len([]rune(mp.stack))-1])
}

func (mp *MP) TryReplace(s string, replacement string) error {
	for _, c := range s {
		if mp.Pick() == string(c) {
			mp.Pop()
		} else {
			return fmt.Errorf("wrong input")
		}
	}
	mp.stack = mp.stack + replacement
	return nil
}

func (mp *MP) TryDrop(s string) error {
	for _, c := range s {
		if mp.Pick() == string(c) {
			mp.Pop()
		} else {
			return fmt.Errorf("wrong input")
		}
	}
	return nil
}

const (
	R1 = iota + 1
	R2
	R3
	R4
	R5
	R6
	R7
	R8
	R9
	R10
	R11
	R12
	FINE
	DROP
)

func (mp *MP) Recognize() (int, error) {
	if mp.Pick() == "S" {
		mp.Pop()
		if mp.Pick() == EndStackSymbol {
			return FINE, nil
		} else {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		}
	}
	if mp.Pick() == "Y" {
		if err := mp.TryReplace("Y=a", "O"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			return R7, nil
		}
	}
	if mp.Pick() == ";" {
		if err := mp.TryReplace(";Z", "S"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			return R2, nil
		}
	}
	if mp.Pick() == "O" {
		mp.TryDrop("O")
		if mp.Pick() == "[" || mp.Pick() == EndStackSymbol {
			mp.stack = mp.stack + "Z"
			return R12, nil
		}
		if err := mp.TryReplace(";S", "S"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			return R1, nil
		}
	}
	if mp.Pick() == "a" {
		if err := mp.TryReplace("a", "Y"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			return R11, nil
		}
	}
	if mp.Pick() == ")" {
		if err := mp.TryDrop(")Y"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		}
		if v, ok := recognitionTable[")"][mp.Pick()]; !ok {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			if err := mp.TryReplace(v.S, "Y"); err != nil {
				return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
			} else {
				return v.R, nil
			}
		}
	}
	if mp.Pick() == "]" {
		if err := mp.TryDrop("]S["); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		}
		if v, ok := recognitionTable["]"][mp.Pick()]; !ok {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			if err := mp.TryReplace(v.S, "O"); err != nil {
				return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
			} else {
				return v.R, nil
			}
		}
	}
	if mp.Pick() == "}" {
		if err := mp.TryDrop("}"); err != nil {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		}
		if v, ok := recognitionTable["}"][mp.Pick()]; !ok {
			return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
		} else {
			if err := mp.TryReplace(v.S, "O"); err != nil {
				return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
			} else {
				return v.R, nil
			}
		}
	}
	return DROP, fmt.Errorf("wrong stack input %s", mp.Pick())
}

func (mp *MP) Analyze(input string) error {
	str := strings.TrimSpace(input) + EndLineSymbol
	runes := []rune(str)
	process := true
	for process {
		stackSymbol := mp.Pick()
		strSymbol := string(runes[mp.CurrPos])
		action, ok := Table[stackSymbol][strSymbol]
		if !ok {
			mp.ScanLogger.Printf("\033[31mОшибка\033[0m\n")
			mp.ScanLogger.Printf("Stack: %s", mp.stack)
			mp.ScanLogger.Printf("Оставшаяся часть строки: %s\n", str[mp.CurrPos:])
			return fmt.Errorf("error during analyze. stack symbol <%s> and string symbol <%s>", stackSymbol, strSymbol)
		}
		switch action.Action {
		case MPTransfer.Action:
			mp.stack = mp.stack + string([]rune(str)[mp.CurrPos])
			mp.CurrPos++
			//mp.ScanLogger.Printf("\033[35mПроизош. Входно.\033[0m Входной символ: Стек-символ: %s %s0, stackSymbol, strSymbolbol", stackSymbol, strSymbol)
			//mp.ScanLogger.Printf("Магазин:\t\033[34m%s\033[0m", mp.stack)
			//mp.ScanLogger.Printf("Необработанная часть цепочки:\t\033[34m%s\033[0m", string(runes[mp.CurrPos:]))
		case MPRecognize.Action:
			id, err := mp.Recognize()
			if err != nil {
				return err
			}
			if id != FINE {
				mp.Steps = append(mp.Steps, id)
				mp.ScanLogger.Printf("Применяется правило %d. \033[33m %s -> %s \033[0m", id, Rules[id][0], Rules[id][1])
				mp.ScanLogger.Printf("Магазин:\t\033[34m%s\033[0m", mp.stack)
				mp.ScanLogger.Printf("Необработанная часть цепочки:\t\033[34m%s\033[0m", string(runes[mp.CurrPos:]))
			} else {
				mp.ScanLogger.Printf("\033[32mЦепочка обработана успешно\033[0m")
				process = false
			}
		}
	}
	return nil
}
