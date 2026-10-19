#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, char *);                 
int String_Dtor(char *, int);                            
int func_0013D680(char * , char *);                       
int Tex_Release(int, int, int);                       
const unsigned int D_004C0018[2] = { 0x0, 0x0 };
extern int g_TextureMgr;

#pragma push
#pragma opt_common_subs off
void func_0043C810(char * arg0) {
    struct { int f20[4]; } sl;
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        Tex_Release(g_TextureMgr, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
    F_(arg0, 0x4C, int) = 0;
    String_CtorCStr_13B480(sl.f20, &(*(char*)D_004C0018));
    func_0013D680(arg0 + 0x50, sl.f20);
    String_Dtor(sl.f20, 0);
}
#pragma pop
