#include <stdio.h>
int main(int argc, char *argv[]) 
{
    int ans = 0;
    char element;
    FILE *input = NULL;
    if (argc != 2) {
        printf("%d\n", argc);
        printf("error\n");
        return -1;
    }
    input = fopen(argv[1], "r");
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

