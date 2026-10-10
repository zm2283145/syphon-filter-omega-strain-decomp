#include "types.h"

typedef struct { char b[0xC]; } String;
typedef struct { int id; char name[1]; } NameRec;
typedef struct { char pad[0x100]; int id; String name; } Obj2AD;
extern void* D_004FFC04;
extern char D_004ABB08[];
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(String* dst, String* src);
extern void func_00138B70(String* s, int flag);
extern int func_001692D0(String* s);
extern int func_0033CE30(Obj2AD* o, int type, int a, int b, int c, int d);
extern void func_002CAE30(void* mgr, int a, const char* text, int b, Obj2AD* o, int c);

/* Sets the id and name from rec, then registers the object (event 0x35) with the manager. */
void func_002ADA10(Obj2AD* o, NameRec* rec)
{
    void* mgr;
    String tmp;
    int h;
    o->id = rec->id;
    String_CtorCStr_13B480(&tmp, rec->name);
    func_0013D680(&o->name, &tmp);
    func_00138B70(&tmp, 0);
    h = func_001692D0(&o->name);
    mgr = D_004FFC04;
    func_002CAE30(mgr, 5, D_004ABB08, func_0033CE30(o, 0x35, h, 0, 0, 0), o, 0xD);
}
