#pragma cplusplus on
#include "types.h"
struct V4H {
    float x, y, z, w;
    V4H& operator=(const V4H& o) { const V4H* ps = &o; V4H* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct ItemsH { int unk0; int count; void** data; unsigned char bC; };
struct HotboxH {
    void* vt;
    char p4[0x60 - 4];
    ItemsH items;
    V4H bmin;
    V4H bmax;
    int type;
    int f94;
    int f98;
    int f9C;
    int fA0;
};
extern "C" {
extern char D_004EE6B8[];
extern char D_004D9AC0[];
void cGOBJ_ctor(void* self, int* gid, int n, char* cls);
void PtrVec_InitEmpty(ItemsH* v);
}
extern "C" HotboxH* cHotbox_ctor2(HotboxH* self, int* gid, int type, V4H* mn, V4H* mx)
{
    cGOBJ_ctor(self, gid, 8, D_004EE6B8);
    self->vt = D_004D9AC0;
    { ItemsH* it = &self->items; PtrVec_InitEmpty(it); it->bC = 1; }
    self->bmin.x = 3.4028235e38f;
    self->bmin.y = 3.4028235e38f;
    self->bmin.z = 3.4028235e38f;
    self->bmin.w = 1.0f;
    self->bmax.x = -3.4028235e38f;
    self->bmax.y = -3.4028235e38f;
    self->bmax.z = -3.4028235e38f;
    self->bmax.w = 1.0f;
    self->f94 = -1;
    self->type = type;
    self->bmin = *mn;
    self->bmax = *mx;
    self->f98 = 0;
    self->fA0 = 0;
    self->f9C = 10;
    return self;
}
