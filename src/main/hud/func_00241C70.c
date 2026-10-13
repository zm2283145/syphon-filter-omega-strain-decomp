#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int Archive_Open();                     
int Hog_Register();                   
int Mem_Alloc();                        
int func_0036E220();                            
int func_0036E5D0();                               
int Interface_Ctor();                        
int sprintf();                      
extern char D_0048B2F8;
extern char D_004A7208;
extern char D_004A7210;
extern unsigned char D_00533880;
extern int D_00533888;

int func_00241C70(char *arg0, int arg1) {
    int spF0[36];
    int spD0[8];
    int sp30[40];
    int var_s0;

    func_0036E5D0(sp30);
    sprintf(spF0, "%s\\COMMON\\%s.HOG", &D_0048B2F8, arg0);
    sprintf(spD0, &D_004A7208, arg0);
    Hog_Register(sp30, spD0, Archive_Open(arg1, spF0, 0, 0), 0);
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    var_s0 = Mem_Alloc(0, 8, &D_004A7210, 0x6F1);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (var_s0 != 0) {
        var_s0 = Interface_Ctor(var_s0, sp30);
    }
    func_0036E220(sp30, -1);
    return var_s0;
}
