#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int List_Begin();                       
int func_0027AA80();                      
int func_0027AC70();                        
int func_0027AC80();                       
int func_0027AC90();                                  
int func_0027B4E0();                            
int IeElement_SetShown();                            

void func_0027AB60(char * arg0) {
    int sp3C;
    char * sp38;
    int sp34;
    int sp30;
    int temp_v0;
    char * var_s0;

    func_0027AC90();
    temp_v0 = F_(arg0, 0x3C, int);
    if (temp_v0 == 0) {
        F_(arg0, 0x38, int) = 0;
        IeElement_SetShown(F_(arg0, 0x4, int), 1);
        IeElement_SetShown(F_(arg0, 0x8, int), 1);
        IeElement_SetShown(F_(arg0, 0xC, int), 1);
        IeElement_SetShown(F_(arg0, 0x10, int), 1);
    } else if (temp_v0 == 1) {
        F_(arg0, 0x38, int) = 0;
        IeElement_SetShown(F_(arg0, 0x28, int), 1);
        List_Begin(&sp34, arg0 + 0x2C);
        func_0027AA80(&sp38, &sp34);
        var_s0 = sp38;
        func_0027AC80(&sp30, arg0 + 0x2C);
        func_0027AC70(&sp3C, &sp30);
        if ((int)var_s0 != (int)sp3C) {
            do {
                IeElement_SetShown(F_(F_(var_s0, 0x8, int), 0x14, int), 1);
                var_s0 = (char *)(F_(var_s0, 0x4, int));
                func_0027AC80(&sp30, arg0 + 0x2C);
                func_0027AC70(&sp3C, &sp30);
            } while ((int)var_s0 != (int)sp3C);
        }
    }
    func_0027B4E0(arg0);
}
