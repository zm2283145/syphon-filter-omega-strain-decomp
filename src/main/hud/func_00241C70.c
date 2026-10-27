#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int EnableIntc();                                  
int cHogList_Open();                     
int cFileMan_EncodeFilename_charP_cHogFileR_bool();                   
int cMemMan_Allocate();                        
int cFileMan_dtor();                            
int cFileMan_ctor_void();                               
int cInterface_ctor();                        
int sprintf();                      
extern char D_0048B2F8;
extern char D_004A7208;
extern char D_004A7210;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int LoadInterface_charP_cHogListR(char *arg0, int arg1) {
    int spF0[36];
    int spD0[8];
    int sp30[40];
    int var_s0;

    cFileMan_ctor_void(sp30);
    sprintf(spF0, "%s\\COMMON\\%s.HOG", &D_0048B2F8, arg0);
    sprintf(spD0, &D_004A7208, arg0);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(sp30, spD0, cHogList_Open(arg1, spF0, 0, 0), 0);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 8, &D_004A7210, 0x6F1);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s0 != 0) {
        var_s0 = cInterface_ctor(var_s0, sp30);
    }
    cFileMan_dtor(sp30, -1);
    return var_s0;
}
