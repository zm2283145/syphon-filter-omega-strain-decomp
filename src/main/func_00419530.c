#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00419530 { virtual int v0(); virtual int v1(...); };
extern "C" {
int func_002CCE50(...);                      
}
extern "C" void GuiManager_AddWidget(int arg0, char * arg1) {
    void **temp_a0;

    if (!(F_(arg1, 0x14, unsigned short) & 1)) {
        func_002CCE50(arg0 + 0x14, &arg1);
        temp_a0 = (void **)(F_(arg1, 0x44, int));
        ((VC00419530 *)(temp_a0))->v1();
    }
}
