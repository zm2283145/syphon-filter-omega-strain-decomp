#include "types.h"
typedef struct { int a, b, c, d; } Str_4D66B0;
typedef struct { char pad[0xC]; void* c; void* d; void* e; } Obj_4D66B0;
extern char D_0055A240[], D_0055A230[];
extern char func_003E75A0[], func_0013BF60[];
extern void String_CtorCStr_13B480(Str_4D66B0* s, const char* c);
extern void func_0013BCB0(void* o, Str_4D66B0* s);
extern void* func_0013BE20(void);
extern void func_0013BD40(void* a, void* b, void* c);
extern void func_00138B70(void* s, int f);
extern void __register_global_object(void* obj, void* dtor, void* link);

void func_004D66B0(void)
{
    Str_4D66B0 tmp;
    Obj_4D66B0* o = (Obj_4D66B0*)D_0055A240;
    String_CtorCStr_13B480(&tmp, "INTERFACE");
    func_0013BCB0(o, &tmp);
    func_0013BD40(func_0013BE20(), D_0055A240, D_0055A240);
    func_00138B70(&tmp, 0);
    o->c = "INTERFACE";
    o->d = "Send commands to the interface.";
    o->e = func_003E75A0;
    __register_global_object(o, func_0013BF60, D_0055A230);
}
