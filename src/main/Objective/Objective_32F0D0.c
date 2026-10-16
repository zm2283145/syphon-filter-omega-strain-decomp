#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x18]; } ObjRow_32F0D0;
extern int D_00532BC0;
extern char D_005329F0[];
extern void* ObjectiveRow_Construct(ObjRow_32F0D0* r, int a, int b, int id);
extern void func_00147600(void* registry, void* item);
int Objective_Register(ScriptArg* args)
{
    ObjRow_32F0D0 r;
    int p0[1];
    int p1[1];
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_005329F0, ObjectiveRow_Construct(&r, *(int*)p0, *(int*)p1, D_00532BC0++));
    return 0;
}