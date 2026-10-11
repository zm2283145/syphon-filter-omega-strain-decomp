#include "types.h"
extern char* D_0048C160[];
extern int D_0051EEC0[];
extern int D_0051EF10[];
extern char D_004AD0B0[];
extern int Loc_FindKeyThunk(const char* key);
extern int sprintf(char* buf, const char* fmt, ...);
void func_002CC980(void)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 0x12; i++) {
        D_0051EEC0[i] = Loc_FindKeyThunk(D_0048C160[i]);
        sprintf(buf, D_004AD0B0, i);
        D_0051EF10[i] = Loc_FindKeyThunk(buf);
    }
}