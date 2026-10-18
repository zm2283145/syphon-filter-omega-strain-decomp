/* Npc_ConstructSpawned / Actor_Construct2: the two NPC constructors of this unit. They share one
   member-initialisation body; the first allocates its object id (category 69), the second takes it. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on

template <int O, class T> struct At_1B7B00 { char pad[O]; T v; };
#define W_(p, o) (((At_1B7B00<o, int>*)(p))->v)
#define F_(p, o) (((At_1B7B00<o, float>*)(p))->v)
#define B_(p, o) (((At_1B7B00<o, unsigned char>*)(p))->v)

typedef struct V4_1B7B00 { float x, y, z, w; } __attribute__((aligned(16))) V4_1B7B00;
typedef struct Pair_1B7B00 { V4_1B7B00 a, b; } Pair_1B7B00;
typedef struct Blk_1B7B00 { __int128 q[68]; } Blk_1B7B00;
typedef struct Sub60_1B7B00 { char pad[64]; Blk_1B7B00 blk; } Sub60_1B7B00;

extern "C" {
extern char D_0049D010[];
extern char D_0049D8D0[];
extern char D_004DA690[];
extern char D_004DA2F0[];
extern char D_004DA7B8[];
extern char D_004DA7A8[];
extern int D_004BDD00;
extern int D_004EE968;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_00533880;
extern int D_00533888;
void IdMgr_Allocate(int* id, int cat);
void Actor_Construct(void* self, int* id, char* name);
void func_001B7AE0(void* p);
V4_1B7B00* Vec4_GetZero(void);
void Vec4_Assign(void* d, V4_1B7B00* s);
void AngleCurve_Construct(void* p);
void func_001B79F0(void* p);
void Curve_Construct(void* p);
int func_001B7940(void* p, float a, float b);
void AngleCurve_SetDamping(void* p, float d);
void VecCurve_SetDamping(void* p, float d);
void func_001B78F0(void* p, int v);
void func_001B75B0(void* p, int v);
void func_001B7580(void* p, int v);
void func_00136540(void* p, int* a, int* b);
void func_001364B0(void* p);
void cCheckpoint_ctor(void* p);
void Root_BaseConstruct(Pair_1B7B00* p);
void VecPair_Copy(void* d, Pair_1B7B00* s);
void Vec4_SetOrigin(V4_1B7B00* v);
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* WeaponInv_Construct(void* p, void* owner, int local);
void NetGame_InitLocalSlot(int* slot, int session);
int Npc_Initialize(void* a, void* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label);
void* Npc_ConstructSpawned(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int flag, int tag);
void* Actor_Construct2(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int* idp, int flag, int tag, Blk_1B7B00* src);
}

struct Obj_1B7B00 { char pad[12]; int id; };
struct Hd_1B7B00 { Obj_1B7B00* p; int id; };
static inline void Set_1B7B00(Hd_1B7B00* h, Obj_1B7B00* o)
{
    int d;
    h->p = o;
    h->id = *(o ? &o->id : (d = -1, &d));
}
struct V4q_1B7B00 {
    float x, y, z, w;
    V4q_1B7B00() {}
    V4q_1B7B00(const V4q_1B7B00& o) { V4q_1B7B00* pd = this; const V4q_1B7B00* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V4q_1B7B00& operator=(const V4q_1B7B00& o) { V4q_1B7B00* pd = this; const V4q_1B7B00* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
static inline float Dot_1B7B00(const V4q_1B7B00* a, const V4q_1B7B00* b)
{
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline void Tag_1B7B00(char* t, int tag) { *(int*)t = tag; F_(t, 4) = -1.0f; F_(t, 8) = 36.69f; B_(t, 12) = 0; }
/* the original copies the block with this inline-asm quadword loop */
static inline void QCopyN_1B7B00(void* dd, void* ss, int nn)
{
    void* d = dd; int n = nn; void* s = ss; __int128 q;
    asm {
        .set noreorder
    lp:
        lq q, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq q, -0x10(d)
        .set reorder
    }
}
static inline void Body_1B7B00(void* self, int x, unsigned char type, int flag, int tag, int line)
{
    V4q_1B7B00 o;
    V4q_1B7B00 n;
    V4q_1B7B00 z;
    {
        char* a = (char*)self + 12336;
        func_001B7AE0(a);
        B_(a, 12) = 1;
        Vec4_Assign(a + 16, Vec4_GetZero());
        AngleCurve_Construct(a + 32);
        func_001B79F0(a + 88);
        W_(a, 108) = 0;
        W_(a, 112) = 0;
        W_(a, 116) = 0xFF7FFFFF;
        W_(a, 120) = 0;
        B_(a, 124) = 0;
        B_(a, 125) = 0;
        Vec4_Assign(a + 128, Vec4_GetZero());
        W_(a, 144) = 0;
        Vec4_Assign(a + 160, Vec4_GetZero());
        W_(a, 176) = 0;
        Curve_Construct(a + 192);
        B_(a, 384) = 0;
        B_(a, 385) = 0;
        B_(a, 386) = 0;
        B_(a, 387) = 0;
        B_(a, 388) = 0;
        B_(a, 389) = 0;
        B_(a, 390) = 0;
        B_(a, 391) = 0;
        Vec4_Assign(a + 400, Vec4_GetZero());
        W_(a, 416) = 0;
        W_(a, 420) = 0;
        W_(a, 424) = 0;
        B_(a, 428) = 1;
        B_(a, 429) = 0;
        W_(a, 432) = 0;
        W_(a, 104) = func_001B7940(a, 0.0f, -1.0f);
        AngleCurve_SetDamping(a + 32, 15.0f);
        VecCurve_SetDamping(a + 192, 10.0f);
    }
    *(char**)self = D_004DA690;
    Tag_1B7B00((char*)self + 12784, tag);
    {
        char* b = (char*)self + 12800;
        func_001B78F0(b, 0);
        func_001B78F0(b + 4, 0);
        func_001B78F0(b + 8, 0);
    }
    {
        char* c = (char*)self + 12812;
        func_001B75B0(c, 0);
        func_001B75B0(c + 20, 0);
        func_001B75B0(c + 40, 0);
        func_001B7580(c + 60, 0);
        func_001B7580(c + 68, 0);
        func_001B7580(c + 76, 0);
    }
    B_(self, 12896) = 0;
    B_(self, 12904) = 0;
    B_(self, 12905) = 0;
    B_(self, 12906) = 0;
    {
        char* d = (char*)self + 12960;
        int t1;
        int t2;
        t2 = 0;
        t1 = 0;
        func_00136540(d, &t1, &t2);
        *(char**)d = D_004DA2F0;
        W_(d, 32) = 0;
        Vec4_Assign(d + 48, Vec4_GetZero());
        func_001364B0(d + 64);
        W_(d, 96) = 0;
    }
    W_(self, 13072) = 0;
    W_(self, 13076) = 0;
    W_(self, 13216) = 0;
    B_(self, 13220) = 0;
    B_(self, 13221) = 0;
    W_(self, 13224) = 0;
    W_(self, 13228) = 0;
    W_(self, 13232) = 0;
    W_(self, 13236) = 0;
    W_(self, 13260) = D_004BDD00;
    W_(self, 13264) = 0;
    W_(self, 13268) = 0;
    W_(self, 13272) = 0;
    W_(self, 13276) = 0;
    W_(self, 13280) = 0;
    B_(self, 13284) = 0;
    B_(self, 13285) = 0;
    B_(self, 13286) = 0;
    B_(self, 13288) = 0;
    cCheckpoint_ctor((char*)self + 13296);
    { int x; int* px = &x; (void)px; } /* dead address-taken local: reserves the retail stack slot between t2 and the handle temporary */
    W_(self, 13412) = 0;
    B_(self, 13416) = 0;
    W_(self, 13428) = 0;
    ((Hd_1B7B00*)((char*)self + 13432))->id = -1;
    Set_1B7B00((Hd_1B7B00*)((char*)self + 13432), 0);
    W_(self, 13444) = -2;
    W_(self, 13440) = 0;
    B_(self, 13456) = 0;
    {
        Pair_1B7B00 pr;
        Root_BaseConstruct(&pr);
        VecPair_Copy((char*)self + 13472, &pr);
    }
    {
        V4_1B7B00 org;
        Vec4_SetOrigin(&org);
        Vec4_Assign((char*)self + 13504, &org);
    }
    Vec4_Assign((char*)self + 13520, Vec4_GetZero());
    W_(self, 13588) = -1;
    *(signed char*)((char*)self + 13592) = -1;
    W_(self, 13596) = 0;
    W_(self, 13600) = 0;
    W_(self, 13616) = (int)D_004DA7B8;
    W_(self, 13616) = (int)D_004DA7A8;
    W_(self, 13620) = 0;
    B_(self, 13625) = 0;
    B_(self, 13626) = 0;
    W_(self, 13628) = 0;
    F_(self, 13632) = 1.0f;
    W_(self, 13636) = 0;
    W_(self, 13640) = x;
    {
        int* h = (int*)((char*)self + 13644);
        do {
            h[1] = -2;
            h[0] = 0;
            h += 2;
        } while (h != (int*)((char*)self + 13668));
    }
    n.x = 0.0f;
    n.z = 1.0f;
    n.y = 0.0f;
    n.w = 0.0f;
    {
        V4q_1B7B00* pz = &z;
        asm { sqc2 vf0, 0x0(pz) }
    }
    o = z;
    {
        float d = Dot_1B7B00(&n, &o);
        { float x, y, z2, w; z2 = n.z; y = n.y; x = n.x; w = -d; F_(self, 13680) = x; F_(self, 13684) = y; F_(self, 13688) = z2; F_(self, 13692) = w; }
    }
    W_(self, 13696) = 0;
    W_(self, 13700) = 0;
    W_(self, 13716) = 0;
    B_(self, 13720) = flag ? true : false;
    {
        void* p;
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        p = Mem_Alloc(0, 248, D_0049D8D0, line);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        if (p) { int l = type == 1; if (!l) l = type == 3; p = WeaponInv_Construct(p, self, l); }
        W_(self, 13604) = (int)p;
        W_(self, 13620) = W_(self, 13604);
    }
}

void* Npc_ConstructSpawned(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int flag, int tag)
{
    int id;
    IdMgr_Allocate(&id, 69);
    Actor_Construct(self, &id, D_0049D010);
    Body_1B7B00(self, x, type, flag, tag, 540);
    if (flag) {
        int s = D_005721A8;
        int id = 0;
        if (D_005721C8) {
            if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, s);
            id = D_00494178;
        } else {
            asm { .set reorder } /* scheduling barrier: keeps the empty else block (b + nop) */
        }
        W_(self, 12) |= (id + 1) << 24;
    }
    if (((At_1B7B00<12784, unsigned int>*)self)->v == (unsigned int)-1) {
        if (type == 2 || type == 4) {
            ((At_1B7B00<12784, unsigned int>*)self)->v = D_004EE968;
            D_004EE968 = D_004EE968 + 1;
        }
    }
    Npc_Initialize(self, mtx, name, health, 0, weap, flag, type, label);
    W_(self, 48) = 1;
    return self;
}

void* Actor_Construct2(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int* idp, int flag, int tag, Blk_1B7B00* src)
{
    Actor_Construct(self, idp, D_0049D010);
    Body_1B7B00(self, x, type, flag, tag, 448);
    if (src) {
        { Sub60_1B7B00* sb = (Sub60_1B7B00*)((char*)self + 96); QCopyN_1B7B00(&sb->blk, src, 68); }
        name = 0;
    }
    if (type == 3 || type == 4)
        B_(self, 20) = 0;
    if (((At_1B7B00<12784, unsigned int>*)self)->v == (unsigned int)-1) {
        if (type == 2 || type == 4) {
            ((At_1B7B00<12784, unsigned int>*)self)->v = D_004EE968;
            D_004EE968 = D_004EE968 + 1;
        }
    }
    Npc_Initialize(self, mtx, name, health, 0, weap, flag, type, label);
    W_(self, 48) = 1;
    return self;
}
