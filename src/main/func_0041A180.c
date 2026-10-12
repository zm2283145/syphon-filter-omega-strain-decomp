#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Alloc_41A180 { char unused; };
union Str_41A180 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    bool IsShort() const { return !(l.w0 & 1); }
    int Size() const { return IsShort() ? (unsigned char)s.n : l.len; }
};
struct O_41A180 {
    VPAD16(p) VPAD4(q) VPAD1(r)
    virtual void Changed();
    char pad[0x44];
    Str_41A180 str;
    char pad54[0x38];
    int cursor;
};
extern "C" void func_0041A100(O_41A180* o, int c);
extern "C" void String_Replace(Str_41A180* s, int pos, int count, const char* first, const char* last, Alloc_41A180 a);

extern "C" int func_0041A180(O_41A180* o, int fwd)
{
    func_0041A100(o, o->cursor);
    if (o->str.Size() == 0) return 0;
    if (fwd) {
        if (o->cursor == o->str.Size()) return 0;
        Alloc_41A180 a;
        String_Replace(&o->str, o->cursor, 1, 0, 0, a);
    } else {
        if (o->cursor == 0) return 0;
        Alloc_41A180 a;
        String_Replace(&o->str, o->cursor - 1, 1, 0, 0, a);
        o->cursor--;
    }
    o->Changed();
    return 1;
}


