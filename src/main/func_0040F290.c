#include "types.h"
typedef struct { unsigned short code; char ch; char pad; } T40F290;
extern T40F290 D_00494020[];
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
