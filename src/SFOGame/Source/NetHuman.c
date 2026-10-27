/*
 * SFOGame/Source/NetHuman: 3 files, 002D1940-002D1D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D1940 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cNetHuman_InitNet: describe the cNetHuman replicated fields to the net
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
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* db, int offset, int size, int count, int type, PrmD1940* prm);
extern int NetRegisterStructure(int* h, char* name, int n);
extern int NetRegisterRemoteObjectCallback(int h, void* a, void* b, void* c);
extern unsigned char cTargetInfo_InitNet(void* self, NetHumanD1940* r, PrmD1940* prm);
extern unsigned char cAimWeapon_InitNet(void* self, NetHumanD1940* r, PrmD1940* prm);
extern void cTargetInfo_Init(NetHumanD1940*);
extern void cTargetInfo_dtor(NetHumanD1940*, int);
void cNetHuman_NetHumanCreationCallback(void);
void cNetHuman_NetHumanUpdateCallback(void);
void cNetHuman_NetHumanDeleteCallback(void);
extern char D_004AD588[]; /* "cNetHuman", shared with cNetHuman_CreateNetHuman */
extern int D_0051F078;
unsigned char cNetHuman_InitNet(void);
}
#define OFS(f) ((char*)&o.f - base)
extern "C" unsigned char cNetHuman_InitNet(void)
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
    cTargetInfo_Init(&o);
    prm.max = 100;
    prm.ver = 1;
    pm = &prm.mode;
    *pm = 0;
    prm.flags = 0;
    if (NetRegisterObjectStart() == 0 &&
        cTargetInfo_InitNet(&o, &o, &prm) &&
        cAimWeapon_InitNet(&o.f1C, &o, &prm) &&
        (base = (char*)&o, 1) && /* the offset base is set up here, after the sub-record calls */
        NetObjectField(&db, OFS(f2C), 4, 5, 1, &prm) == 0 &&
        (*pm = 0x40, NetObjectField(&db, OFS(f30), 2, 2, 1, &prm) == 0) &&
        (prm.max = 1000, r = NetObjectField(&db, OFS(f50), 1, 1, 1, &prm), *pm = 0, r == 0) && /* mode reset either way */
        NetObjectField(&db, OFS(f3C), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f40), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f44), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f48), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f4C), 4, 6, 1, &prm) == 0 &&
        (*pm = 0x40, NetObjectField(&db, OFS(f38), 4, 6, 1, &prm) == 0) &&
        (prm.max = 100, NetObjectField(&db, OFS(f32), 1, 1, 1, &prm) == 0) &&
        NetObjectField(&db, OFS(f52), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f33), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f34), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f35), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, prm.max = 1000, NetObjectField(&db, OFS(f54), 4, 5, 1, &prm) == 0) &&
        NetObjectField(&db, OFS(f51), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, NetRegisterStructure(&h, D_004AD588, 0x58) == 0) &&
        NetRegisterRemoteObjectCallback(h, cNetHuman_NetHumanCreationCallback, cNetHuman_NetHumanUpdateCallback, cNetHuman_NetHumanDeleteCallback) == 0) {
        D_0051F078 = h;
        ok = 1;
    }
    cTargetInfo_dtor(&o, 0);
    return ok;
}
static inline void merge_flush_func_002D1940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1940 */

/* merge_units: begin func_002D1D50 */
#pragma push /* merge_units */
extern char D_005723C8[];

void cNetHuman_NetHumanDeleteCallback(void) {
    int v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L002D1D68;
    *(char*)(char*)D_005723C8 = v1;
L002D1D68:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
static inline void merge_flush_func_002D1D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1D50 */

/* merge_units: begin func_002D1D80 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; void* h; unsigned char done; } Obj1D80;
extern int NetRequestObjectPrivateOwnership(void* h);
void cNetHuman_Activate(Obj1D80* o)
{
    if (!o->done && NetRequestObjectPrivateOwnership(o->h) == 0)
        o->done = 1;
}
static inline void merge_flush_func_002D1D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1D80 */
