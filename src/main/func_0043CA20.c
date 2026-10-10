#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { char pad[0x48]; int handle; int unk4C; String name; } Obj;
extern void* D_00539248;
extern char D_004C0018[];
extern void func_0041F090(Obj* self);
extern void func_003813A0(void* mgr, int handle, int a2);
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(String* dst, String* src);
extern void func_00138B70(String* s, int flags);

/* Resets: base reset, releases the handle, clears fields and the name. */
void func_0043CA20(Obj* self)
{
    String tmp;
    func_0041F090(self);
    if (self->handle != -1) {
        func_003813A0(D_00539248, self->handle, 0);
        self->handle = -1;
    }
    self->unk4C = 0;
    String_CtorCStr_13B480(&tmp, D_004C0018);
    func_0013D680(&self->name, &tmp);
    func_00138B70(&tmp, 0);
}
