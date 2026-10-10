#include "types.h"

typedef struct { int words[3]; } String; /* 12-byte short-string-optimized string */
typedef struct { char pad[0x64]; int unk64; int unk68; char pad6C[0x7C - 0x6C]; unsigned char unk7C; char pad7D[3]; String name; } Obj80;
extern char D_004BAF98[];
extern void func_00356CD0(Obj80* self);
extern void String_CtorCStr_13B480(String* s, const char* text);   /* String(const char*) */
extern void func_0013D680(String* dst, String* src);       /* String::operator= */
extern void func_00138B70(String* s, int flags);           /* ~String */

/* Resets the object: base reset, clears the flag, sets the name to D_004BAF98 and zeroes +0x64/+0x68. */
void func_00353850(Obj80* self)
{
    String tmp;
    func_00356CD0(self);
    self->unk7C = 0;
    String_CtorCStr_13B480(&tmp, D_004BAF98);
    func_0013D680(&self->name, &tmp);
    func_00138B70(&tmp, 0);
    self->unk64 = 0;
    self->unk68 = 0;
}
