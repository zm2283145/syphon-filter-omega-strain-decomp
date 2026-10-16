/*
 * main/human: range (2 files, 00186BF0-00186F30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_00186BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void FileMan_Release(Str_00186BF0* s, int flag);
void Actor_SetHealth(Npc_00186BF0* self, int a, int b);
void func_0038CBF0(void* p);
void WeaponInv_ReleaseHeldObject(int a);
int Actor_ClassifyHitDirection(Npc_00186BF0* self, V4_00186BF0* dir, int n);
void Controller_DeathNotice(Npc_00186BF0* self, int a1, Att_00186BF0* att, int a3, int type, V4_00186BF0* pos);
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
extern "C" void Actor_Kill(Npc_00186BF0* self, int a1, Att_00186BF0* att, int a3, int type, V4_00186BF0* pos)
{
    if (self->b33A4) {
        Actor_SetHealth(self, self->f3398, 0);
        func_0038CBF0(self->f60);
    } else if (self->b14) {
        int anim;
        char* snd;
        WeaponInv_ReleaseHeldObject(self->f3524);
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
                anim = Actor_ClassifyHitDirection(self, &dir, 4);
            } else if (t == 1) {
                anim = Actor_ClassifyHitDirection(self, &dir, 6);
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
            FileMan_Release(&s.s114, -1);
            FileMan_Release(&s.s78, -1);
            cMessage_dtor(&s, 0);
        }
        Controller_DeathNotice(self, a1, att, a3, type, pos);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    self->b33A5 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00186BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00186BF0 */

/* merge_units: begin func_00186F30 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_00186F30 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer();
};
struct Act_00186F30 { char pad0[0xC]; unsigned int fC; int f10; unsigned char b14; char pad15[0x58 - 0x15]; Ctl_00186F30* ctl; };
struct Npc_00186F30 { char pad0[0xC]; int fC; char pad10[0x3488 - 0x10]; unsigned char b3488; };
struct Msg_00186F30 { void* vt; char pad4[0x18]; int f1C; unsigned char b20; char pad21[3]; Act_00186F30* att; unsigned char type; unsigned char sub; char pad2A[6]; };
extern "C" {
extern char D_004EF008[];
extern "C" void Message_GetScriptTypeKey();
extern "C" void cNetUpdateStatsMsg_dtor();
extern "C" void cNetUpdateStatsMsg_v01();
extern "C" void cNetUpdateStatsMsg_v04();
extern "C" void cNetUpdateStatsMsg_v05();
extern "C" void func_002823E0();
void * const D_004DA990[8] = { (void*)0x0, (void*)0x0, (void*)cNetUpdateStatsMsg_dtor, (void*)cNetUpdateStatsMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cNetUpdateStatsMsg_v04, (void*)cNetUpdateStatsMsg_v05 };
extern char D_004DCF10[];
void* Agent_GetSelected(void* a, int b);
void Stats_Add(void* ag, int a, int b);
int TeamTable_AreEnemies(Act_00186F30* att, Npc_00186F30* self);
int cAgentData_GetStat(void* ag, int stat);
void Actor_BuildVoiceKey(Act_00186F30* att, int k);
void Transport_Send(int a, void* m, int b, int c);
}
#pragma opt_propagation off
extern "C" void Actor_RecordDeathStats(Npc_00186F30* self, Act_00186F30* att, unsigned char type, int sub)
{
    if (att && *(Ctl_00186F30* volatile*)&att->ctl) {
        unsigned char r = 0;
        Ctl_00186F30* c = att->ctl;
        if (c && c->IsPlayer())
            r = 1;
        if (r) {
            if (att->b14) {
                void* ag = Agent_GetSelected(D_004FFB50, -1);
                Stats_Add(ag, 0, 1);
                if (!TeamTable_AreEnemies(att, self)) {
                    int k;
                    int st;
                    Stats_Add(ag, 7, 1);
                    st = cAgentData_GetStat(ag, 0x19);
                    k = 0x10;
                    switch (st) {
                    case 1: k = 0xC; break;
                    case 2: k = 0xE; break;
                    case 3: k = 0xF; break;
                    case 4: k = 0x11; break;
                    }
                    Actor_BuildVoiceKey(att, k);
                }
                if (type == 9) {
                    Stats_Add(ag, 1, 1);
                } else if (type == 4) {
                    if (self->b3488)
                        Stats_Add(ag, 4, 1);
                } else if (type == 2) {
                    Stats_Add(ag, 4, 1);
                } else if (type == 10) {
                    Stats_Add(ag, 3, 1);
                } else if (type != 5 && type != 9 && sub == 2) {
                    Stats_Add(ag, 2, 1);
                }
            } else {
                Msg_00186F30 m;
                Event_Construct(&m, D_004EF008);
                m.type = type;
                m.vt = ((char*)D_004DA990);
                m.sub = sub;
                m.f1C = 0x40;
                m.b20 = 4;
                m.att = att;
                Transport_Send(self->fC, &m, -1, ((att->fC & 0x7F000000) >> 24) - 1);
                m.vt = D_004DCF10;
                cMessage_dtor(&m, 0);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00186F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00186F30 */
