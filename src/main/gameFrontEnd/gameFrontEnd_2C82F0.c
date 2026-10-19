/*
 * main/gameFrontEnd: range (2 files, 002C82F0-002C8460)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_002C82F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Thp82F0 {
    int status;
    void* entry;
    void* stack;
    int stackSize;
    void* gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
};
extern "C" {
static const unsigned int dat_0048C340[2] = { 0x18000, 0x0 };
extern int D_0048C348;
extern int D_0048C350;
extern int D_0048C358;
extern void* g_SplashThreadStack;
extern char D_004ACF10[];
extern char D_004E9B70[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void FrontEnd_SplashThreadMain(void);
int FrontEnd_SplashVblankHandler(void);
int GetThreadId(void);
void ChangeThreadPriority(int thread, int prio);
int CreateThread(Thp82F0* p);
void StartThread(int thread, void* arg);
int AddIntcHandler(int id, void* fn, int arg);
}
struct Obj82F0 { char pad[0x310]; unsigned char active; };
extern "C" void FrontEnd_StartSplashThread(Obj82F0* o)
{
    if (!o->active) {
        Thp82F0 tp;
        void* p;
        int size = (*(int*)dat_0048C340) + 0x10;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, size, D_004ACF10, 0x862);
        }
        tp.status = 0x10;
        g_SplashThreadStack = p;
        tp.entry = (void*)FrontEnd_SplashThreadMain;
        tp.stack = (void*)((unsigned int)p & ~0xF);
        tp.waitType = 0;
        tp.wakeupCount = 0;
        tp.gpReg = D_004E9B70;
        tp.initPriority = 5;
        tp.stackSize = (*(int*)dat_0048C340);
        D_0048C348 = GetThreadId();
        ChangeThreadPriority(D_0048C348, 10);
        D_0048C350 = CreateThread(&tp);
        StartThread(D_0048C350, o);
        D_0048C358 = AddIntcHandler(2, (void*)FrontEnd_SplashVblankHandler, 0);
        Alloc_Unlock(2);
        o->active = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C82F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C82F0 */

/* merge_units: begin func_002C8460 */
#pragma push /* merge_units */
extern unsigned char D_0051EE90;
extern void iWakeupThread(int id);
#pragma push
#pragma optimization_level 2
#pragma peephole on
#pragma optimization_level 3
int FrontEnd_SplashVblankHandler(void) {
    if (D_0048C350 != -1 && !D_0051EE90) iWakeupThread(D_0048C350);
    asm {
        sync
        ei
    }
    asm { .set reorder } /* barrier: keeps retail block layout */ return -1;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8460 */
