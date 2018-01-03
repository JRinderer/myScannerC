//
// Created by jrinder on 1/3/18.
//

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <memory.h>
#include <jmorecfg.h>

#include "token.h"
#include "scanner.h"
#include "systemdefs.h"

TokenType getTokenType(FILE *filePntr) {
    int lneNum = 1;
    char chr;

//-------------------------------------Loop through Chars and scan to determine types----------------------------------
    while((chr=fgetc(filePntr))!=EOF){
        chr=mkeUprCse(chr);
        //-----------------------------Check to see if end of line if so increment next line---------------------------
        if (testChar(chr,'\n')==0){
            lneNum++;
        }
        //-----------------------------Check to see if a comment has been made-----------------------------------------
        if((testChar(chr,'/'))==0){
            if(getNxtPntdVal(filePntr)=='/'){
                while(getNxtPntdVal(filePntr)!='\n'){
                    lneNum++;
                }
            }else{
                fseek(filePntr,-1,SEEK_CUR);
            }
        }
        //-----------------------------Determine what char is alpha, num, etc------------------------------------------
        int chrType = 0;

        chrType = charType(chr);

        if (chrType==1){
            build2dArry(words,wordi,wordj, chr, filePntr);
            //Now I need a method to determine if this is a KEYWORD or word.
            printf("First word is %s",words[wordi]);
        }else if(chrType==2){
            printf("% d This is a digit\n",nums[numi]);
        }else if(chrType==3){
            printf("This is the default\n");
        }
    }

    return EOT;
}

void writeLnes(){}

void build2dArry(char arry[LIMIT][MAX],int itemi, int itemj, char c, FILE * fPtr) {
    arry[itemi][itemj++] = c;
    while (charType(c = fgetc(fPtr))==1){

        arry[itemi][itemj++]= mkeUprCse(c);
    }
    arry[itemi][itemj] = '\0';
}

char getNxtPntdVal(FILE *fPntr) {
    return (fgetc(fPntr));
}

int testChar(char c, char c2) {
    if (c==c2){
        return 0;
    }else{
        return 1;
    }
}

char mkeUprCse(char c) {
    c = putchar(toupper(c));
    return c;
}

int charType(char c) {
    if(isalpha(c)){
        return 1;
    }else if(isdigit(c)){
        return 2;
    }else if(ispunct(c)){
        return 3;
    }
}




int isExAcceptableChar(char c) {
    if (c == '.' || c == '(' || c == ')' || c == ',' || c =='{' || c == '}' ||
        c == ';' || c == '[' || c == ']' ||
        c == ':' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
        c == '=' || c == '<' || c == '>' || c == '!' || c == '"'
        /* || c == '#' */ ) {

        return 1;
    } else
        return 0;
}

