#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cSkaNode_ctor_eType_cQuaternionR(char **, int, char *);                
int cSkaSlider_ctor_cSkaSliderR_cQuaternionR(char *, int, int);                   
int cSkaSlider_dtor(char *, int);                        
int cSkaAnimationSet_GetNode_cString16NR(int, int);                            
int cQuaternion_GetIdentity(char *);                            
int cSkaNode_CheckType(int, int);                          
int cArray_cSkaBlendSequenceItem_ctor_void(char **);                              
int cSkaSlider_opAssign(char **, char *);                         
extern char D_004DFBF0;

char **cSkaSlider_ctor_cString16NR_cSkaAnimationSetR_cQuaternionR(char **arg0, int arg1, int arg2, int arg3) {
    int sp60[16];
    int sp50[4];
    int temp_v0;

    cQuaternion_GetIdentity(sp50);
    cSkaNode_ctor_eType_cQuaternionR(arg0, 2, sp50);
    *arg0 = &D_004DFBF0;
    cArray_cSkaBlendSequenceItem_ctor_void((char *)arg0 + 0x24);
    temp_v0 = cSkaAnimationSet_GetNode_cString16NR(arg2, arg1);
    if (cSkaNode_CheckType(temp_v0, 2) != 0) {
        cSkaSlider_ctor_cSkaSliderR_cQuaternionR(sp60, temp_v0, arg3);
        cSkaSlider_opAssign(arg0, sp60);
        cSkaSlider_dtor(sp60, -1);
    }
    return arg0;
}
