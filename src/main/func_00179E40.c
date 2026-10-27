#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00179E40 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
typedef __int128 Q128;
int nActivation_GetActivationFor(...);                
}
#pragma opt_common_subs off
extern "C" void cCollisionModelList_Game_Prepare(char * arg0) {
    Q128 *var_v0;
    char * temp_s0;
    char * temp_v0;
    char *d = arg0 + 0x40;

    temp_v0 = (char *)(F_(arg0, 0x20, int));
    if (temp_v0 != NULL) {
        temp_s0 = (char *)(F_(temp_v0, 0x50, int));
        if (F_(temp_s0, 0x50, unsigned char) != 0) {
            ((VC00179E40 *)(temp_s0))->v20();
        }
        var_v0 = (__int128 *)(temp_s0 + 0x40);
    } else {
        var_v0 = (__int128 *)(arg0 + 0x30);
    }
    VCopyF(arg0 + 0x40, var_v0);
    F_(arg0, 0x60, int) = nActivation_GetActivationFor(arg0 + 0x40);
}
