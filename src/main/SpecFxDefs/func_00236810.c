#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int IdMgr_Allocate(char *, int);                           
char * Mem_Alloc(int, int, char *, int);                    
int cGOBJ_ctor(char * , char *, int, int *);                
extern char D_004A6E38;
extern char D_004DBD80;
extern char D_004DF860;
extern unsigned char D_00533880;
extern int D_00533888;

typedef struct { int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70; int f74; int f78; int f7C; int f80; int f84; } PS0_00236810;
char * func_00236810(PS0_00236810 *arg0, int arg1, int arg2, int arg3, float farg0) {
    int sp9C;
    int sp98;
    int var_s0;
    char * temp_s5;
    char * temp_s6;
    int var_s5;

    IdMgr_Allocate(&sp9C, 0xE7);
    sp98 = 0;
    cGOBJ_ctor(arg0, &sp9C, 4, &sp98);
    arg0->f0 = (int)(&D_004DF860);
    arg0->f60 = -1;
    arg0->f64 = 0;
    arg0->f68 = 0;
    arg0->f70 = 0x3F800000;
    arg0->f2F = 1;
    arg0->f0 = (int)(&D_004DBD80);
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s5 = Mem_Alloc(0, arg3 * 4, &D_004A6E38, 0x194);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    var_s0 = 0;
    D_00533888 -= 1;
    arg0->f7C = (int)(temp_s5);
    for (var_s0 = 0; var_s0 < arg3; var_s0++) {
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            temp_s6 = Mem_Alloc(0, 0x20, &D_004A6E38, 0x197);
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            if (temp_s6 != NULL) {
                F_(temp_s6, 0x0, int) = 0;
                F_(temp_s6, 0x4, float) = farg0;
            }
            ((char **)arg0->f7C)[var_s0] = temp_s6;
    }
    arg0->f78 = arg2;
    arg0->f84 = arg3;
    arg0->f74 = arg1;
    arg0->f80 = 0x3C23D70A;
    return arg0;
}
