#pragma cplusplus on
#include "types.h"
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049B1D0[];
extern char *D_00489CC0[];
extern "C" void Alloc_Lock(int);
extern "C" void Alloc_Unlock(int);
extern "C" void *Mem_Alloc(int, int, char *, int);
extern "C" void Mem_Free(int, void *, char *, int);
struct Sub46 { char p[0x20]; Sub46() {} };
struct Obj46 {
    char p0[0x140];
    Sub46 sub[12];
    char p2C0[0x3E0 - 0x2C0];
    float mn[4];
    float mx[4];
    char p400[0x20];
    Obj46() { mn[0] = 3.4028235e38f; mn[1] = 3.4028235e38f; mn[2] = 3.4028235e38f; mn[3] = 1.0f; mx[0] = -3.4028235e38f; mx[1] = -3.4028235e38f; mx[2] = -3.4028235e38f; mx[3] = 1.0f; }
    void *operator new(unsigned int sz, int line) { void *o; if (D_00533880) Alloc_Lock(9); D_00533888++; o = Mem_Alloc(0, sz, D_0049B1D0, line); if (D_00533880) Alloc_Unlock(9); D_00533888--; return o; }
};
typedef struct { char p0[4]; int f4; } Tbl46;
typedef struct { char p0[0x148]; Tbl46 *f148; } Src46;
typedef struct { char p0[0xB8]; Obj46 *slot[7]; } Slot46;
extern "C" char *func_0036D200(Src46 *, int);
extern "C" int func_0036D4E0(Src46 *, int);
extern "C" void func_0038D530(Obj46 *, char *, int, int, int, int, int, int);
extern "C" void func_0038CD90(Obj46 *, int);
extern "C" void func_00146B80(void *, Obj46 *, Obj46 *);

static inline int NameCmp_46(const char *a, const char *b)
{
    for (;;) {
        int ca = *a;
        int cb = *b;
        int d;
        if (ca == '.') ca = 0;
        if (ca >= 'a' && ca <= 'z') ca -= 0x20;
        if (cb == '.') cb = 0;
        if (cb >= 'a' && cb <= 'z') cb -= 0x20;
        d = ca - cb;
        if (d) return d;
        if (!ca) return 0;
        a++;
        b++;
    }
}

#define OBJ46_NEW(o, line) do { if (D_00533880) Alloc_Lock(9); D_00533888++; o = (Obj46 *)Mem_Alloc(0, 0x420, D_0049B1D0, line); if (D_00533880) Alloc_Unlock(9); D_00533888--; o = new (o) Obj46; } while (0)

extern "C" void func_00146040(Slot46 *self, Src46 *src)
{
    int n __attribute__((aligned(32))) = src->f148->f4;
    int i;
    for (i = 0; i < n; i++) {
        int found = 0;
        char *name = func_0036D200(src, i);
        int x = func_0036D4E0(src, i);
        int k;
        for (k = 0; k < 7; k++) {
            if (NameCmp_46(D_00489CC0[k], name) == 0) {
                self->slot[k] = new (0x293) Obj46;
                func_0038D530(self->slot[k], D_00489CC0[k], k, 0, 0, 0, 0, 0);
                func_0038CD90(self->slot[k], x);
                found = 1;
            }
        }
        if (!found) {
            Obj46 *t = new (0x2B4) Obj46;
            func_0038D530(t, name, 0, 0, 0, 0, 0, 0);
            func_0038CD90(t, x);
            func_00146B80(self, t, t);
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, t, D_0049B1D0, 0x2BC);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
        }
    }
}






