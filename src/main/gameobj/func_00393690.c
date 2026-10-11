#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_001A09F0();                        
int func_001A0A10();                               
int func_001A0A30();                               
int func_001A0AD0();                             
int func_001A0AE0();                             
int func_001A0AF0();                          
int func_001A0B10();                          
int func_001A0B20();                             
int func_001AD940();                      

void func_00393690(int arg0) {
    int sp3C;
    int sp38;
    char * sp34;
    int temp_v0;
    int temp_v1_2;
    char * temp_v1;

    temp_v0 = func_001A0B20(arg0 + 0x10);
    func_001A0B10(&sp3C, temp_v0);
    func_001A0AF0(&sp38, temp_v0);
    if (func_001A09F0(&sp3C, &sp38) != 0) {
        do {
            func_001A0A30(func_001A0AD0(func_001A0AE0(&sp3C)));
            func_001A0A10(&sp3C);
        } while (func_001A09F0(&sp3C, &sp38) != 0);
    }
    temp_v1 = (char *)(arg0 + 0x100);
    sp34 = temp_v1;
    temp_v1_2 = F_(*(char * volatile *)&sp34, 0x4, int);
    if (temp_v1_2 != 0) {
        func_001AD940(temp_v1_2 + 8, &sp34);
        F_(sp34, 0x4, int) = 0;
    }
}
