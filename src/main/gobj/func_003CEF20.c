#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CEF20 { virtual int v0(...); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(...); };
extern "C" {
int Mem_Free(...);                     
int func_003CAD70(...);                         
int operator_delete(...);                          
extern char D_004BD228;
extern char D_004DFF50;
extern unsigned char D_00533880;
typedef struct { int f0; char p4[68]; unsigned char f48; char p49[7]; int f50; int f54; int f58; } PS0_003CEF20;
}
extern "C" char * cGOBJ_dtor(PS0_003CEF20 *arg0, long long arg1) {
    void **temp_a0;
    void **temp_s2;
    void **temp_s2_2;

    if (arg0 != NULL) {
        arg0->f0 = (int)(&D_004DFF50);
        temp_s2 = (void **)(arg0->f50);
        if (temp_s2 != NULL) {
            if (arg0->f48 != 0) {
                {
                    AllocGuard g;
                ((VC003CEF20 *)(temp_s2))->v0(-1);
                Mem_Free(0, temp_s2, &D_004BD228, 0x174);
                }
                arg0->f48 = 0U;
            }
            arg0->f50 = NULL;
        }
        temp_a0 = (void **)(arg0->f58);
        if (temp_a0 != NULL) {
            ((VC003CEF20 *)(temp_a0))->v33(0);
            arg0->f58 = NULL;
        }
        temp_s2_2 = (void **)(arg0->f54);
        if (temp_s2_2 != NULL) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2_2, &D_004BD228, 0x210);
            }
            arg0->f54 = NULL;
        }
        func_003CAD70(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}
