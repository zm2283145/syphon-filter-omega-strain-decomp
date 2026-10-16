#include "ee_kernel_types.h"

typedef struct { int status; void* func; void* stack; int stack_size; void* gp_reg; int initial_priority; int current_priority; unsigned int attr; unsigned int option; int pad[15]; } TP2B4D08;
typedef struct { int x0; int x4; int x8; } T2B4D08;
extern int D_0048BD88;
extern int D_00506644;
extern T2B4D08 D_00506B60;
extern char D_00506B80[];
extern char D_004E9B70[];
extern void func_002B5BA8(void);
extern int func_002B4E50(void);
extern void func_002BB690(void);
extern void func_002BA9E8(void);
extern void func_002B69A0(void);
extern int CreateThread(TP2B4D08* p);
extern int StartThread(int th, void* arg);

int func_002B4D08(int mode)
{
    TP2B4D08 tp;
    SemaParam sp;

    if (D_0048BD88 == 1) return 0;
    if (mode != 0) return 0x81010016;
    D_0048BD88 = 1;
    D_00506B60.x0 = -1;
    D_00506B60.x4 = -1;
    D_00506B60.x8 = -1;
    sp.initCount = 0;
    sp.maxCount = 1;
    D_00506B60.x4 = CreateSema(&sp);
    if (D_00506B60.x4 < 0) return 0x81018003;
    sp.initCount = 0;
    sp.maxCount = 1;
    D_00506B60.x8 = CreateSema(&sp);
    if (D_00506B60.x8 < 0) {
        func_002B4E50();
        return 0x81018003;
    }
    D_00506644 = 0;
    tp.func = func_002B5BA8;
    tp.stack = D_00506B80;
    tp.stack_size = 0xC000;
    tp.gp_reg = D_004E9B70;
    tp.initial_priority = 1;
    D_00506B60.x0 = CreateThread(&tp);
    if (D_00506B60.x0 < 0) {
        func_002B4E50();
        return 0x81018004;
    }
    func_002BB690();
    func_002BA9E8();
    func_002B69A0();
    StartThread(D_00506B60.x0, 0);
    return 0;
}
