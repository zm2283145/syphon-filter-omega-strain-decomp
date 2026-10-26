#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int MotionNode_BaseCtor(char **, int, char *);                
int MotionSlider_Copy(char *, int, int);                   
int MotionSlider_Dtor(char *, int);                        
int Motion_Lookup(int, int);                            
int Quat_SetIdentity(char *);                            
int cSkaNode_CheckType(int, int);                          
int cArray_cSkaBlendSequenceItem_ctor_void(char **);                              
int cSkaSlider_opAssign(char **, char *);                         
extern char D_004DFBF0;

char **cSkaSlider_ctor_cString16NR_cSkaAnimationSetR_cQuaternionR(char **arg0, int arg1, int arg2, int arg3) {
    int sp60[16];
    int sp50[4];
    int temp_v0;

    Quat_SetIdentity(sp50);
    MotionNode_BaseCtor(arg0, 2, sp50);
    *arg0 = &D_004DFBF0;
    cArray_cSkaBlendSequenceItem_ctor_void((char *)arg0 + 0x24);
    temp_v0 = Motion_Lookup(arg2, arg1);
    if (cSkaNode_CheckType(temp_v0, 2) != 0) {
        MotionSlider_Copy(sp60, temp_v0, arg3);
        cSkaSlider_opAssign(arg0, sp60);
        MotionSlider_Dtor(sp60, -1);
    }
    return arg0;
}
