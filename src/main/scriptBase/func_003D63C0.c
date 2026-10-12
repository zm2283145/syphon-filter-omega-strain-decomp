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

extern "C" void func_003D63C0(ScriptWriter* w, int words)
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

