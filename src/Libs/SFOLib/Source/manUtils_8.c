/*
 * Libs/SFOLib/Source/manUtils: 3 files, 004061B0-00406700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004061B0 */
#pragma push /* merge_units */
#include "types.h"
/* SKL_AddBlankParts: appends to the appearance's part-pair list (out[2..]) every
 * mesh key of the part cache that matches the blank pattern (m60/m10) for the body's lod
 * digit ('1'/'2') and is not yet listed, then every colour key likewise, pairing each with
 * the first matching mesh key; returns the new pair count. The digit scan of ToneOf is
 * evaluated for nothing, as in retail. */
typedef struct { __int128 a; __int128 key; } KOut;
/* 128-bit key masking/compare: MMI pand/pceqw/ppach/pcpyld have no C equivalent */
static inline __int128 kfrom(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int kmeq(__int128 m, __int128 a, __int128 b) {
    __int128 y;
    long long x;
    asm {
        pand y, m, b
        pand x, m, a
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int kmeq2(__int128 m, __int128 a, __int128 b) {
    __int128 y;
    long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int kmeqE(__int128 b, __int128 a, __int128 m) {
    __int128 y;
    long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
typedef struct {
    char pad0[0x10];
    __int128 m10;
    char pad20[0x10];
    __int128 m30;
    char pad40[0x20];
    __int128 m60;
    char pad70[0x30];
    __int128 mA0;
    char padB0[0x10];
    unsigned int mcount;
    char padC4[8];
    unsigned int ccount;
    char padD0[0x2C10 - 0xD0];
    __int128 mkeys[0x300];
    char recs[0x300][2][0x10];
    __int128 ckeys[0x300];
} PartCache;
extern PartCache g_AgentPartCache;
int SKL_FindSex(void* app);
static inline signed char ToneOf(KOut* out)
{
    signed char* b; int i; KOut* o;
    for (i = 0, o = out; i < 0x20; i++, o++) {
        if (((signed char*)&o[2].a)[9] >= '0' && ((signed char*)&o[2].a)[9] <= '9')
            return ((signed char*)&o[2].a)[9];
        b = (signed char*)&o[2].key;
        if (((signed char*)&o[2].key)[9] >= '0' && ((signed char*)&o[2].key)[9] <= '9')
            return ((signed char*)&o[2].key)[9];
        if (b[0] == 0)
            return '_';
    }
    return '_';
}
int SKL_AddBlankParts(KOut* out, int n)
{
    int mode;
    signed char t;
    __int128 v;
    int found;
    unsigned int k;
    int j;
    int j2;
    unsigned int i;
    int found2;
    unsigned int m;
    unsigned int idx;
    mode = SKL_FindSex(out);
    t = ToneOf(out);
    if (mode == 1)
        v = kfrom(50);
    if (mode == 0)
        v = kfrom(49);
    for (i = 0; i < g_AgentPartCache.mcount; i++) {
        if (kmeqE(g_AgentPartCache.m10, g_AgentPartCache.mkeys[i], g_AgentPartCache.m60) && !kmeq(g_AgentPartCache.m30, g_AgentPartCache.mkeys[i], v)) {
            found = 0;
            for (j = 0; j < n; j++) {
                if (kmeq2(g_AgentPartCache.mA0, g_AgentPartCache.mkeys[i], out[j + 2].a)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                out[n + 4].a = out[n + 3].a;
                out[n + 3].a = out[n + 2].a;
                out[n + 4].key = out[n + 3].key;
                out[n + 3].key = out[n + 2].key;
                out[n + 2].key = g_AgentPartCache.mkeys[i];
                out[n + 2].a = g_AgentPartCache.mkeys[i];
                n++;
            }
        }
    }
    for (k = 0; k < g_AgentPartCache.ccount; k++) {
        if (kmeqE(g_AgentPartCache.m10, g_AgentPartCache.ckeys[k], g_AgentPartCache.m60) && !kmeq(g_AgentPartCache.m30, g_AgentPartCache.ckeys[k], v)) {
            found2 = 0;
            idx = 0;
            for (j2 = 0; j2 < n; j2++) {
                if (kmeq2(g_AgentPartCache.mA0, g_AgentPartCache.ckeys[k], out[j2 + 2].a)) {
                    found2 = 1;
                    break;
                }
            }
            if (!found2) {
                found2 = 1;
                for (m = 0; m < g_AgentPartCache.mcount; m++) {
                    if (kmeq2(g_AgentPartCache.mA0, g_AgentPartCache.ckeys[k], g_AgentPartCache.mkeys[m]) && !kmeq(g_AgentPartCache.m30, g_AgentPartCache.mkeys[m], v)) {
                        idx = m;
                        found2 = 0;
                        break;
                    }
                }
            }
            if (!found2) {
                out[n + 4].a = out[n + 3].a;
                out[n + 3].a = out[n + 2].a;
                out[n + 4].key = out[n + 3].key;
                out[n + 3].key = out[n + 2].key;
                out[n + 2].key = g_AgentPartCache.ckeys[k];
                out[n + 2].a = g_AgentPartCache.mkeys[idx];
                n++;
            }
        }
    }
    return n;
}
static inline void merge_flush_func_004061B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004061B0 */

/* merge_units: begin func_00406570 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[1]; } H2Pack;
static inline int h2count(H2Pack* p) {
    int n = 0;
    while ((long long)p->pairs[n].a != 0) n++;
    return n;
}
/* Upper-cases text into a manifest buffer, dropping separators and padding lines to 16 bytes. */
void SKL_ConvertSKL(H2Pack* dst, char* src, int len) {
    int c;
    char* w = (char*)dst;
    char* lim = (char*)dst + 0x440;
    char* end = src + len;
    int n;
    while (src < end) {
        c = *src++;
        if (c >= 'a' && c <= 'z')
            c -= 0x20;
        *w++ = c;
        if (w >= lim)
            break;
        if (c == 0) w--;
        if (c == ' ') w--;
        if (c == '#') w--;
        if (c == '$') w--;
        if (c == '*') w--;
        if (c == '\t') w--;
        if (c == '\n') w--;
        if (c == '\r') {
            w[-1] = 0;
            while ((int)w & 0xF)
                *w++ = 0;
        }
    }
    *w = 0;
    while ((int)w & 0xF)
        *w++ = 0;
    n = h2count(dst);
    dst->pairs[n + 1].a = dst->pairs[n].a;
    dst->pairs[n + 1].b = dst->pairs[n].a;
}
static inline void merge_flush_func_00406570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406570 */

/* merge_units: begin func_00406700 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * manUtils.cc
 */


#if 0 /* merge_units */
extern void SKL_ConvertSKL(int dst, int text, int a2);
#endif /* merge_units */
#define SKL_ConvertSKL(a0, a1, a2) (SKL_ConvertSKL((H2Pack *)(a0), (char *)(a1), (a2))) /* merge_units */

extern int cFileMan_Read_void(int a0);

/* Convert a1 with cFileMan_Read_void and pack the result with SKL_ConvertSKL. */
void SKL_ReadSKL(int dst, int a1, int a2) {
    SKL_ConvertSKL(dst, cFileMan_Read_void(a1), a2);
}
#undef SKL_ConvertSKL /* merge_units */
static inline void merge_flush_func_00406700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406700 */
