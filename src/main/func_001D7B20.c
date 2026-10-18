#pragma opt_strength_reduction off
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7B20;
typedef struct { float x, y, z; float pad; V4_7B20 q10; V4_7B20 q20; } T_7B20;
typedef struct { char pad[0xC0]; unsigned char* pC0; char padC4[0x1D0 - 0xC4]; } E_7B20;
typedef struct { int pad; unsigned int count; E_7B20* data; } V_7B20;
typedef struct R_7B20 { char pad[0x10]; char xf[0x60]; unsigned char b70; char pad71[0x47]; unsigned char bB8; char padB9[7]; struct R_7B20* pC0; char padC4[0x3C]; } R_7B20;
extern R_7B20 D_004F32B0[];
extern unsigned char D_004F47B0;
extern V4_7B20 D_004F3030[];
extern V4_7B20 D_004F2D90[];
extern unsigned char D_0048A6A0[];
extern unsigned char D_0048A6C0[];
extern void func_001D7DE0(V_7B20* v);
extern T_7B20* func_001D7D20(T_7B20* d, V4_7B20* s, V4_7B20* q);
extern void func_001D7CE0(void* d, T_7B20* s);
extern void func_001D7C90(T_7B20* t, int f);
void UpperBody_BuildChainTable(V_7B20* v)
{
    func_001D7DE0(v);
    if (!D_004F47B0) {
        int i;
        R_7B20* r;
        V4_7B20* q;
        V4_7B20* p;
        unsigned char* a;
        unsigned char* b;
        unsigned int n;
        unsigned int j;
        D_004F47B0 = 1;
        for (i = 0, q = D_004F2D90, p = D_004F3030, a = D_0048A6A0, b = D_0048A6C0; i < 21; i++, q++, p++, a++, b++) {
            T_7B20 t;
            r = &D_004F32B0[i];
            func_001D7D20(&t, p, q);
            func_001D7CE0(r->xf, &t);
            func_001D7C90(&t, -1);
            r->b70 = *a;
            r->bB8 = *b;
        }
        n = v->count;
        for (j = 0; j < n; j++) {
            unsigned char k = *v->data[j].pC0;
            if (k != 0xFF)
                D_004F32B0[j].pC0 = &D_004F32B0[k];
            else
                D_004F32B0[j].pC0 = 0;
        }
    }
}





