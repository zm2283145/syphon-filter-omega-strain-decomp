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
extern char D_004C2018;
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
        Mem_Free(0, temp_s1, &D_004C2018, 0x58);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}

