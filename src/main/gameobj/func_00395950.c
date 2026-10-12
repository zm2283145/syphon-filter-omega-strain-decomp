#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BC430[];
extern char D_004DF970[];
void Mem_Free(int heap, void* p, char* file, int line);
void cGOBJ_dtor(void* self, int flag);
void func_0036D5D0(void* p, int flag);
void func_0036E220(void* p, int flag);
void func_00377BD0(void* p, int flag);
void func_003C1790(void* p);
void operator_delete(void* p);
}
static inline void DelA_00395950(void* p, int line) { AllocGuard g; func_0036E220(p, -1); Mem_Free(0, p, D_004BC430, line); }
static inline void DelB_00395950(void* p, int line) { AllocGuard g; func_00377BD0(p, -1); Mem_Free(0, p, D_004BC430, line); }
struct S_00395950 {
    void* vt; char pad4[0x5C]; int i60; int i64; void* p68; char pad6c[4]; void* p70; char m74[0x1E0 - 0x74];
    void* p1E0; void* p1E4; void* p1E8; void* p1EC; char pad1f0[2]; unsigned char b1F2;
};
extern "C" S_00395950* cVUM_GOBJ_dtor(S_00395950* self, short flag)
{
    if (self) {
        self->vt = D_004DF970;
        if (self->i64 == 0 && self->b1F2) {
            DelA_00395950(self->p1E0, 0x3B);
            self->p1E0 = 0;
        } else if (self->i64) {
            self->p1E0 = 0;
        }
        if (self->i60 == 0) {
            DelB_00395950(self->p68, 0x44);
            { void* q = self->p70; if (q) { { AllocGuard g; if (q) func_003C1790(q); Mem_Free(0, q, "collision.hh", 0x506); } self->p70 = 0; } }
            if (self->p1E0) DelA_00395950(self->p1E0, 0x49);
            DelA_00395950(self->p1E8, 0x4B);
            DelA_00395950(self->p1E4, 0x4C);
            DelA_00395950(self->p1EC, 0x4D);
        }
        self->p68 = 0;
        self->p1E0 = 0;
        self->p1E8 = 0;
        self->p1E4 = 0;
        self->p1EC = 0;
        func_0036D5D0(self->m74, -1);
        {
            void** h = (void**)((char*)self + 0x6C);
            if (h) { if (self->p70) func_003C1790(self->p70); }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}