#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct TENode_func_003CA530 { TENode_func_003CA530* left; TENode_func_003CA530* right; int parentColor; };
extern "C" {
extern char D_004BD178[];
void* func_003CAA40(void* t);
void* func_003CAA00(void* t);
void func_003CAA10(void* a, void* v);
void func_003CA9A0(void* a, TENode_func_003CA530* n, int count);
void func_003CA860(TENode_func_003CA530* n, int a, int b, char* file, int ln);
void func_003CA940(void* v, int flags);
void func_003CA3F0(void* v, int flags);
void func_003CA530(void* t, TENode_func_003CA530* x);
void operator_delete(void* p);
}
static inline void L2_func_003CA530(void* t, TENode_func_003CA530* g)
{
    if (g->left)
        func_003CA530(t, g->left);
    if (g->right)
        func_003CA530(t, g->right);
    func_003CAA10(func_003CAA40(t), (char*)g + 0xC);
    func_003CA9A0(func_003CAA00(t), g, 1);
}
static inline void L1_func_003CA530(void* t, TENode_func_003CA530* c)
{
    TENode_func_003CA530* g;
    if ((g = c->left) != 0)
        L2_func_003CA530(t, g);
    if ((g = c->right) != 0)
        L2_func_003CA530(t, g);
    func_003CAA40(t);
    func_003CA940((char*)c + 0xC, -1);
    func_003CAA00(t);
    if (c)
        func_003CA860(c, 0, 0, D_004BD178, 0x64);
}
static inline void D3_func_003CA530(void* p) { if (p) { if (p) func_003CA3F0(p, 0); } }
static inline void D2_func_003CA530(void* p) { if (p) D3_func_003CA530(p); }
static inline void D1_func_003CA530(char* v) { if (v) D2_func_003CA530(v + 4); }
extern "C" void func_003CA530(void* t, TENode_func_003CA530* x)
{
    TENode_func_003CA530* c;
    if ((c = x->left) != 0)
        L1_func_003CA530(t, c);
    if ((c = x->right) != 0)
        L1_func_003CA530(t, c);
    D1_func_003CA530((char*)x + 0xC);
    if (x)
        TStr_Free((char*)x, D_004BD178, 0x64);
}