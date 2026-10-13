#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC00414AC0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(...); virtual int v24(...); };
extern "C" {

}
extern "C" void GuiStack_SwapScreens(void **arg0, int arg1, int arg2) {
    if (arg1 != 0) {
        ((VC00414AC0 *)(arg0))->v24();
    }
    if (arg2 != 0) {
        ((VC00414AC0 *)(arg0))->v23(arg2, 0);
    }
}
