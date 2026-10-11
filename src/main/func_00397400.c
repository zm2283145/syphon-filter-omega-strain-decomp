#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int GroupPayload_Destroy();             
int cMessage_dtor();                         
int func_00189FD0();                            
int func_0018A040();                            
int func_00397540();                            
int func_003975A0();                        
int func_003975C0();                          
int func_003975D0();                               
int *func_00397820();                            
int func_00397830();                          
int operator_delete();                          
extern char D_004BC528;
extern char D_004DA930;

char * func_00397400(char * arg0, short arg1) {
    int sp3C;
    int sp38;
    int temp_a1;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        temp_a1 = (int)(arg0 + 0xE8);
        if (temp_a1 != 0) {
            func_00397830(&sp3C, temp_a1);
            func_003975C0(&sp38, arg0 + 0xE8);
            if (func_003975A0(&sp3C, &sp38) != 0) {
                do {
                    GroupPayload_Destroy(*func_00397820(&sp3C), 0, 1, &D_004BC528, 205);
                    func_003975D0(&sp3C);
                    func_003975C0(&sp38, arg0 + 0xE8);
                } while (func_003975A0(&sp3C, &sp38) != 0);
            }
            func_00397540(arg0 + 0xE8, 0);
        }
        if ((arg0 + 0x94) != 0) {
            func_00189FD0(arg0 + 0xD0, -1);
            func_0018A040(arg0 + 0x98, -1);
        }
        temp_a0 = arg0 + 0x5C;
        if (temp_a0 != NULL) {
            F_(arg0, 0x5C, int) = (int)(&D_004DA930);
            cMessage_dtor(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x24;
        if (temp_a0_2 != NULL) {
            F_(arg0, 0x24, int) = (int)(&D_004DA930);
            cMessage_dtor(temp_a0_2, 0);
        }
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
