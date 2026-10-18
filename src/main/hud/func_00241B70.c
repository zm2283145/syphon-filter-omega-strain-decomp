#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Hog_Register(char *, char *, int, int);                     
int Mem_Alloc(int, int, char *, int);                        
int FileMan_Release(char *, int);                            
int Resource_Construct(char *);                               
int Interface_Ctor(int, char *);                        
int sprintf(char *, char *, int);                           
extern unsigned char D_00533880;
extern int D_00533888;

int LoadingScreen_BuildIeScreen(int arg0, int arg1) {
    int spD0[12];
    int sp30[40];
    int var_s0;

    Resource_Construct(sp30);
    sprintf(spD0, "%s.IE", arg0);
    Hog_Register(sp30, spD0, arg1, 0);
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    var_s0 = Mem_Alloc(0, 8, "hud.cc", 0x704);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (var_s0 != 0) {
        var_s0 = Interface_Ctor(var_s0, sp30);
    }
    FileMan_Release(sp30, -1);
    return var_s0;
}
