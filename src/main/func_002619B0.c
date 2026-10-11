#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_00260D50(int, char *);                        
int func_003EEB30(int, char *);                        
int func_003EEBE0(int, int, int);                         
int func_003F45A0(float, int);                          
extern int D_0048B0D8;
extern char D_004A80A8;
extern char D_004A80C0;
extern char D_004A80D8;
extern char D_004A80E8;
extern char D_004A80F8;
extern char D_004A8100;
extern char D_004A8118;
extern char D_004A8128;
extern char D_004DC930;
extern char D_004DC950;
extern int D_004FFD50;
extern int D_004FFD58;
extern int D_004FFD60;

typedef struct { char p0[4]; int f4; int f8; int fC; int f10; int f14; int f18; } PS0_002619B0;
char * func_002619B0(PS0_002619B0 *arg0, int arg1) {
    arg0->f4 = (int)(&D_004DC930);
    arg0->f4 = (int)(&D_004DC950);
    arg0->f8 = func_00260D50(arg1, &D_004A80A8);
    arg0->fC = func_00260D50(arg1, &D_004A80C0);
    arg0->f10 = func_00260D50(arg1, &D_004A80D8);
    arg0->f14 = func_00260D50(arg1, &D_004A80E8);
    func_003EEBE0(arg1, 1, 0);
    func_003EEBE0(func_003EEB30(arg1, &D_004A80F8), 1, 1);
    arg0->f18 = func_00260D50(arg1, &D_004A8100);
    func_003F45A0((float) D_0048B0D8, arg0->f18);
    D_004FFD58 = func_003EEB30(arg1, &D_004A8118);
    D_004FFD50 = func_003EEB30(arg1, &D_004A8118);
    D_004FFD60 = func_003EEB30(arg1, &D_004A8128);
    return arg0;
}
