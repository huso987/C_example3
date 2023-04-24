#include <stdio.h>
#include <string.h>

int getValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int i, num = 0, len = strlen(s);
    for (i = 0; i < len; i++) {
        int value = getValue(*(s+i));
        if (i + 1 < len && value < getValue(*(s+i+1))) {
            num -= value;
        } else {
            num += value;
        }
    }
    return num;
}

int main() {
    char roman[20];
    printf("Enter a Roman numeral: ");
    scanf("%s", roman);
    int decimal = romanToInt(roman);
    printf("%s in decimal is %d\n", roman, decimal);
    return 0;
}
