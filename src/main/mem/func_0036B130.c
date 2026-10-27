#include "types.h"

/* One memory pool (0x818 bytes); the pool index is stored in the block header. */
typedef struct MemPool {
    char data[0x818];
} MemPool;

extern MemPool D_00533CB0[]; /* memory pools */
extern void cMemBin_Deallocate(MemPool* pool, void* block);

/* Frees a block back to the pool recorded in its header (low nibble at block-0xC). */
void cMemMan_Deallocate(void* self, char* block) {
    if (block) {
        char pool = block[-0xC] & 0xF;
        cMemBin_Deallocate(&D_00533CB0[pool], block);
    }
}
