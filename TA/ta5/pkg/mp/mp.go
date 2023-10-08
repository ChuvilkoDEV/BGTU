package mp

import (
	"DanArmor/ta5/pkg/rules"
	"fmt"
	"log"
	"strings"
)

const (
	ActionReplace  = "ЗАМЕНИТЬ"
	ActionPop      = "ВЫТОЛК"
	ActionDone     = "ДОПУСК"
	EndLineSymbol  = "⊣"
	EndStackSymbol = "∆"
)

type MPAction struct {
	Move          bool
	Action        string
	RepalceString []string
	RuleNum       int
}

var (
	Rules []MPAction = []MPAction{
		{Move: false, Action: ActionReplace, RepalceString: []string{"S'", "O"}, RuleNum: 1},
		{Move: false, Action: ActionReplace, RepalceString: []string{"S'", "O"}, RuleNum: 2},
		{Move: false, Action: ActionPop, RuleNum: 3},
		{Move: true, Action: ActionReplace, RepalceString: []string{"O'"}, RuleNum: 4},
		{Move: true, Action: ActionReplace, RepalceString: []string{"}", "]", "S", "[", "Y"}, RuleNum: 5},
		{Move: true, Action: ActionReplace, RepalceString: []string{"]", "S", "[", ")", "Y", "("}, RuleNum: 6},
		{Move: true, Action: ActionReplace, RepalceString: []string{"]", "S", "[", "a"}, RuleNum: 7},
		{Move: true, Action: ActionReplace, RepalceString: []string{"R"}, RuleNum: 8},
		{Move: true, Action: ActionReplace, RepalceString: []string{")", "E", "("}, RuleNum: 9},
		{Move: true, Action: ActionReplace, RepalceString: []string{"E'", "E"}, RuleNum: 10},
		{Move: true, Action: ActionReplace, RepalceString: []string{"T"}, RuleNum: 11},
		{Move: true, Action: ActionReplace, RepalceString: []string{"]", "S"}, RuleNum: 12},
		{Move: false, Action: ActionPop, RuleNum: 13},
		{Move: true, Action: ActionReplace, RepalceString: []string{")", "Y", "("}, RuleNum: 14},
		{Move: true, Action: ActionReplace, RepalceString: []string{"Y'"}, RuleNum: 15},
		{Move: true, Action: ActionReplace, RepalceString: []string{"a"}, RuleNum: 16},
		{Move: true, Action: ActionReplace, RepalceString: []string{"a"}, RuleNum: 17},
		{Move: true, Action: ActionReplace, RepalceString: []string{")", "E", "("}, RuleNum: 18},
		{Move: true, Action: ActionReplace, RepalceString: []string{""}, RuleNum: 19},
		{Move: true, Action: ActionReplace, RepalceString: []string{"E'", "E"}, RuleNum: 20},
		{Move: true, Action: ActionReplace, RepalceString: []string{")", "E"}, RuleNum: 21},
		{Move: true, Action: ActionReplace, RepalceString: []string{")", "E"}, RuleNum: 22},
	}
	Rule_generic MPAction = MPAction{Move: true, Action: ActionPop}
	Rule_done    MPAction = MPAction{Move: false, Action: ActionDone}
)

var Table map[string]map[string]MPAction = map[string]map[string]MPAction{
	"S": {
		"{": Rules[0],
		"a": Rules[0],
		"!": Rules[0],
	},
	"S'": {
		"{":           Rules[1],
		"]":           Rules[2],
		"a":           Rules[1],
		"!":           Rules[1],
		EndLineSymbol: Rules[2],
	},
	"O": {
		"{": Rules[4],
		"a": Rules[3],
		"!": Rules[5],
	},
	"O'": {
		"=": Rules[7],
		"<": Rules[6],
	},
	"R": {
		"a": Rules[10],
		"(": Rules[9],
		"-": Rules[8],
	},
	"T": {
		"[":           Rules[11],
		"]":           Rules[12],
		"{":           Rules[12],
		"a":           Rules[12],
		"!":           Rules[12],
		EndLineSymbol: Rules[12],
	},
	"Y": {
		"a": Rules[14],
		"!": Rules[13],
	},
	"Y'": {
		"=": Rules[15],
		"<": Rules[16],
	},
	"E": {
		"a": Rules[18],
		"(": Rules[19],
		"-": Rules[17],
	},
	"E'": {
		"*": Rules[20],
		"+": Rules[21],
	},
	"]":            {"]": Rule_generic},
	"[":            {"[": Rule_generic},
	"}":            {"}": Rule_generic},
	"a":            {"a": Rule_generic},
	"=":            {"=": Rule_generic},
	"(":            {"(": Rule_generic},
	")":            {")": Rule_generic},
	EndStackSymbol: {EndLineSymbol: Rule_done},
}

func reverse(arr []string) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func init() {
	for i := 0; i < len(Rules); i++ {
		reverse(Rules[i].RepalceString)
	}
}

type MP struct {
	stack      []string
	inner      string
	CurrPos    int
	ScanLogger *log.Logger
}

func (mp *MP) Init(ScanLogger *log.Logger) {
	mp.stack = append(mp.stack, "S")
	mp.stack = append(mp.stack, EndStackSymbol)
	mp.inner = "S"
	mp.ScanLogger = ScanLogger
}

func (mp *MP) Pop() error {
	if mp.stack[0] == EndStackSymbol {
		return fmt.Errorf("try of pop from the end of the stack")
	}
	mp.stack = mp.stack[1:]
	return nil
}

func (mp *MP) Replace(replacement []string) error {
	if mp.stack[0] == EndStackSymbol {
		return fmt.Errorf("try of replace the end of the stack")
	}
	mp.Pop()
	mp.stack = append(mp.stack, replacement...)
	copy(mp.stack[len(replacement):], mp.stack[:len(mp.stack)-len(replacement)])
	copy(mp.stack[:len(replacement)], replacement[:])
	if mp.stack[0] == "" {
		mp.Pop()
	}
	return nil
}

func (mp *MP) Analyze(input string) error {
	str := strings.TrimSpace(input) + EndLineSymbol
	runes := []rune(str)
	process := true
	mp.ScanLogger.Printf("Промежуточное представление:\t%s", mp.inner)
	for process {
		stackSymbol := mp.stack[0]
		strSymbol := string(runes[mp.CurrPos])
		action, ok := Table[stackSymbol][strSymbol]
		if !ok {
			mp.ScanLogger.Printf("\033[31mОшибка\033[0m\n")
			mp.ScanLogger.Printf("Stack: %s", strings.Join(mp.stack, ""))
			mp.ScanLogger.Printf("Оставшаяся часть строки: %s\n", str[mp.CurrPos:])
			return fmt.Errorf("error during analyze. stack symbol <%s> and string symbol <%s>", stackSymbol, strSymbol)
		}
		if action.Move {
			mp.CurrPos++
		}
		switch action.Action {
		case ActionDone:
			process = false
		case ActionPop:
			if err := mp.Pop(); err != nil {
				return err
			}
		case ActionReplace:
			if err := mp.Replace(action.RepalceString); err != nil {
				return err
			}
		}
		if action.RuleNum != 0 {
			if action.RuleNum == 3 || action.RuleNum == 13 {
				mp.ScanLogger.Printf("Применяется правило %d:\t\033[33m%s -> %s\033[0m", action.RuleNum, stackSymbol, "ε")
			} else {
				mp.ScanLogger.Printf("Применяется правило %d:\t\033[33m%s -> %s\033[0m", action.RuleNum, stackSymbol, rules.Rules[action.RuleNum])
			}
			mp.inner = strings.Replace(mp.inner, stackSymbol, rules.Rules[action.RuleNum], 1)
			mp.ScanLogger.Printf("Промежуточное представление:\t\033[34m%s\033[0m", mp.inner)
		}
	}
	return nil
}
