/* NpcPerception_AddAwareness: find or create the awareness record for an
 * object, apply the cause-specific delay/salience, refresh its handle and
 * last seen position, and announce new human pickups once. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; const V* s = &o; Q16(d, s); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } };
struct AObj {
    void** vt; char p04[8]; int id; char p10[0x1C];
    unsigned char enabled, activated, removed; char p2F[0x1D];
    int team; char p50[0x3468 - 0x50]; unsigned char human;
};
struct ObjV;
struct ARec {
    void* obj; int id; int id2; char p0C[4]; V lastPos; unsigned char cause; char p21[3];
    float age, since7, visibility, threat, salience; unsigned char inView, lineClear, seenFlag, sent, f3C;
};
struct RNode { int p0; RNode* next; ARec* value; };
struct Perc { char p0[0x30]; char recs[0xC]; void* component; };
extern "C" {
void Alloc_Lock(int);
void Alloc_Unlock(int);
void* Mem_Alloc(int, int, void*, int);
void Event_Construct(void*, void*);
void Event_Send(void*, void*, int);
void cMessage_dtor(void*, int);
void NpcPerception_FindRecord(RNode** out, void* map, AObj* key);
void func_0016BB80(void*, void*);
void func_0016BB90(void*, void*);
void List_PushBack_16CEE0(void* list, ARec* const* v);
extern char D_0049C650[];
extern int g_HumanActorClassKey;
extern char D_004DCD70[], D_004DCBD0[];
extern char g_AIPickupableAwarenessMsgKey[];
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
}
#include "vslot_pad.h"
struct ObjVt { VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V Pos(int); VPAD4(e) virtual int D4(); VPAD4(f) virtual M Mtx(); VPAD2(g) VPAD1(h) virtual int Type(void*); VPAD2(i) VPAD1(j) virtual unsigned char Life(); };
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB { void* vt;
    MsgB(void* k) { Event_Construct(this, k); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); } };
struct MsgPick : MsgB { char p04[0x1C]; unsigned char kind; char p21[3]; AObj* obj;
    MsgPick(AObj* o) : MsgB(g_AIPickupableAwarenessMsgKey) { vt = D_004DCD70; obj = o; kind = 2; vt = D_004DCBD0; }
    void Send(void* to) { Event_Send(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgPick() { vt = D_004DCD70; } };
static inline bool Active(AObj* p) { return p->activated && p->enabled && !p->removed; }
static inline bool Human(AObj* o) { bool r = false; bool a = Active(o); if (a && o->human) r = true; return r; }
static inline int Key0() { int* p = &g_HumanActorClassKey; return *p; }
static inline const int& IdOf(AObj* p) { if (p) return p->id; int m = -1; return m; }
static inline ARec* NewRec() {
    void* m;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    m = Mem_Alloc(0, 0x40, D_0049C650, 0x33E);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    if (m) { ARec* r = (ARec*)m; r->id = -2; r->obj = 0; r->id2 = -1; }
    return (ARec*)m;
}
static inline void SetId2(ARec* r, AObj* o) { r->id2 = o->id; }
/* The end-iterator helpers nest three deep so its temp lands below the IdOf temp, as in retail. */
/* Retail reserves an unused slot above the IdOf temp; a dead address-taken local reproduces it. */
static inline void Set(ARec* r, AObj* o) { int u; int* pu = &u; r->obj = o; r->id = IdOf(o); }
static inline void En2(void* recs, RNode** e) { void* s; func_0016BB80(&s, recs); func_0016BB90(e, &s); }
static inline void En1(void* recs, RNode** e) { En2(recs, e); }
static inline void En0(void* recs, RNode** e) { En1(recs, e); }

extern "C" void NpcPerception_AddAwareness(Perc* self, AObj* who, unsigned char cause, float amt)
{
    RNode* it;
    ARec* rec;
    RNode* end;
    bool human;
    NpcPerception_FindRecord(&it, self->recs, who);
    human = false;
    if (((ObjVt*)who)->Life() == 3) {
        if (who->team == Key0()) human = Human(who);
        if (!human) return;
    }
    En0(self->recs, &end);
    if (it != end) {
        rec = it->value;
        if (rec->lineClear) rec->seenFlag = 1;
        if (rec->age < 0.0f) return;
    } else {
        rec = NewRec();
        rec->inView = 0;
        rec->lineClear = 0;
        rec->seenFlag = 0;
        rec->visibility = 0.0f;
        rec->threat = 0.0f;
        rec->salience = 0.0f;
        rec->sent = 0;
        rec->f3C = 0;
        List_PushBack_16CEE0(self->recs, &rec);
    }
    rec->age = 0.0f;
    if (cause == 6) {
        rec->inView = 1;
        rec->lineClear = 1;
        rec->seenFlag = 1;
    } else if (cause == 4) {
        rec->salience = 0.2f;
        if (!rec->lineClear || !rec->inView) {
            if (!(amt <= 25.0f)) rec->age = -amt / 500.0f;
        }
    } else if (cause == 8) {
        rec->salience = 1.0f;
    } else if (cause == 7) {
        rec->salience = 5.0f;
        rec->age = -1.0f;
    }
    Set(rec, who);
    SetId2(rec, who);
    rec->lastPos = ((ObjVt*)who)->Mtx().T();
    rec->cause = cause;
    if (human && !rec->sent) {
        MsgPick(who).Send(self->component);
        rec->sent = 1;
    }
}
