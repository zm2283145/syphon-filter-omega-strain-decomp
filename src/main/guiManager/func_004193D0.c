#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC004193D0 { virtual int v0(); virtual int v1(); virtual int v2(...); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int func_00138DA0(...);                     
int func_0015AF40(...);                      
int func_002A8890(...);                        
int func_002A88B0(...);                          
int func_002CCDE0(...);                      
int func_002CCDF0(...);                               
int *func_002CCE10(...);                            
int func_002CCE20(...);                          
int func_002CCE30(...);                          
int func_002CCE40(...);                               
void **func_004147A0(...);                             
typedef struct { char p0[20]; unsigned short f14; } PS0_004193D0;
}
extern "C" void func_004193D0(char *arg0, PS0_004193D0 *arg1) {
    char * sp4C;
    char * sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    int sp34;
    void **temp_a0;
    void **temp_v0;

    if (arg1->f14 & 1) {
        func_002CCE40(&sp3C);
        func_002CCE30(&sp38, arg0 + 0x14);
        func_002CCE20(&sp3C, &sp38);
        func_002A88B0(&sp34, arg0 + 0x14);
        if (func_002A8890(&sp3C, &sp34) != 0) {
loop_3:
            if ((void *)(*func_002CCE10(&sp3C)) != (void *)(arg1)) {
                func_002CCDF0(&sp3C);
                func_002A88B0(&sp34, arg0 + 0x14);
                if (func_002A8890(&sp3C, &sp34) == 0) {

                } else {
                    goto loop_3;
                }
            }
        }
        func_002CCDE0(&sp4C, &sp3C);
        if (F_(sp4C, 0x8, int) != NULL) {
            if ((func_004147A0() != NULL) && (arg1->f14 & 8)) {
                temp_v0 = func_004147A0();
                ((VC004193D0 *)(temp_v0))->v24(arg1);
            }
            temp_a0 = (void **)(F_(F_(sp4C, 0x8, int), 0x44, int));
            ((VC004193D0 *)(temp_a0))->v2();
            sp48 = sp4C;
            func_0015AF40(&sp40, &sp48);
            func_00138DA0(&sp44, arg0 + 0x14, &sp40);
        }
    }
}
