#include "types.h"
typedef struct F1Los136 { void* vt; char pad4[0x1C]; int x20; char pad24[0xC]; Vec4 v30; char st40[0x20]; int x60; char pad64[0xC]; } F1Los136;
extern unsigned char D_00533880;
extern int D_00533888;
extern F1Los136* D_004EA0B8;
extern char D_0049AEA8[];
extern char D_004DA2F0[];
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
extern void func_00136540(F1Los136* p, int* a, int* b);
extern Vec4* Vec4_GetZero(void);
extern void Vec4_Assign(Vec4* d, Vec4* s);
extern void func_001364B0(void* p);
static inline void* f1_Alloc136(int size, char* file, int line)
{
    void* p;
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, size, file, line);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    return p;
}
void LosProvider_Create(int arg)
{
    if (D_004EA0B8 == 0) {
        F1Los136* p = f1_Alloc136(0x70, D_0049AEA8, 0xAE);
        if (p) {
            int b[1];
            int a[1];
            b[0] = 2;
            a[0] = arg;
            func_00136540(p, a, b);
            p->vt = D_004DA2F0;
            p->x20 = 0;
            Vec4_Assign(&p->v30, Vec4_GetZero());
            func_001364B0(p->st40);
            p->x60 = 0;
        }
        D_004EA0B8 = p;
    }
}