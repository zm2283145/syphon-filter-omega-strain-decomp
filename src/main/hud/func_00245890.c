#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
float func_00245810();                                
extern unsigned char D_005721C8;

float func_00245890(int arg0) {
    if (D_005721C8 != 0) {
        return func_00245810() - F_(arg0, 0x6E0, float);
    }
    return F_(arg0, 0x6DC, float);
}
