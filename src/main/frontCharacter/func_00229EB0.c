#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_001AF7A0(...);                                  
int func_0036CD80(...);                            
int func_003B62E0(...);                            
int func_00404FD0(...);                            
extern char D_004A6320;
extern int D_004F77A0;
extern unsigned char D_00533880;
extern char D_0055DDA0;
extern int D_005712F0;
extern int D_005712F4;
}
#pragma opt_common_subs off
extern "C" void func_00229EB0(char * arg0) {
    int temp_s0;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;
    char * temp_a0_4;
    char * temp_a0_5;

    func_00404FD0(&D_0055DDA0, -1);
    D_005712F0 = 0;
    D_005712F4 = 0;
    temp_a0 = (char *)(F_(arg0, 0x4, int));
    if ((temp_a0 != NULL) && (F_(temp_a0, 0x14C, unsigned char) != 0)) {
        func_0036CD80(temp_a0);
    }
    temp_a0_2 = (char *)(F_(arg0, 0x8, int));
    if ((temp_a0_2 != NULL) && (F_(temp_a0_2, 0x14C, unsigned char) != 0)) {
        func_0036CD80(temp_a0_2);
    }
    temp_a0_3 = (char *)(F_(arg0, 0xC, int));
    if ((temp_a0_3 != NULL) && (F_(temp_a0_3, 0x14C, unsigned char) != 0)) {
        func_0036CD80(temp_a0_3);
    }
    temp_a0_4 = (char *)(F_(arg0, 0x10, int));
    if ((temp_a0_4 != NULL) && (F_(temp_a0_4, 0x14C, unsigned char) != 0)) {
        func_0036CD80(temp_a0_4);
    }
    temp_a0_5 = (char *)(F_(arg0, 0x14, int));
    if ((temp_a0_5 != NULL) && (F_(temp_a0_5, 0x14C, unsigned char) != 0)) {
        func_0036CD80(temp_a0_5);
    }
    F_(arg0, 0x4, int) = NULL;
    F_(arg0, 0x8, int) = NULL;
    F_(arg0, 0xC, int) = NULL;
    F_(arg0, 0x10, int) = NULL;
    F_(arg0, 0x14, int) = NULL;
    temp_s0 = D_004F77A0;
    {
        AllocGuard g;
    func_003B62E0(temp_s0, -1);
    Mem_Free(0, temp_s0, &D_004A6320, 0x8F);
    }
    D_004F77A0 = 0;
    func_001AF7A0();
}
