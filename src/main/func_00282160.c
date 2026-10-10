#include "types.h"
extern void Script_ReadU32(int* handle);
extern int Object_LookupById(int* handle);
/* Look up a handle and store the result in *out. */
void func_00282160(int* out)
{
    int handle = -1;
    Script_ReadU32(&handle);
    *out = Object_LookupById(&handle);
}
