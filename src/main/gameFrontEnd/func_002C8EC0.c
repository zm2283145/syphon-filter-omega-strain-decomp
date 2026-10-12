#include "types.h"

typedef struct RomanDigit {
    int value;
    char* text;
    int subValue;
    char* subText;
} RomanDigit;

extern unsigned char D_0048C2C8;
extern RomanDigit D_0048C2D0[];
extern char D_004ACF20[];
extern int sprintf(char*, const char*, ...);

char* func_002C8EC0(int n, char* buf, int size) {
    int len = 0;
    int i = 0;
    if (n > 3999) return 0;
    do {
        while (n >= D_0048C2D0[i].value) {
            len += sprintf(buf + len, D_004ACF20, D_0048C2D0[i].text);
            n -= D_0048C2D0[i].value;
            if (len >= size) return 0;
        }
        if (D_0048C2C8 && n >= D_0048C2D0[i].subValue) {
            len += sprintf(buf + len, D_004ACF20, D_0048C2D0[i].subText);
            n -= D_0048C2D0[i].subValue;
            if (len >= size) return 0;
        }
        i++;
    } while (n > 0);
    return buf;
}
