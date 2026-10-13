#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Loc_LookupText(int);
int func_0033D8E0(int, int);
int func_0041BEB0(int, int, int);
int DME_GetLobby();
int func_004515F0(int, int);
extern char D_004AB698[];
void * const D_0048BBD8[2] = { (void*)D_004AB698, (void*)0x0 };

void func_002A8BE0(int arg0) {
    int temp_a0;
    int temp_v0;

    func_0033D8E0(arg0, 0);
    if (DME_GetLobby() != 0) {
        func_004515F0(DME_GetLobby(), 1);
    }
    temp_v0 = Loc_LookupText((*(int*)D_0048BBD8));
    if (temp_v0 != 0) {
        temp_a0 = F_(arg0, 0x160, int);
        if (temp_a0 != 0) {
            func_0041BEB0(temp_a0, temp_v0, 0);
        }
    }
}
