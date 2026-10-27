/*
 * SFOGame/Source/NetTargetInfo: 4 files, 00316980-00316A80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316980 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V316980 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual unsigned char v32(); };
struct T316980 { V316980 v; char pad[0x40]; int x48; char pad4C[0x1E0 - 0x48]; int x1E0; };
struct S316980 { char pad[0x58]; T316980* p58; };
extern "C" void cTargetInfo_Creation(int val, S316980* s)
{
    if (s->p58) {
        unsigned char t = s->p58->v.v32();
        switch (t) {
        case 2:
            s->p58->x1E0 = val;
            break;
        case 4:
            s->p58->x48 = val;
            break;
        }
    }
}
static inline void merge_flush_func_00316980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316980 */

/* merge_units: begin func_00316A00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Resets the record to its empty state. */
void cTargetInfo_Init(Rec316A00* self) {
    self->unk08 = -1;
    self->unk00 = 0;
    self->unk01 = 0;
    self->unk04 = -1;
    self->unk08 = -1;
    self->unk0C = -1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
}
static inline void merge_flush_func_00316A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316A00 */

/* merge_units: begin func_00316A30 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cTargetInfo_dtor)
static inline void merge_flush_func_00316A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316A30 */

/* merge_units: begin func_00316A80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE610[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
union V2_6250 { struct { float x, y; } f; struct { char c[8]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V4_E100 v; V2_6250 w; };
extern "C" Msg2530* cNetWeaponMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x3C, "NetWeaponMsg.hh", 0x21);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->d = src->d;
        p->e = src->e;
        p->f = src->f;
        p->g = src->g;
        p->h = src->h;
        p->vtable = D_004DE610;
        p->v = src->v;
        p->w = src->w;
    }
    return p;
}
static inline void merge_flush_func_00316A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316A80 */
