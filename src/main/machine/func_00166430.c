#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Archive_Open(char *, int, int, int);                     
int Loc_LookupText(char *);                            
int Mem_Alloc(int, int, char *, int);                        
int atoi(signed char *);                            
int func_00166650();                                  
int func_00166690(char *);                               
int func_00271B10(int, float);                            
int func_00271D80(int);                               
int func_002721B0(int, int, char *);                   
int func_0036DEF0(char *);                             
int func_0036E220(char *, int);                            
int func_0036E4B0(char *, int, int, int);                    
signed char *func_003CBA90(char *);                             
int func_003F9600(char *, int);                        
int sprintf(char *, char *, char *);                           
extern char D_0049C390;
extern int D_004EE4C8;
extern int D_004EE4D0;
extern signed char D_004EE4D8;
extern int D_004EE500;
extern int D_004EE508;
extern int D_004EE510;
extern int D_004EE518;
extern char D_004FFB8C;
extern char D_004FFC90;
extern unsigned char D_00533880;
extern int D_00533888;
extern char func_00166840;

typedef struct { char p0[624]; int f270; int f274; char p278[8]; int f280; } PS0_00166430;
void func_00166430(PS0_00166430 *arg0, int d1, int arg2) {
    int spC0[40];
    int sp40[32];
    int var_s2;
    signed char *temp_v0;

    if (arg2 != 0) {
        func_0036E4B0(spC0, arg2, 0, 0);
        if (!(func_0036DEF0(spC0) & 0xFF)) {
            Archive_Open(&D_004FFB8C, arg2, 0, 1);
            arg0->f270 = func_003F9600(&D_004FFB8C, arg2);
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            var_s2 = Mem_Alloc(0, 0x3C, &D_0049C390, 0x7A9);
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            if (var_s2 != 0) {
                var_s2 = func_002721B0(var_s2, arg0->f270, "loading_screen");
            }
            arg0->f274 = var_s2;
            func_00271D80(arg0->f274);
            func_00271B10(arg0->f274, 0.0f);
        }
        func_0036E220(spC0, -1);
    }
    if (arg2 != 0) {
        D_004EE500 = arg0->f274;
        D_004EE508 = arg0->f280;
        D_004EE518 = Loc_LookupText("LoadingText");
        D_004EE510 = Loc_LookupText("Continue");
        func_00166690(&func_00166840);
    }
    func_00166650();
    sprintf(sp40, "%s_LOADINGFRAMES", &D_004FFC90);
    temp_v0 = func_003CBA90(sp40);
    if ((temp_v0 == NULL) || (*temp_v0 == 0)) {
        D_004EE4D8 = 0;
        D_004EE4D0 = 0x4B0;
    } else {
        D_004EE4D0 = atoi(temp_v0);
        D_004EE4D8 = 1;
    }
    D_004EE4C8 = 0;
}

