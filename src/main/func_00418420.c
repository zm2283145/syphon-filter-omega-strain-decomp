#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_418420;
typedef struct { char* p; } It_418420;
typedef struct { char pad[0x18]; int value; } Node_418420;
typedef struct { Node_418420* n; } MIt_418420;
typedef struct { char pad[0x10]; int def; } O_418420;
extern void String_CtorCStr_13B480(Str_418420* s, char* c);
extern void String_Dtor(Str_418420* s, int f);
extern void func_001BFF20(It_418420* out, Str_418420* s);
extern void func_001BFEE0(It_418420* out, Str_418420* s);
extern int func_001BFE90(It_418420* a, It_418420* b);
extern char* func_001BFED0(It_418420* a);
extern void func_001BFEB0(It_418420* a);
extern void func_00419740(MIt_418420* out, O_418420* o, Str_418420* key);
extern void func_00418590(MIt_418420* out, O_418420* o);
extern void func_00418580(MIt_418420* out, MIt_418420* src);

#pragma bool off
static inline int Ne_418420(Node_418420* a, Node_418420* b) { return (a == b) ^ 1; }

int func_00418420(O_418420* o, char* name)
{
    if (name == 0 || *name == 0) return o->def;
    {
        Str_418420 s;
        MIt_418420 e;
        MIt_418420 f;
        It_418420 it;
        It_418420 end;
        MIt_418420 tmp;
        Node_418420* n;
        String_CtorCStr_13B480(&s, name);
        func_001BFF20(&it, &s);
        func_001BFEE0(&end, &s);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
            func_001BFEB0(&it);
        }
        func_00419740(&f, o, &s);
        n = f.n;
        func_00418590(&tmp, o);
        func_00418580(&e, &tmp);
        if (Ne_418420(n, e.n)) {
            int r = n->value;
            String_Dtor(&s, 0);
            return r;
        } else {
            int r = o->def;
            String_Dtor(&s, 0);
            return r;
        }
    }
}
#pragma bool reset


