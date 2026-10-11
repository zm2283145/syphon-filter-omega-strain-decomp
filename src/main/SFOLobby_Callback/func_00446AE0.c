#include "types.h"
extern int func_004505C0();
extern void func_0044EDC0(void* ctx, int a, int b, int c, int d, void* e);
extern void* D_00585E60;
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void func_00446AE0(int a0, int a1, int a2, char* m) {
    if (func_004505C0() == 0 && F_(m, 0x18, int) == 0) {
        func_0044EDC0(D_00585E60, F_(m, 0x3C, int), F_(m, 0x30, int), F_(m, 0x24, int), F_(m, 0x184, int), m + 0x34);
    }
}