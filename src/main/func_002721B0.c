#include "types.h"
typedef struct { int* model; } Obj002721B0;
extern int* func_00241B70(int name);
extern void func_003EEBE0(int a, int b, int c);
extern void func_00272170(Obj002721B0* obj);
/* Construct: look up the model by name, activate it and finish setup. */
Obj002721B0* func_002721B0(Obj002721B0* obj, int unused, int name)
{
    obj->model = func_00241B70(name);
    func_003EEBE0(*obj->model, 0, 1);
    func_00272170(obj);
    return obj;
}
