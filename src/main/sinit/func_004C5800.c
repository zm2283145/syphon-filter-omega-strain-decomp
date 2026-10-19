#include "types.h"
#pragma opt_propagation off
extern char D_004EA7B0[], D_004EA7A0[], D_004ED9F0[], D_004EDA00[], D_004EDA20[], D_004ED9D8[];
extern char D_004EE000[], D_004EE130[], D_004EE120[];
extern char func_001652E0[], func_00165270[], func_00165250[], func_00163890[], func_00163820[], func_00163730[], func_00165200[], cNode_dtor[];
extern char* g_NpcRouteMgr;
extern char* D_004ED9B8;
extern int D_004EE010;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void func_001640B0(void* p, int a, int b);
extern void func_00163970(void* p);
extern void func_00163810(void* p);
extern void Ptr_Identity(void* p);
extern void cNode_ctor2(void* p, int a, int b, int c, float x, float y, float z);
void func_004C5800(void)
{
    char* s;
    __construct_array(D_004EA7B0, func_001652E0, func_00165270, 0x20, 0x190);
    __register_global_object(0, func_00165250, D_004EA7A0);
    g_NpcRouteMgr = "Path System";
    D_004ED9B8 = "Path Message";
    s = D_004ED9F0;
    func_001640B0(s, 0, 2);
    func_00163970(D_004EDA00);
    __construct_array(D_004EDA20, func_00163890, func_00163820, 0x20, 0x20);
    func_00163810(s + 0x430);
    Ptr_Identity(s + 0x440);
    Ptr_Identity(s + 0x450);
    __register_global_object(s, func_00163730, D_004ED9D8);
    D_004EE010 = 0;
    __register_global_object(&D_004EE010, func_00165200, D_004EE000);
    cNode_ctor2(D_004EE130, 1, -1, 0, 0.0f, 0.0f, 0.0f);
    __register_global_object(D_004EE130, cNode_dtor, D_004EE120);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}