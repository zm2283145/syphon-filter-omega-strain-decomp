#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_001AF2C0(char *, char *);                        
int func_001AF2E0(char *);                               
int SkelNode_SetWeight(int, float);                          
float func_001AF320(int);                             
int SkelNodes_GetAt(char * , int);                     
int func_001AF350(int);                             
int *func_001AF360(char *);                            
int func_001AF370(char *, int);                          
int func_001AF390(char *, int);                          
int func_001AF3A0(char *, char *);                        
int func_001AF3C0(char *);                               
int SkelNode_ClearWeight(int);                               
int SkelNode_GetWeightPtr(int);                             
int func_001AF410(char *);                             
int func_001AF420(char *, char * );                       
int func_001AF450(char *, char * );                       
extern int D_004EE9D0;

void Human_ApplyCentroidWeights(char * arg0) {
    char * temp_s1;
    int sp3C;
    int temp_s0;
    int sp38;
    int sp34;
    int sp30;
    int temp_s0_2;

    temp_s0 = D_004EE9D0;
    temp_s1 = arg0 + 0x2E50;
    if (F_(arg0, 0x2E64, unsigned char) != 0) {
        func_001AF450(&sp3C, temp_s1 + 0x18);
        func_001AF420(&sp38, temp_s1 + 0x18);
        if (func_001AF3A0(&sp3C, &sp38) != 0) {
            do {
                SkelNode_ClearWeight(SkelNode_GetWeightPtr(func_001AF410(&sp3C)));
                func_001AF3C0(&sp3C);
            } while (func_001AF3A0(&sp3C, &sp38) != 0);
        }
        func_001AF390(&sp34, temp_s0);
        func_001AF370(&sp30, temp_s0);
        if (func_001AF2C0(&sp34, &sp30) != 0) {
            do {
                temp_s0_2 = SkelNode_GetWeightPtr(SkelNodes_GetAt(temp_s1 + 0x18, func_001AF350(*func_001AF360(&sp34))));
                { float ff = func_001AF320(*func_001AF360(&sp34)); SkelNode_SetWeight(temp_s0_2, ff); }
                func_001AF2E0(&sp34);
            } while (func_001AF2C0(&sp34, &sp30) != 0);
        }
    }
}
