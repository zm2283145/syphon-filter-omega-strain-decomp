#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
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
extern int D_0048C340;
extern int D_0048C348;
extern int D_0048C350;
extern int D_0048C358;
extern void* D_0051EF70;
extern char D_004ACF10[];
extern char D_004E9B70[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_002C84B0(void);
void func_002C8460(void);
int func_0010D050(void);
void func_0010CFF0(int thread, int prio);
int func_0010CF60(Thp82F0* p);
void func_0010CF80(int thread, void* arg);
int func_0010CE40(int id, void* fn, int arg);
}
struct Obj82F0 { char pad[0x310]; unsigned char active; };
extern "C" void func_002C82F0(Obj82F0* o)
{
    if (!o->active) {
        Thp82F0 tp;
        void* p;
        int size = D_0048C340 + 0x10;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, size, D_004ACF10, 0x862);
        }
        tp.status = 0x10;
        D_0051EF70 = p;
        tp.entry = (void*)func_002C84B0;
        tp.stack = (void*)((unsigned int)p & ~0xF);
        tp.waitType = 0;
        tp.wakeupCount = 0;
        tp.gpReg = D_004E9B70;
        tp.initPriority = 5;
        tp.stackSize = D_0048C340;
        D_0048C348 = func_0010D050();
        func_0010CFF0(D_0048C348, 10);
        D_0048C350 = func_0010CF60(&tp);
        func_0010CF80(D_0048C350, o);
        D_0048C358 = func_0010CE40(2, (void*)func_002C8460, 0);
        Alloc_Unlock(2);
        o->active = 1;
    }
}