#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
char * Archive_Open();                   
int Expression_Init();                                
int Skf_Register(char *, char * );                        
int func_00391B30(char * , char *);                       
int func_004037F0(char *, char *);                          
int func_00403D20(char *, char * );                       
int func_00404AA0(char *, char * );                       
extern char D_004A6370;
extern char D_004A6390;
extern char D_004A63B0;
extern char D_004A63D0;
extern char D_004A63F0;
extern char D_004A6410;
extern char D_0055DDA0;

typedef struct { char p0[4]; int f4; int f8; int fC; int f10; int f14; } PS0_0022A220;
void func_0022A220(PS0_0022A220 *arg0, int arg1) {
    char * temp_a0;
    char * temp_a1;
    char * temp_a1_2;
    char * temp_a1_3;

    arg0->f4 = NULL;
    arg0->f8 = NULL;
    arg0->fC = NULL;
    arg0->f10 = 0;
    arg0->f14 = NULL;
    func_004037F0(&D_0055DDA0, &D_004A6370);
    arg0->f14 = (int)(Archive_Open(arg1, &D_004A6390, 0, 0));
    temp_a1 = (char *)(arg0->f14);
    if (F_(temp_a1, 0x14C, unsigned char) != 0) {
        func_00403D20(&D_0055DDA0, temp_a1);
    }
    arg0->f4 = (int)(Archive_Open(arg1, &D_004A63B0, 0, 0));
    temp_a1_2 = (char *)(arg0->f4);
    if (F_(temp_a1_2, 0x14C, unsigned char) != 0) {
        Skf_Register(&D_0055DDA0, temp_a1_2);
    }
    arg0->f8 = (int)(Archive_Open(arg1, &D_004A63D0, 0, 0));
    temp_a1_3 = (char *)(arg0->f8);
    if (F_(temp_a1_3, 0x14C, unsigned char) != 0) {
        func_00404AA0(&D_0055DDA0, temp_a1_3);
    }
    Expression_Init();
    arg0->fC = (int)(Archive_Open(arg1, &D_004A63F0, 0, 0));
    temp_a0 = (char *)(arg0->fC);
    if (F_(temp_a0, 0x14C, unsigned char) != 0) {
        func_00391B30(temp_a0, &D_004A6410);
    }
}
