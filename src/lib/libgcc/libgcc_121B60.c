#include "types.h"
extern void func_00128910(int code);
extern void func_00100218(int code) __attribute__((noreturn));
void Libc_Abort(void) {
    func_00128910(6);
    func_00100218(1);
}
