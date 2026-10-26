#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct T_439670 { int id; unsigned int a : 4; unsigned int b : 4; };
typedef struct { char pad[0x1C]; T_439670* f1C; } P_439670;
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721B8;
extern unsigned char D_005721D0;
extern unsigned char D_005721C0;
extern unsigned char D_00583880;
extern T_439670* D_00583888;
extern char D_004BFD60[];
extern int D_00497570;
extern int D_00497578;
int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, T_439670* g, char* h, int i);
int NetGetObject(P_439670** out, int key);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void cGenInfoObject_Setup(void);
}
static inline void Reg_439670(int* key, T_439670** out)
{
    P_439670* p;
    if (!NetCreateObject(key, 2, 4, 0, 0, 0, 0, *out, "cGenInfoObject", D_00497570) && !NetGetObject(&p, *key)) *out = p->f1C;
}
static inline int NetOk_439670(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void RegAll_439670(void) { if (D_005721D0 && NetOk_439670()) Reg_439670(&D_00497578, &D_00583888); }

#pragma push
#pragma opt_unroll_loops off
void cGenInfoObject_Setup(void)
{
    if (g_IsMultiplayer && !D_005721B8) {
    if (D_005721D0) {
        T_439670* p;
        if (D_00583880) return;
        if (!NetOk_439670()) return;
        p = D_00583888;
        RegAll_439670();
        if (p) {
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            Mem_Free(0, p, D_004BFD60, 0x211);
            if (g_ProfileLockEnabled) Alloc_Unlock(9);
            g_ProfileLockDepth--;
        }
        D_00583880 = 1;
    } else {
        T_439670* p;
        if (D_00583888) return;
        {
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            p = (T_439670*)Mem_Alloc(0, 0x1B8, D_004BFD60, 0x21B);
            if (g_ProfileLockEnabled) Alloc_Unlock(9);
            g_ProfileLockDepth--;
        }
        if (p) {
            T_439670* e;
            for (e = p; e != p + 55; e++) {
                e->id = -1;
                e->a = 15;
                e->b = 0;
            }
        }
        D_00583888 = p;
    }
    }
}
#pragma pop