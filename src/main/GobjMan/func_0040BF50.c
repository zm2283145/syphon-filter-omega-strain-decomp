#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct O40BF50 { virtual ~O40BF50(); };
struct I40BF50 { int p; };
struct G40BF50 { char pad[0x14]; int map; };
extern "C" {
extern G40BF50* D_00571740;
extern unsigned char D_00571768;
extern char D_004BECA8[];
int func_0012F2B0(void);
void func_0040C120(I40BF50* out, int* map, int key);
void func_0040C100(I40BF50* out, int* map);
int func_0040C0E0(I40BF50* a, I40BF50* b);
int func_0040C080(G40BF50* g, int key);
void Mem_Free(int pool, void* allocation, char* file, int line);
}
static inline bool check40BF50(G40BF50* g, int key)
{
    I40BF50 it;
    I40BF50 end;
    func_0040C120(&it, &g->map, key);
    func_0040C100(&end, &g->map);
    return func_0040C0E0(&it, &end) || !func_0040C080(g, key);
}
extern "C" void func_0040BF50(O40BF50* obj)
{
    G40BF50* g = D_00571740;
    int key = func_0012F2B0();
    if (check40BF50(g, key)) {
        D_00571768 = 1;
        if (obj) {
            AllocGuard guard;
            obj->~O40BF50();
            Mem_Free(0, obj, D_004BECA8, 0x11C);
        }
        D_00571768 = 0;
    }
}
