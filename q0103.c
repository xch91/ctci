#include<stdio.h>
#define MAX_LENGTH 2000
#define RANGE 26

int check_perm(char * str1, int len1, char * str2, int len2) {
    if (len1 != len2) return 0;
    int i;
    int cnt[RANGE];
    for (i = 0; i < RANGE; ++i) {
        cnt[i] = 0;
    }
    for (i = 0; i < len1; ++i) {
        cnt[str1[i]-'a'] += 1;
    }
    for (i = 0; i < len2; ++i) {
        cnt[str2[i]-'a'] -= 1;
    }
    for (i = 0; i < RANGE; ++i) {
        if (cnt[i] != 0) return 0;
    }
    return 1;
}

int main() {
    char input1[MAX_LENGTH], input2[MAX_LENGTH];
    int len1 = 0, len2 = 0;
    char cursor = fgetc(stdin);
    while (len1 < MAX_LENGTH && cursor >= 'a' && cursor <= 'z') {
        input1[len1++] = cursor;
        cursor = fgetc(stdin);
    }
    input1[len1] = 0;
    cursor = fgetc(stdin);
    while (len2 < MAX_LENGTH && cursor >= 'a' && cursor <= 'z') {
        input2[len2++] = cursor;
        cursor = fgetc(stdin);
    }
    input2[len2] = 0;
    if (check_perm(input1, len1, input2, len2)) {
        printf("The second string is a permutation of the first\n");
    } else {
        printf("The second string is not a permutation of the first\n");
    }
}
