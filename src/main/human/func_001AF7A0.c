#include "types.h"
typedef struct { int w; } G_1AF7A0;
extern void* D_004EE9D0;
extern void* D_004EE9D8;
extern char D_0049D8D0[];
extern void func_00136DA0(G_1AF7A0* g);
extern void func_0012F530(G_1AF7A0* g, int f);
extern void func_001AF9D0(void* p, int f);
extern void func_001AF880(void* p, int f);
extern void Mem_Free(int pool, void* p, char* file, int line);
extern void func_001D8710(void);
extern void HumanCol_Shutdown(void);
extern void func_00135020(void);
extern void func_003C2A80(void);
void func_001AF7A0(void)
{
    G_1AF7A0 g1;
    G_1AF7A0 g2;
    void* p = D_004EE9D0;
    if (p) {
        func_00136DA0(&g1);
        func_001AF9D0(p, -1);
        Mem_Free(0, p, D_0049D8D0, 0xB2A);
        func_0012F530(&g1, -1);
        D_004EE9D0 = 0;
    }
    p = D_004EE9D8;
    if (p) {
        func_00136DA0(&g2);
        func_001AF880(p, -1);
        Mem_Free(0, p, D_0049D8D0, 0xB30);
        func_0012F530(&g2, -1);
        D_004EE9D8 = 0;
    }
    func_001D8710();
    HumanCol_Shutdown();
    func_00135020();
    func_003C2A80();
}