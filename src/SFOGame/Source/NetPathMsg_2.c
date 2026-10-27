/*
 * SFOGame/Source/NetPathMsg: 4 files, 002D79D0-002D7C60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D79D0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_U(b, 0x10) = MP_U(e, 0x34); MP_F(b, 0x14) = MP_F(e, 0x38); MP_F(b, 0x18) = MP_F(e, 0x3C); MP_F(b, 0x1C) = MP_F(e, 0x40); MP_I(e, 0x1C) = 0x40;
DEFINE_MESSAGE_PACK(cNetPathMsg_Pack, 0x20, D_0051F0C8, PACK_BODY)
static inline void merge_flush_func_002D79D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D79D0 */

/* merge_units: begin func_002D7A80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node2D7A80;
typedef struct { float x, y, z; } V2D7A80;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; unsigned char f34; char p35[3]; V2D7A80 v; } Evt2D7A80;
typedef struct { int kind; int id; int f8; int fC; unsigned char b10; char p11[3]; V2D7A80 v; } Arg2D7A80;
extern "C" {
extern void cMessage_ctor_cMessageNameR_messagebaseR(Evt2D7A80* e, void* type, Arg2D7A80* a);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt2D7A80* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D7A80* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node2D7A80** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node2D7A80** out, void* in);
extern char D_004DE510[];
extern char D_0051F0C0[];
extern unsigned char D_005721D0;
}
static inline int Eq2D7A80(Node2D7A80* a, Node2D7A80* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNetPathMsg_PathCallback(int a0, int a1, int a2, Arg2D7A80* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D7A80 e;
        int k[1];
        Node2D7A80* end[1];
        Node2D7A80* it[1];
        int tmp[1];
        Node2D7A80* n;
Arg2D7A80* a = arg;
void* m = D_0055C7A0;
Evt2D7A80* p = &e;
        cMessage_ctor_cMessageNameR_messagebaseR(p, D_0051F0C0, a);
        e.vt = D_004DE510;
        e.v.x = -1.0f;
        e.v.y = -1.0f;
        e.v.z = -1.0f;
        p->f2C = -1;
        p->f30 = -1;
        p->v.x = a->v.x;
        p->v.y = a->v.y;
        p->v.z = a->v.z;
        p->f34 = a->b10;
        p->f2C = a->f8;
        p->f30 = a->fC;
        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, m, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, m);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq2D7A80(n, end[0]) ^ 1) QueueMessage_cMessageR_cSystemP_int_int(&e, n->val, 0, 0);
        e.vt = D_004DE510;
        cMessage_dtor(&e, 0);
    }
    return 0x20;
}
#pragma pop
static inline void merge_flush_func_002D7A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7A80 */

/* merge_units: begin func_002D7BE0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; int pad; int st; int p14[3]; int *list; int p24; int n; } S7BE0b;
typedef struct { char p0[0x2C]; int last; int first; char bool34; char p35[3]; float x, y, z; } S7BE0a;
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, S7BE0a *, int, int);
void cNetPathMsg_SendPath(S7BE0a *m, int t, S7BE0b *s)
{
    if (s->n) {
        m->last = s->list[s->n - 1];
        m->first = s->list[0];
    } else {
        m->last = -1;
        m->first = -1;
    }
    m->x = s->x;
    m->y = s->y;
    m->z = s->z;
    m->bool34 = !(s->st >= 0);
    cNetObj_SendMessage_int_cMessageR_int_int(t, m, -1, -1);
}
static inline void merge_flush_func_002D7BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7BE0 */

/* merge_units: begin func_002D7C60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cNetPlayer_GetControllerType(void) {
    return 4;
}

int cNetPlayer_IsPlayer(void) {
    return 1;
}
static inline void merge_flush_func_002D7C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7C60 */
