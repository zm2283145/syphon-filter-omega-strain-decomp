#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int MotionNode_BaseCtor(char **, int, char *);                
int MotionSlider_Copy(char *, int, int);                   
int MotionSlider_Dtor(char *, int);                        
int Motion_Lookup(int, int);                            
int Quat_SetIdentity(char *);                            
int func_001914A0(int, int);                          
int func_001F3B20(char **);                              
int func_00201A90(char **, char *);                         
extern char D_004DFBF0;

char **func_002019D0(char **arg0, int arg1, int arg2, int arg3) {
    int sp60[16];
    int sp50[4];
    int temp_v0;

    Quat_SetIdentity(sp50);
    MotionNode_BaseCtor(arg0, 2, sp50);
    *arg0 = &D_004DFBF0;
    func_001F3B20((char *)arg0 + 0x24);
    temp_v0 = Motion_Lookup(arg2, arg1);
    if (func_001914A0(temp_v0, 2) != 0) {
        MotionSlider_Copy(sp60, temp_v0, arg3);
        func_00201A90(arg0, sp60);
        MotionSlider_Dtor(sp60, -1);
    }
    return arg0;
}
