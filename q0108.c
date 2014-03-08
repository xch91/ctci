#include<stdio.h>
#include<string.h>
#define MAX 1000

int is_substring(char * needle, char * haystack) {
    if (strstr(haystack, needle)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input1[2*MAX], input2[MAX], cursor;
    int len = 0;
    while (len < MAX && (cursor = fgetc(stdin)) != '\n') {
        input1[len++] = cursor;
    }
    memcpy(input1+len, input1, len*sizeof(char));
    input1[2*len+1] = 0;
    len = 0;
    while (len < MAX && (cursor = fgetc(stdin)) != '\n') {
        input2[len++] = cursor;
    }
    input2[len] = 0;
    if (is_substring(input2, input1)) {
        printf("Second string is a rotation of the first\n");
    } else {
        printf("Second string is not a rotation of the first\n");
    }
}
