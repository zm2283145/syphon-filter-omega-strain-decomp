#include "types.h"
extern void Libc_Raise(int code);
extern void Newlib_SysExit_Thunk(int code) __attribute__((noreturn));
void Libc_Abort(void) {
    Libc_Raise(6);
    Newlib_SysExit_Thunk(1);
}
