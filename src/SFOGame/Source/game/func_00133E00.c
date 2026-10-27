#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00133E00 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
typedef __int128 Q128;
int cSkeleton_GetBoneToWorldMatrix(...);         
int Physical_GetPositionPtr(...);                
int cVector_opAdd(...);                    
int func_00133EC0(...);                             
}
extern "C" void cHuman_GetActivationPoint(Q128 * volatile sp2C, char * arg1) {
    char * temp_s0;
    char * temp_s0_2;

    temp_s0 = (char *)(F_(arg1, 0x3310, int));
    if (temp_s0 != NULL) {
        if (F_(temp_s0, 0x10, unsigned char) != 0) {
            cVector_opAdd(sp2C, Physical_GetPositionPtr(temp_s0 + 0x2E0), temp_s0 + 0x380);
        } else {
            Q128 sp30[4]; cSkeleton_GetBoneToWorldMatrix(sp30, F_(temp_s0, 0x8, int), 0);
            cVector_opAdd(sp2C, func_00133EC0(sp30), temp_s0 + 0x380);
        }
        return;
    }
    temp_s0_2 = (char *)(F_(arg1, 0x50, int));
    if (F_(temp_s0_2, 0x50, unsigned char) != 0) {
        ((VC00133E00 *)(temp_s0_2))->v20();
    }
    { Q128* d = sp2C; V4Copy(d, &F_(temp_s0_2, 0x40, Q128)); (void)sp2C; }
}
