package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func writeFileString(str, filename string) error {
	if err := ioutil.WriteFile(filename, []byte(str), 0666); err != nil {
		return err
	}
	return nil

}

func writeFileBytes(content []byte, filename string) error {
	if err := ioutil.WriteFile(filename, content, 0666); err != nil {
		fmt.Fprintf(os.Stderr, "file.go:writeFileBytes(): 文件写入失败.%v", err)
		return err
	}
	return nil
}

func readFileBytes(filename string) ([]byte, error) {
	bytes, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	return bytes, nil
}

func readFileString(filename string) (string, error) {
	bytes, err := readFileBytes(filename)
	return string(bytes), err
}
