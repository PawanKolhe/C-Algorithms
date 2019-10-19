#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address){
    char *temp = malloc((strlen(address) + 7) * sizeof(address[0]));
    int i = 0, j = 0;
    for(; i < strlen(address); i++){
        if(address[i] == '.'){
            temp[j++] = '[';
            temp[j++] = '.';
            temp[j++] = ']';
        }else{
            temp[j++] = address[i];
        }
    }
    temp[j] = '\0';
    return temp;
}

