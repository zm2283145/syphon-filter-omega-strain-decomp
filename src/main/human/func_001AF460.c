#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Vec4_Assign(char *, int);                          
int SkelNodes_GetAt(char * , int);                     
int func_001AF3A0(char *, char *);                        
int func_001AF3C0(char *);                               
int func_001AF410(char *);                             
int func_001AF420(char *, char * );                       
int func_001AF450(char *, char * );                       
int func_001AF5C0(char *, char *);                        
int func_001AF5E0(char *);                               
int BoundSphere_Set(int, int, float);                     
int func_001AF6B0(int);                             
float func_001AF6C0(int);                             
int func_001AF6D0(int);                             
int *func_001AF6E0(char *);                            
int func_001AF6F0(char *, int);                          
int func_001AF710(char *, int);                          
int BoundSphere_Reset(int);                               
int SkelNode_GetBoundSphere(int);                             
extern int D_004EE9D8;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void Human_ApplyBoundSpheres(char * arg0) {
    int sp5C;
    int temp_s0;
    int sp58;
    int sp54;
    char * temp_s1;
    int temp_s0_2;
    int sp40[4];
    int sp50;
    float temp_f20;

    temp_s0 = D_004EE9D8;
    temp_s1 = arg0 + 0x2E50;
    if (F_(arg0, 0x2E64, unsigned char) != 0) {
        func_001AF450(&sp5C, temp_s1 + 0x18);
        func_001AF420(&sp58, temp_s1 + 0x18);
        if (func_001AF3A0(&sp5C, &sp58) != 0) {
            do {
                BoundSphere_Reset(SkelNode_GetBoundSphere(func_001AF410(&sp5C)));
                func_001AF3C0(&sp5C);
            } while (func_001AF3A0(&sp5C, &sp58) != 0);
        }
        func_001AF710(&sp54, temp_s0);
        func_001AF6F0(&sp50, temp_s0);
        if (func_001AF5C0(&sp54, &sp50) != 0) {
            do {
                temp_s0_2 = SkelNode_GetBoundSphere(SkelNodes_GetAt(temp_s1 + 0x18, func_001AF6D0(*func_001AF6E0(&sp54))));
                temp_f20 = func_001AF6C0(*func_001AF6E0(&sp54));
                BoundSphere_Set(temp_s0_2, Vec4_Assign(sp40, func_001AF6B0(*func_001AF6E0(&sp54))), temp_f20);
                func_001AF5E0(&sp54);
            } while (func_001AF5C0(&sp54, &sp50) != 0);
        }
    }
}

