/*
 * main/scriptBase: 2 files, 003D63C0-003D6570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D63C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BD418[];
extern char D_004BD428[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void* memcpy(void* d, const void* s, unsigned int n);
}

struct ScriptWriter {
    char pad[0xA4];
    int* data;   /* 0xA4 */
    int* cursor; /* 0xA8 */
    char padAC[4];
    int count;   /* 0xB0 */
    int cap;     /* 0xB4 */
};

static inline void* GuardedAlloc(unsigned int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}

extern "C" void ScriptFileBuff_expand(ScriptWriter* w, int words)
{
    if (w->count + words > w->cap) {
        int* nb;
        w->cap += 500;
        nb = (int*)GuardedAlloc(w->cap * 4, D_004BD428, 0xCE);
        if (w->data) {
            memcpy(nb, w->data, w->count * 4);
        }
        w->cursor = nb + (w->cursor - w->data);
        if (w->data) {
            void* old = w->data;
            AllocGuard g;
            Mem_Free(0, old, D_004BD418, 0xD3);
        }
        w->data = nb;
    }
    w->count += words;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D63C0 */

/* merge_units: begin func_003D6570 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "scriptBase_types.h"

/* Number of 4-byte words needed for 'size' bytes. */
unsigned int ScriptFileBuff_charsToInts(int a0, int size) {
    return (unsigned int)(size + 3) >> 2;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D6570 */
