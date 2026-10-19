#include "types.h"

/* Net packet handler (returns the packet size 0x28): builds an actor-action message
 * (class via func_003E4940, kind 13) with a target sub-record and queues a clone to the
 * object found by NetMap_Lookup. For u26 == 0xFFFF the direction is decoded from two
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
/* object id handle built by func_0015AC90; 8 bytes gives retail's slot at sp+296 */
typedef struct { int v; int pad; } Handle;

extern unsigned char D_005723C8, D_005721D0;
extern char D_004E0100[], D_004E0840[];
extern void func_003E4940(Msg* m, Pkt* p, int a, int b);
extern V4* func_003E4920(V4* v, float x, float y, float z, float w);
extern V4* Vec4_Set(V4* v, float x, float y, float z, float w);
extern float Fixed13ToFloat(int v);
extern float UFixed15ToFloat(unsigned int v);
extern float Fixed14ToFloat(int v);
extern void func_003E4880(Sub* s, V4* a, V4* b, float c, float d, int e);
extern void StaticInit_FloorContactVecs(V4* v, int flag);
extern void Vec4_NormalizeXYZInPlace(V4* v);
extern float* func_003B2680(V4* v);
extern float* func_003B2650(V4* v);
extern float* func_003B2630(V4* v);
extern Sub* func_003E4850(Sub* s);
extern void Vec4_Assign(V4* d, Sub* s);
extern void func_003E4840(V4* d, V4* s);
extern int func_003E4830(void);
extern void func_0015AC90(Handle* h, int id);
extern void* Object_LookupById(Handle* h);
extern void* Camera_GetNode(void* o);
extern void* Transform_GetUpdated(void* n);
extern void Mtx_Multiply4(V4* v, void* m);
extern void func_003E4720(V4* v, void* m);
extern void func_003E4710(Sub* s, void* o);
extern void func_003E4700(Sub* s, V4* v);
extern void func_003E46F0(Sub* s, V4* v);
extern void func_003E46E0(Sub* s, float f);
extern void** NetMap_Lookup(int id);
extern void MsgQueue_QueueClone(Msg* m, void* o, int a, int b);
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
        func_003E4940(m, p, 0, 13);
        func_003E4920(&a, p->q.f.x, p->q.f.y, p->q.f.z, p->q.f.w);
        pb = Vec4_Set(&b, p->x, p->y, p->z, 1.0f);
        c = Fixed13ToFloat(p->h24);
        func_003E4880(&m->sub, pb, &a, c, UFixed15ToFloat(p->u26), 0);
        StaticInit_FloorContactVecs(&a, -1);
        m->vt = D_004E0100;
        if (p->u26 == 0xFFFF) {
            int w = *(int*)&p->q.i.px;
            float fx = Fixed14ToFloat((short)w);
            float* rx;
            float* ry;
            int id;
            Vec4_Set(&d, fx, Fixed14ToFloat((short)(w >> 16)), p->q.i.pz, 0.0f);
            Vec4_NormalizeXYZInPlace(&d);
            rx = func_003B2680(&d);
            ry = func_003B2650(&d);
            func_003E4920(&e, *rx, *ry, *func_003B2630(&d), p->q.i.pw);
            Vec4_Assign(&g, func_003E4850(&m->sub));
            func_003E4840(&h, &e);
            id = p->q.i.obj;
            if (id != func_003E4830()) {
                Handle hd;
                void* o;
                func_0015AC90(&hd, id);
                o = Object_LookupById(&hd);
                if (o) {
                    void* n = Camera_GetNode(o);
                    if (n) {
                        void* m = Transform_GetUpdated(n);
                        Mtx_Multiply4(&g, m);
                        func_003E4720(&h, m);
                    }
                    func_003E4710(&m->sub, o);
                }
            }
            func_003E4700(&m->sub, &g);
            func_003E46F0(&m->sub, &h);
            func_003E46E0(&m->sub, 1.0f);
            StaticInit_FloorContactVecs(&h, -1);
            StaticInit_FloorContactVecs(&e, -1);
        }
        obj = NetMap_Lookup(p->id);
        if (obj) MsgQueue_QueueClone(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x28;
}
