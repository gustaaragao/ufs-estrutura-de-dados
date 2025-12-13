// go run rede_social.go ./heavy.input ./output.txt

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type person struct {
	name string
	prev *person
	next *person
}

func createPerson(name *string) *person {
	newPerson := person{*name, nil, nil}
	return &newPerson
}

type socialNetwork struct {
	last *person
	size int
}

func createSocialNetwork() *socialNetwork {
	network := socialNetwork{nil, 0}
	return &network
}

func searchPerson(name *string, network *socialNetwork) *person {
	current := network.last
	for i := 0; i < network.size; i++ {
		if current.name == *name { // Encontrou a pessoa na rede
			break
		}

		current = current.next
	}
	if current == nil || current.name != *name {
		return nil
	}
	return current
}

func insertPerson(newPerson *person, network *socialNetwork) string {
	p := searchPerson(&newPerson.name, network)
	if p != nil {
		return "[ERROR] ADD " + newPerson.name
	}

	if network.size == 0 {
		network.last = newPerson
		newPerson.prev = newPerson
		newPerson.next = newPerson
	} else {
		first := network.last.next
		// Ajustando o primeiro
		newPerson.next = first
		first.prev = newPerson
		// Ajustando o último
		network.last.next = newPerson
		newPerson.prev = network.last
		// Ajustando a lista encadeada
		network.last = newPerson
	}

	network.size++
	return "[ OK  ] ADD " + newPerson.name
}

func showPerson(name *string, network *socialNetwork) string {
	p := searchPerson(name, network)
	if p == nil {
		return "[ERROR] ?<-" + *name + "->?"
	}

	return "[ OK  ] " + p.prev.name + "<-" + *name + "->" + p.next.name
}

func removePerson(name *string, network *socialNetwork) string {
	p := searchPerson(name, network)
	if p == nil {
		return "[ERROR] REMOVE " + *name
	}

	prevPerson := p.prev
	nextPerson := p.next
	// Ajustando a pessoa anterior
	prevPerson.next = p.next
	// Ajustando a próxima pessoa
	nextPerson.prev = prevPerson

	// Ajustando lista
	if p == network.last {
		network.last = prevPerson
	}
	network.size--

	return "[ OK  ] REMOVE " + *name
}

func main() {
	input, err := os.Open(os.Args[1])
	// Abrindo arquivos
	if err != nil {
		panic(err)
	}
	defer input.Close()
	output, err := os.Create(os.Args[2])
	if err != nil {
		panic(err)
	}
	defer output.Close()

	// Writer com Buffer
	writer := bufio.NewWriter(output)
	defer writer.Flush()

	// Cria a rede social
	network := createSocialNetwork()

	// Itera linha por linha
	scanner := bufio.NewScanner(input)
	for scanner.Scan() {
		op, name, _ := strings.Cut(scanner.Text(), " ")

		out := ""
		switch op {
		case "ADD":
			newPerson := createPerson(&name)
			out = insertPerson(newPerson, network)
		case "SHOW":
			out = showPerson(&name, network)
		case "REMOVE":
			out = removePerson(&name, network)
		}

		// Arquivo output
		_, err := fmt.Fprintln(writer, out)
		if err != nil {
			panic(err)
		}
	}
}
