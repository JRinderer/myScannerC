//
// Created by jrinder on 1/3/18.
//

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <memory.h>

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
        if (testChar(chr,'\n')==0|| testChar(chr,NULL)==0){
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
            build2dArry(words,intlArryi,intlArryj, chr, filePntr); //builds the 2d array (forming words)
            wordLineNums[intlArryi] = lneNum;
            if(isKeyWord(words[intlArryi])==0){
                token[tokeni]=words[intlArryi];
                tokeni++;
            }else{
                token[tokeni]="CONST";
                tokeni++;
            }
            //printf("The Word is %s",words[wordi]);
            intlArryi++;intlArryj = 0;
            fseek(filePntr, -1, SEEK_CUR);
        }else if(chrType==2){
            build2dArryNum(nums,intlArryi,intlArryj,chr,filePntr);
            token[tokeni]="NUMBER";
            tokeni++;
            wordLineNums[intlArryi] = lneNum;
            intlArryi++;intlArryj = 0;
            fseek(filePntr, -1, SEEK_CUR);
        }else if(chrType==3){
            printf("This is the default\n"); //Here will require a deeper dive like in word to determine if the data
                                            //type fits in a particular type. Operator punctuation. etc.
        }
    }
    printTokens();
    return EOT;
}
//=====================================================================================================================
//-------------------Functions below support the above function--------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//===================This function will eventually write this data to an output file===================================
void printTokens(){
    int i;
    for(i = 0; i<tokeni; i++){
        if(token[i]!="NUMBER"){
            writeLnes(token[i],words[i]);
            //printf("%s\t\t%s\n",token[i],words[i]);
        }else{
            writeLnes(token[i],nums[i]);
            //printf("%s\t\t%s\n",token[i],nums[i]);
        }
    }
}
//=====================================================================================================================
//*********************************************************************************************************************
//====================This function tests to see if the string is a keyword============================================
int isKeyWord(char *strn){
    int i;
    int results = 1; //1 is false if not a keyWord then 1 otherwise 0

    for(i = 0; i<42;i++){
        if(!strcmp(keywords[i],strn)) {
            results = 0;
        }
    }
    return results;
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================this function determines if the string is a constant like a string of text chars/numbers========
int isConstant(char *strn){

}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================This function determines if the char is an operator possibly break down to dif types ops========
int isOperator(char c){
    int i;
    int results = 1;

    for(i = 0; i< 22;i++){
        //code to check against operator array
    }
}
//=====================================================================================================================
//*********************************************************************************************************************
//====================This function will write data to a file may not need=============================================
void writeLnes(char * txt1, char * txt2){
    FILE * flPntr;
    char stngHldr[LIMIT]="";
    strcat(stngHldr,txt1);
    strcat(stngHldr, "\t\t");
    strcat(stngHldr,txt2);
    strcat(stngHldr,"\n");
    flPntr = fopen("scnr.scan","a");
    fputs(stngHldr,flPntr);
    fclose(flPntr);
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================this function builds a 2d array of continuous chars (ints included)=============================
void build2dArry(char arry[LIMIT][MAX],int itemi, int itemj, char c, FILE * fPtr) {
    arry[itemi][itemj++] = c;
    while (charType(c = fgetc(fPtr))==1){

        arry[itemi][itemj++]= mkeUprCse(c);
    }
    arry[itemi][itemj] = '\0';
}

void build2dArryNum(char arry[LIMIT][MAX],int itemi, int itemj, char c, FILE * fPtr) {
    arry[itemi][itemj++] = c;
    while (charType(c = fgetc(fPtr))==2){

        arry[itemi][itemj++]= c;
    }
    arry[itemi][itemj] = '\0';
}


//=====================================================================================================================
//*********************************************************************************************************************
//=====================Gets value from pointer in file consider removing===============================================
char getNxtPntdVal(FILE *fPntr) {
    return (fgetc(fPntr));
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================Test 2 char's against one another tests end of line comments, etc===============================
int testChar(char c, char c2) {
    if (c==c2){
        return 0;
    }else{
        return 1;
    }
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================Makes a char upper case possibly remove as this may be done elsewhere===========================
char mkeUprCse(char c) {
    c = putchar(toupper(c));
    return c;
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================Determines what the char type is. ispunct will require deeper dive==============================
int charType(char c) {
    if(isalpha(c)){
        return 1;
    }else if(isdigit(c)){
        return 2;
    }else if(ispunct(c)){
        return 3;
    }
}
//=====================================================================================================================
//*********************************************************************************************************************
//=====================================================================================================================
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

