/*
 * SFOGame/Source/NIEvent: 5 files, 0023FB30-0023FED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023FB30 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(cNIShuttle_Pack, 12, D_004F7C40, PACK_PRE, PACK_BODY)
static inline void merge_flush_func_0023FB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FB30 */

/* merge_units: begin func_0023FBB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
struct VBase_23FBB0 { int x; };

struct VObj_23FBB0 : VBase_23FBB0 { virtual void Destroy(int f); };
typedef struct {
    void* vt;
    char pad04[0x98];
    char m9C[0x10];
    char mAC[0x18];
    char mC4[0xAC];
    char m170[0x20];
    char m190[0x4];
    char m194[0x1C];
} Light_23FBB0;
typedef struct { char pad[0x140]; VObj_23FBB0* obj; } LightP_23FBB0;
extern "C" {
extern char D_004DBED0[];
extern char D_004DC190[];
extern void std_vector_deleter_FloatKey_dtor(void* p, int f);
extern void cArray_VisKey_dtor(void* p, int f);
extern void cArray_VectorKey_dtor(void* p, int f);
extern void cArray_cNIEventBasePtr_dtor(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
}
static inline void L4_23FBB0(void* p) { if (p) std_vector_deleter_FloatKey_dtor(p, 0); }
static inline void L3_23FBB0(void* p) { if (p) L4_23FBB0(p); }
static inline void L2_23FBB0(void* p) { if (p) L3_23FBB0(p); }
static inline void L2b_23FBB0(void* p) { if (p) L2_23FBB0(p); }
static inline void L1_23FBB0(char* p) { if (p) L2_23FBB0(p + 4); }
static inline void Del_23FBB0(VObj_23FBB0* p) { if (p) p->Destroy(1); }
static inline void Base_23FBB0(Light_23FBB0* l)
{
    if (l) {
        l->vt = D_004DC190;
        cArray_VisKey_dtor(l->mC4, -1);
        cArray_VectorKey_dtor(l->mAC, -1);
        cArray_cNIEventBasePtr_dtor(l->m9C, -1);
        cGOBJ_dtor(l, 0);
    }
}
extern "C" Light_23FBB0* cNIEventLight_dtor(Light_23FBB0* l, short flag)
{
    if (l) {
        VObj_23FBB0* o;
        l->vt = D_004DBED0;
        o = ((LightP_23FBB0*)l)->obj;
        if (o)
            Del_23FBB0(o);
        L1_23FBB0(l->m190);
        L1_23FBB0(l->m170);
        Base_23FBB0(l);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023FBB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023FBB0 */

/* merge_units: begin func_0023FCD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cNIEventBase_GetChildList_void(char* self) {
    return self + 156;
}

void* cNIEventBase_GetChildList_void_2(char* self) {
    return self + 156;
}

int cNIEventBase_IsNetworked(void) {
    return 1;
}
static inline void merge_flush_func_0023FCD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FCD0 */

/* merge_units: begin func_0023FD00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_23FD00 { virtual void Destroy(int f); };
struct Obj_23FD00 {
    void* vt;
    char pad04[0x98];
    char m9C[0x10];
    char mAC[0x18];
    char mC4[0x7C];
    VObj_23FD00* obj;
    char m144[0x20];
    char m164[0x20];
    char m184[0x20];
    char m1A4[0x10];
};
extern "C" {
extern char cNIEventOBJ_vtable[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cNIEventFXTrack_dtor(void* p, int f);
void std_vector_deleter_FloatKey_dtor(void* p, int f);
void cArray_VisKey_dtor(void* p, int f);
void cArray_VectorKey_dtor(void* p, int f);
void cArray_cNIEventBasePtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void L4_23FD00(void* p) { if (p) std_vector_deleter_FloatKey_dtor(p, 0); }
static inline void L3_23FD00(void* p) { if (p) L4_23FD00(p); }
static inline void L2_23FD00(void* p) { if (p) L3_23FD00(p); }
static inline void L1_23FD00(char* p) { if (p) L2_23FD00(p + 4); }
static inline void Base_23FD00(Obj_23FD00* l)
{
    if (l) {
        l->vt = D_004DC190;
        cArray_VisKey_dtor(l->mC4, -1);
        cArray_VectorKey_dtor(l->mAC, -1);
        cArray_cNIEventBasePtr_dtor(l->m9C, -1);
        cGOBJ_dtor(l, 0);
    }
}
extern "C" Obj_23FD00* cNIEventOBJ_dtor(Obj_23FD00* l, short flag)
{
    if (l) {
        VObj_23FD00* o;
        l->vt = cNIEventOBJ_vtable;
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            cMemMan_Deallocate(0, o, "NIEvent.hh", 0x166);
        }
        cNIEventFXTrack_dtor(l->m1A4, -1);
        L1_23FD00(l->m184);
        L1_23FD00(l->m164);
        L1_23FD00(l->m144);
        Base_23FD00(l);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}
static inline void merge_flush_func_0023FD00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FD00 */

/* merge_units: begin func_0023FED0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

class Tgt0023FED0 {
public:
    VPAD32(a)
    VPAD8(b)
    VPAD4(c)
    virtual int run();
};
struct Ev0023FED0 {
    char pad00[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0xDC - 0x2F];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt0023FED0* target;
};
extern "C" int cNIEventOBJ_GetCollisionModel(Ev0023FED0* self)
{
    Tgt0023FED0* t;
    return (self->enabled && (t = self->target) != 0 && !(self->b2D == 0) && self->b2C && !self->b2E)
        ? t->run() : 0;
}
static inline void merge_flush_func_0023FED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FED0 */
