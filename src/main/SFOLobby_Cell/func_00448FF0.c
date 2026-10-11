#include "types.h"
extern void func_00451AE0(void*);
extern char* func_00449070(void*, int);
char* func_00448FF0(char* p, int id) {
    char* r;
    func_00451AE0(p);
    /* .set reorder barrier keeps the early-return arm */
    if (id < 0) { asm { .set reorder } return 0; }
    r = func_00449070(p, id);
    if (r == 0) return 0;
    if (((unsigned char*)p)[0x2564] == 0) return r + 0x20;
    return 0;
}