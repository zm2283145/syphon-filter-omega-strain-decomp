#include "types.h"
extern char D_004F53B8[];
extern char D_004F53C8[];
extern char D_004F53D8[];
extern char D_004F53E8[];
void func_004CCA30(void)
{
    *(int*)D_004F53B8 = (int)"MSGGAME_PLAYSND";
    *(int*)D_004F53C8 = (int)"MSGGAME_PLAYVAG";
    *(int*)D_004F53D8 = (int)"MSGGAME_STOPSND";
    *(int*)D_004F53E8 = (int)"MSGGAME_PAUSEMUSIC";
}
