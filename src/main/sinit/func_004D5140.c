#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int __register_global_object(int *, int *, int *);          
int func_003747A0(int *);                               
extern int D_004BC110;
extern int D_004BC114;
extern int D_004BC118;
extern int D_004BC11C;
extern int D_004BC120;
extern int D_004BC124;
extern int D_004BC128;
extern int D_004BC12C;
extern int D_004BC130;
extern int D_004BC134;
extern int D_004BC138;
extern int D_004BC13C;
extern int D_004BC140;
extern int D_004BC144;
extern int D_004BC148;
extern int D_004BC14C;
extern int D_00535D10;
extern int D_00535D20;
extern int func_00374740;

void func_004D5140(void) {
    func_003747A0(&D_00535D20);
    __register_global_object(&D_00535D20, &func_00374740, &D_00535D10);
    D_004BC114 = 0;
    D_004BC110 = 0xBF800000;
    D_004BC118 = 0xBF800000;
    D_004BC11C = 0x3F800000;
    D_004BC120 = 0xBF800000;
    D_004BC138 = 0xBF800000;
    D_004BC124 = 0;
    D_004BC128 = 0x3F800000;
    D_004BC12C = 0x3F800000;
    D_004BC130 = 0x3F800000;
    D_004BC134 = 0;
    D_004BC13C = 0x3F800000;
    D_004BC140 = 0x3F800000;
    D_004BC144 = 0;
    D_004BC148 = 0x3F800000;
    D_004BC14C = 0x3F800000;
}
