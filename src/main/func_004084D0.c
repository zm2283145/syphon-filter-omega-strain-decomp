#include "types.h"
typedef struct { int a; int b; int c; } S4D0Str;
typedef struct { char pad[0x18]; unsigned char val; } S4D0Node;
typedef struct { S4D0Node* n; } S4D0It;
typedef struct { void* map; int b; unsigned char ready; } S4D0Obj;
extern void String_CtorCStr_13B480(S4D0Str* s, const char* c);
extern void func_00138B70(S4D0Str* s, int del);
extern void func_004097A0(S4D0It* out, void* map, S4D0Str* key);
extern void func_00408590(S4D0It* out, void* map);
extern void func_00408580(S4D0It* out, S4D0It* in);
/* Looks up name in the object's map and returns its byte value. */
int func_004084D0(S4D0Obj* o, const char* name, unsigned char* out) {
    S4D0It e2;
    S4D0It it;
    S4D0It e1;
    S4D0Str s;
    S4D0Node* n;
    if (!o->ready)
        return 0;
    String_CtorCStr_13B480(&s, name);
    func_004097A0(&it, o->map, &s);
    n = it.n;
    func_00138B70(&s, 0);
    func_00408590(&e1, o->map);
    func_00408580(&e2, &e1);
    if (n == e2.n)
        return 0;
    *out = n->val;
    return 1;
}