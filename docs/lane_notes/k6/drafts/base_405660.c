#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
typedef unsigned long u64;
typedef __int128 u128;
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cBox {
    cVector min, max;
    void Reset() { min = cVector(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f); max = cVector(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f); }
    void Extend(const cVector& p) {
        cVector* lo = &min; cVector* hi = &max; const cVector* pp = &p;
        asm {
            lqc2 vf1, 0(lo)
            lqc2 vf2, 0(hi)
            lqc2 vf3, 0(pp)
            vmini.xyz vf1, vf1, vf3
            vmax.xyz vf2, vf2, vf3
            sqc2 vf1, 0(lo)
            sqc2 vf2, 0(hi)
        }
    }
};
struct S16 { char c[16]; } __attribute__((aligned(16)));
struct Monster {
    u128 blank, none, RACE_MASK, SEX_MASK, LEFT_MASK, NAME_MASK, SUB_MASK, TYPE_MASK, LOD_MASK, FULL_MASK, NAMEL_MASK, X_MASK;
    unsigned int monsterPartCount, monsterHandFaceCount, monsterCoreCount, manTexCount, texCoreCount;
    u128* savedPartNames;
    u128* savedTexNames;
    unsigned int savedPartCount, savedTexCount, swapRuleCount;
    void* swapRules;
    int sortRuleCount;
};
extern "C" {
extern S16 D_00493AC0, D_00493AD0;
extern int D_00571300;
extern char D_00571304[];
extern char D_004BE900[];
extern cVector* D_00571484;
extern cVector D_00571570[];
extern cBox D_005716C0;
void func_0036E5D0(void*);
void func_00407EC0(void*, int, void*);
Monster* Monster_ctor(Monster* self);
}
static inline u128 kpu(u64 hi, u128 lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kqq(u128 hi, u128 lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kfrom(u64 v) { u128 r; asm { pcpyld r, zero, v } return r; }
static inline u128 kpair(u128 hi, u128 lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kpair(u64 hi, u128 lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kpair(long hi, long lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kpair(u64 hi, long lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
static inline u128 kpair(u64 hi, u64 lo) { u128 r; asm { pcpyld r, hi, lo } return r; }
Monster* Monster_ctor(Monster* self)
{
    S16 blankName;
    S16 noneName;
    u64 RACE_MASK1, SEX_MASK2, LEFT_MASK2, NAME_MASK2, SUB_MASK1, SUB_MASK2, TYPE_MASK1, TYPE_MASK2, LOD_MASK1, LOD_MASK2, NAMEL_MASK2, X_MASK2;
    int j;
    func_0036E5D0((char*)self + 0x13410);
    func_0036E5D0((char*)self + 0x134AC);
    self->monsterPartCount = 0;
    self->monsterHandFaceCount = 0;
    self->monsterCoreCount = 0;
    self->manTexCount = 0;
    self->texCoreCount = 0;
    self->swapRuleCount = 0;
    self->savedPartNames = 0;
    self->savedTexNames = 0;
    self->sortRuleCount = 0;
    blankName = D_00493AC0;
    self->blank = *(u128*)&blankName;
    noneName = D_00493AD0;
    self->none = *(u128*)&noneName;
    RACE_MASK1 = 0xFF00;
    self->RACE_MASK = kpair(RACE_MASK1, (u128)0);
    SEX_MASK2 = 0xFF;
    self->SEX_MASK = kfrom(SEX_MASK2);
    LEFT_MASK2 = 0xFF0000000000;
    self->LEFT_MASK = kfrom(LEFT_MASK2);
    NAME_MASK2 = 0xFFFFFFFF00;
    self->NAME_MASK = kfrom(NAME_MASK2);
    SUB_MASK1 = 0xFF;
    SUB_MASK2 = 0xFFFF000000000000;
    self->SUB_MASK = kpu(SUB_MASK1, SUB_MASK2);
    TYPE_MASK1 = 0xFFFFFFFF0000;
    TYPE_MASK2 = 0;
    self->TYPE_MASK = kpair(TYPE_MASK1, TYPE_MASK2);
    LOD_MASK1 = 0xFF00FFFFFFFFFFFF;
    LOD_MASK2 = 0xFFFFFFFFFFFFFFFF;
    self->LOD_MASK = kqq(LOD_MASK1, LOD_MASK2);
    self->FULL_MASK = kpair(SUB_MASK1, (long)0xFFFF00FFFFFFFF00);
    NAMEL_MASK2 = 0xFFFFFFFFFF00;
    self->NAMEL_MASK = kfrom(NAMEL_MASK2);
    X_MASK2 = 0xFFFFFF00;
    self->X_MASK = kfrom(X_MASK2);
    D_00571300 = 1;
    func_00407EC0(D_00571304, 0xF, D_004BE900);
    D_00571484 = D_00571570;
    cVector boneScale(1.0f, 1.0f, 1.0f, 1.0f);
    for (j = 0; j < 21; j++) D_00571570[j] = boneScale;
    D_005716C0.Reset();
    D_005716C0.Extend(cVector(0.0f, 0.0f, 0.0f, 0.0f));
    return self;
}
