#include<stdio.h>
#define MAX_LENGTH 2000

char * compress(char * str) {
    char ret[MAX_LENGTH];
    int count = 1, i = 1, j = 0;
    if (str[0] == 0) {
        return str;
    } else {
        ret[0] = str[0];
    }
    while (str[i] != 0) {
        if (ret[j] != str[i]) {
            ret[j+1] = count + 48; // Convert int to char
            count = 1;
            j += 2;
            ret[j] = str[i];
        } else {
            ++count;
        }
        ++i;
    }
    ret[++j] = count + 48;
    ret[++j] = 0;
    if (i > j) {
        return ret;
    } else {
        return str;
    }
}

int main() {
    int i = 0;
    char input[MAX_LENGTH], cursor;
    while (i < MAX_LENGTH &&
           (cursor = fgetc(stdin)) != '\n') {
        input[i++] = cursor;
    }
    input[i] = 0;
    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", compress(input));
}
