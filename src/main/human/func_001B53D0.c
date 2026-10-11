#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMap_BindReceiver(int, int, char * );            
int Npc_CreatePhysical();                             
int func_001AF190(char * );                            
int func_001AF460(char * );                            
int func_0022C650(char *, char * );                       
int func_002D1D80(int);                               
int func_002D1FF0(char * , int);                       
int func_002EBAF8(int *, int);                        
int func_00392940(char * , int);                         
int func_003FB4B0(int, int);                          
int func_004341F0(char *, char * );                       
int func_00436BA0(char *, int);                            
int func_00436C00(char *);                               
extern int D_00494178;
extern char D_004F77C0;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;

#pragma opt_common_subs off
static inline int LocalId_53D0(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (D_005721C8) {
        if (D_00494178 == -1) func_002EBAF8(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
void Npc_Activate(char * arg0, int arg1) {
    int sp3C;
    int temp_a0;
    int temp_s1;
    int temp_s1_2;
    int var_a1;
    int var_a1_2;

    Npc_CreatePhysical();
    func_00392940(arg0, arg1);
    func_001AF460(arg0);
    func_001AF190(arg0);
    func_0022C650(&D_004F77C0, arg0);
    if (D_005721C8 != 0) {
        if ((F_(arg0, 0x3584, int) == 0) && (D_005721D0 != 0)) {
            func_002D1FF0(arg0 + 0xC, F_(arg0, 0x10, int));
            temp_s1 = F_(arg0, 0x10, int);
            var_a1 = LocalId_53D0();
            NetMap_BindReceiver(temp_s1, var_a1, arg0);
        }
        temp_s1_2 = F_(arg0, 0x10, int);
        var_a1_2 = LocalId_53D0();
        func_003FB4B0(temp_s1_2, var_a1_2);
        func_00436C00(&sp3C);
        func_004341F0(&sp3C, arg0 + 0xC);
        F_(arg0, 0x14, signed char) = 1;
        temp_a0 = F_(arg0, 0x3584, int);
        if (temp_a0 != 0) {
            func_002D1D80(temp_a0);
        }
        func_00436BA0(&sp3C, -1);
    }
    F_(arg0, 0x3268, signed char) = 1;
}
