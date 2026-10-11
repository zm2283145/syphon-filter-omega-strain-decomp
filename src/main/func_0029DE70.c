#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, int);                 
int func_00138B70(char *, int);                            
int func_001692D0(char *);                             
int func_002CA640(int, int);                            
int func_002CAE30(int, int, int, int, int, int);                  
int func_0033CE30(char * , int, int, int, int, int);                 
int func_00414790();                                
int func_004147A0();                                
int func_00414AC0(int, char * , int);                  
int func_00418A80(int, char *, char *);                   
int func_004294C0();                                
int func_0044C3C0(int);                               
extern char D_004AAC40;
extern char D_004AAC58;
extern int D_004FFC04;

typedef struct { char p0[148]; unsigned char f94; } PS0_0029DE70;
void func_0029DE70(PS0_0029DE70 *arg0, int arg1) {
    int sp50[4];
    int sp40[4];
    int temp_s0;
    int temp_s0_2;

    temp_s0 = func_00418A80(func_00414790(), &D_004AAC40, &D_004AAC58);
    func_00414AC0(func_004147A0(), arg0, temp_s0);
    if (arg0->f94 != 0) {
        if (func_004294C0() != 0) {
            func_0044C3C0(func_004294C0());
        }
        arg0->f94 = 0U;
    }
    func_002CA640(D_004FFC04, 1);
    if (arg1 != 0) {
        String_CtorCStr_13B480(sp50, func_0033CE30(arg0, 0xB, 0, 0, 0, 0));
        String_CtorCStr_13B480(sp40, func_0033CE30(arg0, 0x84, 0, 0, 0, 0));
        temp_s0_2 = func_001692D0(sp40);
        func_002CAE30(D_004FFC04, 2, func_001692D0(sp50), temp_s0_2, 0, 0);
        func_00138B70(sp40, 0);
        func_00138B70(sp50, 0);
    }
}
