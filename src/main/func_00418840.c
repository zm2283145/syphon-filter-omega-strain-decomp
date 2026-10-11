#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
/*fc*/
int func_0028C090();                        
int func_0028C0A0();                          
int func_002A8890();                        
int func_002A88B0();                          
int func_002CCDE0();                      
int func_002CCDF0();                               
int *func_002CCE10();                            
int func_002CCE20();                          
int func_002CCE30();                          
int func_002CCE40();                               
int func_00418E00();                    

typedef struct { char pad[0x18]; unsigned short cnt; } N418;
int func_00418840(char *arg0, char *arg1) {
    char * sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    unsigned short temp_v0;
    N418 * temp_a1;

    func_002CCE40(&sp44);
    func_002CCE30(&sp40, arg0 + 0x14);
    func_002CCE20(&sp44, &sp40);
    func_002A88B0(&sp3C, arg0 + 0x14);
    if (func_002A8890(&sp44, &sp3C) != 0) {
loop_1:
        if ((void *)(*func_002CCE10(&sp44)) != (void *)(arg1)) {
            func_002CCDF0(&sp44);
            func_002A88B0(&sp3C, arg0 + 0x14);
            if (func_002A8890(&sp44, &sp3C) == 0) {

            } else {
                goto loop_1;
            }
        }
    }
    func_002CCDE0(&sp4C, &sp44);
    func_0028C0A0(&sp38, arg0 + 0x14);
    func_0028C090(&sp48, &sp38);
    if ((int)sp4C == (int)sp48) {
        return 0;
    }
    temp_a1 = (N418 *)(F_(sp4C, 0x8, int));
    if (temp_a1->cnt == 0) {
        return 0;
    }
    if ((int)temp_a1->cnt > 0) {
        temp_a1->cnt--;
    }
    if (temp_a1->cnt == 0) {
        func_00418E00(arg0, temp_a1, 0);
    }
    return 1;
}
