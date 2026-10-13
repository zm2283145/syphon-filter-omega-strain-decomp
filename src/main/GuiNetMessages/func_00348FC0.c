#include "types.h"
typedef struct { int a; int b; int c; } Str348FC0;
typedef struct {
    void* vtable; char pad4[0x54]; unsigned char a58; char pad59[0x37];
    int a90; int a94; int a98; int a9C; int padA0; int aA4; Str348FC0 sA8;
} S348FC0;
extern char D_004DEB80[];
extern char D_004BA338[];
extern void func_00424C50(S348FC0* self);
extern char* Loc_LookupText(char* key);
extern void String_CtorCStr_13B480(Str348FC0* s, char* text);
extern void func_0013D680(Str348FC0* dst, Str348FC0* src);
extern void String_Dtor(Str348FC0* s, int flags);
S348FC0* func_00348FC0(S348FC0* self)
{
    Str348FC0 tmp;
    char* t;
    func_00424C50(self);
    self->vtable = D_004DEB80;
    self->sA8.a = 0;
    self->sA8.b = 0;
    self->sA8.c = 0;
    self->a90 = 0;
    self->a94 = 0;
    self->a98 = 0;
    self->a9C = 0;
    self->a58 = 2;
    self->aA4 = 0;
    t = Loc_LookupText("TOSSystem");
    { Str348FC0* p = &tmp; String_CtorCStr_13B480(p, t ? t : D_004BA338); }
    func_0013D680(&self->sA8, &tmp);
    String_Dtor(&tmp, 0);
    return self;
}