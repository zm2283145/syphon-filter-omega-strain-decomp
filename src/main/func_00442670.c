#include "types.h"

typedef struct Tmp16 {
    int a, b, c, d;
} Tmp16;

extern void String_Copy(Tmp16*);
extern void func_0044F470(void*, Tmp16*);

/* Builds a temporary with String_Copy and passes it to func_0044F470(self + 0x54). */
void func_00442670(char* self) {
    Tmp16 tmp;
    String_Copy(&tmp);
    func_0044F470(self + 0x54, &tmp);
}
