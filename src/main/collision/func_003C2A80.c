#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct VObj_3C2A80 { virtual void dtor(int f); };
extern "C" {
extern char D_004BD0A0[];
extern void* D_00542CC8;
extern void* D_00542CD0;
extern void* D_00542CD8;
extern VObj_3C2A80* D_00542CE0;
extern void* D_00542D00;
void Mem_Free(int pool, void* p, char* file, int line);
void func_00139DF0(void* p, int f);
void func_001810D0(void* p, int f);
void HumanColBufB_Dtor(void* p, int f);
}
static inline void A3_3C2A80(void* p) { if (p) func_00139DF0(p, 0); }
static inline void A2_3C2A80(void* p) { if (p) A3_3C2A80(p); }
static inline void A1_3C2A80(void* p) { if (p) A2_3C2A80(p); }
static inline void B3_3C2A80(void* p) { if (p) HumanColBufB_Dtor(p, 0); }
static inline void B2_3C2A80(void* p) { if (p) B3_3C2A80(p); }
static inline void B1_3C2A80(void* p) { if (p) B2_3C2A80(p); }
static inline void C3_3C2A80(void* p) { if (p) func_001810D0(p, 0); }
static inline void C2_3C2A80(void* p) { if (p) C3_3C2A80(p); }
static inline void C1_3C2A80(void* p) { if (p) C2_3C2A80(p); }

extern "C" void func_003C2A80(void)
{
    void* p;
    if ((p = D_00542CC8) != 0) { { AllocGuard g; A1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x41); } D_00542CC8 = 0; }
    if ((p = D_00542CD0) != 0) { { AllocGuard g; A1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x47); } D_00542CD0 = 0; }
    if ((p = D_00542CD8) != 0) { { AllocGuard g; B1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x4D); } D_00542CD8 = 0; }
    { VObj_3C2A80* v; if ((v = D_00542CE0) != 0) { { AllocGuard g; v->dtor(-1); Mem_Free(0, v, D_004BD0A0, 0x53); } D_00542CE0 = 0; } }
    if ((p = D_00542D00) != 0) { { AllocGuard g; C1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x68E); } D_00542D00 = 0; }
}