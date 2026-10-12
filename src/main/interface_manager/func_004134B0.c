#pragma cplusplus on
#include "types.h"

struct Str4134B0 { int a; int b; int c; };
struct List4134B0 { int pad0; int count; Str4134B0* data; };
struct Self4134B0 { char pad[0x1E4]; List4134B0* list; int arc; };
struct Hog4134B0 { char pad[0xA0]; };

extern "C" {
char* func_001692D0(Str4134B0* s);
int sprintf(char* buf, const char* fmt, ...);
void func_0036E5D0(Hog4134B0* h);
void func_0036E220(Hog4134B0* h, int flags);
void func_0036E140(Hog4134B0* h, char* name, int a, int b);
void Hog_Register(Hog4134B0* h, char* name, int arc, int z);
int func_0036DEF0(Hog4134B0* h);
void String_CtorCStr_13B480(Str4134B0* s, char* src);
void func_0013D680(Str4134B0* dst, Str4134B0* src);
void func_00138B70(Str4134B0* s, int flags);
}

#pragma push
#pragma opt_strength_reduction off
extern "C" bool func_004134B0(Self4134B0* self, Str4134B0* out, const char* name, unsigned char* isPak)
{
    Str4134B0 tmp;
    Str4134B0 tmp2;
    char buf[0x80];
    Hog4134B0 h;
    char buf2[0x80];
    Hog4134B0 h2;
    int i;
    if (!name || !*name || !self->list)
        return false;
    for (i = self->list->count - 1; i >= 0; i--) {
        char* p;
        func_0036E5D0(&h);
        sprintf(buf, "%s\\%s.HOG", func_001692D0(&self->list->data[i]), name);
        for (p = buf; *p; p++) {
            char c = *p;
            if (c >= 'a' && c <= 'z')
                *p -= 0x20;
        }
        func_0036E140(&h, buf, 0, 0);
        if ((unsigned char)func_0036DEF0(&h)) {
            func_0036E220(&h, -1);
            continue;
        }
        {
            String_CtorCStr_13B480(&tmp, buf);
            func_0013D680(out, &tmp);
            func_00138B70(&tmp, 0);
        }
        if (isPak)
            *isPak = 0;
        func_0036E220(&h, -1);
        return true;
    }
    if (self->arc) {
        func_0036E5D0(&h2);
        sprintf(buf2, "%s.HOG", name);
        Hog_Register(&h2, buf2, self->arc, 0);
        if ((unsigned char)func_0036DEF0(&h2)) {
            func_0036E220(&h2, -1);
            return false;
        }
        {
            String_CtorCStr_13B480(&tmp2, buf2);
            func_0013D680(out, &tmp2);
            func_00138B70(&tmp2, 0);
        }
        if (isPak)
            *isPak = 1;
        func_0036E220(&h2, -1);
        return true;
    }
    return false;
}
#pragma pop
