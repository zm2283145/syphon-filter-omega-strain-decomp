#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
char *strncpy(char *, char *, int);                            
extern signed char D_005721D8;
extern signed char D_005721E0;
extern signed char D_005721F0;
extern signed char D_005723B0;

void GameOptions_QueueDialog(signed char arg0, char *arg1, char *arg2) {
    D_005723B0 = arg0;
    D_005721D8 = 1;
    strncpy(&D_005721E0, arg1, 0x10);
    if (arg2 != 0) {
        strncpy(&D_005721F0, arg2, 0x80);
        return;
    }
    D_005721F0 = 0;
}
