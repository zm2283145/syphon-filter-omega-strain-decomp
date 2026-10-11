#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int GuiWidget_ctor(...);                                 
char * Mem_Alloc(...);                      
extern char D_004B9BB0;
extern char D_004DE830;
extern char D_004E1220;
extern int D_00532FD8;
extern char * D_00532FE0;
extern unsigned char D_00533880;
}
extern "C" char * GuiScreen_ctor(char * arg0) {
    char * temp_s1;

    GuiWidget_ctor();
    F_(arg0, 0x0, int) = (int)(&D_004E1220);
    F_(arg0, 0x48, int) = -2;
    F_(arg0, 0x0, int) = (int)(&D_004DE830);
    if ((D_00532FD8 == 0) && (D_00532FE0 == NULL)) {
        {
            AllocGuard g;
        temp_s1 = Mem_Alloc(0, 0xC, &D_004B9BB0, 0x5B);
        }
        if (temp_s1 != NULL) {
            F_(temp_s1, 0x0, int) = 0;
            F_(temp_s1, 0x4, int) = 0;
            F_(temp_s1, 0x8, int) = 0;
        }
        D_00532FE0 = temp_s1;
    }
    D_00532FD8 += 1;
    F_(arg0, 0x78, signed char) = 0;
    F_(arg0, 0x80, signed char) = 0;
    return arg0;
}
