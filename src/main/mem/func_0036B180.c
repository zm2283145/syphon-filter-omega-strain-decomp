#include "types.h"
typedef struct MemPool { char data[0x818]; } MemPool;
extern unsigned char D_00533C98;
extern int D_00533CA0;
extern MemPool D_00533CB0[];
extern void Mem_Init(void);
extern char* Mem_HeapAlloc(MemPool* pool, int size, char* file, int line);
char* Mem_Alloc(int pool, int size, char* file, int line) {
    char* p;
    if (!D_00533C98) Mem_Init();
    pool = pool == 0 ? D_00533CA0 : pool;
    if (size == 0) return 0;
    p = Mem_HeapAlloc(&D_00533CB0[pool], size, file, line);
    if (p) p[-0xC] = (p[-0xC] & 0xF0) + (char)pool;
    return p;
}

