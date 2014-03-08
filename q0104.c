#include<stdio.h>
#define MAX_LENGTH 3000

void encode(char * str, int len) {
    int i, j, new_len, spaces = 0;
    for (i = 0; i < len; ++i) {
        if (str[i] == ' ') spaces++;
    }
    new_len = len + 2 * spaces;
    for (j = new_len, i = len; i >= 0; --i) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    int len = 0;
    char input[MAX_LENGTH], cursor = fgetc(stdin);
    while (len < MAX_LENGTH / 3 && cursor != '\n') {
        input[len++] = cursor;
        cursor = fgetc(stdin);
    }
    input[len] = 0;
    printf("Original string: %s\n", input);
    encode(input, len);
    printf("Encoded string: %s\n", input);
}
