#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isSymbol(char s) {
    return (!isdigit(s) && s != '.' && s != '\0' && s != '\n');
}

int main(){
    FILE *fptr = fopen("input.txt", "r");

    char prevLine[200] = "";
    char line[200] = "";
    char nextLine[200];

    int j = 1;
    int finalAnswer = 0;

    while(fgets(nextLine, 200, fptr) || j--) {
        // printf("Prev: %s", prevLine);
        // printf("Cur: %s", line);
        // printf("Next: %s", nextLine);

        int length = strlen(line);
        int num = 0;
        int valid = 0;
        for (int i=0; i<length; i++) {
            if (isdigit(line[i])) {
                num = num*10 + line[i] - '0';
                if (i > 0) {
                    if (isSymbol(line[i-1]) || isSymbol(prevLine[i-1]) || isSymbol(nextLine[i-1])) {
                        valid = 1;
                        // printf("Setting valid on i-1 %c %c %c\n", prevLine[i-1], line[i-1], nextLine[i-1]);
                    };
                }
                if (isSymbol(prevLine[i]) || isSymbol(nextLine[i])) {
                    valid = 1;
                    // printf("Setting valid on i %c %c %c\n", prevLine[i], line[i], nextLine[i]);
                };
                if (i < length - 1) {
                    if (isSymbol(line[i+1]) || isSymbol(prevLine[i+1]) || isSymbol(nextLine[i+1])) {
                        valid = 1;
                        // printf("Setting valid on i+1 %c %c %c\n", prevLine[i+1], line[i+1], nextLine[i+1]);
                    };

                }
            }
            else if (num) {
                if (valid) {
                    // printf("%d\n", num);
                    finalAnswer += num;
                }
                num = 0;
                valid = 0;
            }
        }

        strcpy(prevLine, line);
        strcpy(line, nextLine);
    }
    printf("Answer: %d", finalAnswer);
    fclose(fptr);
    return 0;
}
