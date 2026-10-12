#include "types.h"
#include "vc_copy.h"
typedef struct { char pad[5]; char flag; char pad6[10]; __int128 q; char pad20[0x50]; } E_E230;
typedef struct { char pad[0x3A0]; E_E230 e[4]; } O_E230;
void LookCtl_SetSlotPoint(O_E230* o, unsigned char i, __int128* src) {
    E_E230* e = (E_E230*)((char*)o->e + i * sizeof(E_E230));
    __int128* d = &e->q;
    VCopyF(d, src);
    e->flag = 1;
}