/*
 * main/machine: range (2 files, 00166690-001667C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00166690 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
int Mem_Alloc(int, int, char *, int);
int CreateThread(void *);
int StartThread(int, int);
int ChangeThreadPriority(int, int);
int func_0010D050(void);
extern int D_0048A030;
extern int D_0048A040;
extern int D_0048A048;
extern char D_0049C390;
extern char D_004E9B70;
extern int D_004EE4E8;
extern unsigned char D_00533880;
extern int D_00533888;

typedef struct {
    int status;
    void *func;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
    int pad30[4];
} TP_00166690;

void func_00166690(void *fn) {
    TP_00166690 tp;
    int size;
    int mem;

    size = D_0048A040 + 0x10;
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    mem = Mem_Alloc(0, size, &D_0049C390, 0x770);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_004EE4E8 = mem;
    D_00533888 -= 1;
    tp.status = 0x10;
    tp.func = fn;
    tp.stack = (void *)(mem & ~0xF);
    tp.stackSize = D_0048A040;
    tp.gpReg = &D_004E9B70;
    tp.initPriority = 5;
    tp.waitType = 0;
    tp.wakeupCount = 0;
    D_0048A048 = func_0010D050();
    ChangeThreadPriority(D_0048A048, 0xA);
    D_0048A030 = CreateThread(&tp);
    StartThread(D_0048A030, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00166690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00166690 */

/* merge_units: begin func_001667C0 */
#pragma push /* merge_units */
extern int D_004EE4C8;
extern int D_004EE4F8;
int iWakeupThread(int);

int func_001667C0(int cause) {
    D_004EE4C8 += 1;
    if (D_0048A030 != -1) {
        if (D_004EE4F8 == 0) {
            iWakeupThread(D_0048A030);
        } else {
            D_004EE4F8 -= 1;
        }
    }
    /* ExitHandler(): sync + ei cannot be expressed in C */
    asm { sync }
    asm { ei }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001667C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001667C0 */
