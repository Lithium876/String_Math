#include<stdio.h>
#include <ctype.h>

//GLOBAL VARIABLES
char S1[9], O[1], S2[9];
int error =0;
char operations[4]={'+','/','-','*'};
char alphabet[27]={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//=============================================

//FUNCTION PROTOTYPE
void clear();
//==================

int main(){
    char input[19];

    printf("\t\t\t String Math Program\n\n");
    printf("Use any of the following keyphrases to stop:\n'exit', 'end', or 'quit'\n\n");
    while(1){ //LOOP FOREVER
        printf("> ");
        scanf("%s",input);

        //ENDS LOOP IF KEYPHRASE IS ENTERED
        if(check(input,"end") || check(input,"exit") || check(input,"quit")) break;

        //FUNCTION CALL TO SLPIT UP INPUT INTO THE  CORRECT GRAMMER 'S  O S'
        str_split(input);

        if(error>0){
            clear();
            printf("Error\n");
            error=0;
        }else if(length(S1)>9 || length(O)==0 || length(S2)>9){
            printf("Error\n");
            //CLEAR OUT OLD DATA FROM THE ARRAYS 'S1, O, S2'
            clear();
        }else{
            //FUNCTION CALL TO DO CALCULATIONS
            cal(S1,S2);
            clear();
        }
    }
    return 0;
}

char upper(char ch){
    //CHANGE CHARACTERS TO UPPERCASE
    if (ch >= 'a' && ch <= 'z'){
        ch = (int)ch - 32;
    }
    return ch;
}

int lower(char ch){
    //CHECKS IF CHARACTERS ARE LOWECASE
    if ((int)ch >= 97 && (int)ch <= 122)
      return 1;
   else
      return 0;

}

int cal(char str1[],char str2[]){
    int i,j,val;
    char op=O[0];
    int str1_Val[9],str2_Val[9];

    /**GETS THE NUMERICAL VALUE OF EACH CHARACTER IN string 1 and string 2 AND STORE EACH VALUE IN A NEW ARRAY, str1_VaL
    and str2_Val. EXAMPLE: str1 CONTAINS CHARACTERS 'A, B, C' and str2 CONTAINS CHARACTERS 'D, E, F'; THESE LOOPS GET
    THE VALUE OF EACH CHARACTER WHICH IS '1, 2, 3' AND '4, 5, 6' AND STORE IT IN A NEW ARRAY CALLED str1_Val and str2_Val
    RESPECTIVELY**/
    for(j=0;j<length(str1);j++){
         for(i=1;i<=27;i++){
            if(alphabet[i]==str1[j]){
                str1_Val[j]=i;
            }
        }
    }
    for(j=0;j<length(str2);j++){
         for(i=1;i<=27;i++){
            if(alphabet[i]==str2[j]){
                str2_Val[j]=i;
            }
        }
    }
    //========================================================================================

    //IF THE FIRST STRING IS LONGER THAN THE SECOND STRING:
    if(length(str1)>length(str2)){
        for(i=0;i<length(str2);i++){

            //GETS THE OPERATION SYMBOL AND CHECK FOR CASES
            switch(op){

            //IF THE OPERATION SYMBOL IS A PLUS SIGN THIS CASE RUNS
            case '+':
                val=str1_Val[i]+str2_Val[i];

                /**IF THE RESULT OF 'str1_Val[i]+str2_Val[i]' IS GREATER THAN 26 OR LESS THAN 0 PRING THR UPPER CASE
                VEVRSION OF THE CHARACTER IN STRING 1**/
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                //=============================================================
                }else{
                    printf("%c", alphabet[val]); //GETS THE CHARACTER AT THE INDEX REPRESENTED BY 'val'
                }
                break;//END CASE
            //==================================================

            //IF THE OPERATION SYMBOL IS A MINUS SIGN THIS CASE RUNS
            case '-':
                val=str1_Val[i]-str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            //===================================

            //IF THE OPERATION SYMBOL IS A DIVISION SIGN THIS CASE RUNS
            case '/':
                val=str1_Val[i]/str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            //==============================================

            //IF THE OPERATION SYMBOL IS A MULTIPLICATION SIGN THIS CASE RUNS
            case '*':
                val=str1_Val[i]*str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            //=================================================
            }
        }
        //THIS LOOP PRINTS BACK THE REMAINING CHARACTERS FROM THE LONGER STRING, str1
        for(i=length(str2);i<=length(str1);i++){
            printf("%c", str1[i]);
        }
        //=======================================================
    }

    //IF THE FIRST STRING IS THE SAME LENGTH AS THE SECOND STRING:
    if(length(str1)==length(str2)){
        for(i=0;i<length(str2);i++){

            switch(op){
            case '+':
                val=str1_Val[i]+str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '-':
                val=str1_Val[i]-str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '/':
                val=str1_Val[i]/str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '*':
                val=str1_Val[i]*str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            }
        }
    }
    //=================================================================

    //IF THE SECOND STRING IS LONGER THAN THE FIRST STRING:
    if(length(str1)<length(str2)){
        for(i=0;i<length(str1);i++){

            switch(op){
            case '+':
                val=str1_Val[i]+str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '-':
                val=str1_Val[i]-str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '/':
                val=str1_Val[i]/str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            case '*':
                val=str1_Val[i]*str2_Val[i];
                if(val<1 || val>26){
                    printf("%c", upper(alphabet[str1_Val[i]]));
                }else{
                    printf("%c", alphabet[val]);
                }
                break;
            }
        }
         //THIS LOOP PRINTS BACK THE REMAINING CHARACTERS FROM THE LONGER STRING, str2
        for(i=length(str1);i<=length(str2);i++){
            printf("%c", str2[i]);
        }
        //=================================================
    }
    //============================================================================
    printf("\n");
}

int check(char str1[],char str2[]){
    //THIS FUNCTION COMPARE STRING1 AND STRING2 AND RETURN IF THEY MATCH OR NOT
    int i=0,flag=0;

    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }
    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;
    //================================================
}

int length(char str[]){
    //THIS FUNCTION GETS THE LENGTH OF A STRING
    int i;
    for(i = 0; str[i] != '\0'; ++i);
    return i;
    //=========================================
}

int str_split(char str[]) {
    //THIS FUNCTION SPLITS UP INPUT INTO THE CORRECT GRAMMER S O S
    int i,j;
    int flag=0,k=0;

    //GETS CHARACTERS INTO ARRAY S1
    for(j=0;j<length(str);j++){
        if(isalpha(str[j]) && flag ==0 ){
            //IF THE CHARACTER IS NOT IN LOWER CASE ADD 1 TO THE GLOBAL VARIABLE 'error'
            if(!lower(str[j])){
                error++;
                break;
            }
            S1[j]=str[j];
    //======================================
        }else {
            //IF FLAG IS ZERO IT MEANS THAT NO ARITHMENTIC OPERATOR WAS FOUND IN INPUT AS YET
            if(flag==0){
                // GETS THE ARITHMENTIC OPERATOR INTO ARRAY O
                for(i=0;i<4;i++){
                   if (operations[i] == str[j]){
                        O[0]=str[j];
                        flag=1;
                        break;
                        }
                //===============================================
                }
            }
        }
        //IF THE ARITHMENTIC OPERATOR IS FOUND, START ADDING THE REMAINING CHARACTERS TO ARRAY S2
        if(flag ==1){
            if(isalpha(str[j])){
                if(!lower(str[j])){
                    error++;
                    break;
                }else{
                    S2[k]=str[j];
                    k++;
                }
        //=======================================
            }
        }
    }
}

void clear(){
    //CLEARS EACH INDEX OF THE ARRAYS
    memset (S1, 0, 9);
    memset (S2, 0, 9);
    memset (O, 0, 1);
}
