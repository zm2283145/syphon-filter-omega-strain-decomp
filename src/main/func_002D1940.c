#pragma cplusplus on
#include "types.h"
/* cNetHuman_NetRegister: describe the cNetHuman replicated fields to the net
 * object database and register the class with its create/update/destroy
 * handlers. */
typedef struct {
    unsigned char f00, f01; char p02[2];
    int f04;
    int f08;
    signed char f0C; char p0D[3];
    int f10, f14, f18;
    short f1C; char p1E[2];
    unsigned char f20, f21; short f22;
    char p24[4];
    unsigned char f28, f29; char p2A[2];
    int f2C;
    short f30; unsigned char f32, f33;
    unsigned char f34, f35; char p36[2];
    float f38;
    int f3C, f40;
    int f44, f48, f4C;
    unsigned char f50, f51, f52; char p53;
    int f54;
    char p58[4];
} NetHumanD1940;
typedef struct { int max; int ver; int flags; unsigned char mode; } PrmD1940;
extern "C" {
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, PrmD1940* prm);
extern int func_002E9CD0(int* h, char* name, int n);
extern int func_002E9D88(int h, void* a, void* b, void* c);
extern unsigned char func_002D23D0(void* self, NetHumanD1940* r, PrmD1940* prm);
extern unsigned char func_002D22E0(void* self, NetHumanD1940* r, PrmD1940* prm);
extern void func_00316A00(NetHumanD1940*);
extern void func_00316A30(NetHumanD1940*, int);
void func_002D1F00(void);
void func_002D1DC0(void);
void func_002D1D50(void);
extern char D_004AD588[]; /* "cNetHuman", shared with func_002D1FF0 */
extern int D_0051F078;
unsigned char cNetHuman_NetRegister(void);
}
#define OFS(f) ((char*)&o.f - base)
extern "C" unsigned char cNetHuman_NetRegister(void)
{
    int db;
    int h;
    PrmD1940 prm;
    NetHumanD1940 o;
    bool ok;
    char* base;
    unsigned char* pm;
    int r;
    o.f00 = 0;
    o.f01 = 0;
    o.f10 = 0;
    o.f14 = 0;
    o.f04 = -1;
    o.f08 = -1;
    o.f0C = -1;
    o.f18 = 0;
    o.f28 = 0;
    o.f30 = 4;
    o.f32 = 0;
    o.f33 = 0;
    o.f38 = 1000.0f;
    o.f3C = 0;
    o.f40 = 0;
    o.f50 = 0;
    o.f22 = 0;
    o.f21 = 0;
    o.f1C = 0;
    o.f20 = 0;
    ok = 0;
    func_00316A00(&o);
    prm.max = 100;
    prm.ver = 1;
    pm = &prm.mode;
    *pm = 0;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002D23D0(&o, &o, &prm) &&
        func_002D22E0(&o.f1C, &o, &prm) &&
        (base = (char*)&o, 1) && /* the offset base is set up here, after the sub-record calls */
        func_002E9BE8(&db, OFS(f2C), 4, 5, 1, &prm) == 0 &&
        (*pm = 0x40, func_002E9BE8(&db, OFS(f30), 2, 2, 1, &prm) == 0) &&
        (prm.max = 1000, r = func_002E9BE8(&db, OFS(f50), 1, 1, 1, &prm), *pm = 0, r == 0) && /* mode reset either way */
        func_002E9BE8(&db, OFS(f3C), 4, 6, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f40), 4, 6, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f44), 4, 6, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f48), 4, 6, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f4C), 4, 6, 1, &prm) == 0 &&
        (*pm = 0x40, func_002E9BE8(&db, OFS(f38), 4, 6, 1, &prm) == 0) &&
        (prm.max = 100, func_002E9BE8(&db, OFS(f32), 1, 1, 1, &prm) == 0) &&
        func_002E9BE8(&db, OFS(f52), 1, 1, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f33), 1, 1, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f34), 1, 1, 1, &prm) == 0 &&
        func_002E9BE8(&db, OFS(f35), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, prm.max = 1000, func_002E9BE8(&db, OFS(f54), 4, 5, 1, &prm) == 0) &&
        func_002E9BE8(&db, OFS(f51), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, func_002E9CD0(&h, D_004AD588, 0x58) == 0) &&
        func_002E9D88(h, func_002D1F00, func_002D1DC0, func_002D1D50) == 0) {
        D_0051F078 = h;
        ok = 1;
    }
    func_00316A30(&o, 0);
    return ok;
}
