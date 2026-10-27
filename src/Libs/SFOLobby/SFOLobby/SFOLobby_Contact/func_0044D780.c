#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, char *);                            
int SFOLobby_GetMillisecs();                                
int SFOLobby_GuiCallback(char * , int, int);                      
int SFOLobby_Poll(char * , int, int, int);             
int MediusGetBuddyInvitations(char *, char *);                        
int memset(char *, int, int);                                
extern int D_00497890;
extern char SFOLobby_Callback_GetBuddyInvitations;

typedef struct { char p0[552]; int f228; int f22C; char p230[28]; int f24C; } PS0_0044D780;
void SFOLobby_ContactGetInvites(PS0_0044D780 *arg0) {
    int sp30[8];
    int temp_v0;

    if (arg0->f228 == 0) {
        arg0->f228 = 1;
        memset(sp30, 0, 0x15);
        Libc_Strcpy(sp30, "1");
        arg0->f24C = MediusGetBuddyInvitations(sp30, &SFOLobby_Callback_GetBuddyInvitations);
        if (arg0->f24C == 0) {
            temp_v0 = SFOLobby_GetMillisecs();
            arg0->f22C = 0;
            if (arg0->f22C == 0) {
loop_4:
                SFOLobby_GuiCallback(arg0, 0, 0);
                if (SFOLobby_Poll(arg0, temp_v0, D_00497890, 0) != 0) {
                    if (arg0->f22C != 0) {

                    } else {
                        goto loop_4;
                    }
                }
            }
        }
    }
}
