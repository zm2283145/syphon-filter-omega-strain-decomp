#include "types.h"
/* AgentPacking_AddBlankPairs: appends to the appearance's part-pair list (out[2..]) every
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
int Appearance_GetBodyKind(void* app);
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
int AgentPacking_AddBlankPairs(KOut* out, int n)
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
    mode = Appearance_GetBodyKind(out);
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
