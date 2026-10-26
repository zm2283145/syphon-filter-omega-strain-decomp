#include "ee_kernel_types.h"

typedef struct { int status; void* func; void* stack; int stack_size; void* gp_reg; int initial_priority; int current_priority; unsigned int attr; unsigned int option; int pad[15]; } TP2B4D08;
typedef struct { int x0; int x4; int x8; } T2B4D08;
extern int D_0048BD88;
extern int D_00506644;
extern T2B4D08 D_00506B60;
extern char D_00506B80[];
extern char D_004E9B70[];
extern void basic_thread(void);
extern int sceMc2End(void);
extern void _sceMcCoreInit(void);
extern void _sceMcpInit(void);
extern void _sceMcFatInit(void);
extern int CreateThread(TP2B4D08* p);
extern int StartThread(int th, void* arg);

int sceMc2Init(int mode)
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
        sceMc2End();
        return 0x81018003;
    }
    D_00506644 = 0;
    tp.func = basic_thread;
    tp.stack = D_00506B80;
    tp.stack_size = 0xC000;
    tp.gp_reg = D_004E9B70;
    tp.initial_priority = 1;
    D_00506B60.x0 = CreateThread(&tp);
    if (D_00506B60.x0 < 0) {
        sceMc2End();
        return 0x81018004;
    }
    _sceMcCoreInit();
    _sceMcpInit();
    _sceMcFatInit();
    StartThread(D_00506B60.x0, 0);
    return 0;
}
