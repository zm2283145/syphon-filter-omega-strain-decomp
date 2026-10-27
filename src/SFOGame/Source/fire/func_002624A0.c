#pragma cplusplus on
#include "types.h"
struct VF24 { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void f5C(int); };
typedef struct { char pad[0xC]; int id; } Own24;
typedef struct Fire24 {
    void** vt; char pad4[0x5C]; int x60; char pad64[0x1C]; float x80, x84, x88; char pad8C[4];
    Own24* owner; int ownerId;
} Fire24;
extern "C" {
extern void* D_004DC970[];
extern int D_004F8308[];
extern int D_0048B0E0;
void nGobjManager_GetNextId(int* out, int kind);
void cGOBJ_ctor(void* p, int* id, int a, int* b);
void nGobjManager_AddGOBJ(Fire24* p);
}
extern "C" Fire24* cFireObj_ctor_cGOBJP_float_float(Fire24* s, Own24* o, float r, float t)
{
    int id;
    nGobjManager_GetNextId(&id, 0xF8);
    cGOBJ_ctor(s, &id, 0x12, D_004F8308);
    s->vt = D_004DC970;
    s->ownerId = -2;
    s->owner = 0;
    s->owner = o;
    {
        int tmp;
        s->ownerId = *(o ? &o->id : (tmp = -1, &tmp));
    }
    s->x88 = r;
    s->x84 = r;
    s->x80 = r;
    s->x60 = (int)((float)D_0048B0E0 * t / 100.0f);
    nGobjManager_AddGOBJ(s);
    ((VF24*)s)->f5C(1);
    return s;
}

