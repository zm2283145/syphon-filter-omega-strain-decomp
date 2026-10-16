#include "types.h"
typedef struct { int* model; } Obj002721B0;
extern int* LoadingScreen_BuildIeScreen(int name);
extern void func_003EEBE0(int a, int b, int c);
extern void LoadingScreen_Reset(Obj002721B0* obj);
/* Construct: look up the model by name, activate it and finish setup. */
Obj002721B0* LoadingScreen_ctor(Obj002721B0* obj, int unused, int name)
{
    obj->model = LoadingScreen_BuildIeScreen(name);
    func_003EEBE0(*obj->model, 0, 1);
    LoadingScreen_Reset(obj);
    return obj;
}
