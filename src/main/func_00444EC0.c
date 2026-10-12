#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char *);                            
int func_002CF648(int *, int *);                    
int func_002EB910(char *);                               
int func_00476998();                                
int memset(int *, int, int);                              
extern char D_004C0B40;
extern signed char D_00584231;
extern char D_00584242;
extern char D_00584262;
extern char D_00584282;
extern char D_005842A2;
extern int D_005842C4;
extern unsigned char D_00584518;
extern char func_00445130;
extern char func_004451B0;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

#pragma opt_dead_assignments off
int func_00444EC0(void) {
    struct { int f20[4]; int f30; int f34; int f38; char * f3C; char * f40; int f44; int f48; int f4C[4]; int f5C; } sl;
    int temp_v0;
    int keep;

    if (D_00584518 != 0) {
        D_00584231 = 1;
        return 0;
    }
    memset(&sl.f30, 0, 0x20);
    memset(&sl.f5C, 0, 4);
    sl.f30 = 0;
    sl.f34 = 0;
    sl.f3C = &func_004451B0;
    sl.f38 = 0;
    sl.f44 = 0;
    sl.f40 = &func_00445130;
    sl.f48 = 0x20;
    sl.f4C[0] = func_00476998();
    keep = temp_v0 = func_002CF648(&sl.f30, &sl.f5C);
    if (temp_v0 != 0) {
        return keep;
    }
    
    D_00584231 = 1;
    func_002EB910(sl.f20);
    String_Copy(&D_00584242, sl.f20);
    String_Copy(&D_00584262, &D_004C0B40);
    String_Copy(&D_00584282, sl.f20);
    String_Copy(&D_005842A2, &D_004C0B40);
    D_00584518 = (D_005842C4 = 1); 
    return temp_v0;
}
#pragma pop
