#include "types.h"
extern char D_00538080[];
extern int D_00538170;
extern void* memset(void*, int, unsigned int);
extern void func_00378020(void*);
extern void func_00377F20(void*);
void func_004D5260(void) {
    memset(D_00538080, 0, 0x160);
    D_00538170 = -1;
    func_00378020(D_00538080);
    func_00377F20(D_00538080);
}