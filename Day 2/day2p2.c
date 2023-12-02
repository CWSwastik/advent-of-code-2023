#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    FILE *fptr = fopen("input.txt", "r");

    char line[200];

    int answer = 0;
    while(fgets(line, 200, fptr)) {
        // printf("%s", line);
        
        int length = strlen(line);
        int mr, mg, mb;
        mr = 0;
        mg = 0;
        mb = 0;
        for (int i = 0; i <= length; i++) {
            if (isdigit(line[i])) {
                int v = line[i] - '0';
                if (isdigit(line[i+1])){
                    i++;
                    v = 10*v + line[i] - '0';
                }
                if (line[i+2] == 'r' && mr < v) {
                    mr = v;
                }
                else if (line[i+2] == 'g' && mg < v) {
                    mg = v;
                }
                else if (line[i+2] == 'b' && mb < v) {
                    mb = v;
                }
            }
        }
        // printf("%d %d %d %d \n", mr, mg, mb, mr*mg*mb);
        answer += mr*mg*mb;
    }
    printf("%d\n", answer);
    fclose(fptr);
    return 0;
}