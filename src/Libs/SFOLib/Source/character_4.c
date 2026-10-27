/*
 * Libs/SFOLib/Source/character: 3 files, 003E4370-003E4430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin scriptManager_3E4370 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; const V* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } return *this; } } __attribute__((aligned(16)));
struct T70 { int a; int b; char pad[8]; V c; V d; };
extern "C" T70* cInteractParams_ctor_int_cQuatVecR_cObjectIdR(T70* t, int a, const V* q, const int* p);
T70* cInteractParams_ctor_int_cQuatVecR_cObjectIdR(T70* t, int a, const V* q, const int* p) {
    t->a = a;
    t->b = *p;
    t->c = q[0];
    t->d = q[1];
    void* xx = &t->d; /* dead on purpose: retail keeps this addiu */
    return t;
}
static inline void merge_flush_scriptManager_3E4370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end scriptManager_3E4370 */

/* merge_units: begin func_003E43B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern char D_004E0840[];         /* Msg3E43D0 vtable */
extern char g_ActorActionMsgClass[];         /* Msg3E43D0 type descriptor */
extern void* cMessage_ctor_cMessageNameR_messagebaseR(void* self, void* type, void* arg);

Vec4* cQuaternion_ctor_float_float_float_float(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Builds the message from a source record. */
Msg3E43D0* cCharActionMsg_ctor_netcharactionreqR(Msg3E43D0* self, Msg3E43D0Src* src) {
    cMessage_ctor_cMessageNameR_messagebaseR(self, g_ActorActionMsgClass, src);
    self->vtable = D_004E0840;
    self->unk24 = src->unk08;
    self->unk28 = src->unk09;
    return self;
}
static inline void merge_flush_func_003E43B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E43B0 */

/* merge_units: begin func_003E4430 */
#pragma push /* merge_units */
/* Net packet handler (returns the packet size 0x28): builds an actor-action message
 * (class via cCharActionMsg_ctor_messagebaseR_int_eParamType, kind 13) with a target sub-record and queues a clone to the
 * object found by cNetObj_GetNetSystem. For u26 == 0xFFFF the direction is decoded from two
 * 2.14 fixed values and optionally transformed by the referenced object's camera node. */

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; float c; float d; int e; } Sub;
typedef struct { void* vt; char p4[0x2C]; Sub sub; } Msg;
typedef struct {
    int kind, id;
    float x, y, z;
    union { struct { float x, y, z, w; } f; struct { int obj; short px, py; float pz, pw; } i; } q;
    short h24;
    unsigned short u26;
} Pkt;
/* object id handle built by cObjectId_ctor_uint; 8 bytes gives retail's slot at sp+296 */
typedef struct { int v; int pad; } Handle;

extern unsigned char D_005723C8, D_005721D0;
extern char D_004E0100[], D_004E0840[];
extern void cCharActionMsg_ctor_messagebaseR_int_eParamType(Msg* m, Pkt* p, int a, int b);
extern V4* cPlane_ctor_float_float_float_float(V4* v, float x, float y, float z, float w);
extern V4* cVector_ctor_float_float_float_float(V4* v, float x, float y, float z, float w);
extern float cCharActionMsg_DestinationParams_UnpackDestinationRotZ(int v);
extern float cCharActionMsg_DestinationParams_UnpackSpeedOfMotion(unsigned int v);
extern float Fixed14ToFloat(int v);
extern void cDestinationParams_ctor_cVectorR_cPlaneR_float_float(Sub* s, V4* a, V4* b, float c, float d, int e);
extern void cPlane_dtor(V4* v, int flag);
extern void cVector_Normalize_void(V4* v);
extern float* cVector_X_void_2(V4* v);
extern float* cVector_Y_void_2(V4* v);
extern float* cVector_Z_void_2(V4* v);
extern Sub* func_003E4850(Sub* s);
extern void cVector_ctor_cVectorR(V4* d, Sub* s);
extern void func_003E4840(V4* d, V4* s);
extern int func_003E4830(void);
extern void cObjectId_ctor_uint(Handle* h, int id);
extern void* nGobjManager_LookupGOBJ_cObjectIdR(Handle* h);
extern void* cGOBJ_GetXform_void(void* o);
extern void* cXform_GetMatrix(void* n);
extern void cVector_Transform_cMatrixR(V4* v, void* m);
extern void func_003E4720(V4* v, void* m);
extern void func_003E4710(Sub* s, void* o);
extern void func_003E4700(Sub* s, V4* v);
extern void func_003E46F0(Sub* s, V4* v);
extern void func_003E46E0(Sub* s, float f);
extern void** cNetObj_GetNetSystem(int id);
extern void QueueMessage_cMessageR_cSystemP_int_int(Msg* m, void* o, int a, int b);
extern void cMessage_dtor(Msg* m, int f);

#pragma opt_propagation off
#pragma opt_common_subs off
int func_003E4430(int x, int y, int z, Pkt* p0)
{
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Pkt* p = p0;
        Msg msg;
        V4 d;
        V4 e;
        V4 g;
        V4 h;
        V4 b;
        V4 a;
        Msg* m = &msg;
        V4* pb;
        float c;
        void** obj;
        cCharActionMsg_ctor_messagebaseR_int_eParamType(m, p, 0, 13);
        cPlane_ctor_float_float_float_float(&a, p->q.f.x, p->q.f.y, p->q.f.z, p->q.f.w);
        pb = cVector_ctor_float_float_float_float(&b, p->x, p->y, p->z, 1.0f);
        c = cCharActionMsg_DestinationParams_UnpackDestinationRotZ(p->h24);
        cDestinationParams_ctor_cVectorR_cPlaneR_float_float(&m->sub, pb, &a, c, cCharActionMsg_DestinationParams_UnpackSpeedOfMotion(p->u26), 0);
        cPlane_dtor(&a, -1);
        m->vt = D_004E0100;
        if (p->u26 == 0xFFFF) {
            int w = *(int*)&p->q.i.px;
            float fx = Fixed14ToFloat((short)w);
            float* rx;
            float* ry;
            int id;
            cVector_ctor_float_float_float_float(&d, fx, Fixed14ToFloat((short)(w >> 16)), p->q.i.pz, 0.0f);
            cVector_Normalize_void(&d);
            rx = cVector_X_void_2(&d);
            ry = cVector_Y_void_2(&d);
            cPlane_ctor_float_float_float_float(&e, *rx, *ry, *cVector_Z_void_2(&d), p->q.i.pw);
            cVector_ctor_cVectorR(&g, func_003E4850(&m->sub));
            func_003E4840(&h, &e);
            id = p->q.i.obj;
            if (id != func_003E4830()) {
                Handle hd;
                void* o;
                cObjectId_ctor_uint(&hd, id);
                o = nGobjManager_LookupGOBJ_cObjectIdR(&hd);
                if (o) {
                    void* n = cGOBJ_GetXform_void(o);
                    if (n) {
                        void* m = cXform_GetMatrix(n);
                        cVector_Transform_cMatrixR(&g, m);
                        func_003E4720(&h, m);
                    }
                    func_003E4710(&m->sub, o);
                }
            }
            func_003E4700(&m->sub, &g);
            func_003E46F0(&m->sub, &h);
            func_003E46E0(&m->sub, 1.0f);
            cPlane_dtor(&h, -1);
            cPlane_dtor(&e, -1);
        }
        obj = cNetObj_GetNetSystem(p->id);
        if (obj) QueueMessage_cMessageR_cSystemP_int_int(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x28;
}
static inline void merge_flush_func_003E4430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4430 */
