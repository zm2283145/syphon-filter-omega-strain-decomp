#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_43C890;
typedef struct { char* p; } It_43C890;
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x32]; int h48; int f4C; Str_43C890 name; } O_43C890;
extern void String_CtorCStr_13B480(Str_43C890* s, char* c);
extern void func_0013D680(Str_43C890* d, Str_43C890* s);
extern void func_00138B70(Str_43C890* s, int f);
extern void func_001BFF20(It_43C890* out, Str_43C890* s);
extern void func_001BFEE0(It_43C890* out, Str_43C890* s);
extern int func_001BFE90(It_43C890* a, It_43C890* b);
extern char* func_001BFED0(It_43C890* a);
extern void func_001BFEB0(It_43C890* a);
extern void func_003813A0(int a, int b, int c);
extern int func_0043C730(O_43C890* o);
extern int D_00539248;
extern char D_004C0018[];

int func_0043C890(O_43C890* o, char* name, int arg)
{
    Str_43C890 t2;
    Str_43C890 t;
    if (o->h48 != -1) {
        func_003813A0(D_00539248, o->h48, 0);
        o->h48 = -1;
    }
    o->f4C = 0;
    {
        String_CtorCStr_13B480(&t, D_004C0018);
        func_0013D680(&o->name, &t);
        func_00138B70(&t, 0);
    }
    if (name == 0 || *name == 0) return 1;
    o->f4C = arg;
    {
        It_43C890 it;
        It_43C890 end;
        String_CtorCStr_13B480(&t2, name);
        func_0013D680(&o->name, &t2);
        func_00138B70(&t2, 0);
        func_001BFF20(&it, &o->name);
        func_001BFEE0(&end, &o->name);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'a' && *func_001BFED0(&it) <= 'z') *func_001BFED0(&it) -= 0x20;
            func_001BFEB0(&it);
        }
    }
    if (o->flags & 8) return func_0043C730(o);
    return 1;
}

