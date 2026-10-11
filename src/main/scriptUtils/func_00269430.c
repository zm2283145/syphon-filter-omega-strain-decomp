#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int IdMgr_Allocate();                           
char * Mem_Alloc(int, int, char *, int);                      
int Object_Register();                          
int cGOBJ_ctor();                
int func_00269530();                      
extern char D_004A82B8;
extern char D_004DCA80;
extern char D_004F83C0;
extern unsigned char D_00533880;
extern int D_00533888;

#pragma push
#pragma opt_common_subs off
char * func_00269430(int arg0) {
    struct { int f30; int f34[2]; char * f3C; } sl;
    char * temp_s1;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s1 = (char *)(Mem_Alloc(0, 0x64, &D_004A82B8, 0x70));
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s1 != NULL) {
        sl.f30 = 0;
        IdMgr_Allocate(sl.f34, 0xF5);
        cGOBJ_ctor(temp_s1, sl.f34, 0, &sl.f30);
        F_(temp_s1, 0x0, int) = (int)(&D_004DCA80);
        F_(temp_s1, 0x60, int) = arg0;
        Object_Register(temp_s1);
    }
    sl.f3C = temp_s1;
    func_00269530(&D_004F83C0, &sl.f3C);
    return sl.f3C;
}
#pragma pop
