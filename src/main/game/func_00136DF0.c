/* World_Destruct: world destructor - frees the owned subsystems, then destroys the members and the base. */
#pragma cplusplus on
#include "alloc_guard.h"
struct VObj_36DF0 { virtual void Destroy(int f); };
typedef struct PtrVec_36DF0 { int unk0; int count; } PtrVec_36DF0;
typedef struct Guard_36DF0 { char d[0x10]; } Guard_36DF0;

typedef struct World_36DF0 {
    void* vt;
    char pad4[0x2C - 0x4];
    char m2C[0x3C - 0x2C];
    char m3C[0x54 - 0x3C];
    char m54[0x70 - 0x54];
    char m70[0x80 - 0x70];
    VObj_36DF0* p80;
    void* p84;
    void* p88;
    void* p8C;
    PtrVec_36DF0* objs;
    char pad94[0x9C - 0x94];
    char m9C[0xC4 - 0x9C];
    char mC4[0xDC - 0xC4];
    void* pDC;
    void* pE0;
    void* pE4;
    void* pE8;
    void* pEC;
    char padF0[0x1C8 - 0xF0];
    void* p1C8[4];
    char pad1D8[0x1E0 - 0x1D8];
    void* p1E0;
} World_36DF0;

extern "C" {
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
extern char D_0049A890[];
extern char D_004D9060[];
void Mem_Free(int pool, void* p, char* file, int line);
VObj_36DF0** PtrVec_At(PtrVec_36DF0* v, int i);
void func_002458E0(void* p, int f);
void func_00260B40(void* p, int f);
void WaterFx_Destroy(void* p, int f);
void func_00279D80(void* p, int f);
void func_001C3B00(void* p);
void func_00136DA0(Guard_36DF0* g);
void func_001378C0(void* p, int f);
void func_0012F530(Guard_36DF0* g, int f);
void TremorList_Free(void* p, int f);
void func_00147390(void* p, int f);
void func_00336460(void* p, int f);
void func_00136CD0(World_36DF0* w);
void func_00136BD0(World_36DF0* w);
void func_001309A0(World_36DF0* w);
void func_00130950(World_36DF0* w);
void func_00132A40(World_36DF0* w);
void func_00137840(void* p, int f);
void func_001377C0(void* p, int f);
void func_00137750(void* p, int f);
void String_Dtor(void* p, int f);
void func_00137670(void* p, int f);
void func_00137580(void* p, int f);
void ListReceiver_Dtor(World_36DF0* w, int f);
void operator_delete(void* p);
}

/* allocator lock taken without a guard object (no stack slot) */
#define LOCKC_36DF0() { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; }
#define UNLOCKC_36DF0() { if (g_ProfileLockEnabled) Alloc_Unlock(9); g_ProfileLockDepth--; }
#define DELETE_36DF0(p, dtor, line) \
    { void* q = (p); if (q) { LOCKC_36DF0() dtor(q, -1); Mem_Free(0, q, D_0049A890, line); UNLOCKC_36DF0() } }

extern "C" World_36DF0* World_Destruct(World_36DF0* self, short del)
{
    if (self) {
        self->vt = D_004D9060;
        DELETE_36DF0(self->pDC, func_002458E0, 0xCA)
        DELETE_36DF0(self->pE0, func_00260B40, 0xCD)
        DELETE_36DF0(self->pE4, WaterFx_Destroy, 0xCF)
        {
            void* q = self->pE8;
            if (q) { AllocGuard g; Mem_Free(0, q, D_0049A890, 0xD1); }
        }
        DELETE_36DF0(self->pEC, func_00279D80, 0xD3)
        if (self->objs) {
            int i;
            for (i = self->objs->count - 1; i >= 0; i--) {
                VObj_36DF0* q = *PtrVec_At(self->objs, i);
                AllocGuard g;
                q->Destroy(-1);
                Mem_Free(0, q, D_0049A890, 0xD7);
            }
        }
        {
            VObj_36DF0* q = self->p80;
            AllocGuard g;
            q->Destroy(-1);
            Mem_Free(0, q, D_0049A890, 0xD9);
        }
        {
            void* q = self->p88;
            AllocGuard g;
            if (q) func_001C3B00(q);
            Mem_Free(0, q, D_0049A890, 0xDA);
        }
        {
            /* this block's allocator guard was not inlined: explicit calls to its out-of-line ctor/dtor */
            Guard_36DF0 g;
            void* q = self->p84;
            func_00136DA0(&g);
            func_001378C0(q, -1);
            Mem_Free(0, q, D_0049A890, 0xDB);
            func_0012F530(&g, -1);
        }
        DELETE_36DF0(self->p8C, TremorList_Free, 0xDE)
        {
            void* q = self->p1E0;
            AllocGuard g;
            func_00147390(q, -1);
            Mem_Free(0, q, D_0049A890, 0xE0);
        }
        int i;
        void** pp;
        for (i = 0, pp = (void**)self; i < 4; i++, pp++) {
            void* q = pp[0x1C8 / 4]; /* self->p1C8[i] */
            if (q) {
                AllocGuard g;
                func_00336460(q, -1);
                Mem_Free(0, q, D_0049A890, 0xE4);
            }
        }
        func_00136CD0(self);
        func_00136BD0(self);
        func_001309A0(self);
        func_00130950(self);
        func_00132A40(self);
        /* member destructors (the null tests are the compiler's this-checks) */
        if (self->mC4) func_00137840(self->mC4, 0);
        if (self->m9C) func_001377C0(self->m9C, 0);
        if (self->m70) func_00137750(self->m70, -1);
        if (self->m54) String_Dtor(self->m54, 0);
        if (self->m3C) func_00137670(self->m3C, -1);
        if (self->m2C) func_00137580(self->m2C, -1);
        ListReceiver_Dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
