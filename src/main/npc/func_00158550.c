#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
struct V158 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); };
extern "C" {
int Mem_Free(int, int, char *, int);
int Service_Lookup(char *, char *);
int cAI_dtor(char *, int);
int func_00161680(int, int);
int NpcRoute_Release(int, V158 *);
int func_0016DFD0(int, int);
int func_0042DF20(char *);
int operator_delete(char *);
extern char D_0049B670;
extern char D_004D9380;
extern char g_NpcRouteMgr;
extern char D_004FFB50;
}
typedef struct { void *f0; char p4[44]; V158 *f30; char p34[293]; unsigned char f159; char p15A[82]; int f1AC; int f1B0; } PS0_00158550;
extern "C" char *cNPC_dtor(PS0_00158550 *arg0, long long arg1) {
    int temp_s2;

    if (arg0 != NULL) {
        arg0->f0 = &D_004D9380;
        if (arg0->f159 == 0) {
            ((V158 *)arg0)->v17();
        } else {
            NpcRoute_Release(Service_Lookup(&D_004FFB50, &g_NpcRouteMgr), arg0->f30);
        }
        if (arg0->f30->v29() != 0) {
            func_0042DF20((char *)arg0->f30 + 0xC);
        }
        temp_s2 = arg0->f1B0;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_00161680(temp_s2, -1);
                Mem_Free(0, temp_s2, &D_0049B670, 0x7E3);
            }
            arg0->f1B0 = 0;
        }
        temp_s2 = arg0->f1AC;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_0016DFD0(temp_s2, -1);
                Mem_Free(0, temp_s2, &D_0049B670, 0x7E8);
            }
            arg0->f1AC = 0;
        }
        cAI_dtor((char *)arg0, 0);
        if (((long long)(arg1 << 0x30) >> 0x30) > 0) {
            operator_delete((char *)arg0);
        }
    }
    return (char *)arg0;
}