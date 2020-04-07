package main

import "encoding/json"

// SearchSingleJSON store one of seach json
type SearchSingleJSON struct {
	ID        int
	ComicName string `json:"comic_name"`
	ComicURL  string `json:"comic_url"`
}

// ComicJSON store comic json. contain chapters->data->chapter_id
type ComicJSON struct {
	ID             int
	ComicName      string `json:"title"`
	Description    string
	LastUpdateTime int    `json:"last_updatetime"`
	ComicPy        string `json:"comic_py"`
	Chapters       []ChapterInfo
}

type ChapterInfo struct {
	Title string
	Data  []ChapterSingleData
}

type ChapterSingleData struct {
	ChapterID    int    `json:"chapter_id"`
	ChapterTitle string `json:"chapter_title"`
}



// Chapter store chapter json
type Chapter struct {
	ChapterID int `json:"chapter_id"`
	ComicID int `json:"comic_id"`
	Title string
	PageURLs []string `json:"page_url"`
	PicNum int
}



func bytesToJSON(bytes []byte, v interface{}) error {
	return json.Unmarshal(bytes, v)
}

func JSONToBytes(v interface{}) ([]byte, error) {
	return json.Marshal(v)
}
