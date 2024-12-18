#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_line_length 100
#define max_quantity_of_numbers 100
int min_3(int a, int b, int c) {
    if (a < b) {
        b = a;
    }
    if (b < c) {
        c = b;
    }
    return c;
}
int solve(int *array, int size) {
    int ans = 0;
    int min = 0;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    if (size != 3) {
        return -1;
    }
    a1 = array[0];
    a2 = array[1];
    a3 = array[2];
    min = min_3(a1 * a2, a2 * a3, a3 * a1);
    ans = a1 * a2 * 2 + a1 * a3 * 2 + a2 * a3 *2 + min;
    return ans;
}
int main(int argc, char *argv[])
{
    int *A = NULL;
    int ans = 0;
    int cnt = 0;
    char line[max_line_length];
    int array[max_quantity_of_numbers];
    int number = 0;
    FILE *input = NULL;
    if (argc != 2) {
        printf("error\n");
        return -1;
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("error\n");
        return -1;
    }
    while (fgets(line, max_line_length, input) != NULL) { //читатет до \n 
        cnt = 0;
        char *token = strtok(line, "x\n");   //разбивает строку на токены
        while (token != NULL) {
            if (sscanf(token, "%d", &number) == 1) { //преобразует токены в число
                array[cnt] = number;
                cnt++;
            }
            token = strtok(NULL, "x\n");
        }
        if (solve(array, cnt) != -1) {
            ans += solve(array, cnt);
        }
    }
    printf("%d\n", ans);
    fclose(input);
    return 0;
}