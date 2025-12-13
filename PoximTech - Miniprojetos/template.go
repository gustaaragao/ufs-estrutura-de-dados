package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Abrindo arquivos
	input, err := os.Open("light.input")
	if err != nil {
		panic(err)
	}
	defer input.Close()
	output, err := os.Create("output.txt")
	if err != nil {
		panic(err)
	}
	defer output.Close()

	// Writer com Buffer
	writer := bufio.NewWriter(output)
	defer writer.Flush()

	// Itera linha por linha
	scanner := bufio.NewScanner(input)
	for scanner.Scan() {
		line := scanner.Text()
		
		// Terminal
		fmt.Println("Linha:", line)

		// Arquivo output
		_, err := fmt.Fprintln(writer, line)
		if err != nil {
			panic(err)
		}
	}
}
