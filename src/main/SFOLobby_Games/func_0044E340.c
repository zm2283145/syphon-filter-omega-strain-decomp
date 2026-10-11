#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00443020(char * );                          
int func_00444040(int);                                 
int func_00444050(int);                                 
int func_00444060();                                
int func_00444070(int);                               
int func_0044C940(char * , int);                         
int func_004505E0(char * , char *);                       
int func_00452F30(char * , int, char *);                    
extern char D_00585E90;
extern int D_00585F78;
extern int D_00585F7C;
extern int D_00585F80;
extern int D_00585F84;
extern signed char D_00585F88;
extern signed char D_00585F89;

#pragma opt_common_subs off
void func_0044E340(char * arg0) {
    if (F_(arg0, 0x255C, int) == 0xA) {
        F_(arg0, 0x255C, int) = 9;
    }
    func_00452F30(arg0, 3, &D_00585E90);
    D_00585F78 = F_(arg0, 0x2484, int);
    D_00585F84 = func_00443020(arg0 + 0x2429);
    D_00585F88 = 5;
    D_00585F7C = 0;
    D_00585F89 = 0;
    D_00585F80 = 0;
    func_004505E0(arg0, &D_00585E90);
    func_0044C940(arg0, 2);
    func_0044C940(arg0, 1);
    if ((func_00444060() != 0) && (func_00444070(1) == 0)) {
        func_00444050(0);
        func_00444040(0);
    }
}
