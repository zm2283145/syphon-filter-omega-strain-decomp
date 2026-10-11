#include "types.h"
typedef struct N1F30 { int m0; struct N1F30* next; void* data; } N1F30;
typedef struct { char pad[0xC]; int list; } T1F30;
extern void func_0013B180(int* out, void* list);
extern void func_003E13D0(N1F30** out, int* in);
extern void func_003E13C0(int* out, void* list);
extern void func_003E13B0(N1F30** out, int* in);
extern void Script_RunVarInitializers(void* s);
void cScriptInterpreter_ExecuteInitCode(T1F30* self)
{
    N1F30* e;
    N1F30* it;
    int t1;
    int t2;
    N1F30* n;
    func_0013B180(&t1, &self->list);
    func_003E13D0(&it, &t1);
    for (n = it; func_003E13C0(&t2, &self->list), func_003E13B0(&e, &t2), n != e; n = n->next)
        Script_RunVarInitializers(n->data);
}
