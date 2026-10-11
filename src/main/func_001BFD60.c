#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_1BFD60;
typedef struct { char* p; } It_1BFD60;
extern void String_CtorCStr_13B480(Str_1BFD60* s, char* c);
extern void func_0013D680(Str_1BFD60* d, Str_1BFD60* s);
extern void func_00138B70(Str_1BFD60* s, int f);
extern void func_001BFF20(It_1BFD60* out, Str_1BFD60* s);
extern void func_001BFEE0(It_1BFD60* out, Str_1BFD60* s);
extern int func_001BFE90(It_1BFD60* a, It_1BFD60* b);
extern char* func_001BFED0(It_1BFD60* a);
extern void func_001BFEB0(It_1BFD60* a);
extern char* func_001692D0(Str_1BFD60* s);
extern void func_001BFF40(void* mgr, char* name);
extern void* D_004FFBD8;
static inline void Ctor_1BFD60(Str_1BFD60* s) { s->word = 0; s->length = 0; s->data = 0; }

#pragma opt_propagation off
void Global_LoadAnimation(char* name)
{
    It_1BFD60 it;
    It_1BFD60 end;
    Str_1BFD60 s;
    { Str_1BFD60* ps = &s; ps->word = 0; ps->length = 0; ps->data = 0; }
    if (name[0]) {
        Str_1BFD60 t;
        String_CtorCStr_13B480(&t, name);
        func_0013D680(&s, &t);
        func_00138B70(&t, 0);
        func_001BFF20(&it, &s);
        func_001BFEE0(&end, &s);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
            func_001BFEB0(&it);
        }
    } else {
        Str_1BFD60 t2;
        String_CtorCStr_13B480(&t2, name);
        func_0013D680(&s, &t2);
        func_00138B70(&t2, 0);
    }
    func_001BFF40(D_004FFBD8, func_001692D0(&s));
    func_00138B70(&s, 0);
}



