package scan

import (
	"fmt"
	"log"
	"strings"
)

type Scan struct {
	Str         string
	Runes       []rune
	CurrPos     int
	LoggerScan  log.Logger
	LoggerError log.Logger
	TreeView    *Tree
	IsError     bool
	Error       error
}

type Tree struct {
	Children   []*Tree
	Label      string
	RuleNumber int
	RuleString string
}

func (s *Scan) nextSym() error {
	if s.CurrPos >= s.SizeRunes() {
		return fmt.Errorf("current pos is <%d> and length of string is <%d>", s.CurrPos, s.SizeRunes())
	}
	s.CurrPos++
	return nil
}

func (s *Scan) SizeRunes() int {
	return len(s.Runes)
}

func (s *Scan) CurrRune() (rune, error) {
	if s.CurrPos >= s.SizeRunes() {
		return '\000', fmt.Errorf("current pos is <%d> and length of string is <%d>", s.CurrPos, s.SizeRunes())
	}
	return s.Runes[s.CurrPos], nil
}

func (s *Scan) IsCurrEqual(r rune) error {
	if currRune, err := s.CurrRune(); currRune == r && err == nil {
		return nil
	} else {
		if err != nil {
			return fmt.Errorf("current rune <%c> is not equal to rune <%c>. %w", currRune, r, err)
		} else {
			return fmt.Errorf("current rune <%c> is not equal to rune <%c>", currRune, r)
		}
	}
}

func (s *Scan) PerfomStep(r rune) (node *Tree, err error) {
	if err = s.IsCurrEqual(r); err != nil {
		return node, err
	}
	node = &Tree{
		Label: string(r),
	}
	err = s.nextSym()
	return node, err
}

func (s *Scan) GenStep(r rune) func() (*Tree, error) {
	return func() (*Tree, error) {
		return s.PerfomStep(r)
	}
}

func (s *Scan) ThrowError(r rune) func() (*Tree, error) {
	return func() (*Tree, error) {
		return nil, fmt.Errorf("wrong input")
	}
}

func (s *Scan) Init(str string) error {
	s.Str = strings.TrimSpace(str)
	s.Runes = []rune(s.Str)
	s.IsError = false
	return nil
}

type (
	Step         func() (*Tree, error)
	SliceOfSteps []Step
)

func (s *Scan) RuleRecord(parent *Tree, number int, representation string) {
	s.LoggerScan.Printf("Применяется правило номер %d: \t\033[33m%s\033[0m\n", number, representation)
	parent.RuleNumber = number
	parent.RuleString = representation
}

func (s *Scan) ApplySteps(parent *Tree, steps SliceOfSteps) error {
	if s.IsError {
		return s.Error
	}
	var err error
	for _, fn := range steps {
		if node, err := fn(); err != nil {
			if node == nil {
				node = &Tree{
					Label:      "ERROR",
					RuleNumber: 0,
				}
			}
			s.Error = err
			s.IsError = true
			parent.Children = append(parent.Children, node)
			return err
		} else {
			parent.Children = append(parent.Children, node)
		}
	}
	return err
}

func (s *Scan) Analyze() error {
	s.LoggerScan.Printf("\033[32mНачало анализа\033[0m\n")
	parent, err := s.RuleS()
	s.TreeView = parent
	if err != nil {
		s.LoggerError.Printf("\033[31mАнализ закончен с ошибкой\033[0m\n")
		s.LoggerError.Printf("\033[31m%s\033[0m\n", err.Error())
	}
	return err
}

func (s *Scan) RuleS() (parent *Tree, err error) {
	parent = &Tree{
		Label: "S",
	}
	if s.CurrPos < s.SizeRunes() &&
		(s.IsCurrEqual('a') == nil || s.IsCurrEqual('{') == nil || s.IsCurrEqual('!') == nil) {
		s.RuleRecord(parent, 1, "S -> OS'")
		err = s.ApplySteps(parent, SliceOfSteps{s.RuleO, s.RuleS_})
	} else {
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('a')}) // force
	}
	return parent, err
}

func (s *Scan) Epsilon() (parent *Tree, err error) {
	parent = &Tree{
		Label: "ε",
	}
	return parent, err
}

func (s *Scan) IsEnd() bool {
	return s.CurrPos >= s.SizeRunes()
}

func (s *Scan) RuleS_() (parent *Tree, err error) {
	parent = &Tree{
		Label: "S'",
	}
	if s.CurrPos < s.SizeRunes() &&
		(s.IsCurrEqual('a') == nil || s.IsCurrEqual('{') == nil || s.IsCurrEqual('!') == nil) {
		s.RuleRecord(parent, 2, "S' -> OS'")
		err = s.ApplySteps(parent, SliceOfSteps{s.RuleO, s.RuleS_})
	} else if s.IsEnd() || s.IsCurrEqual(']') == nil {
		s.RuleRecord(parent, 3, "S' -> ε")
		err = s.ApplySteps(parent, SliceOfSteps{s.Epsilon})
	} else {
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('a')}) // force
	}
	return parent, err
}

func (s *Scan) RuleO() (parent *Tree, err error) {
	parent = &Tree{
		Label: "O",
	}
	switch {
	case s.IsCurrEqual('a') == nil:
		s.RuleRecord(parent, 4, "O -> aO'")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('a'), s.RuleO_})
	case s.IsCurrEqual('{') == nil:
		s.RuleRecord(parent, 5, "O -> {Y[S]}")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('{'), s.RuleY, s.GenStep('['), s.RuleS, s.GenStep(']'), s.GenStep('}')})
	case s.IsCurrEqual('!') == nil:
		s.RuleRecord(parent, 6, "O -> !(Y)[S]")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('!'), s.GenStep('('), s.RuleY, s.GenStep(')'), s.GenStep('['), s.RuleS, s.GenStep(']')})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('a')})
	}
	return parent, err
}

func (s *Scan) RuleO_() (parent *Tree, err error) {
	parent = &Tree{
		Label: "O'",
	}
	switch {
	case s.IsCurrEqual('<') == nil:
		s.RuleRecord(parent, 7, "O' -> <a[S]")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('<'), s.GenStep('a'), s.GenStep('['), s.RuleS, s.GenStep(']')})
	case s.IsCurrEqual('=') == nil:
		s.RuleRecord(parent, 8, "O' -> =R")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('='), s.RuleR})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('<')})
	}
	return parent, err
}

func (s *Scan) RuleR() (parent *Tree, err error) {
	parent = &Tree{
		Label: "R",
	}
	switch {
	case s.IsCurrEqual('-') == nil:
		s.RuleRecord(parent, 9, "R -> -(E)")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('-'), s.GenStep('('), s.RuleE, s.GenStep(')')})
	case s.IsCurrEqual('(') == nil:
		s.RuleRecord(parent, 10, "R -> (EE'")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('('), s.RuleE, s.RuleE_})
	case s.IsCurrEqual('a') == nil:
		s.RuleRecord(parent, 11, "R -> aT")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('a'), s.RuleT})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('-')})
	}
	return parent, err
}

func (s *Scan) RuleT() (parent *Tree, err error) {
	parent = &Tree{
		Label: "T",
	}
	switch {
	case s.IsCurrEqual('[') == nil:
		s.RuleRecord(parent, 12, "T -> [S]")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('['), s.RuleS, s.GenStep(']')})
	case s.IsCurrEqual('a') == nil || s.IsCurrEqual('{') == nil ||
		s.IsCurrEqual('!') == nil || s.IsCurrEqual(']') == nil || s.IsEnd():
		s.RuleRecord(parent, 13, "T -> ε")
		err = s.ApplySteps(parent, SliceOfSteps{s.Epsilon})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('[')})
	}
	return parent, err
}

func (s *Scan) RuleY() (parent *Tree, err error) {
	parent = &Tree{
		Label: "Y",
	}
	switch{
	case s.IsCurrEqual('!') == nil:
		s.RuleRecord(parent, 14, "Y -> !(Y)")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('!'), s.GenStep('('), s.RuleY, s.GenStep(')')})
	case s.IsCurrEqual('a') == nil:
		s.RuleRecord(parent, 15, "Y -> aY'")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('a'), s.RuleY_})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('!')})
	}
	return parent, err
}

func (s *Scan) RuleY_() (parent *Tree, err error) {
	parent = &Tree{
		Label: "Y'",
	}
	switch{
	case s.IsCurrEqual('=') == nil:
		s.RuleRecord(parent, 16, "Y' -> =a")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('='), s.GenStep('a')})
	case s.IsCurrEqual('<') == nil:
		s.RuleRecord(parent, 17, "Y' -> <a")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('<'), s.GenStep('a')})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('=')})
	}
	return parent, err
}

func (s *Scan) RuleE() (parent *Tree, err error) {
	parent = &Tree{
		Label: "E",
	}
	switch {
	case s.IsCurrEqual('(') == nil:
		s.RuleRecord(parent, 20, "E -> (EE'")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('('), s.RuleE, s.RuleE_})
	case s.IsCurrEqual('-') == nil:
		s.RuleRecord(parent, 18, "E -> -(E)")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('-'), s.GenStep('('), s.RuleE, s.GenStep(')')})
	case s.IsCurrEqual('a') == nil:
		s.RuleRecord(parent, 19, "E -> a")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('a')})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('a')})
	}
	return parent, err
}

func (s *Scan) RuleE_() (parent *Tree, err error) {
	parent = &Tree{
		Label: "E'",
	}
	switch{
	case s.IsCurrEqual('*') == nil:
		s.RuleRecord(parent, 21, "E' -> *E)")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('*'), s.RuleE, s.GenStep(')')})
	case s.IsCurrEqual('+') == nil:
		s.RuleRecord(parent, 22, "E' -> +E)")
		err = s.ApplySteps(parent, SliceOfSteps{s.GenStep('+'), s.RuleE, s.GenStep(')')})
	default:
		err = s.ApplySteps(parent, SliceOfSteps{s.ThrowError('+')})
	}
	return parent, err
}
