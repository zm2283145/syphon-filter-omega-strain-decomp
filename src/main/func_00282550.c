#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int __register_global_object(int *, int *, int *);          
int func_00282710(int *);                               
extern signed char D_005061E0;
extern int D_005061E8;
extern int D_00506200;
extern signed char D_0050620C;
extern int func_002825C0;

int *func_00282550(void) {
    if (D_005061E0 == 0) {
        func_00282710(&D_00506200);
        D_0050620C = 1;
        __register_global_object(&D_00506200, &func_002825C0, &D_005061E8);
        D_005061E0 = 1;
    }
    return &D_00506200;
}
