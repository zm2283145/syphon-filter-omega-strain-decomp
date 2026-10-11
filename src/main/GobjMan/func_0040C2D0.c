#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct IdPool_n1 { int unk0; } IdPool_n1;
typedef struct IdSlot_n1 { int id; } IdSlot_n1;
extern "C" {
extern char D_004BECA8[];
extern IdPool_n1* D_00571740;
extern IdPool_n1* D_00571748;
extern int D_00571780[256];
void* Mem_Alloc(int, int, char*, int);
void func_0040BA10(IdPool_n1* self, int capacity, IdPool_n1* parent);
}
static inline void* AllocL_n1(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
extern "C" void IdMgr_Init(void)
{
    int i;
    IdPool_n1* p;
    p = (IdPool_n1*)AllocL_n1(0x24, D_004BECA8, 0xCF);
    if (p) {
        func_0040BA10(p, 0x1194, 0);
    }
    D_00571740 = p;
    p = (IdPool_n1*)AllocL_n1(0x24, D_004BECA8, 0xD0);
    if (p) {
        func_0040BA10(p, 0x9C4, D_00571740);
    }
    D_00571748 = p;
    for (i = 0; i < 256; i++) {
        ((IdSlot_n1*)D_00571780)[i].id = 0;
    }
}