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

void slice(const char* str, char* result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
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
        char text[5];
        slice(m, text, i, i+5);
        // printf("%s\n", text);
        if (text[0] == 'o' && text[1] == 'n' && text[2] == 'e') {
            s[j] = '1';
            j++;
        }
        if (text[0] == 't' && text[1] == 'w' && text[2] == 'o') {
            s[j] = '2';
            j++;
        }
        if (text[0] == 't' && text[1] == 'h' && text[2] == 'r' && text[3] == 'e' && text[4] == 'e') {
            s[j] = '3';
            j++;
        }
        if (text[0] == 'f' && text[1] == 'o' && text[2] == 'u' && text[3] == 'r') {
            s[j] = '4';
            j++;
        }
        if (text[0] == 'f' && text[1] == 'i' && text[2] == 'v' && text[3] == 'e') {
            s[j] = '5';
            j++;
        }
        if (text[0] == 's' && text[1] == 'i' && text[2] == 'x') {
            s[j] = '6';
            j++;
        }
        if (text[0] == 's' && text[1] == 'e' && text[2] == 'v' && text[3] == 'e' && text[4] == 'n') {
            s[j] = '7';
            j++;
        }
        if (text[0] == 'e' && text[1] == 'i' && text[2] == 'g' && text[3] == 'h' && text[4] == 't') {
            s[j] = '8';
            j++;
        }
        if (text[0] == 'n' && text[1] == 'i' && text[2] == 'n' && text[3] == 'e') {
            s[j] = '9';
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