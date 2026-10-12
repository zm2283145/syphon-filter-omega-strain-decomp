#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC001866E0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(...); };
extern "C" {
int Event_Construct(...);                       
int Event_Send(...);                      
int cMessage_dtor(...);                           
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_001867C0();
extern "C" void func_003E61F0();
extern "C" void func_003E7250();
void * const D_004E01C0[8] = { (void*)0x0, (void*)0x0, (void*)func_001867C0, (void*)func_003E7250, (void*)func_003E61F0, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
extern char D_004E0840;
extern char D_0055D480;
extern unsigned char D_005721C8;
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
}
extern "C" void Actor_ApplyFlash(char * arg0, int arg1, float farg0) {
    struct { char * f40[7]; int f5C; signed char f60[4]; int f64; signed char f68[4]; float f6C; } sl;
    void **temp_a0;

    F_(arg0, 0x33AC, float) = farg0;
    if (F_(arg0, 0x14, unsigned char) != 0) {
        temp_a0 = (void **)(F_(arg0, 0x58, int));
        if (temp_a0 != NULL) {
            ((VC001866E0 *)(temp_a0))->v19();
        }
    }
    if ((D_005721C8 != 0) && (arg1 == 0)) {
        Event_Construct(sl.f40, &D_0055D480);
        sl.f64 = 0x46;
        sl.f68[0] = 3;
        sl.f40[0] = &(*(char*)D_004E01C0);
        sl.f60[0] = 4;
        sl.f5C = 0x40;
        sl.f6C = farg0;
        Event_Send(sl.f40, arg0, 0);
        sl.f40[0] = &D_004E0840;
        cMessage_dtor(sl.f40, 0);
    }
}
