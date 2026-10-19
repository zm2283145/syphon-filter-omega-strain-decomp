#include "types.h"

extern void func_003B5300(void* tmp);
extern void String_CopyCtor(void* self, void* tmp);
extern void String_Dtor(void* tmp, int flag);

/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int func_003B52B0(void* self) {
    char tmp[16];
    func_003B5300(tmp);
    String_CopyCtor(self, tmp);
    String_Dtor(tmp, -1);
    return 0;
}
