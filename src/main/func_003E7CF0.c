#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { char unk0; unsigned char unk1; unsigned char unk2; char pad; int unk4; int pad8; int index; char pad10[8]; String names[1]; } Obj;
extern char D_004BDF28[];
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(String* dst, String* src);
extern void func_00138B70(String* s, int flags);

/* Sets defaults and resets the current name slot to D_004BDF28. */
void func_003E7CF0(Obj* self)
{
    String tmp;
    self->unk1 = 1;
    self->unk2 = 1;
    self->unk4 = 8;
    String_CtorCStr_13B480(&tmp, D_004BDF28);
    func_0013D680(&self->names[self->index], &tmp);
    func_00138B70(&tmp, 0);
}
