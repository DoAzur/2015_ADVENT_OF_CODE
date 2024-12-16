#include <stdio.h>
int main(void) 
{
    int ans = 0;
    int cnt = 0;
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
            cnt += 1;
        }
        if (element == ')') {
            ans -= 1;
            cnt += 1;
        }
        if (ans == -1) {
            break;
        }
    }
    printf("%d\n", cnt);
    fclose(input);
    return 0;
}
