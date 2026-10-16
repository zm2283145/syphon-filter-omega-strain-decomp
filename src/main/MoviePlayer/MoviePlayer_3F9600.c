#include "types.h"
typedef struct N9600 { int m0; struct N9600* next; char name[4]; } N9600;
extern N9600* func_003F9520(void* list);
extern void* func_003F95F0(void* self);
extern void func_003F95E0(N9600** out, void* v);
extern int String_CompareNoCase(const char* a, const char* b);
char* func_003F9600(char* self, const char* name)
{
    N9600* e;
    N9600* n;
    for (n = func_003F9520(self + 4)->next; func_003F95E0(&e, func_003F95F0(self)), n != e; n = n->next) {
        if (!String_CompareNoCase(n->name, name))
            return n->name;
    }
    return 0;
}