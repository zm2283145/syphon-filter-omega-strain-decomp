#include "types.h"
extern char D_0055DDA0[];
extern char D_004B9ED0[];
extern char D_004B9EE8[];
extern void func_00403310(void* a);
extern void func_0040F540(void);
extern void* func_00414790(void);
extern int func_00418A80(void* a, const char* b, const char* c);
extern void* func_004147A0(void);
extern void func_00414AC0(void* a, int b, int c);
/* Look up an entry and register it with `arg`. */
void func_00340C00(int arg)
{
    int entry;
    func_00403310(D_0055DDA0);
    func_0040F540();
    entry = func_00418A80(func_00414790(), D_004B9ED0, D_004B9EE8);
    func_00414AC0(func_004147A0(), arg, entry);
}
