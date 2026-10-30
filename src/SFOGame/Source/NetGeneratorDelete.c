/*
 * SFOGame/Source/NetGeneratorDelete: 4 files, 002D15C0-002D1810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D15C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE260[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V4_E100 v; };
extern "C" Msg2530* cNetGeneratorDeleteMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x34, "NetGeneratorDelete.hh", 0x1A);
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
        p->vtable = D_004DE260;
        p->v = src->v;
    }
    return p;
}
static inline void merge_flush_func_002D15C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D15C0 */

/* merge_units: begin func_002D16E0 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_0051F070;
extern int cNetGeneratorDeleteMsg_GeneratorDeleteCallback(int a0, int a1, int a2, void* packet);
unsigned char cNetGeneratorDeleteMsg_InitNet(void)
{
    struct { long long file; int a; int b; } L;
    int err;
    unsigned char ok;
    ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetRegisterMessage(&D_0051F070, 2, cNetGeneratorDeleteMsg_GeneratorDeleteCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002D16E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D16E0 */

/* merge_units: begin func_002D1790 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; int a; int b; } Ev1790;
typedef struct { char pad[8]; int a; int b; } Buf1790;

extern void Event_PackHeader(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int cNetGeneratorDeleteMsg_Pack(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x10 && buf) {
        Buf1790* b = (Buf1790*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a;
        b->b = e->b;
        if (type) {
            r = 0x10;
            *type = D_0051F070;
        }
    }
    return r;
}
static inline void merge_flush_func_002D1790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1790 */

/* merge_units: begin func_002D1810 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node2D1810;
typedef struct { int a; void* b; } Ent2D1810;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; char p34[4]; } Evt2D1810;
typedef struct { int kind; int id; int f8; int fC; } Arg2D1810;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt2D1810* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt2D1810* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D1810* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node2D1810** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node2D1810** out, void* in);
extern Ent2D1810* std_tree_pair_int_value_compare_find_or_insert(void* map, int* key);
extern char D_0051F068[];
extern unsigned char D_005721D0;
}
static inline int Eq2D1810(Node2D1810* a, Node2D1810* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNetGeneratorDeleteMsg_GeneratorDeleteCallback(int a0, int a1, int a2, void* packet) {
    Arg2D1810* arg = (Arg2D1810*)packet;
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D1810 e;
        int k[1];
Node2D1810* end[1];
int k2[1];
Node2D1810* it[1];
int tmp[1];
        Node2D1810* n;
        Arg2D1810* a = arg;
        void* m = D_0055C7A0;
        cMessage_ctor_cMessageNameR(&e, D_0051F068);
        e.vt = D_004DE260;
        e.f2C = a->f8;
        e.f30 = a->fC;
        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, m, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, m);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq2D1810(n, end[0]) ^ 1) {
            k2[0] = a->id;
            QueueMessage_cMessageR_cSystemP_int_int(&e, std_tree_pair_int_value_compare_find_or_insert(m, k2)->b, 0, 0);
        }
        e.vt = D_004DE260;
        cMessage_dtor(&e, 0);
    }
    return 0x10;
}
#pragma pop
static inline void merge_flush_func_002D1810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1810 */
