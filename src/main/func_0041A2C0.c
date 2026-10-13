#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

union Str_41A2C0 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    int Size() const { return (l.w0 & 1) ? l.len : (unsigned char)s.n; }
};
struct O_41A2C0 {
    VPAD16(p) VPAD4(q) VPAD1(r)
    virtual void Changed();
    char pad[0x44];
    Str_41A2C0 str;
    char pad54[0x30];
    int maxLen;
    char pad88[4];
    int cursor;
};
extern "C" {
void String_CtorCStr_13B480(Str_41A2C0* s, char* c);
void String_Dtor(Str_41A2C0* s, int f);
void func_003B52B0(Str_41A2C0* out, Str_41A2C0* s, int a, int b);
void func_002072B0(Str_41A2C0* out, Str_41A2C0* a, Str_41A2C0* b);
void func_0013D680(Str_41A2C0* d, Str_41A2C0* s);
void func_0041A100(O_41A2C0* o, int c);
}

extern "C" int func_0041A2C0(O_41A2C0* o, char* text)
{
    Str_41A2C0 s;
    Str_41A2C0 left;
    Str_41A2C0 right;
    String_CtorCStr_13B480(&s, text);
    if (o->maxLen > 0 && s.Size() + o->str.Size() >= o->maxLen) {
        String_Dtor(&s, 0);
        return 0;
    }
    func_003B52B0(&left, &o->str, 0, o->cursor);
    func_003B52B0(&right, &o->str, o->cursor, -1);
    {
        Str_41A2C0 t1;
        Str_41A2C0 t2;
        func_002072B0(&t1, &left, &s);
        func_002072B0(&t2, &t1, &right);
        func_0013D680(&o->str, &t2);
        String_Dtor(&t2, 0);
        String_Dtor(&t1, 0);
    }
    func_0041A100(o, o->cursor + s.Size());
    o->Changed();
    String_Dtor(&right, 0);
    String_Dtor(&left, 0);
    String_Dtor(&s, 0);
    return 1;
}


