#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * Mem_Alloc(...);                      
int Object_AttachTransform(...);           
int cGOBJ_ctor(...);              
char * func_00393FF0(...);                 
int func_0041F150(...);                                  
int memset(...);                             
extern char D_004BBA20;
extern char D_004DA470;
extern unsigned char D_00533880;
extern char D_0055C9F0;
}
#pragma push
#pragma opt_common_subs off
extern "C" void func_003643A0(char * arg0) {
        int x4C[1];
    char * temp_s1;
    char * var_s1;

    func_0041F150();
    {
        AllocGuard g;
    temp_s1 = (char *)(Mem_Alloc(0, 0x68, &D_004BBA20, 0x49));
    }
    if (temp_s1 != NULL) {
        int x44[1]; int x40[1]; x40[0] = 0;
        x44[0] = 0;
        cGOBJ_ctor(temp_s1, x44, 9, x40);
        F_(temp_s1, 0x0, int) = (int)(&D_004DA470);
        F_(temp_s1, 0x60, int) = 0;
        F_(temp_s1, 0x64, int) = 0;
        Object_AttachTransform(temp_s1, &D_0055C9F0, 0);
        F_(temp_s1, 0x30, int) = 0;
    }
    F_(arg0, 0x90, int) = (int)(temp_s1);
    {
        AllocGuard g;
    var_s1 = (char *)(Mem_Alloc(0, 0x3030, &D_004BBA20, 0x4C));
    }
    if (var_s1 != NULL) {
        x4C[0] = 0;
        var_s1 = (char *)(func_00393FF0(var_s1, x4C));
    }
    F_(arg0, 0x48, int) = (int)(var_s1);
    memset(arg0 + 0xA0, 0, 0x440);
}
#pragma pop
