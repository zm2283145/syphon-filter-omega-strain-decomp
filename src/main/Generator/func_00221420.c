#include "types.h"

extern void func_0043B190(int*);
extern void func_0043A030(int*, void*);
extern void func_003CE7D0(void*);

/* vtable slot 7 of cGenerator. */
void cGenerator_v07(char* self) {
    int tmp;
    func_0043B190(&tmp);
    func_0043A030(&tmp, self + 0xC);
    func_003CE7D0(self);
}
