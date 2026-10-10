#include "types.h"
#pragma global_optimizer off
extern int GObj_IdentityB(void* p);
extern void Global_PlayQuip(int a, int b, int c);
static inline void d6_quip(int c, void* o, int a) { int id = GObj_IdentityB(o); Global_PlayQuip(a, id, c); }
int Script_PlayQuip_2(int* args)
{
    int a[1];
    int c[1];
    c[0] = args[2];
    a[0] = args[0];
    d6_quip(*(int*)c, (void*)args[1], *(int*)a);
    return 0;
}