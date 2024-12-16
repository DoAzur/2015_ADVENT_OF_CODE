#include <stdio.h>
int main(void) 
{
    int ans = 0;
    char element;
    FILE *input = NULL;
    input = fopen("data.txt", "r");
    if (input == NULL) {
        printf("error\n");
        return -1;
    }
    while(fscanf(input, "%c", &element) != EOF) {
        if (element == '(') {
            ans += 1;
        }
        if (element == ')') {
            ans -= 1;
        }
    }
    printf("%d\n", ans);
    fclose(input);
    return 0;
}

