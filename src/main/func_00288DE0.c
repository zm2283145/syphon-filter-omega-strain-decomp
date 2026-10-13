#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x98]; void* w98; char pad9C[4]; void* wA0; char padA4[9]; char flagAD; } SelfDE0;
extern "C" char* Loc_LookupText(const char*);
extern "C" void func_0041BEB0(void*, char*, int);
extern "C" void func_00288DE0(SelfDE0* self, char flag)
{
    if (self->wA0)
        func_0041BEB0(self->wA0, Loc_LookupText((unsigned char)flag == 0 ? "LoginAccount" : "CreateAccount"), 0);
    if (self->w98)
        func_0041BEB0(self->w98, Loc_LookupText((unsigned char)flag == 0 ? "Login" : "Register"), 0);
    self->flagAD = flag;
}




