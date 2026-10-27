#include "types.h"
typedef struct { int a, b, c, d; } Str_4D66B0;
typedef struct { char pad[0xC]; void* c; void* d; void* e; } Obj_4D66B0;
extern char D_0055A240[], D_0055A230[];
extern char confunc_INTERFACE[], cConsCommand_dtor[];
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_4D66B0* s, const char* c);
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* o, Str_4D66B0* s);
extern void* cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(void);
extern void cKeyedRegistry_cString_cConsCommand_Register(void* a, void* b, void* c);
extern void String_Dtor(void* s, int f);
extern void __register_global_object(void* obj, void* dtor, void* link);

void StaticInit_interface(void)
{
    Str_4D66B0 tmp;
    Obj_4D66B0* o = (Obj_4D66B0*)D_0055A240;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, "INTERFACE");
    std_basic_string_char_char_traits_char_ctor_basicstringR(o, &tmp);
    cKeyedRegistry_cString_cConsCommand_Register(cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(), D_0055A240, D_0055A240);
    String_Dtor(&tmp, 0);
    o->c = "INTERFACE";
    o->d = "Send commands to the interface.";
    o->e = confunc_INTERFACE;
    __register_global_object(o, cConsCommand_dtor, D_0055A230);
}
