#include "types.h"
extern void func_00403A20(void* cache, __int128 name, int arg, short* slot, short* out);
extern char D_0055DDA0[];
extern __int128 D_00493410, D_00493420, D_00493430, D_00493440, D_00493450;
extern short D_0053B360, D_0053B362, D_0053B364, D_0053B366, D_0053B368;
#pragma opt_propagation off
void func_0038DD40(int arg)
{
    short tmp;
    __int128* p;
    p = &D_00493410;
    func_00403A20(D_0055DDA0, *p, arg, &D_0053B360, &tmp);
    p = &D_00493420;
    func_00403A20(D_0055DDA0, *p, arg, &D_0053B362, &tmp);
    p = &D_00493430;
    func_00403A20(D_0055DDA0, *p, arg, &D_0053B364, &tmp);
    func_00403A20(D_0055DDA0, D_00493440, arg, &D_0053B366, &tmp);
    func_00403A20(D_0055DDA0, D_00493450, arg, &D_0053B368, &tmp);
}