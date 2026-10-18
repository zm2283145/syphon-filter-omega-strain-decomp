#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Event_Send();                         
int SoundEvent_Ctor();                    
int cMessage_dtor();                           
int FileMan_Release();                            
int GuiWidget_BaseSleep();                                  
int GuiSubTitleDisplay_Clear();                               
extern char D_004DADF0;
extern char D_004FFB50;

void GuiRadioLog_Sleep(char * arg0) {
    struct { char *vt; char p04[0x1C]; signed char f40; char p41[0x57]; char f98[0x9C]; char f134[0xBC]; } m;
    int temp_a0;

    GuiWidget_BaseSleep();
    SoundEvent_Ctor(&m, arg0 + 0x50, 0);
    m.f40 = 1;
    Event_Send(&m, &D_004FFB50, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        GuiSubTitleDisplay_Clear(temp_a0);
    }
    m.vt = &D_004DADF0;
    FileMan_Release(m.f134, -1);
    FileMan_Release(m.f98, -1);
    cMessage_dtor(&m, 0);
}
