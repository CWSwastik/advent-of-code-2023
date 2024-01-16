#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    FILE *fptr = fopen("input.txt", "r");

    
    char line[200];
    int answer = 0;

    while(fgets(line, 200, fptr)) {
        int length = strlen(line);
        int num = 0;
        int valid = 0;
        int winningNums[10];
        int checking = 0;
        int points = 0;
        int w = 0;

        char c;
        for (int i=9; i<=length; i++) {
            if (i == length) {
                c = ' ';
            } else {
                c = line[i];
            }
            if (isdigit(c)) {
                num *= 10;
                num += c - '0'; 
            }
             
            if (c == ' ' && num != 0) {
                
                if (checking) {

                    for (int i=0; i<10; i++) {

                        if (num == winningNums[i]) {
                            points ++;
                            break;
                        }
                    }
                    num = 0;
                } else {
                winningNums[w] = num;
                w++;
                num = 0;
                }
            }

            if (c == '|') {
                checking = 1;
            }
        }

        if (points) {
            answer += pow(2, points - 1);
        }
    }
    printf("%d", answer);
}