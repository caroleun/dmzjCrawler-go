package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
)

// UserAgent User-Agent in Get request
const UserAgent = "Version/118   Mozilla/5.0 (Linux; Android 6.0.1; MuMu Build/V417IR; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/52.0.2743.100 Mobile Safari/537.36"

func getBytes(url string, headers map[string]string) ([]byte, error) {
	request, _ := http.NewRequest("GET", url, nil)
	for k, v := range headers {
		request.Header.Set(k, v)
	}

	resp, err := (&http.Client{}).Do(request)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	bytes, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}
	return bytes, nil
}

func getSearchJSONStr(query string) (JSONStr string, err error) {
	searchURL := "http://sacg.dmzj.com/comicsum/search.php?s=" + query
	regexJSON := `var g_search_data = (.*?);`
	reg := regexp.MustCompile(regexJSON)
	var searchJSONStr string

	if searchBytes, err := getBytes(searchURL, nil); err == nil {
		searchJSONStr = reg.FindStringSubmatch(string(searchBytes))[1]
	} else {
		fmt.Fprintf(os.Stderr, "get search json fail. %v", err)
		return "", err
	}
	return searchJSONStr, nil
}

func getSearchJSON(query string) ([]SearchSingleJSON, error) {
	searchJSONStr, err := getSearchJSONStr(query)
	if err != nil {
		return nil, err
	}
	var searchJSON []SearchSingleJSON
	err = bytesToJSON([]byte(searchJSONStr), &searchJSON)
	if err != nil {
		return nil, err
	}
	return searchJSON, nil
}

func getComicJSONBytes(comicID int) ([]byte, error) {
	// url := fmt.Sprintf("http://v3api.dmzj.com/comic/comic_%d.json", comicID)
	url := fmt.Sprintf("http://v3api.dmzj.com/comic/%d.json", comicID)
	headers := map[string]string{
		"Host":       "sacg.dmzj.com",
		"User-Agent": UserAgent,
	}
	bytes, err := getBytes(url, headers)
	if err != nil {
		fmt.Fprintf(os.Stderr, "get comic json fail. %v", err)
		return nil, err
	}
	return bytes, nil
}

func getComicJSON(comicID int) (*ComicJSON, error) {
	bytes, err := getComicJSONBytes(comicID)
	if err != nil {
		return nil, err
	}
	var comicJSON ComicJSON
	err = bytesToJSON(bytes, &comicJSON)
	if err != nil {
		fmt.Fprintf(os.Stderr, "comic json解析失败. %v\nhttp://v3api.dmzj.com/comic/%d.json返回值:%s", err, comicID, string(bytes))
		return nil, err
	}
	return &comicJSON, nil
}

func getChapterJSONBytes(comicID, chapterID int) ([]byte, error) {
	url := fmt.Sprintf("http://v3api.dmzj.com/chapter/%d/%d.json", comicID, chapterID)
	headers := map[string]string{
		"User-Agent": UserAgent,
		"Host":       "v3api.dmzj.com",
	}
	bytes, err := getBytes(url, headers)
	if err != nil {
		fmt.Fprintf(os.Stderr, "get chapter json fail. %v", err)
		return nil, err
	}
	return bytes, err
}

func getChapterJSON(comicID, chapterID int) (*Chapter, error) {
	bytes, err := getChapterJSONBytes(comicID, chapterID)
	if err != nil {
		return nil, err
	}
	var chapterJSON Chapter
	err = bytesToJSON(bytes, &chapterJSON)
	if err != nil {
		fmt.Fprintf(os.Stderr, "chapter json解析失败。%v", err)
		return nil, err
	}
	return &chapterJSON, nil
}

func getPage(url string) ([]byte, bool) {
	headers := map[string]string{
		"Referer":    "http://images.dmzj.com/",
		"User-Agent": UserAgent,
		"Host":       "imgsmall.dmzj.com",
	}
	bytes, err := getBytes(url, headers)
	if err != nil {
		fmt.Fprintf(os.Stderr, "获取图片失败. %v", err)
		return nil, false
	}
	return bytes, true
}
