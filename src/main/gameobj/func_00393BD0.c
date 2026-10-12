#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00393BD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual float v3(); };
extern "C" {
int PhysicalBase_Construct(...);                 
static const unsigned int dat_00493460[2] = { 0x0, 0x0 };
static const unsigned int dat_00493468[2] = { 0x0, 0x0 };
extern int D_004DA840;
}
extern "C" int func_00393BD0(char *arg0, float farg0) {
    PhysicalBase_Construct(arg0, &(*(int*)dat_00493460), &(*(int*)dat_00493468));
    F_(arg0, 0x0, int) = (int)(&D_004DA840);
    F_(arg0, 0x38, signed char) = 0;
    F_(arg0, 0x10, float) = farg0;
    F_(arg0, 0x8, float) = farg0;
    F_(arg0, 0x4, float) = farg0;
    F_(arg0, 0xC, float) = ((VC00393BD0 *)(arg0))->v3();
    return (int)(arg0);
}
