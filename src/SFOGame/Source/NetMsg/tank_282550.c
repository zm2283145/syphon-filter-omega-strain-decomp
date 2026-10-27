#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int __register_global_object(int *, int *, int *);          
int std_vector_void_cSystem_ctor(int *);                               
extern signed char D_005061E0;
extern int D_005061E8;
extern int D_00506200;
extern signed char D_0050620C;
extern int cArray_void_cSystem_dtor;

int *cNetMsg_GetFuncList(void) {
    if (D_005061E0 == 0) {
        std_vector_void_cSystem_ctor(&D_00506200);
        D_0050620C = 1;
        __register_global_object(&D_00506200, &cArray_void_cSystem_dtor, &D_005061E8);
        D_005061E0 = 1;
    }
    return &D_00506200;
}
