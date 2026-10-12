#pragma cplusplus on
#include "types.h"
extern "C" {
void func_0010CFA0(void);
void func_0010D080(void);
void func_001161A0(void);
void func_001161F8(void);
void func_00429D30(void);
extern signed char D_00572500;
extern unsigned char D_00572530;
}
static inline int Done4295E0() { return D_00572530 != 0; }
#pragma bool off
extern "C" void func_004295E0(void) {
    while (Done4295E0() ^ 1) {
        func_00429D30();
        func_001161F8();
        func_0010D080();
        func_001161A0();
    }
    func_001161F8();
    D_00572500 = 1;
    func_0010CFA0();
}
