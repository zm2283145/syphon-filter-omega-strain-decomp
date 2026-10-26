#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Medius_CloseReportLib();                                
extern unsigned char D_00584518;

int SFOMGCL_Close_API(void) {
    int temp_v0;

    if (D_00584518 == 0) {
        return 0;
    }
    temp_v0 = Medius_CloseReportLib();
    if (temp_v0 == 0) {
        D_00584518 = 0;
    }
    return temp_v0;
}
