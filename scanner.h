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

#endif //SCANNER01_SCANNER_H
