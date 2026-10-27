/*
 * Libs/SFOLib/Source/mem: 4 files, 0036B070-0036B180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036B070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

unsigned int D_00492F68[2] = { 0x1, 0x0 };

void cMemMan_DisallowConsolidation(void) {
    (*(unsigned char*)D_00492F68) = 0;
}

void cMemMan_AllowConsolidation(void) {
    (*(unsigned char*)D_00492F68) = 1;
}
static inline void merge_flush_func_0036B070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036B070 */

/* merge_units: begin func_0036B090 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x814]; int handle; } H36B090;
extern H36B090 D_00533CB0[4];
extern int cMemBin_HaveAllocationInRange(H36B090* h, void* a, void* b);
int cMemMan_HaveAllocationInRange(void* a, void* b)
{
    int i;
    H36B090* h = D_00533CB0;
    for (i = 0; i < 4; i++, h++) {
        if (h->handle != -1 && cMemBin_HaveAllocationInRange(h, a, b)) return 1;
    }
    return 0;
}
static inline void merge_flush_func_0036B090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036B090 */

/* merge_units: begin func_0036B130 */
#pragma push /* merge_units */
/* One memory pool (0x818 bytes); the pool index is stored in the block header. */
typedef struct MemPool {
    char data[0x818];
} MemPool;

#if 0 /* merge_units */
extern MemPool D_00533CB0[]; /* memory pools */
#endif /* merge_units */
#define D_00533CB0 ((MemPool*)&D_00533CB0) /* merge_units */

extern void cMemBin_Deallocate(MemPool* pool, void* block);

/* Frees a block back to the pool recorded in its header (low nibble at block-0xC). */
void cMemMan_Deallocate(void* self, char* block) {
    if (block) {
        char pool = block[-0xC] & 0xF;
        cMemBin_Deallocate(&D_00533CB0[pool], block);
    }
}
#undef D_00533CB0 /* merge_units */
static inline void merge_flush_func_0036B130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036B130 */

/* merge_units: begin func_0036B180 */
#pragma push /* merge_units */
extern unsigned char D_00533C98;
extern int D_00533CA0;
#if 0 /* merge_units */
extern MemPool D_00533CB0[];
#endif /* merge_units */
#define D_00533CB0 ((MemPool*)&D_00533CB0) /* merge_units */

extern void cMemMan_Init_void(void);
extern char* cMemBin_Allocate(MemPool* pool, int size, char* file, int line);
char* cMemMan_Allocate(int pool, int size, char* file, int line) {
    char* p;
    if (!D_00533C98) cMemMan_Init_void();
    pool = pool == 0 ? D_00533CA0 : pool;
    if (size == 0) return 0;
    p = cMemBin_Allocate(&D_00533CB0[pool], size, file, line);
    if (p) p[-0xC] = (p[-0xC] & 0xF0) + (char)pool;
    return p;
}
#undef D_00533CB0 /* merge_units */
static inline void merge_flush_func_0036B180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036B180 */
