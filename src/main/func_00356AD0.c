#include "types.h"

extern char D_004BB340[];
extern char D_004BB358[];
extern void* func_00414790(void);
extern void* func_00418A80(void* manager, const char* a, const char* b);
extern void* func_004147A0(void);
extern void func_00414AC0(void* target, void* self, void* handle);

/* Creates a handle from the two name strings and registers it for self. */
void func_00356AD0(void* self)
{
    void* handle = func_00418A80(func_00414790(), D_004BB340, D_004BB358);
    func_00414AC0(func_004147A0(), self, handle);
}
