#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Obj_8980 { VPAD16(a) VPAD2(b) VPAD1(c) virtual char* GetName(); };
struct Raw_8980 { int p; };
extern "C" {
Raw_8980 func_0013B180(void*);
Raw_8980 func_0028C0A0(void*);
void func_0028C0B0(char**, const Raw_8980&);
void func_0028C090(char**, const Raw_8980&);
int String_CompareNoCase(char*, char*);
}
#pragma opt_common_subs off
extern "C" Obj_8980* GuiManager_FindByName(char* self, char* name) {
    char* end;
    char* n;
    char* it;
    if (!name || !*name) return 0;
    func_0028C0B0(&it, func_0013B180(self + 0x14));
    n = it;
    while ((func_0028C090(&end, func_0028C0A0(self + 0x14)), n != end)) {
        if (String_CompareNoCase(F_(n, 0x8, Obj_8980*)->GetName(), name) == 0) return F_(n, 0x8, Obj_8980*);
        n = F_(n, 0x4, char*);
    }
    return 0;
}