#include "types.h"

typedef struct { float x, y, z, w; } Vec16;
typedef struct { char pad[0x10]; char inner[0xC0]; char out[0x30]; } Slot1D2;
typedef struct { char pad[0x1C0]; Vec16 pos; } Elem1D0;
typedef struct { char pad[0x20]; Elem1D0* elems; } Table1D2;
typedef struct { int unk0; Table1D2* table; } Obj1D2;

extern Slot1D2 D_004F32B0[];
extern void func_00132840(Vec16* v);
extern void* func_001325F0(Vec16* v, void* src);
extern void* func_001D2C00(void* inner);
extern void func_001A7D80(void* dst, void* m);
extern void func_001D2BA0(Vec16* a, Vec16* b);
extern void* func_001D2870(void* inner);
extern void func_001D29F0(void* out, Vec16* v, void* m);
extern void* func_001D29E0(void* inner);
extern void func_001D5FA0(Slot1D2* slot);

/* Transforms a point and the indexed element's position through slot idx and updates the slot. */
void func_001D28D0(Obj1D2* self, void* point, int idx)
{
    Vec16 b;
    Vec16 a;
    void* out;
    Slot1D2* slot;
    Vec16* pos;
    void* r;
    slot = &D_004F32B0[idx];
    out = slot->out;
    pos = &self->table->elems[idx].pos;
    func_00132840(&a);
    r = func_001325F0(&a, point);
    func_001A7D80(r, func_001D2C00(slot->inner));
    func_00132840(&b);
    r = func_001325F0(&b, pos);
    func_001A7D80(r, func_001D2C00(slot->inner));
    func_001D2BA0(&a, &b);
    func_001D29F0(out, &a, func_001D2870(slot->inner));
    func_001A7D80(out, func_001D29E0(slot->inner));
    func_001D5FA0(slot);
}
