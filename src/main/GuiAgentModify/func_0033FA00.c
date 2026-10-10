#include "types.h"

extern int D_0055DDA0;
extern int D_004B9ED0;
extern int D_004B9EE8;
extern void func_00403310(void*);
extern void func_0040F540(void);
extern void* func_00414790(void);
extern void* func_00418A80(void*, void*, void*);
extern void* func_004147A0(void);
extern void func_00414AC0(void*, int, void*);

/* Resets state, looks up a named entry and hands it to func_00414AC0 with the argument. */
void func_0033FA00(int arg) {
    void* entry;
    func_00403310(&D_0055DDA0);
    func_0040F540();
    entry = func_00418A80(func_00414790(), &D_004B9ED0, &D_004B9EE8);
    func_00414AC0(func_004147A0(), arg, entry);
}
