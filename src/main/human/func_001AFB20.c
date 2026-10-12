#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int ColScratch_Init(int, int, int, int);                      
int HumanCol_Init();                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_001360D0(int);                                 
int func_001361D0(int *);                           
int func_001AFCF0(char * , int);                       
int func_001AFD00(char * );                            
int func_001AFD20(char * , int);                       
int func_001AFD30(char * );                            
int HumanBounds_BuildTable(char * );                            
int HumanCentroid_GetTable(char * );                            
int func_001D8720();                                  
extern char D_0049D8D0;
extern char * D_004EE9D0;
extern char * D_004EE9D8;
extern unsigned char D_00533880;
extern int D_00533888;

void func_001AFB20(void) {
    int sp2C;
    char * temp_s0;
    char * temp_s0_2;

    ColScratch_Init(0, 0, 0, 0);
    func_001360D0(0x320);
    HumanCol_Init();
    func_001D8720();
    sp2C = 0x15;
    if (D_004EE9D0 == NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0 = Mem_Alloc(0, 0x10, &D_0049D8D0, 0xB1A);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0 != NULL) {
            func_001AFD30(temp_s0);
            func_001AFD20(temp_s0, func_001361D0(&sp2C));
            F_(temp_s0, 0xC, signed char) = 1;
        }
        D_004EE9D0 = temp_s0;
        HumanCentroid_GetTable(temp_s0);
    }
    if (D_004EE9D8 == NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_0049D8D0, 0xB20);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0_2 != NULL) {
            func_001AFD00(temp_s0_2);
            func_001AFCF0(temp_s0_2, func_001361D0(&sp2C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_004EE9D8 = temp_s0_2;
        HumanBounds_BuildTable(temp_s0_2);
    }
}
