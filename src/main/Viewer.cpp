#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    while (true) {
        char * line = new char[100];
        scanf("%s\n", line);
        if (line[0] == 'S') {
            // next state
            system("clear");
            int n;
            scanf("%d\n", &n);
            while (n--) {
                scanf("%[a-zA-Z0-9 :]\n", line);
                printf("%s\n", line);
            }
        }
        else {
            // answer
            scanf("%[a-zA-Z0-9 :]\n", line);
            printf("%s\n", line);
            scanf("%[a-zA-Z0-9 :]\n", line);
            printf("%s\n", line);
            break;
        }
    }

    return 0;
}
