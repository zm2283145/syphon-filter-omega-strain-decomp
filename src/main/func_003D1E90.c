/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Plain data in front of the vtable pointer (vptr at +0x10). */
struct ObjBase {
    int unk0;    /* +0x00 */
    float* pos;  /* +0x04 */
    int unk8;    /* +0x08 */
    int unkC;    /* +0x0C */
};

struct Obj : ObjBase {
    virtual void v00();
    virtual void Init(); /* +0xC */
    float x; /* +0x14 */
    float y; /* +0x18 */
};

extern char D_004E0080[];
extern char D_004E0090[];

/* Constructor: installs the base vtable D_004E0080, stores the leading fields, installs vtable D_004E0090, copies pos[0..1] and calls virtual +0xC. */
extern "C" Obj* func_003D1E90(Obj* self, float* pos, int a2, int a3, int a0)
{
    *(void**)((char*)self + 0x10) = D_004E0080;
    self->unk0 = a0;
    self->pos = pos;
    self->unk8 = a2;
    self->unkC = a3;
    *(void**)((char*)self + 0x10) = D_004E0090;
    self->x = pos[0];
    self->y = pos[1];
    self->Init();
    return self;
}
