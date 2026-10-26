#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char *);                            
extern char D_00584220;
extern signed char D_00584235;
extern signed char D_00584236;
extern char D_00584378;

void Callback_MGCLServerSessionBegin(int d0, int d1, int d2, char * arg3) {
    D_00584235 = 1;
    if (F_(arg3, 0x15, signed char) == 0) {
        String_Copy(&D_00584220, arg3 + 0x90);
        String_Copy(&D_00584378, &D_00584220);
        D_00584236 = 1;
        return;
    }
    D_00584236 = 0;
}
