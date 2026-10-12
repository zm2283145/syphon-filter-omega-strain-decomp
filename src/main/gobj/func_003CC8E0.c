#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC003CC8E0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); virtual int v25(...); };
extern "C" {

}
extern "C" int TeamTable_AreEnemies(char * arg0, char * arg1) {
    int var_v0;
    void **temp_a0;
    void **temp_s0;

    temp_s0 = (void **)(F_(arg0, 0x58, int));
    var_v0 = -1;
    if (temp_s0 != NULL) {
        temp_a0 = (void **)(F_(arg1, 0x58, int));
        if (temp_a0 != NULL) {
            var_v0 = ((VC003CC8E0 *)(temp_a0))->v24();
        }
        var_v0 = ((VC003CC8E0 *)(temp_s0))->v25(var_v0) & 0xFF;
    }
    return var_v0 != 0;
}
