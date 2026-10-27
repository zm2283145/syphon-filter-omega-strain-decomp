#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cFileMan_EncodeFilename_charP_cHogFileR_bool(char *, char *, int, int);                     
int cMemMan_Allocate(int, int, char *, int);                        
int cFileMan_dtor(char *, int);                            
int cFileMan_ctor_void(char *);                               
int cInterface_ctor(int, char *);                        
int sprintf(char *, char *, int);                           
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int LoadInterface_charP_cHogFileR(int arg0, int arg1) {
    int spD0[12];
    int sp30[40];
    int var_s0;

    cFileMan_ctor_void(sp30);
    sprintf(spD0, "%s.IE", arg0);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(sp30, spD0, arg1, 0);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 8, "hud.cc", 0x704);
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
