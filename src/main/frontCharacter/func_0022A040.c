#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(int, int, char *, int);                      
int func_001C0540(char * );                            
int func_001C05E0(char * );                            
int func_001C0720(char * );                            
int func_001C07C0(char * );                            
int func_001C0810(char * );                            
int func_0022A140();                                  
int func_0022A220(int, int);                            
extern char D_004A6320;
extern char * D_004F77A0;
extern unsigned char D_00533880;
}
extern "C" void func_0022A040(int arg0, int arg1) {
    char * temp_s2;

    {
        AllocGuard g;
    temp_s2 = Mem_Alloc(0, 0x5C, &D_004A6320, 0x70);
    }
    if (temp_s2 != NULL) {
        F_(temp_s2, 0x0, int) = 0;
        func_001C0810(temp_s2 + 4);
        func_001C07C0(temp_s2 + 0x14);
        func_001C0720(temp_s2 + 0x24);
        func_001C05E0(temp_s2 + 0x34);
        func_001C0540(temp_s2 + 0x44);
        F_(temp_s2, 0x54, int) = 0;
        F_(temp_s2, 0x58, int) = 0;
    }
    D_004F77A0 = temp_s2;
    func_0022A140();
    func_0022A220(arg0, arg1);
}
