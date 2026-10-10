#include "types.h"

typedef struct { char pad[0x10]; int flag; } Widget;

extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern void* func_00414790(void);
extern Widget* func_00418A80(void* factory, const char* a, const char* b);
extern void* func_004147A0(void);
extern void func_00414AC0(void* mgr, void* self, Widget* w);

/* Creates a widget from two names, flags it and registers it for self. */
void func_002A0540(void* self)
{
    Widget* w = func_00418A80(func_00414790(), D_004AAEB0, D_004AAEC8);
    w->flag = 1;
    func_00414AC0(func_004147A0(), self, w);
}
