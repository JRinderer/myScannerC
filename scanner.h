//
// Created by jrinder on 1/3/18.
//

#ifndef SCANNER01_SCANNER_H
#define SCANNER01_SCANNER_H

char mkeUprCse(char);
int testChar(char, char);
char getNxtPntdVal(FILE *);
int charType(char);
void build2dArry(char arry[LIMIT][MAX],int, int, char, FILE *);
int isExAcceptableChar(char);
void printTokens();
int isKeyWord(char *);
void build2dArryNum(char arry[LIMIT][MAX],int, int, char, FILE *);

#endif //SCANNER01_SCANNER_H
