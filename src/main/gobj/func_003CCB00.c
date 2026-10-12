#pragma cplusplus on
#include "types.h"
struct Ctl_3CCB00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual int IsGod(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void OnHit(int attacker, int dmg); };
struct SelfV_3CCB00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual unsigned char State(); virtual void Kill(int dmg, int attacker, unsigned char p2, int p3, int p6); };
struct Self_3CCB00 : SelfV_3CCB00 { char pad4[0x10]; unsigned char b14; char pad15[0x2B]; float health; char pad44[0x14]; Ctl_3CCB00* ctl; };
typedef struct { void* vt; char base[0x1C]; unsigned char kind; char pad21[3]; int dmg; int attacker; char p3; char p2; char flag; char pad2F; } Msg_3CCB00;
extern "C" {
extern char D_004E08A0[];
extern char g_MsgLibDamageRequestKey[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
void Event_Construct(Msg_3CCB00* m, void* type);
void Event_Send(Msg_3CCB00* m, void* target, int f);
void cMessage_dtor(Msg_3CCB00* m, int f);
}
static inline unsigned char IsGod_3CCB00(Self_3CCB00* self)
{
    unsigned char r = 0;
    Ctl_3CCB00* c = self->ctl;
    if (c && c->IsGod()) r = 1;
    return r;
}
extern "C" int Actor_ApplyContactDamage(Self_3CCB00* self, int attacker, int p2, int p3, int p4, int flag, int p6, float dmg)
{
    if (!attacker) return 0;
    if (!(self->health <= 0.0f)) {
        int idmg;
        Msg_3CCB00 m;
        if (!D_005721C8 || !IsGod_3CCB00(self)) self->health = self->health - dmg;
        Event_Construct(&m, g_MsgLibDamageRequestKey);
        idmg = (int)dmg;
        m.attacker = attacker;
        m.vt = D_004E08A0;
        m.p3 = p3;
        m.p2 = p2;
        m.dmg = idmg;
        m.flag = 1;
        if (D_005721C8) {
            if (self->ctl == 0 && flag == 0) {
                m.kind = 2;
                m.flag = 0;
                Event_Send(&m, self, 0);
            } else if ((self->b14 && self->ctl) || (!self->ctl && flag)) {
                m.kind = 2;
                Event_Send(&m, self, 0);
            }
        } else {
            Event_Send(&m, self, 0);
        }
        if ((int)self->health <= 0) {
            self->health = 0.0f;
            self->Kill(idmg, attacker, p2, p3, p6);
        } else if (self->ctl && attacker != (int)self) {
            self->ctl->OnHit(attacker, idmg);
        }
        m.vt = D_004E08A0;
        cMessage_dtor(&m, 0);
    } else if (D_005721C8) {
        int v = D_005721C8 ? D_005721C0 : 1;
        if (!v && !self->ctl && !flag) {
            Msg_3CCB00 m2;
            Event_Construct(&m2, g_MsgLibDamageRequestKey);
            m2.attacker = attacker;
            m2.vt = D_004E08A0;
            m2.p3 = p3;
            m2.p2 = p2;
            m2.dmg = (int)dmg;
            m2.flag = 1;
            m2.kind = 2;
            m2.flag = 0;
            Event_Send(&m2, self, 0);
            m2.vt = D_004E08A0;
            cMessage_dtor(&m2, 0);
        }
    }
    return self->State() == 3;
}