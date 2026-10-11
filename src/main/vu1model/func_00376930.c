#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct E376930 { int x0; void* p; int x8; int xC; };
struct S376930 { char pad[0xC]; E376930* arr; int count; };
extern "C" {
extern char D_004BC170[];
extern void* D_0053924C;
void func_003D2630(void* mgr, void* p);
void func_003D1F00(void* p, int f);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Del376930(void* o)
{
    AllocGuard g;
    func_003D1F00(o, -1);
    Mem_Free(0, o, D_004BC170, 0x2AA);
}
static inline void Rel376930(void* p, int line)
{
    AllocGuard g;
    Mem_Free(0, p, D_004BC170, line);
}
extern "C" void func_00376930(S376930* s)
{
    if (s->arr) {
        int i;
        for (i = 0; i < s->count; i++) {
            if (s->arr[i].p) {
                func_003D2630(D_0053924C, s->arr[i].p);
                Del376930(s->arr[i].p);
                s->arr[i].p = 0;
            }
        }
        Rel376930(s->arr, 0x2AE);
        s->arr = 0;
        s->count = 0;
    }
}