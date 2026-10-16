#include "types.h"

typedef struct E_416E40 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_416E40;
typedef struct It_416E40 { E_416E40* p; } It_416E40;
typedef struct O_416E40 { char pad[0x70]; char v70[0x10]; E_416E40* cur; } O_416E40;

extern void func_00416F30(It_416E40* out, void* v, It_416E40* src);
extern E_416E40* func_00416F40(void* v);
extern E_416E40** func_00416F60(void* v);
extern int String_AssignCStr_1C43A0(E_416E40* s, char* c);

#pragma bool off
static inline int Ne_416E40(E_416E40* a, E_416E40* b) { return (a == b) ^ 1; }

E_416E40* GuiInterfaceDecorator_FindEvent(O_416E40* o, char* name)
{
    E_416E40* it;
    It_416E40 end;
    It_416E40 tmp;
    if (name == 0 || *name == 0) return o->cur;
    it = *func_00416F60(o->v70);
    while ((tmp.p = func_00416F40(o->v70), func_00416F30(&end, o->v70, &tmp), Ne_416E40(it, end.p))) {
        if (String_AssignCStr_1C43A0(it, name) == 0) return it;
        it++;
    }
    return 0;
}
#pragma bool reset

