#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int GuiWidget_BroadcastEvent(char * , int, int, int);                 
int func_0041E2B0();                                  

void GuiSliderWidget_OnLoseFocus(char * arg0) {
    char * temp_v0;
    int temp_a0;
    int temp_t1;
    int temp_t0;
    float r;

    func_0041E2B0();
    F_(arg0, 0x48, int) = 1;
    temp_a0 = F_(arg0, 0x48, int);
    if (F_((char *)temp_a0 + (int)arg0, 0x4C, unsigned char) != 0) {
        temp_t1 = F_(arg0, 0x68, int);
        temp_v0 = (char *)(temp_a0 * 4) + (int)(arg0);
        temp_t0 = F_(temp_v0, 0x50, int);
        r = (float) (F_(arg0, 0x64, int) - temp_t1) / (float) (F_(arg0, 0x6C, int) - temp_t1);
        GuiWidget_BroadcastEvent(arg0, 0xA, temp_t0 + (int) (r * (float) (F_(temp_v0, 0x58, int) - temp_t0)), 0);
    }
}


