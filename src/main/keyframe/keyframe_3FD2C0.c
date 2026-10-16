/*
 * main/keyframe: 4 files, 003FD2C0-003FD550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FD2C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern void Loc_LookupText(void);

void func_003FD2C0(void) {
    Loc_LookupText();
}
#pragma pop /* merge_units */
/* merge_units: end func_003FD2C0 */

/* merge_units: begin func_003FD2D0 */
#pragma push /* merge_units */
typedef struct { int w[4]; } SD2D0;
extern unsigned char D_0055D450;
extern void String_CtorCStr_13B480(SD2D0* s, const char* c);
extern int func_003FD740(SD2D0* s);
extern void String_Dtor(SD2D0* s, int del);
extern const char* String_CStr(SD2D0* s);
extern void String_Copy(char* d, const char* s);
int func_003FD2D0(char* buf)
{
    SD2D0 s;
    if (!D_0055D450)
        return 0;
    if (!buf || !*buf)
        return 1;
    String_CtorCStr_13B480(&s, buf);
    if (!func_003FD740(&s)) {
        String_Dtor(&s, 0);
        return 0;
    }
    String_Copy(buf, String_CStr(&s));
    String_Dtor(&s, 0);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FD2D0 */

/* merge_units: begin func_003FD380 */
#pragma push /* merge_units */
typedef unsigned char u8;
extern unsigned int D_0055CA90;
extern int strlen(const char*);

int AgentFile_DecodeName(const unsigned char* in, char* out, int* digit, int max)
{
    int len, n, i, d;
    if (!D_0055D450 || !D_0055CA90)
        return 0;
    if (!in || !out || !digit)
        return 0;
    len = strlen((const char*)in);
    if (len > 1) {
        n = (len - 1) / 2;
        if (n < max && (len & 1))
            goto ok;
    }
    return 0;
ok:
    for (i = 0; i < n; i++) {
        int c0 = in[0];
        u8 c1 = in[1];
        u8 hi, lo;
        unsigned int idx;
        in += 2;
        if (c0 < 0x30 || c0 > 0x34)
            return 0;
        if (c1 < 0x40)
            return 0;
        lo = c1 - 0x40;
        if (lo >= 0x3E)
            return 0;
        hi = c0 - 0x30;
        idx = lo + hi * 0x3E;
        if (idx >= D_0055CA90)
            return 0;
        *out++ = idx + 0x20;
    }
    *out = 0;
    d = *in - 0x30;
    if (d < 0 || d > 9)
        return 0;
    *digit = d;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FD380 */

/* merge_units: begin func_003FD550 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int D_0055CA90;
#endif /* merge_units */
#define D_0055CA90 (*(int*)&D_0055CA90) /* merge_units */

#if 0 /* merge_units */
extern unsigned int strlen(const char*);
#endif /* merge_units */
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */


int AgentFile_EncodeName(const char* in, char* out, int digit, unsigned int max)
{
    if (!D_0055D450 || !D_0055CA90)
        return 0;
    if (!in || !out || strlen(in) * 2 + 1 >= max)
        return 0;
    if (digit < 0 || digit > 9)
        return 0;
    while (*in) {
        unsigned char c = *in;
        int idx;
        int hi;
        if (c < 0x20)
            return 0;
        idx = c - 0x20;
        if (idx >= D_0055CA90)
            return 0;
        hi = 0;
        while (idx >= 0x3E) {
            idx -= 0x3E;
            hi++;
        }
        out[0] = hi + 0x30;
        in++;
        out[1] = idx + 0x40;
        out += 2;
    }
    out[0] = digit + 0x30;
    out[1] = 0;
    return 1;
}
#undef D_0055CA90 /* merge_units */
#undef strlen /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FD550 */
