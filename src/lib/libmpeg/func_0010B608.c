#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { unsigned int base; unsigned int size; unsigned int cur; } Arena;
extern char D_004986C8[];
extern void func_0010BD90(void* ctx, const char* msg);

/* Allocates size bytes aligned to align from the arena; reports an error and returns 0 when full. */
unsigned int func_0010B608(void* ctx, Arena* arena, unsigned int size, unsigned int align)
{
    unsigned int start = (arena->cur + align - 1) / align * align;
    unsigned int end = start + size;
    if (arena->base + arena->size < end) {
        func_0010BD90(ctx, D_004986C8);
        return 0;
    }
    arena->cur = end;
    return start;
}
