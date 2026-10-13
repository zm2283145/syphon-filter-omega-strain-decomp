#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD0A0[];
extern char D_004D9140[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_001361E0(void* p);
int func_001361D0(int* n);
void func_001361C0(void* p, int n);
void HumanColBufB_Init(void* p);
void HumanColBufB_Reserve(void* p, int n);
void func_003C3120(void* p, int* n, int k);
void func_003C3110(void* p);
void func_003C06B0(int a);
}
struct ScrA { int w[3]; unsigned char bC; };
struct ScrB { void* vt; int w[4]; int x[3]; };
extern "C" ScrA* D_00542CC8;
extern "C" ScrA* D_00542CD0;
extern "C" ScrA* D_00542CD8;
extern "C" ScrB* D_00542CE0;
static inline void* AllocL(int size, int line) {
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BD0A0, line);
}
extern "C" void ColScratch_Init(int a0, int a1, int a2, int a3) {
    if (!D_00542CC8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x2E);
        if (p) {
            int n = a0;
            func_001361E0(p);
            func_001361C0(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CC8 = p;
    }
    if (!D_00542CD0) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x31);
        if (p) {
            int n = a0;
            func_001361E0(p);
            func_001361C0(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CD0 = p;
    }
    if (!D_00542CD8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x34);
        if (p) {
            int n = a1;
            HumanColBufB_Init(p);
            HumanColBufB_Reserve(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CD8 = p;
    }
    if (!D_00542CE0) {
        ScrB* p = (ScrB*)AllocL(0x20, 0x37);
        if (p) {
            int n = a2;
            p->vt = D_004D9140;
            func_003C3120(p->w, &n, 1);
            func_003C3110(p->x);
        }
        D_00542CE0 = p;
    }
    func_003C06B0(a3);
}
