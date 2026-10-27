#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
/* cNetPlayer_AimWeapon: objective-marker update - tell the marker's target to show the tracked actor
   (or the fixed objective position once done), or to hide, then refresh the marker if its
   objective state changed. */
struct V4 { float x, y, z, w; V4() {} V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
struct Info { unsigned char dead; char p1[0xB]; signed char id; char pD[3]; float x, y, z; };
struct Flags { char p0[5]; unsigned char b5; };
struct Act { char p0[0xC]; int serial; char p10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; int& Serial() { return serial; } };
struct Obj { char p0[0x44]; Info* info; Flags* flags; void* target; };
extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E01A0[], D_004E0200[], D_004E0140[], D_004D9320[];
extern unsigned char D_0048C428[], D_0048C430[];
extern signed char D_004E1D88;
extern V4 D_004E1D90;
int cAimWeapon_GetFireWeapon(Flags* f);
void cNetPlayer_WeaponShoot(Obj* o);
void cNetPlayer_AimWeapon(Obj* o, Act* a);
}
static inline const V4& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return D_004E1D90;
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
static inline const int& Serial(Act* a) { return a->serial; }
struct MsgSerial : MsgI { int serial; MsgSerial(const int& s) : MsgI(62, 5) { vtable = D_004E01A0; serial = s; } __declspec(weak) __declspec(MSG_DTOR) ~MsgSerial() {} };
struct MsgTrack : MsgI { int pad2C; int val; int id; unsigned char m38; char p39[7]; V4 v; float f50; char p54[0xC];
    MsgTrack(const int& s, int i) : MsgI(57, 11) { vtable = D_004E0200; { const V4* z = &Zero(); val = s; id = i; m38 = 0; V4_Copy(&v, z); f50 = 0.0f; } } __declspec(weak) __declspec(MSG_DTOR) ~MsgTrack() {} };
struct MsgPos : MsgI { int pad2C; V4 v; MsgPos(const V4& p) : MsgI(57, 4) { vtable = D_004E0140; V4_Copy(&v, &p); } __declspec(weak) __declspec(MSG_DTOR) ~MsgPos() {} };
/* the message ctors take references: MW binds them lazily, so the loads land after cMessage_ctor_cMessageNameR as in retail */
struct MsgHide : MsgI { unsigned char b; char p2D[3]; MsgHide(const unsigned char& x) : MsgI(57, 1) { vtable = D_004D9320; b = x; } __declspec(weak) __declspec(MSG_DTOR) ~MsgHide() {} };

static inline unsigned char Alive(Act* a)
{
    unsigned char r = 0;
    unsigned char f = 0;
    if (a->b2D && a->b2C)
        f = 1;
    if (f && ((a->b2E != 0) ^ 1))
        r = 1;
    return r;
}

void cNetPlayer_AimWeapon(Obj* o, Act* a)
{
    if (o->info && ((a && Alive(a)) || o->info->dead) && o->flags) {
        if (o->info->dead || (o->flags->b5 && a)) {
            if (!o->info->dead) {
                {
                    MsgSerial m(a->Serial());
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
                {
                    MsgTrack m(a->Serial(), o->info->id);
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
            } else {
                {
                    MsgI m(63, 0);
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
                {
                    V4 pos(o->info->x, o->info->y, o->info->z, 1.0f);
                    {
                        MsgPos m(pos);
                        QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                    }
                }
            }
        } else {
            {
                MsgI m(63, 0);
                QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
            }
            {
                MsgHide m(D_0048C428[0]);
                QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
            }
        }
    } else {
        {
            MsgI m(63, 0);
            QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
        }
        {
            MsgHide m(D_0048C430[0]);
            QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
        }
    }
    if (o->flags && cAimWeapon_GetFireWeapon(o->flags))
        cNetPlayer_WeaponShoot(o);
}
