#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC004147B0 { virtual int v0(...); };
extern "C" {
int Mem_Free(...);                     
int func_00419590(...);                        
extern unsigned char D_00533880;
extern void **D_00571FB0;
extern void **D_00571FB8;
extern unsigned char D_00571FC0;
}
extern "C" void GuiCanvas_Destroy(void) {
    void **temp_s0;
    void **temp_s0_2;

    if (D_00571FC0 != 0) {
        temp_s0 = D_00571FB0;
        {
            AllocGuard g;
        ((VC004147B0 *)(temp_s0))->v0(-1);
        Mem_Free(0, temp_s0, "gui.cc", 0x27);
        }
        D_00571FB0 = NULL;
        temp_s0_2 = D_00571FB8;
        {
            AllocGuard g;
        func_00419590(temp_s0_2, -1);
        Mem_Free(0, temp_s0_2, "gui.cc", 0x2A);
        }
        D_00571FB8 = NULL;
    }
    D_00571FC0 = 0;
}
