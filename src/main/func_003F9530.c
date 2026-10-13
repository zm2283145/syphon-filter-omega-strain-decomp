#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int String_CompareNoCase(int, int);
int func_0036CD80(int);
int func_003F9520(int);
int func_003F95E0(int *, int);
int func_003F95F0(int);

void ArchiveList_CloseNamed(int arg0, int arg1) {
    int sp4C;
    int var_s0;

    var_s0 = F_(func_003F9520(arg0 + 4), 0x4, int);
    func_003F95E0(&sp4C, func_003F95F0(arg0));
    if (var_s0 != sp4C) {
        do {
            if (String_CompareNoCase(var_s0 + 8, arg1) == 0) {
                func_0036CD80(var_s0 + 8);
            }
            var_s0 = F_(var_s0, 0x4, int);
            func_003F95E0(&sp4C, func_003F95F0(arg0));
        } while (var_s0 != sp4C);
    }
}
