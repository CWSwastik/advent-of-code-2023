#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE* fp, size_t size){
    //The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size); //size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\t'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

int isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int main() {
    char *m;
    char s[10000];

    printf("input string : ");
    m = inputString(stdin, 10);
    int j = 0;
    int length = strlen(m);
    for (int i = 0; i <= length; i++) {
        if (isDigit(m[i]) || m[i] == '\n') {
            s[j] = m[i];
            j++;
        }
    }
    // printf("%s\n", s);
    length = strlen(s);
    int sum = 0;
    for (int i = 0; i <= length; i++) {
        if (i == 0) {
            sum += (s[i] - '0')*10;
        }
        if (s[i] == '\n') {
            sum += s[i-1]  - '0';
            if (isDigit(s[i+1])) {
                sum += 10*(s[i+1] - '0');
            }
        }
    }
    printf("%d\n", sum);
    free(m);
    return 0;
}