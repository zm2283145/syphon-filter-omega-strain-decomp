#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, char *);                            
int MGCLInitialize(int *, int *);                    
int NetGetMyIpAddress(char *);                               
int KM_GetSoftwareID();                                
int memset(int *, int, int);                              
extern signed char D_00584231;
extern char D_00584242;
extern char D_00584262;
extern char D_00584282;
extern char D_005842A2;
extern int D_005842C4;
extern unsigned char D_00584518;
extern char Callback_ServerEndGame;
extern char Callback_ServerJoinGame;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

#pragma opt_dead_assignments off
int SFOMGCL_Initialize_API(void) {
    struct { int f20[4]; int f30; int f34; int f38; char * f3C; char * f40; int f44; int f48; int f4C[4]; int f5C; } sl;
    int temp_v0;
    int keep;

    if (D_00584518 != 0) {
        D_00584231 = 1;
        return 0;
    }
    memset(&sl.f30, 0, 0x20);
    memset(&sl.f5C, 0, 4);
    sl.f30 = 0;
    sl.f34 = 0;
    sl.f3C = &Callback_ServerJoinGame;
    sl.f38 = 0;
    sl.f44 = 0;
    sl.f40 = &Callback_ServerEndGame;
    sl.f48 = 0x20;
    sl.f4C[0] = KM_GetSoftwareID();
    keep = temp_v0 = MGCLInitialize(&sl.f30, &sl.f5C);
    if (temp_v0 != 0) {
        return keep;
    }
    
    D_00584231 = 1;
    NetGetMyIpAddress(sl.f20);
    Libc_Strcpy(&D_00584242, sl.f20);
    Libc_Strcpy(&D_00584262, "2002");
    Libc_Strcpy(&D_00584282, sl.f20);
    Libc_Strcpy(&D_005842A2, "2002");
    D_00584518 = (D_005842C4 = 1); 
    return temp_v0;
}
#pragma pop
