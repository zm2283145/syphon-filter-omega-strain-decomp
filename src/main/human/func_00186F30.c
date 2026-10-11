#pragma cplusplus on
#include "types.h"
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
extern char D_004FFB50[];
extern char D_004EF008[];
extern char D_004DA990[];
extern char D_004DCF10[];
void* Agent_GetSelected(void* a, int b);
void func_00333F10(void* ag, int a, int b);
int func_003CC8E0(Act_00186F30* att, Npc_00186F30* self);
int cAgentData_GetStat(void* ag, int stat);
void func_0018C770(Act_00186F30* att, int k);
void Event_Construct(void* m, void* type);
void Transport_Send(int a, void* m, int b, int c);
void cMessage_dtor(void* m, int flags);
}
#pragma opt_propagation off
extern "C" void func_00186F30(Npc_00186F30* self, Act_00186F30* att, unsigned char type, int sub)
{
    if (att && *(Ctl_00186F30* volatile*)&att->ctl) {
        unsigned char r = 0;
        Ctl_00186F30* c = att->ctl;
        if (c && c->IsPlayer())
            r = 1;
        if (r) {
            if (att->b14) {
                void* ag = Agent_GetSelected(D_004FFB50, -1);
                func_00333F10(ag, 0, 1);
                if (!func_003CC8E0(att, self)) {
                    int k;
                    int st;
                    func_00333F10(ag, 7, 1);
                    st = cAgentData_GetStat(ag, 0x19);
                    k = 0x10;
                    switch (st) {
                    case 1: k = 0xC; break;
                    case 2: k = 0xE; break;
                    case 3: k = 0xF; break;
                    case 4: k = 0x11; break;
                    }
                    func_0018C770(att, k);
                }
                if (type == 9) {
                    func_00333F10(ag, 1, 1);
                } else if (type == 4) {
                    if (self->b3488)
                        func_00333F10(ag, 4, 1);
                } else if (type == 2) {
                    func_00333F10(ag, 4, 1);
                } else if (type == 10) {
                    func_00333F10(ag, 3, 1);
                } else if (type != 5 && type != 9 && sub == 2) {
                    func_00333F10(ag, 2, 1);
                }
            } else {
                Msg_00186F30 m;
                Event_Construct(&m, D_004EF008);
                m.type = type;
                m.vt = D_004DA990;
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