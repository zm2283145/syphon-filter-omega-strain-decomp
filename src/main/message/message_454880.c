#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Event_Send();                         
int SoundEvent_Ctor();                    
int cMessage_dtor();                           
int FileMan_Release();                            
int GuiWidget_ClearFlag4();                                  
int GuiSubTitleDisplay_Clear();                               
extern char D_004DADF0;
extern char g_Game;

void GuiRadioLog_ClearFlag4(char * arg0) {
    struct { char * f20[8]; signed char f40[88]; int f98[39]; int f134[47]; } sl;
    int temp_a0;

    GuiWidget_ClearFlag4();
    SoundEvent_Ctor(sl.f20, arg0 + 0x50, 0);
    sl.f40[0] = 1;
    Event_Send(sl.f20, &g_Game, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        GuiSubTitleDisplay_Clear(temp_a0);
    }
    sl.f20[0] = &D_004DADF0;
    FileMan_Release(sl.f134, -1);
    FileMan_Release(sl.f98, -1);
    cMessage_dtor(sl.f20, 0);
}
