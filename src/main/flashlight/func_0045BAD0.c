#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC0045BAD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34(...); };
extern "C" {
int IdMgr_Allocate(...);                           
void **Mem_Alloc(...);                     
void **cGOBJ_ctor(...);          
extern char D_004C2018;
extern unsigned char D_00533880;
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
