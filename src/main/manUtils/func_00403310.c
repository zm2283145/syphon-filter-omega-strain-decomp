#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void Mem_Free(int pool, void* p, char* file, int line);
extern "C" char D_004BE7F0[];
/* quad copy loop idiom as in src\main\LightMgr_RemoveFromTable.c (retail uses a hand-written addi) */
static inline void QMove(void* d, void* s, int n) {
    __int128 t;
    int nn = n; void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }}
struct Obj {
    char pad0[0xD4];
    void* bufA;
    void* bufB;
    int nA;
    int nB;
    char padE4[0x2C10 - 0xE4];
    char saveA[0xBC10 - 0x2C10];
    char saveB[0x10];
};
extern "C" void func_00403310(Obj* o)
{
    void* s = o->bufA;
    if (s) {
        QMove(o->saveA, s, o->nA);
        QMove(o->saveB, o->bufB, o->nB);
        {
            void* p = o->bufA;
            AllocGuard g;
            Mem_Free(0, p, D_004BE7F0, 0xA28);
        }
        {
            void* p = o->bufB;
            AllocGuard g;
            Mem_Free(0, p, D_004BE7F0, 0xA29);
        }
        o->bufA = 0;
        o->bufB = 0;
    }
}


