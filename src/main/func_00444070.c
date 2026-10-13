#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"

extern "C" {
void* memset(void*, int, unsigned int);
void String_Copy(char*, const char*);
int func_002CF2C0(char*, void*);
int func_002CF5E0(void);
void func_002EBC48(int*);
int func_004446E0(int);
void SFOLobby_CallUpdateHook(char*, int, int);
void func_00445230(void);
extern unsigned char D_00584231;
extern unsigned char D_00584237;
extern int D_00584528;
extern char* D_00585E60;
extern char D_004C0B38[];
}

static inline bool Poll(void) {
    int now = 0;
    func_002EBC48(&now);
    if (now - D_00584528 > 30000) return false;
    SFOLobby_CallUpdateHook(D_00585E60, 0, 0);
    return true;
}

static inline int Busy(void) {
    int r = func_002CF5E0();
    if (r) return r;
    return 0;
}

extern "C" int func_00444070(int arg) {
    if (!D_00584231) return 0;
    if (arg) {
        char buf[0x15];
        memset(buf, 0, sizeof(buf));
        String_Copy(buf, D_004C0B38);
        if (func_002CF2C0(buf, (void*)func_00445230) == 0) {
            D_00584528 = 0;
            func_002EBC48(&D_00584528);
            SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
            while (D_00584237 == 0) {
                if (!Poll()) break;
                if (func_004446E0(0)) break;
            }
        }
    }
    if (Busy()) return -12;
    D_00584231 = 0;
    return 0;
}

