/* Actor_UnlinkAll = cHuman::LetGoOfBodyBeingCarried. opt_propagation off keeps inline ctor 'this' in s0;
 * the empty member dtors on Arr7_L/Tail_L keep X_L's ctor 'this' live while X_L's own dtor (with
 * (char*)this+off forms) avoids the member null checks. Temporaries as args order the X/rate slots;
 * Name_L declared between the two messages orders the slots. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"

static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { int id; void* a; } Pair_L;
extern "C" {
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct Arr7_L { Pair_L p[7]; Arr7_L() { cArray_FixedSize_cSkaAnimEvent_7_ctor_void(this); } __declspec(weak) __declspec(MSG_DTOR) ~Arr7_L() {} };
struct Tail_L { char t[0x14]; Tail_L() { cArray_cTimedEvent_ctor_void(this); } __declspec(weak) __declspec(MSG_DTOR) ~Tail_L() {} };
struct X_L { unsigned char kind; Arr7_L pairs; Tail_L tail;
    X_L() : kind(0) {}
    __declspec(weak) __declspec(MSG_DTOR) ~X_L() { func_001BE5A0((char*)this + 0x3C, 0); __destroy_array((char*)this + 4, (void*)func_0018A210, 8, 7); } };
struct Rate_L { float x, y, z, w; Rate_L(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { void* lib; char pad4[0xFC]; char node[0x10]; } Sys_L;

struct Obj_L { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); char pad[0x2C]; int f30; };
struct Act_L;
struct Hdl { Act_L* volatile obj; int serial;
    int IsValid();
    Act_L* Raw() { return obj; } Act_L* Get() { return IsValid() ? Raw() : 0; }
    void Set(Act_L* l);
};
struct Act_L {
    char pad0[0xC]; int serial; char pad10[4]; unsigned char b14; char pad15[0x58 - 0x15];
    Obj_L* o58; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys;
    char pad2FD0[0x3254 - 0x2FD0];
    int f3254; char pad3258[4]; int f325C; char pad3260[0x3478 - 0x3260];
    Hdl carried;
};
inline int Hdl::IsValid() { Act_L* p = obj; unsigned char ok = 1; if (!IsNullNV(p) && !SameNV(p->serial, serial)) ok = 0; return ok; }
inline void Hdl::Set(Act_L* l) { int none; serial = *((obj = l) ? &l->serial : (none = -1, &none)); }

extern "C" {
extern char D_004FF2B0[]; extern char D_004DCD70[]; extern char D_004DCC70[];
extern char D_004EE960[]; extern char D_004DA890[];
void cSkaSystem_DetachChildrenAnchors_All(void* p);
void cTreeNode_cSkaSystemPtr_DetachChildren(void* p);
void cMessage_ctor_cMessageNameR(void* m, char* cls);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Act_L* a, Name_L* n, float* out, int x, int y);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
int cSkaAnimationSet_GetNode_cString16NR(void* lib, Name_L* n);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
void* func_0018C6A0(Sys_L* s);
void nSka_GetPlaybackGroupId(Y_L* y, int m);
void cSkaRequestStream_AddRequest(void* ctl, int id, int mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void Actor_UnlinkAll(Act_L* a);
}

struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char prio; char pad21[3]; int who; unsigned char picked; char pad29[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, (char*)t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct GobjMsg : MsgB {
    GobjMsg(int w) : MsgB(D_004FF2B0) { vtable = D_004DCD70; who = w; prio = 2; }
    __declspec(weak) __declspec(MSG_DTOR) ~GobjMsg() { vtable = D_004DCD70; }
};
struct BodyMovedMsg : GobjMsg {
    BodyMovedMsg(int w) : GobjMsg(w) { vtable = D_004DCC70; picked = 0; }
    __declspec(weak) __declspec(MSG_DTOR) ~BodyMovedMsg() { vtable = D_004DCC70; }
};
struct PickupMsg : MsgB {
    PickupMsg() : MsgB(D_004EE960) { vtable = D_004DA890; }
    __declspec(weak) __declspec(MSG_DTOR) ~PickupMsg() { vtable = D_004DA890; }
};

static inline void QZero_L(void* dd) { int n = 3; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}

static inline unsigned char IsPlayer_L(Act_L* h) { unsigned char r = 0; if (h->o58 && h->o58->IsPlayer()) r = 1; return r; }
static inline void Play_L(Sys_L* sys, Name_L* n, const Rate_L& r, const X_L& x)
{
    int mo = cSkaAnimationSet_GetNode_cString16NR(sys->lib, n);
    if (mo) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        ctl = func_0018C6A0(sys);
        nSka_GetPlaybackGroupId(&y, mo);
        cSkaRequestStream_AddRequest(ctl, mo, 1, (void*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline bool Bit4(int f) { return (f >> 4) & 1; }
static inline bool Skip_L(Act_L* a) { return Bit4(a->f325C) && !Bit4(a->f3254); }

void Actor_UnlinkAll(Act_L* a)
{
    Sys_L* s = &a->sys;
    cSkaSystem_DetachChildrenAnchors_All(s);
    cTreeNode_cSkaSystemPtr_DetachChildren(s->node);
    if (a->carried.Get()) {
        if (IsPlayer_L(a) && a->b14) {
            BodyMovedMsg m(a->o58->f30);
            m.prio = 2;
            QueueMessage_cMessageR_cSystemP_int(&m, a->carried.Get(), 0);
        }
        Name_L n;
        float dur;
        {
            PickupMsg m;
            QueueMessage_cMessageR_cSystemP_int(&m, a->carried.Get(), 0);
        }
        if (!Skip_L(a)) {
            QZero_L(&n);
            cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(a->carried.Get(), &n, &dur, 0, 0);
            Play_L(&a->carried.Get()->sys, &n, Rate_L(0.5f, 0.5f, 2.0f, 2.0f), X_L());
        }
        a->carried.Set(0);
    }
}
