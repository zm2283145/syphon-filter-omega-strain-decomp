#include "types.h"
typedef struct { short a; short b; } A3Tex;
typedef union { __int128 q; int w; } A3Name;
typedef struct {
    char pad0[0x80];
    __int128 mask;
    char pad1[0xCC - 0x90];
    unsigned int count;
    int loaded;
    char pad2[0x810 - 0xD4];
    short ref[0x600];
    A3Tex tex[0x2A00];
    A3Name names[0x600];
} A3State;
extern int D_00539248;
extern __int128 D_0055DE00;
extern __int128 D_0055DDA0;
extern int String_CompareN(char* a, char* b, int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_0036DFB0(void* f, char* name, void* src);
extern short func_0037FEA0(int lib, void* f, void* key);
extern short TexCache_LoadErrorTexture(int lib);
static inline __int128 a3and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int a3eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
void TexCache_LoadPartTexture(A3State* st, __int128 key, void* f, short* outA, short* outB) {
    unsigned int i;
    unsigned int n;
    int j;
    char buf[80];
    __int128 o;
    __int128 m;
    __int128 k;
    {
        for (i = 0; i < st->count; i++) {
            if (a3eq(a3and(st->mask, st->names[i].q), a3and(st->mask, key))) {
                *outA = st->tex[i].a;
                *outB = st->tex[i].b;
                if (st->ref[i] != 0)
                    st->ref[i]++;
                return;
            }
        }
    }
    if (st->count < 0x600) {
        i = st->count;
        st->count++;
    } else {
        for (j = st->loaded; j < 0x600; j++) {
            if ((int)st->names[j].q == 0)
                break;
        }
    }
    m = D_0055DE00;
    k = key;
    o = D_0055DDA0;
    if (a3eq(a3and(m, k), a3and(m, o)) && String_CompareN((char*)&key, "_MAKE", 5) != 0) {
        st->tex[i].a = st->tex[0].b;
        st->tex[i].b = st->tex[0].b;
        *outA = st->tex[i].a;
        *outB = st->tex[i].b;
        st->names[i].q = key;
        st->ref[i] = 0;
        return;
    }
    st->names[i].q = key;
    sprintf(buf, "%s.TDX", (char*)&key);
    buf[14] = '0';
    func_0036DFB0(f, buf, f);
    st->tex[i].a = func_0037FEA0(D_00539248, f, &key);
    buf[14] = '1';
    func_0036DFB0(f, buf, f);
    st->tex[i].b = func_0037FEA0(D_00539248, f, &key);
    if (st->tex[i].a == -1)
        st->tex[i].a = TexCache_LoadErrorTexture(D_00539248);
    if (st->tex[i].b == -1)
        st->tex[i].b = st->tex[i].a;
    *outA = st->tex[i].a;
    *outB = st->tex[i].b;
    st->ref[i] = 1;
}
