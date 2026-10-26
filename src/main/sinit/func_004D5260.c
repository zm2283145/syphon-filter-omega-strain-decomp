#include "types.h"
extern char D_00538080[];
extern int D_00538170;
extern void* memset(void*, int, unsigned int);
extern void cVU1Man_BuildPageTable(void*);
extern void cVU1Man_BuildAddressTable(void*);
void StaticInit_vu1man(void) {
    memset(D_00538080, 0, 0x160);
    D_00538170 = -1;
    cVU1Man_BuildPageTable(D_00538080);
    cVU1Man_BuildAddressTable(D_00538080);
}