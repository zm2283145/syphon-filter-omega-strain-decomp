#include "types.h"
typedef struct { const char* name; } E6BE0;
typedef struct { int m0; int m4; int m8; int* mC; } T6BE0;
extern E6BE0** func_003D6C80(int* list, int i);
extern int String_CompareNoCase(const char* a, const char* b);
int func_003D6BE0(T6BE0* self, const char* name)
{
    int n = self->m8;
    int i;
    for (i = 0; i < n; i++) {
        if (!String_CompareNoCase((*func_003D6C80(&self->m4, i))->name, name))
            return self->mC[i];
    }
    return 0;
}
