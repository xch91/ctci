#include<stdio.h>
#define MAX_LENGTH 2000

void reverse(char * str, int len) {
    char tmp;
    int i;
    for (i = 0; i < len / 2; ++i) {
        tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
}

int main() {
    char input[MAX_LENGTH], cursor = fgetc(stdin);
    int len = 0;
    while (len < MAX_LENGTH && cursor != '\n') {
        input[len++] = cursor;
        cursor = fgetc(stdin);
    }
    input[len] = 0;
    printf("The original string: %s\n", input);
    reverse(input, len);
    printf("The reversed string: %s\n", input);
}
