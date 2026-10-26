#include "types.h"
#pragma opt_propagation off
extern char D_004EA7B0[], D_004EA7A0[], D_004ED9F0[], D_004EDA00[], D_004EDA20[], D_004ED9D8[];
extern char D_004EE000[], D_004EE130[], D_004EE120[];
extern char cPathCell_ctor[], cPathCell_dtor[], func_00165250[], cNodeIndex_ctor[], cNodeIndex_dtor[], cNodeRequest_dtor[], cArray_FixedCapacity_int_64_dtor[], cNode_dtor[];
extern char* g_NpcRouteMgr;
extern char* D_004ED9B8;
extern int D_004EE010;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void cPathSystemRequest_ctor(void* p, int a, int b);
extern void cPriorityQueue_cNodeIndex_ctor(void* p);
extern void cNodePickerParameters_ctor_void(void* p);
extern void Ptr_Identity(void* p);
extern void cNode_ctor2(void* p, int a, int b, int c, float x, float y, float z);
void StaticInit_PathSystem(void)
{
    char* s;
    __construct_array(D_004EA7B0, cPathCell_ctor, cPathCell_dtor, 0x20, 0x190);
    __register_global_object(0, func_00165250, D_004EA7A0);
    g_NpcRouteMgr = "Path System";
    D_004ED9B8 = "Path Message";
    s = D_004ED9F0;
    cPathSystemRequest_ctor(s, 0, 2);
    cPriorityQueue_cNodeIndex_ctor(D_004EDA00);
    __construct_array(D_004EDA20, cNodeIndex_ctor, cNodeIndex_dtor, 0x20, 0x20);
    cNodePickerParameters_ctor_void(s + 0x430);
    Ptr_Identity(s + 0x440);
    Ptr_Identity(s + 0x450);
    __register_global_object(s, cNodeRequest_dtor, D_004ED9D8);
    D_004EE010 = 0;
    __register_global_object(&D_004EE010, cArray_FixedCapacity_int_64_dtor, D_004EE000);
    cNode_ctor2(D_004EE130, 1, -1, 0, 0.0f, 0.0f, 0.0f);
    __register_global_object(D_004EE130, cNode_dtor, D_004EE120);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}