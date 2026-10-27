/*
 * main/ska: range (2 files, 003AD3F0-003AD500)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AD3F0 */
#pragma push /* merge_units */
typedef struct {
    unsigned char b0;
    unsigned char b1;
    char pad2[2];
    int i4;
    char req[0x14];
    char x1C[8];
    char ev1[0x38];
    char ev2[0x38];
    char x94[0x4C];
    float fE0;
    int iE4;
    char trans[0x10];
} F6Sel;
typedef struct { char pad[0x18]; char a18[0x14]; int n2C; char a30[0x14]; int n44; } F6Ctl;
extern F6Sel* std_deque_deleter_common_cSkaSystem_Request_back_void_2(void* arr);
extern signed char D_00542B70;
extern char D_00542B78[];
extern F6Sel D_00542B90;
extern void cSkaSystem_Transition_ctor_void(void*);
extern void cSkaPlaybackGroupId_ctor_int(void*, int);
extern void cSkaAnimEndedMessage_ctor_void(void*);
extern void cSkaAnimCheckpoints_ctor_void(void*);
extern void TransitionReq_Construct(void*, float);
extern void __register_global_object(void*, void*, void*);
extern void func_00397400(void);
#pragma opt_propagation off
F6Sel* cSkaRequestStream_GetLatestRequest(F6Ctl* c)
{
    if (c->n44) {
        return std_deque_deleter_common_cSkaSystem_Request_back_void_2(c->a30);
    }
    if (c->n2C) {
        return std_deque_deleter_common_cSkaSystem_Request_back_void_2(c->a18);
    }
    if (!D_00542B70) {
        F6Sel* s = &D_00542B90;
        D_00542B90.b0 = 0;
        D_00542B90.b1 = 0;
        D_00542B90.i4 = 0;
        cSkaSystem_Transition_ctor_void(D_00542B90.req);
        cSkaPlaybackGroupId_ctor_int(D_00542B90.x1C, -1);
        cSkaAnimEndedMessage_ctor_void(D_00542B90.ev1);
        cSkaAnimEndedMessage_ctor_void(D_00542B90.ev2);
        cSkaAnimCheckpoints_ctor_void(s->x94);
        s->fE0 = -1.0f;
        s->iE4 = 0;
        TransitionReq_Construct(s->trans, 0.0f);
        __register_global_object(s, func_00397400, D_00542B78);
        D_00542B70 = 1;
    }
    return &D_00542B90;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD3F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD3F0 */

/* merge_units: begin func_003AD500 */
#pragma push /* merge_units */
typedef struct { float v[5]; } D5F5;
typedef struct { float v[4]; } D5F4;
typedef struct {
    unsigned char b0;
    unsigned char b1;
    char pad2[2];
    int i4;
    D5F5 req;
    char x1C[8];
    char ev1[0x38];
    char ev2[0x38];
    char x94[0x4C];
    float fE0;
    int iE4;
    char trans[0x10];
} D5Sel;
extern D5F5* cSkaSystem_Transition_ctor_cSkaSystemTransitionR(D5F5* dst, D5F5* src);
extern void cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(void* dst, void* src);
extern void cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(void* dst, void* src);
extern void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* dst, void* src);
#if 0 /* merge_units */
extern void TransitionReq_Construct(void* self, float t);
#endif /* merge_units */
#define TransitionReq_Construct(a0, a1) (TransitionReq_Construct((a0), (a1))) /* merge_units */

extern void AnimCtl_Install(void* c, D5Sel* r, unsigned char mode);
extern void func_00396910(void* p, int f);
extern void cSkaAnimCheckpoints_dtor(void* p, int f);
extern void cSkaAnimEndedMessage_dtor(void* p, int f);
#pragma opt_propagation off
void cSkaRequestStream_AddRequest(void* ctl, int id, unsigned char mode, D5F4* range, void* pair, void* m1, void* m2, void* x, float f0, float f1)
{
    D5Sel s;
    D5F5 t;
    D5Sel* p = &s;
    t.v[0] = range->v[0];
    t.v[1] = range->v[1];
    t.v[2] = range->v[2];
    t.v[3] = range->v[3];
    t.v[4] = 0;
    s.b0 = 0;
    s.b1 = 0;
    s.i4 = id;
    cSkaSystem_Transition_ctor_cSkaSystemTransitionR(&s.req, &t);
    cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(s.x1C, pair);
    cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(s.ev1, m1);
    cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(s.ev2, m2);
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p->x94, x);
    p->fE0 = f0;
    p->iE4 = 0;
    TransitionReq_Construct(p->trans, f1);
    AnimCtl_Install(ctl, &s, mode);
    func_00396910(s.trans, -1);
    cSkaAnimCheckpoints_dtor(s.x94, -1);
    cSkaAnimEndedMessage_dtor(s.ev2, -1);
    cSkaAnimEndedMessage_dtor(s.ev1, -1);
}
#undef TransitionReq_Construct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD500 */
