package main

import (
	"DanArmor/ta5/pkg/mp"
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

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
	mpr := mp.MP{}
	mpr.Init(scannerLoggerSCAN)
	if err := mpr.Analyze(str); err != nil {
		fmt.Printf("\033[31mАнализ закончен с ошибкой: %s\033[0m", err.Error())
		return
	}
	steps := make([]int, len(mpr.Steps))
	copy(steps, mpr.Steps)
	for i, j := 0, len(steps)-1; i < j; i, j = i+1, j-1 {
		steps[i], steps[j] = steps[j], steps[i]
	}
	inner := "S"
	var output []string
	output = append(output, inner)
	for _, s := range steps {
		inner = mp.LastReplace(inner, mp.Rules[s][0], mp.Rules[s][1], 1)
		output = append(output, inner)
	}
	fmt.Printf("Правый вывод: %s\n", strings.Join(output, " \033[33m=>\033[0m "))
	for _, s := range steps{
		fmt.Printf("%d, ", s)
	}
	fmt.Printf("\n")
}
