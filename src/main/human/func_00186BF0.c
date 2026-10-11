#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V4_00186BF0 { __int128 q; V4_00186BF0() {} };
struct Att_00186BF0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual V4_00186BF0 GetPos();
};
struct Ctl_00186BF0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsPlayer(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual unsigned char FilterAnim(unsigned char a);
    char pad[0x1D6 - 4]; unsigned char b1D6;
};
struct Msg_00186BF0 { void* vt; char pad4[0x18]; int f1C; char pad20[4]; int kind; unsigned char b28; char pad29[3]; int anim; };
typedef struct { char d[0x9C]; } Str_00186BF0;
struct Snd_00186BF0 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00186BF0 s78;
    Str_00186BF0 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Npc_00186BF0 {
    char pad0[0x14]; unsigned char b14; char pad15[0x58 - 0x15]; Ctl_00186BF0* ctl; char pad5C[4]; char f60[0x3260 - 0x60];
    unsigned char b3260; char pad3261[0x3398 - 0x3261]; int f3398; char pad339C[0x33A4 - 0x339C]; unsigned char b33A4; unsigned char b33A5;
    char pad33A6[0x3524 - 0x33A6]; int f3524;
};
extern "C" {
extern char D_0055D480[];
extern char D_004E0840[];
extern char D_004E01E0[];
extern char D_004F0430[];
extern char D_004F00F0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void SoundEvent_CtorFromPreset(Snd_00186BF0* e, void* preset, void* owner);
void func_0036E220(Str_00186BF0* s, int flag);
void func_003CC990(Npc_00186BF0* self, int a, int b);
void func_0038CBF0(void* p);
void func_00143770(int a);
int func_00186950(Npc_00186BF0* self, V4_00186BF0* dir, int n);
void func_003CCAC0(Npc_00186BF0* self, int a1, Att_00186BF0* att, int a3, int type, V4_00186BF0* pos);
}
static inline Msg_00186BF0* Ctor_00186BF0(Msg_00186BF0* p)
{
    Event_Construct(p, D_0055D480);
    p->vt = D_004E0840;
    p->kind = 0x42;
    p->b28 = 2;
    return p;
}
static inline void Send_00186BF0(Msg_00186BF0* p, int anim, Npc_00186BF0* self)
{
    Event_Construct(p, D_0055D480);
    p->vt = D_004E0840;
    p->kind = 0x42;
    p->b28 = 2;
    p->vt = D_004E01E0;
    p->anim = anim;
    p->f1C = 0x40;
    Event_Send(p, self, 1);
}
#pragma opt_propagation off
extern "C" void func_00186BF0(Npc_00186BF0* self, int a1, Att_00186BF0* att, int a3, int type, V4_00186BF0* pos)
{
    if (self->b33A4) {
        func_003CC990(self, self->f3398, 0);
        func_0038CBF0(self->f60);
    } else if (self->b14) {
        int anim;
        char* snd;
        func_00143770(self->f3524);
        anim = 0;
        if (self->b3260 == 1)
            snd = D_004F0430;
        else
            snd = D_004F00F0;
        if ((unsigned char)type == 0xB) {
            anim = 8;
            snd = 0;
        } else if ((unsigned char)type == 0xC) {
            anim = 9;
        } else if ((unsigned char)type == 0xE) {
            anim = 0xA;
        } else if ((unsigned char)type == 0xF) {
            anim = 0xB;
        } else {
            V4_00186BF0 dir = att->GetPos();
            if (pos)
                V4Copy(&dir, pos);
            {
            int t = (unsigned char)type;
            if (t == 2 || t == 0xD) {
                anim = func_00186950(self, &dir, 4);
            } else if (t == 1) {
                anim = func_00186950(self, &dir, 6);
            } else if (a3 == 2) {
                anim = 1;
                snd = 0;
            }
            }
        }
        if (self->ctl) {
            anim = self->ctl->FilterAnim(anim);
            if (anim == 2 && a3 != 2) {
                unsigned char r = 0;
                Ctl_00186BF0* c = self->ctl;
                if (c && c->IsPlayer())
                    r = 1;
                if (r) {
                    Ctl_00186BF0* c2 = self->ctl;
                    c2->b1D6 = 1;
                }
            }
        }
        Msg_00186BF0 msg;
        int a = (unsigned char)anim;
        Msg_00186BF0* p = &msg;
        Event_Construct(p, D_0055D480);
        p->vt = D_004E0840;
        p->kind = 0x42;
        p->b28 = 2;
        p->vt = D_004E01E0;
        p->anim = a;
        msg.f1C = 0x40;
        Event_Send(p, self, 1);
        if (snd) {
            Snd_00186BF0 s;
            SoundEvent_CtorFromPreset(&s, snd, self);
            s.flag = 1;
            Event_Send(&s, D_004FFB50, 0);
            s.vt = D_004DAE30;
            func_0036E220(&s.s114, -1);
            func_0036E220(&s.s78, -1);
            cMessage_dtor(&s, 0);
        }
        func_003CCAC0(self, a1, att, a3, type, pos);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    self->b33A5 = 0;
}