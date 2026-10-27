/*
 * SFOGame/Source/npc: 7 files, 0014D340-0014D470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D340 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
#include "types.h"

struct Ret_0014D340 { int w[4]; Ret_0014D340() {} };
struct VObj_0014D340 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual Ret_0014D340 Get(); /* +0xE4 */
};

extern "C" Ret_0014D340 cGOBJ_GetTargetPosition(VObj_0014D340* obj)
{
    return obj->Get();
}
static inline void merge_flush_func_0014D340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D340 */

/* merge_units: begin func_0014D350 */
#pragma push /* merge_units */
#include "npc_types.h"

typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

/* Returns the referenced object if it is still the same instance (serial matches), else 0. */
Tracked* cSafePtr_cGOBJ_GetPtr_void(WeakRef* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D350 */

/* merge_units: begin func_0014D390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x28. */
int cNPC_UseCurrentLookAt(cNPC* self, unsigned char i) {
    return self->unk17C[i].unk00;
}

/* vtable slot 0x27. */
signed char cNPC_v27(cNPC* self) {
    return self->unk13C;
}

/* vtable slot 0x34. */
float cNPC_GetRawTravelSpeed(cNPC* self) {
    return self->unk060;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D390 */

/* merge_units: begin func_0014D3D0 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define V4CopyQ V4Copy
typedef struct { char pad[0xE8]; unsigned char ok; char pad2[7]; __int128 q; } B_D3D0;
typedef struct { char pad[0x3310]; B_D3D0* b; } A_D3D0;
#pragma push

int cHuman_GetFloorPlane(A_D3D0* a, __int128* out) {
    B_D3D0* b = a->b;
    if (b && b->ok) {
        VCopyF(out, &b->q);
        return 1;
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_0014D3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D3D0 */

/* merge_units: begin func_0014D410 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; Tracked* obj; int serial; } RefHolder;

/* Returns the referenced object at +0x50 if it is still the same instance (serial matches), else 0. */
Tracked* func_0014D410(RefHolder* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D410 */

/* merge_units: begin func_0014D450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */


int func_0014D450(Word* self) {
    return self->value;
}

void* func_0014D460(char* self) {
    return self + 0x2FE0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D450 */

/* merge_units: begin func_0014D470 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; unsigned char b0:3; unsigned char b3:1; unsigned char b4:4; } Info14D470;
typedef struct { char pad0[0x7C]; int x7C; char pad80[0x20]; int xA0; char padA4[0x98]; unsigned char x13C; char pad13D[0x73]; Info14D470* x1B0; } NPC14D470;
extern void cNPC_SetMoveMode(NPC14D470*, int, int);
void cNPC_ResumeMovement(NPC14D470* n) {
    if (!n->x1B0->b3) {
        n->xA0 = 0;
        if (!n->x13C) cNPC_SetMoveMode(n, 2, 0);
        n->x7C = 0;
    }
}
static inline void merge_flush_func_0014D470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D470 */
