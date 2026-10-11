#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char *);                            
int func_00443E70();                                
int func_00452F70(char * , int, int);                      
int func_004534A0(char * , int, int, int);             
int func_0046C7A0(char *, char *);                        
int memset(char *, int, int);                                
extern int D_00497890;
extern char D_004C0EC0;
extern char func_00446740;

typedef struct { char p0[552]; int f228; int f22C; char p230[28]; int f24C; } PS0_0044D780;
void func_0044D780(PS0_0044D780 *arg0) {
    int sp30[8];
    int temp_v0;

    if (arg0->f228 == 0) {
        arg0->f228 = 1;
        memset(sp30, 0, 0x15);
        String_Copy(sp30, &D_004C0EC0);
        arg0->f24C = func_0046C7A0(sp30, &func_00446740);
        if (arg0->f24C == 0) {
            temp_v0 = func_00443E70();
            arg0->f22C = 0;
            if (arg0->f22C == 0) {
loop_4:
                func_00452F70(arg0, 0, 0);
                if (func_004534A0(arg0, temp_v0, D_00497890, 0) != 0) {
                    if (arg0->f22C != 0) {

                    } else {
                        goto loop_4;
                    }
                }
            }
        }
    }
}
