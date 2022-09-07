# Webwalker

Webwalker is a piece of code that I have written, aimed to calculate the optimal solution for a game of [Weaver](https://wordwormdormdork.com/).

# Usage

## To compile:
`g++ *.h *.cpp `

## To run:
`<EXECUTABLE_NAME> <WORD_LIST_FILE> <SOURCE_WORD> <DESTINATION_WORD>`

where `<EXECUTABLE_NAME>` is the executable output by g++, 

`<WORD_LIST_FILE>` is the path to the file containing the words, one word for each line, without any spaces,

`<SOURCE_WORD>` is the beginning word, 

and `<DESTINATION_WORD>` is the target word.

## Example:
`./out.exe words4.txt mini mart`

# Word lists

The files [words4.txt](./words4.txt) and [words5.txt](./words5.txt) are the official word lists used by Weaver (last updated 7/09/2022) which contain words of lengths 4 and 5, respectively.
