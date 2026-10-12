#include "types.h"
extern void TexCache_LoadPartTexture(void* cache, __int128 name, int arg, short* slot, short* out);
extern char D_0055DDA0[];
char D_00493410[16] = "_THER_BLA_----0";
char D_00493420[16] = "_THER_COO_----0";
char D_00493430[16] = "_THER_WAR_----0";
char D_00493440[16] = "_THER_HOT_----0";
char D_00493450[16] = "_THER_FLA_----0";
extern short D_0053B360, D_0053B362, D_0053B364, D_0053B366, D_0053B368;
#pragma opt_propagation off
void TexCache_AddThermalTextures(int arg)
{
    short tmp;
    __int128* p;
    p = (__int128*)D_00493410;
    TexCache_LoadPartTexture(D_0055DDA0, *p, arg, &D_0053B360, &tmp);
    p = (__int128*)D_00493420;
    TexCache_LoadPartTexture(D_0055DDA0, *p, arg, &D_0053B362, &tmp);
    p = (__int128*)D_00493430;
    TexCache_LoadPartTexture(D_0055DDA0, *p, arg, &D_0053B364, &tmp);
    TexCache_LoadPartTexture(D_0055DDA0, *(__int128*)D_00493440, arg, &D_0053B366, &tmp);
    TexCache_LoadPartTexture(D_0055DDA0, *(__int128*)D_00493450, arg, &D_0053B368, &tmp);
}