#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { int kind; String name; } Src;
typedef struct { char pad[0x100]; int kind; String name; } Item;
extern void* D_004FFC04;
extern char D_004ABCD0[];
extern void String_CtorCStr_13B480(String* dst, String* src);
extern void func_0013D680(String* dst, String* src);
extern void func_00138B70(String* s, int flags);
extern int func_0033CE30(Item* it, int id, String* name, int a, int b, int c);
extern void func_002CAE30(void* mgr, int a, char* fmt, int v, Item* it, int b);
/* Copies kind and name from src, then registers the item. */
void func_002AF190(Item* it, Src* src)
{
    String tmp;
    void* mgr;
    it->kind = src->kind;
    String_CtorCStr_13B480(&tmp, &src->name);
    func_0013D680(&it->name, &tmp);
    func_00138B70(&tmp, 0);
    mgr = D_004FFC04;
    func_002CAE30(mgr, 5, D_004ABCD0, func_0033CE30(it, 0x51, &src->name, 0, 0, 0), it, 0x12);
}
