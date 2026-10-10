#include "types.h"
extern void* GObj_IdentityB(int handle);
extern void Global_AddTremor(void* obj, float a, float b, float c);
/* Script: AddTremor(obj, a, b, c). */
int Script_AddTremor(int* args)
{
    float c[1]; /* staged through the stack */
    float b[1];
    float a[1];
    float bv, cv;
    *(int*)c = args[3];
    *(int*)b = args[2];
    bv = *b;
    *(int*)a = args[1];
    cv = *c;
    Global_AddTremor(GObj_IdentityB(args[0]), *a, bv, cv);
    return 0;
}