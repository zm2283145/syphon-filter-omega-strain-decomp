#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int QueueMessage_cMessageR_cSystemP_int();                         
int cStopSoundMsg_ctor_cSndFxR_bool();                    
int cMessage_dtor();                           
int cFileMan_dtor();                            
int GuiWidget_onSleep();                                  
int GuiSubTitleDisplay_Clear();                               
extern char D_004DADF0;
extern char g_Game;

void GuiRadioLog_onSleep(char * arg0) {
    struct { char *vt; char p04[0x1C]; signed char f40; char p41[0x57]; char f98[0x9C]; char f134[0xBC]; } m;
    int temp_a0;

    GuiWidget_onSleep();
    cStopSoundMsg_ctor_cSndFxR_bool(&m, arg0 + 0x50, 0);
    m.f40 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, &g_Game, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        GuiSubTitleDisplay_Clear(temp_a0);
    }
    m.vt = &D_004DADF0;
    cFileMan_dtor(m.f134, -1);
    cFileMan_dtor(m.f98, -1);
    cMessage_dtor(&m, 0);
}
