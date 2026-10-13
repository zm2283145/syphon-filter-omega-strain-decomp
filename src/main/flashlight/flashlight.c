/*
 * main/flashlight: 2 files, 0045B990-0045BAD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045B990 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC0045B990 { char vpad[4]; virtual int v0(...); };
struct VD0045B990 { virtual int v0(...); };
extern "C" {
int Mem_Free(...);
int TargetVis_Unregister(...);
int operator_delete(...);
extern char g_TargetVisMgr;
extern unsigned char D_00533880;
typedef struct { char p0[8]; int f8; int fC; char p10[8]; int f18; } PS0_0045B990;
}
extern "C" char * Flashlight_Destroy(PS0_0045B990 *arg0, long long arg1) {
    void **temp_s1;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        TargetVis_Unregister(&g_TargetVisMgr, arg0->f18);
        temp_a0 = (char *)(arg0->f8);
        if ((temp_a0 != NULL) && (temp_a0 != NULL)) {
            ((VC0045B990 *)(temp_a0))->v0(1);
        }
        temp_a0_2 = (char *)(arg0->fC);
        if ((temp_a0_2 != NULL) && (temp_a0_2 != NULL)) {
            ((VC0045B990 *)(temp_a0_2))->v0(1);
        }
        temp_s1 = (void **)(arg0->f18);
        {
            AllocGuard g;
        ((VD0045B990 *)(temp_s1))->v0(-1);
        Mem_Free(0, temp_s1, "flashlight.cc", 0x58);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0045B990 */

/* merge_units: begin func_0045BAD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


struct VC0045BAD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34(...); };
extern "C" {
int IdMgr_Allocate(...);                           
void **Mem_Alloc(...);                     
void **cGOBJ_ctor(...);          
extern char D_004C2018;
extern char D_0055C9F0;
}
extern "C" char * Flashlight_Construct(char * arg0, int arg1) {
    int sp4C;
    int sp48;
    void **temp_a0;
    void **var_s2;

    {
        AllocGuard g;
    var_s2 = Mem_Alloc(0, 0x60, &D_004C2018, 0x42);
    }
    if (var_s2 != NULL) {
        sp4C = 0;
        IdMgr_Allocate(&sp48, 0xE7);
        var_s2 = cGOBJ_ctor(var_s2, &sp48, 0, &sp4C);
    }
    F_(arg0, 0x18, int) = (int)(var_s2);
    temp_a0 = (void **)(F_(arg0, 0x18, int));
    ((VC0045BAD0 *)(temp_a0))->v34(&D_0055C9F0, 0);
    F_(arg0, 0x0, unsigned char) = 0;
    F_(arg0, 0x8, int) = 0;
    F_(arg0, 0xC, int) = 0;
    F_(arg0, 0x4, int) = arg1;
    F_(arg0, 0x10, int) = 0xBF800000;
    F_(arg0, 0x14, int) = 0;
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045BAD0 */
