#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
float SoftFloat_U64ToFloat(int);                             
int Time_GetMilliseconds();                                

int GuiTitleScreen_HandleInput(int arg0) {
    F_(arg0, 0x4C, float) = (float) (SoftFloat_U64ToFloat(Time_GetMilliseconds()) / 1000.0f);
    return 0;
}
