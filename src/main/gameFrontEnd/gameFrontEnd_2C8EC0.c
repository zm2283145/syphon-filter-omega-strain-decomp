/*
 * main/gameFrontEnd: range (2 files, 002C8EC0-002C8FD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_002C8EC0 */
#pragma push /* merge_units */
typedef struct RomanDigit {
    int value;
    char* text;
    int subValue;
    char* subText;
} RomanDigit;

extern unsigned char D_0048C2C8;
extern RomanDigit D_0048C2D0[];
extern char D_004ACF20[];

char* Format_RomanNumeral(int n, char* buf, int size) {
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8EC0 */

/* merge_units: begin func_002C8FD0 */
#pragma push /* merge_units */
static const unsigned int dat_0048C2B0[6] = { 0xA, 0x14, 0x23, 0x32, 0x3C, 0x0 };
int WeaponStats_RatingB(int x)
{
 int i;
 for (i = 0; i < 5; i++) { if (x <= ((int*)dat_0048C2B0)[i]) return i + 1; } return 5;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8FD0 */
