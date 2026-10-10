#include "types.h"
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
extern F6Sel* func_003AD3A0(void* arr);
extern signed char D_00542B70;
extern char D_00542B78[];
extern F6Sel D_00542B90;
extern void TransitionReq_Reset(void*);
extern void func_0018A700(void*, int);
extern void AnimEvent_Construct(void*);
extern void func_001A1500(void*);
extern void TransitionReq_Construct(void*, float);
extern void __register_global_object(void*, void*, void*);
extern void func_00397400(void);
#pragma opt_propagation off
F6Sel* AnimCtl_GetSelected(F6Ctl* c)
{
    if (c->n44) {
        return func_003AD3A0(c->a30);
    }
    if (c->n2C) {
        return func_003AD3A0(c->a18);
    }
    if (!D_00542B70) {
        F6Sel* s = &D_00542B90;
        D_00542B90.b0 = 0;
        D_00542B90.b1 = 0;
        D_00542B90.i4 = 0;
        TransitionReq_Reset(D_00542B90.req);
        func_0018A700(D_00542B90.x1C, -1);
        AnimEvent_Construct(D_00542B90.ev1);
        AnimEvent_Construct(D_00542B90.ev2);
        func_001A1500(s->x94);
        s->fE0 = -1.0f;
        s->iE4 = 0;
        TransitionReq_Construct(s->trans, 0.0f);
        __register_global_object(s, func_00397400, D_00542B78);
        D_00542B70 = 1;
    }
    return &D_00542B90;
}