#include "types.h"
typedef struct { char pad[0xF00]; char sub[1]; } Obj00379B20;
extern void Renderer_UpdateCameraMatrices(Obj00379B20* obj, int a, int b);
extern void Model_BoundsIntersect(Obj00379B20* obj, void* sub, int a, int b);
/* Initialise base, then the sub-object at 0xF00. */
void Renderer_TestVisibility(Obj00379B20* obj, int a, int b)
{
    Renderer_UpdateCameraMatrices(obj, a, b);
    Model_BoundsIntersect(obj, obj->sub, a, b);
}
