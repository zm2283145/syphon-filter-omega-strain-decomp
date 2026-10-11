#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0036E220(int, int);                            
int func_00461DC0(int, int);                            
int operator_delete(int);                             

int func_00460E00(int arg0, long long arg1) {
    if (arg0 != 0) {
        if ((arg0 + 0x20) != 0) {
            func_0036E220(arg0 + 0x104, -1);
            func_0036E220(arg0 + 0x68, -1);
        }
        if ((arg0 != 0) && (arg0 != 0) && (arg0 != 0)) {
            func_00461DC0(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
