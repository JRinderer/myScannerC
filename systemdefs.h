//
// Created by jrinder on 1/3/18.
//

#ifndef SCANNER01_SYSTEMDEFS_H
#define SCANNER01_SYSTEMDEFS_H



char *keywords[42] = {"AND", "ARRAY", "ASCII", "BEGIN", "BOOL", "BREAK", "CALL",
                      "CASE", "CONST", "CSTRING", "DCL", "DECIMAL", "DEFAULT", "DO",
                      "DOWNTO", "ELSE", "END", "FOR", "GLOBAL", "GOTO", "IF", "INT", "NEXT",
                      "NOT", "NUMBER", "OF", "OR", "PROC", "PROCEDURE", "READ", "READLN",
                      "REAL", "RECORD", "RETURN", "STRING", "THEN", "TO", "TYPE", "VAR", "WHILE",
                      "WRITE", "WRITELN"};

char *relationalOperators[] = {"==", "<", ">", "=!=", "=>", "=<"};

char otherOperators[6] = {':', '+', '-', '*', '/', '%'};

char delimiters[9] = {'.', '(', ')', ',', '{', '}', ';', '[', ']'};

char words[LIMIT][MAX]; // include LEXEME, and TOKENS
int wordi = 0, wordj = 0;
int wordLineNums[LIMIT];

char token[LIMIT][MAX]; // to store TOKEN TYPE not sure this is needed.
int tokeni = 0;
int tokenLineNums[LIMIT];

char lexeme[LIMIT][MAX]; // this is the literal string VALUE IF, X, 2, 3, ANDREW, etc.
int lexemei = 0; lexemej = 0;
int lexemeLineNum[LIMIT];

char nums[LIMIT][MAX];  // to store numbers
int numi = 0, numj = 0;
int numLineNums[LIMIT];

char delims[LIMIT]; // to store delimiters
int delimi = 0;
int delimLineNums[LIMIT];

char otherOps[LIMIT]; // to store other operators
int otherOpi = 0;
int otherOpLineNums[LIMIT];

char relOps[LIMIT][MAX]; // to store keywords
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];

#endif //SCANNER01_SYSTEMDEFS_H
