#include "types.h"
typedef struct { unsigned short code; char ch; char pad; } T40F290;
static T40F290 D_00494020[] = {
    { 0x8140, ' ' },
    { 0x8149, '!' },
    { 0x8168, '"' },
    { 0x8194, '#' },
    { 0x8190, '$' },
    { 0x8193, '%' },
    { 0x8195, '&' },
    { 0x8166, '\'' },
    { 0x8169, '(' },
    { 0x816A, ')' },
    { 0x8196, '*' },
    { 0x817B, '+' },
    { 0x8143, ',' },
    { 0x817C, '-' },
    { 0x8144, '.' },
    { 0x815E, '/' },
    { 0x8146, ':' },
    { 0x8147, ';' },
    { 0x8171, '<' },
    { 0x8181, '=' },
    { 0x8172, '>' },
    { 0x8148, '?' },
    { 0x8197, '@' },
    { 0x816D, '[' },
    { 0x818F, '\\' },
    { 0x816E, ']' },
    { 0x814F, '^' },
    { 0x8151, '_' },
    { 0x8165, '`' },
    { 0x816F, '{' },
    { 0x8162, '|' },
    { 0x8170, '}' },
    { 0x8150, '~' }
};
extern int strlen(const char*);
void func_0040F290(unsigned short* dst, char* src, int max) {
    int len = strlen(src);
    int i;
    if (max < len)
        len = max;
    for (i = 0; i < len; i++) {
        char c = src[i];
        unsigned short w = 0;
        if (c >= 'a' && c <= 'z') {
            w = c + 0x8220;
        } else if (c >= 'A' && c <= 'Z') {
            w = c + 0x821F;
        } else if (c >= '1' && c <= '9') {
            w = c + 0x821F;
        } else {
            unsigned int j;
            for (j = 0; j < 0x21; j++) {
                if (c == D_00494020[j].ch) {
                    w = D_00494020[j].code;
                    break;
                }
            }
        }
        dst[i] = ((w & 0xFF) << 8) + ((int)w >> 8);
    }
    dst[len] = 0;
}

