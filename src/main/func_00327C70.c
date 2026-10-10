#include "types.h"

typedef struct String {
    int a, b, c;
} String;

typedef struct Obj84 {
    char pad[0x6C];
    String name;
    String desc;
    int value;
} Obj84;

extern void String_CtorCStr_13B480(String*, const char*);
extern void func_0013D680(String*, String*);
extern void func_00138B70(String*, int);

/* Sets two string fields and an int. */
void func_00327C70(Obj84* o, const char* name, const char* desc, int value) {
    String tmp2;
    String tmp1;
    String_CtorCStr_13B480(&tmp1, name);
    func_0013D680(&o->name, &tmp1);
    func_00138B70(&tmp1, 0);
    String_CtorCStr_13B480(&tmp2, desc);
    func_0013D680(&o->desc, &tmp2);
    func_00138B70(&tmp2, 0);
    o->value = value;
}
