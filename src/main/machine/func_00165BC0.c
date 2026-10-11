#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsgTypes_RegisterAll();                        
int ObjectiveNet_Setup();                             
int func_0016A690();                                  
int func_00170080();                                  
int func_0020E420();                                  
int func_0020E950();                                  
int func_0020EE70();                                  
int func_0020F540();                                  
int func_002107F0();                                  
int func_00211540();                                  
int func_00211820();                                  
int func_002120D0();                                  
int func_00212920();                                  
int func_0021D190();                                  
int func_0021D600();                                  
int func_0022E240();                                  
int func_0022E420();                                  
int func_0022E5E0();                                  
int func_0023F890();                                  
int func_0023FAA0();                                  
int func_0025DFF0();                                  
int func_0025E330();                                  
int func_0026F2B0();                                  
int func_0026F4E0();                                  
int func_0026F6F0();                                  
int func_0026F930();                                  
int func_0026FBF0();                                  
int func_0026FED0();                                  
int func_00270100();                                  
int func_002702C0();                                  
int func_00270470();                                  
int func_00282240();                                  
int func_002C5270();                                  
int func_002C5AC0();                                  
int func_002C64D0();                                  
int func_002C7460();                                  
int func_002C7560();                                  
int func_002C7A00();                                  
int func_002D0FE0();                                  
int func_002D16E0();                                  
int func_002D1940();                                  
int func_002D2850();                                  
int func_002D7020();                                  
int func_002D78C0();                                  
int func_00316550();                                  
int func_00316860();                                  
int func_00316BB0();                                  
int func_003240C0();                                  
int func_003A6710(int);                                 
int func_0042AF00();                                  
extern unsigned char D_004EE530;
extern signed char D_0051EEA0;
extern unsigned char D_0051EEA8;
extern unsigned char D_005723D0;

void func_00165BC0(void) {
    if (D_004EE530 == 0) {
        D_004EE530 = 1;
        func_003A6710(1);
        if (D_0051EEA8 == 0) {
            D_0051EEA0 = 1;
            func_0042AF00();
        }
    }
    if (D_005723D0 == 0) {
        func_002D1940();
        func_002C7A00();
        func_002D78C0();
        func_002D0FE0();
        func_002D16E0();
        ObjectiveNet_Setup();
        func_00316BB0();
        func_0025E330();
        func_0025DFF0();
        func_0021D600();
        func_0021D190();
        func_00270100();
        func_002702C0();
        func_00270470();
        func_0026FED0();
        func_0026FBF0();
        func_0026F930();
        func_0026F6F0();
        func_0026F2B0();
        func_0026F4E0();
        func_0020E420();
        func_0020F540();
        func_0020EE70();
        func_0020E950();
        func_002C64D0();
        func_002C5270();
        func_00316860();
        func_003240C0();
        func_0023FAA0();
        func_0023F890();
        func_002D7020();
        func_002C5AC0();
        func_0022E240();
        func_0022E420();
        func_0022E5E0();
        func_002D2850();
        func_00170080();
        func_00211820();
        func_00211540();
        func_002120D0();
        func_00212920();
        func_00316550();
        func_002107F0();
        func_0016A690();
        func_002C7460();
        func_002C7560();
        func_00282240();
        NetMsgTypes_RegisterAll();
        D_005723D0 = 1;
    }
}
