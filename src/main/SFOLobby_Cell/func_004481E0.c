#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_NoInstance();                                
int SFOLobby_SetError(char * , int, char *, int);                 
extern char D_004C0D10;
extern char * D_00585E60;

void func_004481E0(int d0, int d1, int d2, char * arg3) {
    int temp_a0;

    if (SFOLobby_NoInstance() == 0) {
        F_(D_00585E60, 0x1DC, int) = 1;
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x941);
            break;
        }
    }
}
