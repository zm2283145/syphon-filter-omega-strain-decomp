#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
};
static inline void Sub(const V* a, const V* b, V* c) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(a), "r"(c), "r"(b) : "memory"); }
struct Ctl { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int IsPlayer(); };
struct GObjV {
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
    virtual V GetPos();
};
struct Ref { int id; const int& Get() const { return id; } };
struct Obj : GObjV {
    char pad4[8];
    Ref ref;
    char pad10[4];
    unsigned char b14;
    char pad15[0x2C - 0x15];
    unsigned char b2C, b2D; bool b2E;
    char pad2F[0x40 - 0x2F];
    float health;
    char pad44[0x4C - 0x44];
    int classKey;
    char pad50[0x58 - 0x50];
    Ctl* ctl;
};
struct BlastMsg { void* vt; char base[0x18]; int size; unsigned char kind; char pad21[3]; int src; int dmg; float fdmg; float r0; float r1; int b38; int b3C; };
struct Handle { int a, b; };
struct It { Obj** p; };
struct Vec;
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_0051EE68[];
extern char D_004DE130[];
extern char D_004DAEB0[];
extern char D_004A4550[];
extern void* g_TremorList;
extern float D_0048A9A0;
extern float D_0048A9A8;
extern float D_0048A9B0;
extern int g_HumanActorClassKey;
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
void Transport_Send(int target, BlastMsg* msg, int a, int b);
void VisionFx_RequestFlash(void* fx, V* v, float a, float b, float c, float d);
void* World_GetActorArray(void);
Vec* cObjList_cGOBJPtr_GetList(void* arr);
void PtrVec_Begin(It* out, Vec* v);
void PtrVec_End(It* out, Vec* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It* out, It* in);
void* Mem_Alloc(int pool, int size, char* file, int line);
void SchedEvent_Init(void* e, int t, int a, int b);
void cSafePtr_cGOBJ_ctor_void(Handle* h);
void Ptr_Identity(V* v);
void ObjHandle_Set(Handle* h, Obj* o);
void Vec4_Copy(V* d, V* s);
void EventQueue_Admit(void* e);
}
struct BlastEvent {
    char base[8];
    void* vt;
    Handle tgt;
    int dmg;
    Handle src;
    unsigned char kind;
    char pad21[0xF];
    V pos;
};
static inline BlastEvent* NewBlast(int t, Obj* a, int dmg, Obj* src, unsigned char kind, V* pos)
{
    void* p;
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x40, D_004A4550, 0x1D4);
    }
    BlastEvent* e = (BlastEvent*)p;
    if (e) {
        SchedEvent_Init(e, t, 1, 0);
        e->vt = D_004DAEB0;
        cSafePtr_cGOBJ_ctor_void(&e->tgt);
        cSafePtr_cGOBJ_ctor_void(&e->src);
        Ptr_Identity(&e->pos);
        ObjHandle_Set(&e->tgt, a);
        e->dmg = dmg;
        ObjHandle_Set(&e->src, src);
        e->kind = kind;
        Vec4_Copy(&e->pos, pos);
    }
    return e;
}
static inline bool IsPlayer(Obj* o) { bool r = false; Ctl* c = o->ctl; if (c) { if (c->IsPlayer()) r = true; } return r; }
static inline bool Eq(It* a, It* b) { Obj** e = b->p; return a->p == e; }
static inline bool Ne(It* a, It* b) { return !Eq(a, b); }
static inline bool Standing(Obj* o) { bool r = false; if (o->b2D && o->b2C) r = true; return r; }
static inline bool Alive(Obj* o) { bool r = false; if (Standing(o) && ((o->b2E != 0) ^ 1)) r = true; return r; }
static inline bool DeadOk(void) { unsigned char r; if (g_IsMultiplayer) r = D_005721C0; else r = true; return r; }
static inline int HumanKey(void) { int* p = &g_HumanActorClassKey; return *p; }
static inline void GetBegin(It* o, Vec* v) { It tb; PtrVec_Begin(&tb, v); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(o, &tb); }
static inline void GetEnd(It* o, Vec* v) { It te; PtrVec_End(&te, v); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(o, &te); }
/* the extra inline level orders the iterator temps like retail */
static inline void GetBegin2(It* o, Vec* v) { GetBegin(o, v); }
static inline void GetEnd2(It* o, Vec* v) { GetEnd(o, v); }
#pragma opt_rotateloops off
extern "C" void Blast_Prepare(Obj* obj, int dmg, float fdmg, float r0, float r1, unsigned char flag, V* at, unsigned char skipHumans, int quiet)
{
    if (g_IsMultiplayer && !quiet) {
        BlastMsg msg;
        BlastMsg* p = &msg;
        Ref* r = &obj->ref;
        Event_Construct(p, D_0051EE68);
        p->vt = D_004DE130;
        p->src = r->Get();
        p->dmg = dmg;
        p->fdmg = fdmg;
        p->r0 = r0;
        p->r1 = r1;
        p->b38 = skipHumans;
        p->b3C = flag;
        msg.kind = 4;
        msg.size = 0x40;
        Transport_Send(0, &msg, -1, -1);
        msg.vt = D_004DE130;
        cMessage_dtor(&msg, 0);
    }
    V c(0.0f, 0.0f, 0.0f, 1.0f);
    if (at) {
        c = *at;
    } else if (obj) {
        V t = obj->GetPos();
        c = t;
    }
    void* fx = g_TremorList;
    VisionFx_RequestFlash(fx, &c, 1.0f, 1.0f, r0 * D_0048A9A0, r1 * D_0048A9A8);
    void* arr = World_GetActorArray();
    It it;
    It end;
    Obj* a;
    GetBegin2(&it, cObjList_cGOBJPtr_GetList(arr));
    bool local = !obj || obj->b14;
    while (GetEnd2(&end, cObjList_cGOBJPtr_GetList(arr)), Ne(&it, &end)) {
        a = *it.p;
        if (skipHumans && a->classKey == HumanKey()) goto next;
        if (!a) goto next;
        if (!Alive(a)) goto next;
        if (!(IsPlayer(a) ? a->b14 : local)) goto next;
        if ((int)a->health <= 0 && DeadOk()) goto next;
        {
            V e;
            V q = a->GetPos();
            V d;
            Sub(&q, &c, &d);
            e = d;
            float dist = e.Length();
            if (dist < r1) {
                float fd;
                float id;
                int kind;
                if (dist < r0) {
                    fd = fdmg;
                    id = (float)dmg;
                } else {
                    float t = 1.0f - (dist - r0) / (r1 - r0);
                    fd = fdmg * t;
                    id = (float)dmg * t;
                }
                if (fd <= 0.0f) {
                    kind = 0;
                } else if (!flag) {
                    kind = 0xD;
                } else {
                    kind = 2;
                }
                float delay = 1000.0f * (dist / D_0048A9B0);
                EventQueue_Admit(NewBlast((int)delay, a, (int)id, obj, kind, &c));
            }
        }
    next:
        it.p++;
    }
}
