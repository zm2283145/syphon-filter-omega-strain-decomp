#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int GuiObjectives_ctor(...);                 
char * Mem_Alloc(int, int, char *, int);                      
extern char D_004C1CA0;
extern char D_004E1430;
extern unsigned char D_00533880;
}
extern "C" char * func_004575D0(void) {
    char * temp_s0;

    {
        AllocGuard g;
    temp_s0 = (char *)(Mem_Alloc(0, 0xB4, &D_004C1CA0, 0x2A));
    }
    if (temp_s0 != NULL) {
        GuiObjectives_ctor(temp_s0, 1, 1);
        F_(temp_s0, 0x0, int) = (int)(&D_004E1430);
        F_(temp_s0, 0x90, int) = 0;
        F_(temp_s0, 0x94, int) = 0;
        F_(temp_s0, 0x98, int) = 0;
        F_(temp_s0, 0x9C, int) = 0;
        F_(temp_s0, 0xA0, int) = 0;
        F_(temp_s0, 0xA4, int) = 0;
        F_(temp_s0, 0xA8, int) = 0;
        F_(temp_s0, 0x14, unsigned short) = (unsigned short) (F_(temp_s0, 0x14, unsigned short) & 0xFFDF);
    }
    return temp_s0;
}
