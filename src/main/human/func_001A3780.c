#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Actor_EnterDeadState: block actions, drop held items, clear motion state and broadcast the death message */
#define AP(o) (*(char**)(a + (o)))
#define PI(p, o) (*(int*)((char*)(p) + (o)))
#define PB(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define PF(p, o) (*(float*)((char*)(p) + (o)))
#define PP(p, o) (*(char**)((char*)(p) + (o)))
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
class VO {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual unsigned char IsHeld();
};
extern "C" {
extern signed char D_004E1D88;
extern V4 D_004E1D90;
extern char D_004DA950[];
extern char g_CasEventMsgClass[];
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper2(void* p, int index, int v);
unsigned char AnimPriority_Helper3(void* bits, int index);
void WeaponInv_ReleaseHeldObject(void* w);
void Npc_DeadStateDrop(char* a);
void Event_Construct(void* e, char* t);
void Event_Send(void* e, char* t, int f);
void cMessage_dtor(void* e, int f);
void Actor_EnterDeadState(char* a);
}
static inline void APri(char* a, int k, int on)
{
    char* p = a + 0x320C;
    unsigned char o = AnimPriority_Helper3(p + 0xC, k);
    AnimPriority_Helper2(p + 4, k, on);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, o);
}
/* second site: same as APri, with the Helper3 argument address formed before the index */
static inline void APri2(char* a, int k, int on)
{
    char* p = a + 0x320C;
    char* q = p + 0xC;
    unsigned char o;
    asm volatile { .set noreorder; .set reorder } // scheduling barrier: retail sets up a0 before a1 at this site
    o = AnimPriority_Helper3(q, k);
    AnimPriority_Helper2(p + 4, k, on);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, o);
}
static inline V4& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
static inline bool FTest(int w, int n) { return ((w >> n) & 1) != 0; }
struct Ev30 { char c[0x30]; };
struct V2 { float x, y; V2(float a, float b) { x = a; y = b; } };
// 128-bit lq/sq quadword copy idiom
static inline void GV(void* d0, void* s0) { void* d = d0; __int128 q; void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void SetF(char* p, float v) { *(float*)p = v; }
static inline void SetF2(char* p, float x, float y) { ((float*)p)[0] = x; ((float*)p)[1] = y; }

#pragma opt_propagation off
void Actor_EnterDeadState(char* a)
{
    APri(a, 27, 0);
    if (FTest(PI(a, 0x3210), 31)) return;
    APri2(a, 31, 1);
    WeaponInv_ReleaseHeldObject(AP(0x3524));
    if (!((VO*)AP(0x58))->IsHeld()) Npc_DeadStateDrop(a);
    GV(a + 0x31C0, &Zero());
    SetF(a + 0x31D0, 0.0f); SetF(a + 0x31D4, 0.0f);
    PB(a, 0x31B7) = 0;
    {
        Ev30 e;
        char* p = e.c;
        Event_Construct(p, g_CasEventMsgClass);
        PP(p, 0) = D_004DA950;
        PI(p, 0x24) = 16;
        PI(p, 0x28) = -1;
        PI(p, 0x2C) = 0;
        Event_Send(p, AP(0x58), 0);
        PP(&e, 0) = D_004DA950;
        cMessage_dtor(p, 0);
    }
    if (AP(0x3310)) {
        bool f = false;
        VO* o = (VO*)AP(0x58);
        if (o && o->IsHeld()) f = true;
        if (!f || !PB(a, 20)) { char* t = AP(0x3310); PB(t, 20) = 1; }
    }
}
