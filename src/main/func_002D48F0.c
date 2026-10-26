/* cNetNPC_AimFire: NPC attack driver: send the "aim at target point" action,
 * fire a burst shot while burst rounds and the shot timer allow, otherwise
 * start a new burst (3..10 rounds) after the burst delay; then send the
 * "track target" action with the target id. */
#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
} __attribute__((aligned(16)));
struct Ctl { char p0[0xC]; unsigned short seed; };
struct Actor { char p0[0x3524]; void* inv; };
struct Self { char p0[0x30]; Ctl* ctl; char p34[0x84 - 0x34]; float burstWait; float shotWait; float shotDelay; char p90[0x1EC - 0x90]; unsigned short burst; };
class Tgt {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45();
    virtual V4 AimPoint(int bone);
    char p4[8]; int id;
};
struct MsgA : CMsg { int a24; unsigned char a28; char p29[7]; V4 v; };
struct MsgB : CMsg { int a24; unsigned char a28; char p29[3]; int id; };
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0140[], D_004E01A0[];
extern "C" {
void MsgQueue_QueueClone(void*, void*, int, int);
Actor* AiController_GetActor(Self*);
int Weapon_CanAttack(void*);
int cNetNPC_WeaponShoot(Self*);
void cNetNPC_AimFire(Self* s, Tgt* t);
}
/* GCC-style volatile lq/sq quad copy */
static inline void V4_Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

void cNetNPC_AimFire(Self* s, Tgt* t)
{
    {
        V4 p = t->AimPoint(-1);
        MsgA m;
        MsgA* pm = &m;
        Event_Construct(pm, g_ActorActionMsgClass);
        pm->vtable = D_004E0840;
        pm->a24 = 0x39;
        pm->a28 = 4;
        pm->vtable = D_004E0140;
        V4_Copy(&pm->v, &p);
        MsgQueue_QueueClone(&m, s->ctl, 1, 0);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
    if (s->burst > 0) {
        if (Weapon_CanAttack(AiController_GetActor(s)->inv) && s->shotWait <= 0.0f && cNetNPC_WeaponShoot(s)) {
            s->burst--;
            s->shotWait = s->shotDelay;
        }
    } else if (s->burstWait <= 0.0f) {
        s->burst = (s->ctl->seed & 7) + 3;
        s->burstWait = 4.0f * (0.2f + 0.01f * (float)(unsigned int)(s->ctl->seed & 0xF));
    }
    {
        MsgB m;
        MsgB* pm = &m;
        int* id = &t->id;
        Event_Construct(pm, g_ActorActionMsgClass);
        pm->vtable = D_004E0840;
        pm->a24 = 0x3E;
        pm->a28 = 5;
        pm->vtable = D_004E01A0;
        pm->id = *id;
        MsgQueue_QueueClone(pm, s->ctl, 1, 0);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
