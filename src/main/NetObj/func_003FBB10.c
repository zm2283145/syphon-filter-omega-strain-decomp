#include "types.h"
typedef struct { char pad[0x10]; int val; } E4Node;
extern char D_0055C7A0[];
extern void func_001BB080(E4Node** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(E4Node** out, void* in);
static inline int E4Eq(E4Node* a, E4Node* b) { return a == b; }
#pragma bool off
int* NetMap_Lookup(int key)
{
    E4Node* end[1]; E4Node* it[1]; int tmp[1]; int k[1];
    E4Node* n;
    k[0] = key;
    func_001BB080(it, D_0055C7A0, k);
    n = it[0];
    func_0021D360(tmp, D_0055C7A0);
    func_0021D350(end, tmp);
    if (E4Eq(n, end[0]) ^ 1) { int* p = &n->val; if (*p) return p; } return 0;
}