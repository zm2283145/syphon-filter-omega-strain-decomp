#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Ctl { char pad[0x3524]; void* inv; } Ctl;
typedef struct Self { char pad[0x30]; Ctl* ctl; char pad2[0x1E0 - 0x34]; int* ref; } Self;
typedef struct Obj { char pad[0xC]; int id; } Obj;
struct Msg : CMsg { int a24; unsigned char a28; char p29[7]; };
struct Msg2 : Msg { int id; int m34; unsigned char m38; char p39[7]; V4 v; float f50; char p54[0xC]; };
extern int g_NoneWord;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0200[];
extern "C" {
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int*);
void QueueMessage_cMessageR_cSystemP_int_int(void*, void*, int, int);
int cWeapon_GetClipAmmo(void*, int);
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded address registers */
static inline void V4_Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" int cNetNPC_WeaponShoot(Self* self)
{
    if (self->ref) {
        int id = self->ref[2];
        Obj* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        Msg2 msg;
        V4 z;
        Msg2* m = &msg;
        z.x = 0; z.y = 0; z.z = 0; z.w = 0;
        cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
        m->vtable = D_004E0840;
        m->a24 = 0x3B;
        m->a28 = 0xB;
        m->vtable = D_004E0200;
        m->id = *(o ? &o->id : &g_NoneWord);
        m->m34 = -1;
        m->m38 = 0;
        V4_Copy(&m->v, &z);
        m->f50 = 0.0f;
        msg.kind = 1;
        QueueMessage_cMessageR_cSystemP_int_int(&msg, self->ctl, 0, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    if (cWeapon_GetClipAmmo(self->ctl->inv, 6) == 0) {
        Msg msg;
        Msg* m = &msg;
        cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
        m->vtable = D_004E0840;
        m->a24 = 0x3C;
        m->a28 = 0;
        QueueMessage_cMessageR_cSystemP_int_int(m, self->ctl, 0, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    return 1;
}


