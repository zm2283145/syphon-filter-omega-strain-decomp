#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
char *Loc_LookupText(char *);                             
int func_00426510(int, int, int, char *);                  
int sprintf(char *, char *, int);                             
extern char D_004C1A38;
extern char D_004C1A40;
extern char D_004C1A50;

void func_00455A20(int arg0, int arg1) {
    int sp40[4];
    int var_s0;

    var_s0 = 0;
    do {
        func_00426510(arg0, 0, var_s0, &D_004C1A38);
        func_00426510(arg0, 1, var_s0, &D_004C1A38);
        var_s0 += 1;
    } while (var_s0 < 3);
    func_00426510(arg0, 0, 2, Loc_LookupText(&D_004C1A40));
    sprintf(sp40, &D_004C1A50, arg1);
    func_00426510(arg0, 1, 2, sp40);
}
