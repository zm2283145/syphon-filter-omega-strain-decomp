#include "types.h"

typedef struct { char b[0xC]; } String;
typedef struct { char pad[0x64]; int unk64; int unk68; char pad2[0x10]; char kind; char pad3[3]; String name; } Obj353;
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(String* dst, String* src);
extern void func_00138B70(String* s, int flag);

/* Sets the kind, name and two parameters of the object. */
void func_00353790(Obj353* o, char kind, const char* name, int a, int b)
{
    String tmp;
    o->kind = kind;
    String_CtorCStr_13B480(&tmp, name);
    func_0013D680(&o->name, &tmp);
    func_00138B70(&tmp, 0);
    o->unk64 = a;
    o->unk68 = b;
}
