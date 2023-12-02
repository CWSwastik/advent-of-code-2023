#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    FILE *fptr = fopen("input.txt", "r");

    char line[200];

    int gameId = 1;
    int answer = 0;
    while(fgets(line, 200, fptr)) {
        // printf("%s", line);
        
        int length = strlen(line);
        int flag = 1;
        for (int i = 0; i <= length; i++) {
            if (isdigit(line[i])) {
                int v = line[i] - '0';
                if (isdigit(line[i+1])){
                    i++;
                    v = 10*v + line[i] - '0';
                }
                int cond = (line[i+2] == 'r' && v > 12) || (line[i+2] == 'g' && v > 13) || (line[i+2] == 'b' && v > 14);
                if (cond) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            answer += gameId;
        }
        gameId += 1;

    }
    printf("%d\n", answer);
    fclose(fptr);
    return 0;
}