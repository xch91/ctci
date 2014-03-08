#include<stdio.h>
#define MAX_LENGTH 2000

int check_string(char * str, int len) {
    int i;
    long check = 0;
    for (i = 0; i < len; ++i) {
        int c = str[i] - 'a';
        if ((check & (1 << c)) != 0) {
            return 0;
        } else {
            check |= 1 << c;
        }
    }
    return 1;
}

int main() {
    int len = 0;
    char cursor = fgetc(stdin), input[MAX_LENGTH];
    while (len < MAX_LENGTH &&
           cursor >= 'a' &&
           cursor <= 'z') {
        input[len++] = cursor;
        cursor = fgetc(stdin);
    }
    input[len] = 0;

    if (check_string(input, len)) {
        printf("The string has all unique chars\n");
    } else {
        printf("The string has duplicated chars\n");
    }
    return 0;
}
