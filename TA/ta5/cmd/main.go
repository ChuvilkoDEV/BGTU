package main

import (
	"DanArmor/ta5/pkg/scan"
	//"DanArmor/ta5/pkg/mp"
	"DanArmor/ta5/pkg/rules"
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
	"unicode"

	"github.com/m1gwings/treedrawer/tree"
)

type LeftOutput struct {
	inner string
	Steps []string
}

func (lo *LeftOutput) Init() {
	lo.inner = "S"
	lo.Steps = append(lo.Steps, "S")
}

func (lo *LeftOutput) Analyze(node *scan.Tree) {
	if unicode.IsUpper([]rune(node.Label)[0]){
		if(node.Label == "ERROR"){
			lo.inner = "ERROR"
			lo.Steps = append(lo.Steps, lo.inner)
		} else if node.RuleNumber != 0{
			lo.inner = strings.Replace(lo.inner, node.Label, rules.Rules[node.RuleNumber], 1)
			lo.Steps = append(lo.Steps, lo.inner)
		}
		for _, c := range node.Children {
			lo.Analyze(c)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var (
		str string
		err error
	)
	fmt.Print("Ввод: ")
	if str, err = reader.ReadString('\n'); err != nil {
		fmt.Println(err)
	}
	scannerLoggerSCAN := log.New(os.Stdout, "SCAN: ", log.Ltime)
	scannerLoggerERROR := log.New(os.Stderr, "ERROR: ", log.Ltime|log.Lshortfile)
	s := scan.Scan{
		LoggerScan:  *scannerLoggerSCAN,
		LoggerError: *scannerLoggerERROR,
	}
	if err = s.Init(str); err != nil {
		fmt.Println(err)
	}
	s.Analyze()
	var drawFn func(node *scan.Tree, t *tree.Tree)
	drawFn = func(node *scan.Tree, t *tree.Tree) {
		t.SetVal(tree.NodeString(node.Label))
		for _, c := range node.Children {
			tChild := t.AddChild(tree.NodeString(c.Label))
			drawFn(c, tChild)
		}
	}
	t := tree.NewTree(tree.NodeString(""))
	drawFn(s.TreeView, t)
	var lo LeftOutput
	lo.Init()
	lo.Analyze(s.TreeView)

	fmt.Println(t)
	strSteps := strings.Join(lo.Steps, "\033[33m => \033[0m")
	fmt.Println("Левый вывод: ", strSteps)

}
