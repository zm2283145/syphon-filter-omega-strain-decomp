/*
 * SFOGame/Source/NetNPC: 3 files, 002D4680-002D4760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D4680 */
#pragma push /* merge_units */
#include "types.h"
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, unsigned char a, int b, int c, int d);
typedef struct { char pad[0xC]; int c; } A5_002D4680_M;
typedef struct { char pad[0x30]; void* owner; char pad2[0x154 - 0x34]; float t; } A5_002D4680;
void cNetNPC_Sound(A5_002D4680* self, int v, A5_002D4680_M* m) {
    if (self->t <= 0.0f) {
        cNetNPCMsgs_SendMessage(self->owner, 0x3B, 8, v, m->c, 0, 0);
        self->t = 2.0f;
    }
}
static inline void merge_flush_func_002D4680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4680 */

/* merge_units: begin func_002D46E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M_46E0;
typedef struct { char pad[0x30]; char* p30; } N_46E0;
extern "C" void cMan_GetGunBarrelMatrix(M_46E0* out, void* p, unsigned char f);

extern "C" int cNetNPC_GetBulletDir(N_46E0* self, M_46E0* out, int flag)
{
    M_46E0 tmp; int r;
    __int128 qa; __int128 qb; M_46E0* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; cMan_GetGunBarrelMatrix(&tmp, self->p30 + 0x60, f); }
    s = &tmp; r = 1;
    asm {
        .set noreorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(out)
        lq qa, 0x20(s)
        sq qb, 0x10(out)
        lq qb, 0x30(s)
        sq qa, 0x20(out)
        sq qb, 0x30(out)
        .set reorder
    }
    return r;
}
static inline void merge_flush_func_002D46E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D46E0 */

/* merge_units: begin func_002D4760 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_002D4760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4760 */
