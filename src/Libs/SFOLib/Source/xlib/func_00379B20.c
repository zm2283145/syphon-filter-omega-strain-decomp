#include "types.h"
typedef struct { char pad[0xF00]; char sub[1]; } Obj00379B20;
extern void XLib_UpdateCompMat(Obj00379B20* obj, int a, int b);
extern void XLib_TestBBox_cMatrixR_cVectorR_cVectorR(Obj00379B20* obj, void* sub, int a, int b);
/* Initialise base, then the sub-object at 0xF00. */
void XLib_TestBBox_cVectorR_cVectorR(Obj00379B20* obj, int a, int b)
{
    XLib_UpdateCompMat(obj, a, b);
    XLib_TestBBox_cMatrixR_cVectorR_cVectorR(obj, obj->sub, a, b);
}
