#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00414790();                                
int func_004147A0();                                
int func_00414AC0(int, char * , int);                  
int func_00419530(int, int);                          
int func_0041EFA0(char * );                            
int func_0041F960(char *);                             
int func_0045F4D0(char * );                            
int func_0045F860(char * );                            
int func_0045FAB0();                                  
int func_00460450(char * );                            
extern char D_004C2460;

void func_004603A0(char * arg0) {
    int temp_v0;

    func_0045FAB0();
    if (F_(arg0, 0x1B4, int) == 0) {
        temp_v0 = func_0041F960(&D_004C2460);
        if (temp_v0 != 0) {
            func_00419530(func_00414790(), temp_v0);
            func_00414AC0(func_004147A0(), arg0, temp_v0);
        }
    } else {
        func_0041EFA0(arg0);
        func_00460450(arg0);
        F_(arg0, 0x204, signed char) = 0;
        func_0045F860(arg0);
        func_0045F4D0(arg0);
    }
}
