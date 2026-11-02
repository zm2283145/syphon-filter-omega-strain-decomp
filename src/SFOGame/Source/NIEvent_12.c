/*
 * SFOGame/Source/NIEvent: 12 files, 0023F530-0023FB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023F530 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cNIEventBasePtr_1_dtor)
static inline void merge_flush_func_0023F530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F530 */

/* merge_units: begin func_0023F620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NIEvent_types.h"

/* Constructs an empty vector. */
NIEventVec3* std_vector_VisKey_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}

/* Constructs an empty vector. */
NIEventVec3* std_vector_VectorKey_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}

/* Constructs an empty vector. */
NIEventVec3* std_vector_cNIEventBasePtr_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}
static inline void merge_flush_func_0023F620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F620 */

/* merge_units: begin func_0023F680 */
#pragma push /* merge_units */
/* Net receive handler: look up the object by id and (de)activate its event camera,
   then re-broadcast a toggle event when hosting. */
#pragma cplusplus on
#include "net_recv_guard.h"
#include "npc_auth.h"
typedef struct { void* vt; char p4[0x20]; unsigned char b24; char p25[0x3]; } EvF680;
typedef struct { char p0[0xC]; int id; char p10[0x50]; int kind; char p64[0xDC]; void* cam; } ObjF680;
typedef struct { char pad[0x10]; ObjF680* val; } NodeF680;
typedef struct { char q0[0x4]; int id; unsigned char off; } ArgF680;
extern "C" {
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(EvF680* e, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, EvF680* e, int a, int b);
#if 0 /* merge_units */
extern void cMessage_dtor(EvF680* e, int f);
#endif /* merge_units */
void cMessage_dtor(void*, int); /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern void cGameCamera_PushCurrent(void* c);
extern void cGameCamera_RemoveCamera(void* c);
extern char D_0055C7A0[];
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_find_intR(NodeF680** out, void* map, int* key);
#endif /* merge_units */
void std_tree_pair_int_value_compare_find_intR(void*, void*, int*); /* merge_units */
#define std_tree_pair_int_value_compare_find_intR(a0, a1, a2) (std_tree_pair_int_value_compare_find_intR((void *)(a0), (a1), (a2))) /* merge_units */

extern void std_map_int_netSystemField_end(void* out, void* map);
#if 0 /* merge_units */
extern void cAssocArray_int_netSystemField_Iterator_ctor(NodeF680** out, void* in);
#endif /* merge_units */
void cAssocArray_int_netSystemField_Iterator_ctor(void*, void*); /* merge_units */
#define cAssocArray_int_netSystemField_Iterator_ctor(a0, a1) (cAssocArray_int_netSystemField_Iterator_ctor((void *)(a0), (a1))) /* merge_units */

extern char D_004DC2D0[];
extern char D_004F7C38[];
extern unsigned char D_005721D0;
}
static inline int EqF680(NodeF680* a, NodeF680* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNICameraMsg_NICameraCallback(int a0, int a1, int a2, ArgF680* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        NodeF680* end[1];
        NodeF680* it[1];
        int tmp[1];
        NodeF680* n;
        ArgF680* a = arg;
        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (EqF680(n, end[0]) ^ 1) {
            ObjF680* o = n->val;
            if (o) {
                if (!a->off) {
                    if (o->kind == 5 && o->cam) {
                        cGameCamera_PushCurrent(o->cam);
                        if (g_IsMultiplayer && NpcAuth_IsLocal()) {
                            EvF680 e;
                            cMessage_ctor_cMessageNameR(&e, D_004F7C38);
                            e.vt = D_004DC2D0;
                            e.b24 = 0;
                            cNetObj_SendMessage_int_cMessageR_int_int(o->id, &e, -1, -1);
                            e.vt = D_004DC2D0;
                            cMessage_dtor(&e, 0);
                        }
                    }
                } else {
                    if (o->kind == 5 && o->cam) {
                        cGameCamera_RemoveCamera(o->cam);
                        if (g_IsMultiplayer && NpcAuth_IsLocal()) {
                            EvF680 e;
                            cMessage_ctor_cMessageNameR(&e, D_004F7C38);
                            e.vt = D_004DC2D0;
                            e.b24 = 1;
                            cNetObj_SendMessage_int_cMessageR_int_int(o->id, &e, -1, -1);
                            e.vt = D_004DC2D0;
                            cMessage_dtor(&e, 0);
                        }
                    }
                }
            }
        }
    }
    return 0xC;
}
#pragma pop
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef std_tree_pair_int_value_compare_find_intR /* merge_units */
#undef cAssocArray_int_netSystemField_Iterator_ctor /* merge_units */
static inline void merge_flush_func_0023F680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F680 */

/* merge_units: begin func_0023F890 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { char a; } Proto_0023F890;
#if 0 /* merge_units */
extern char D_004F7C48[];
#endif /* merge_units */
extern int D_004F7C48; /* merge_units */
#define D_004F7C48 ((char*)&D_004F7C48) /* merge_units */

#if 0 /* merge_units */
extern void cNICameraMsg_NICameraCallback(void);
#endif /* merge_units */


NETREG_BEGIN_KEEP(cNICameraMsg_InitNet, Proto_0023F890)
NETREG_FIELD(a, 1, 1)
NETREG_END(D_004F7C48, cNICameraMsg_NICameraCallback)
#undef D_004F7C48 /* merge_units */
static inline void merge_flush_func_0023F890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F890 */

/* merge_units: begin func_0023F920 */
#pragma push /* merge_units */
#include "message_pack.h"
#pragma push
#pragma cplusplus on
#pragma pop

#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(cNICameraMsg_Pack, 12, D_004F7C48, PACK_PRE, PACK_BODY)
static inline void merge_flush_func_0023F920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F920 */

/* merge_units: begin func_0023F9A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; void* val; } Node0023F9A0;
typedef struct { void* vt; char p4[0x20]; int f24; char p28[0x4]; } Evt0023F9A0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0023F9A0;
extern "C" {
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Evt0023F9A0* e, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int_int(Evt0023F9A0* e, void* obj, int a, int b);
#if 0 /* merge_units */
extern void cMessage_dtor(Evt0023F9A0* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_find_intR(Node0023F9A0** out, void* map, int* key);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_find_intR(a0, a1, a2) (std_tree_pair_int_value_compare_find_intR((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0023F9A0** out, void* in);
#endif /* merge_units */
#define cAssocArray_int_netSystemField_Iterator_ctor(a0, a1) (cAssocArray_int_netSystemField_Iterator_ctor((void *)(a0), (a1))) /* merge_units */

extern char D_004DC2F0[];
extern char D_004F7C28[];
}
static inline int Eq0023F9A0(Node0023F9A0* a, Node0023F9A0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNIShuttle_NIShuttleCallback(int a0, int a1, int a2, Arg0023F9A0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0023F9A0 e;
        int k[1];
        Node0023F9A0* end[1];
        Node0023F9A0* it[1];
        int tmp[1];
        Node0023F9A0* n;
        Arg0023F9A0* a = arg;
        cMessage_ctor_cMessageNameR(&e, D_004F7C28);
        e.vt = D_004DC2F0;
        e.f24 = a->a8;
        k[0] = a->a4;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0023F9A0(n, end[0]) ^ 1) QueueMessage_cMessageR_cSystemP_int_int(&e, n->val, 0, 0);
        e.vt = D_004DC2F0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023F9A0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef std_tree_pair_int_value_compare_find_intR /* merge_units */
#undef cAssocArray_int_netSystemField_Iterator_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F9A0 */

/* merge_units: begin func_0023FAA0 */
#pragma push /* merge_units */
typedef struct { int a; } Proto_0023FAA0;
#if 0 /* merge_units */
extern char D_004F7C40[];
#endif /* merge_units */
extern int D_004F7C40; /* merge_units */
#define D_004F7C40 ((char*)&D_004F7C40) /* merge_units */

#if 0 /* merge_units */
extern void cNIShuttle_NIShuttleCallback(void);
#endif /* merge_units */


NETREG_BEGIN_KEEP(cNIShuttle_InitNet, Proto_0023FAA0)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7C40, cNIShuttle_NIShuttleCallback)
#undef D_004F7C40 /* merge_units */
static inline void merge_flush_func_0023FAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023FAA0 */

/* merge_units: begin func_0023FB30 */
#pragma push /* merge_units */
#undef PACK_BODY /* merge_units */
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
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

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
#undef operator_delete /* merge_units */
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
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */

void cNIEventFXTrack_dtor(void* p, int f);
void std_vector_deleter_FloatKey_dtor(void* p, int f);
void cArray_VisKey_dtor(void* p, int f);
void cArray_VectorKey_dtor(void* p, int f);
void cArray_cNIEventBasePtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

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
#undef cMemMan_Deallocate /* merge_units */
#undef operator_delete /* merge_units */
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
