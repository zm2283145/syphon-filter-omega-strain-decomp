#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_4185A0;
typedef struct { char* p; } It_4185A0;
typedef struct { Str_4185A0 first; int second; } Pair_4185A0;
typedef struct { void* it; unsigned char ok; } Res_4185A0;
typedef struct { char pad[0x10]; int def; } O_4185A0;
extern void String_CtorCStr_13B480(Str_4185A0* s, char* c);
extern void String_Dtor(Str_4185A0* s, int f);
extern void func_0013BCB0(Str_4185A0* d, Str_4185A0* s);
extern void func_001BFF20(It_4185A0* out, Str_4185A0* s);
extern void func_001BFEE0(It_4185A0* out, Str_4185A0* s);
extern int func_001BFE90(It_4185A0* a, It_4185A0* b);
extern char* func_001BFED0(It_4185A0* a);
extern void func_001BFEB0(It_4185A0* a);
extern void func_00418780(Pair_4185A0* out, Str_4185A0* k, int v);
extern void func_00419D10(Res_4185A0* out, O_4185A0* o, Pair_4185A0* p);

unsigned char func_004185A0(O_4185A0* o, char* name, int w, int force)
{
    if (name == 0 || w == 0) return 0;
    if (force || o->def == 0) o->def = w;
    {
        Str_4185A0 s;
        It_4185A0 it;
        It_4185A0 end;
        Res_4185A0 r;
        Str_4185A0 k;
        Pair_4185A0 p;
        Pair_4185A0 q;
        unsigned char ok;
        String_CtorCStr_13B480(&s, name);
        func_001BFF20(&it, &s);
        func_001BFEE0(&end, &s);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
            func_001BFEB0(&it);
        }
        func_0013BCB0(&k, &s);
        func_00418780(&p, &k, w);
        func_0013BCB0(&q.first, &p.first);
        q.second = p.second;
        func_00419D10(&r, o, &q);
        ok = r.ok;
        String_Dtor(&q.first, 0);
        String_Dtor(&p.first, 0);
        String_Dtor(&k, 0);
        String_Dtor(&s, 0);
        return ok;
    }
}
