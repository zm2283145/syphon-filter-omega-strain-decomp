#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int Loc_ReadPoolFile();                       
int Mem_Alloc();                        
signed char func_0043FBB0();                         
int sprintf();                      
extern char D_00493A40;
extern char D_004BE440;
extern char D_004BE470;
extern char D_004BE490;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0055CA40;
extern int D_0055CA74;
extern int D_0055CA80;
extern char D_0055CA90;
extern signed char D_0055D450;
extern int D_0055D458;
extern int D_0055D460;
extern int D_0055D468;
extern unsigned char D_0055D470;

void Loc_LoadCommonPool(int arg0) {
    int sp130[68];
    int sp30[64];
    int temp_s1;

    sprintf(sp130, &D_004BE470, arg0, F_(&D_00493A40, (D_0055D470 * 4), int));
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s1 = Mem_Alloc(0, 0x1E000, &D_004BE440, 0x110);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_0055D458 = temp_s1;
    D_0055D460 = temp_s1;
    D_0055D468 = temp_s1;
    D_00533888 -= 1;
    Loc_ReadPoolFile(&D_0055CA40, sp130);
    D_0055CA80 = D_0055CA74;
    D_0055D468 = D_0055D460;
    sprintf(sp30, &D_004BE490, arg0);
    D_0055D450 = func_0043FBB0(&D_0055CA90, sp30);
}
