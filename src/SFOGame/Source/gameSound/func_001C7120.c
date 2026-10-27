#include "types.h"
#pragma global_optimizer off
extern int cGOBJ_SOBJ_convert(void* p);
extern void nGameSound_PlayQuip_charP_cGOBJP_int(int a, int b, int c);
static inline void d6_quip(int c, void* o, int a) { int id = cGOBJ_SOBJ_convert(o); nGameSound_PlayQuip_charP_cGOBJP_int(a, id, c); }
int Script_PlayQuip_2(int* args)
{
    int a[1];
    int c[1];
    c[0] = args[2];
    a[0] = args[0];
    d6_quip(*(int*)c, (void*)args[1], *(int*)a);
    return 0;
}