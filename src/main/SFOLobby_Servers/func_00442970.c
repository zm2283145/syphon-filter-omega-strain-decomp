#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" {
int strcmp(const char*, const char*);
int func_0044CA30(char*);
int func_0044CA90(char*);
int func_0044D510(char*);
char* func_0044F290(int, int);
int func_00442C20(char*, char*, char*);
int func_00442D80(char*);
int func_00442840(char*, int);
}

static inline bool Connect(char* self, int idx) {
    if (F_(self, 0x180, int) > 0) {
        if (!func_0044CA90(self)) return false;
        if (!func_0044CA30(self)) return false;
    }
    if (!F_(self, 0x2184, unsigned char)) {
        char* e = func_0044F290(F_(self, 0x23DC, int), idx);
        if (!func_00442C20(self, e + 0x80, self + 0x1FFC)) return false;
        F_(self, 0x207C, int) = F_(e, 0x100, int);
    }
    if (!func_0044D510(self)) return false;
    if (!func_00442D80(self)) return false;
    return true;
}

extern "C" int func_00442970(char* self) {
    bool found;
    int i;
    char* e;
    int l;

    if (F_(self, 0x2184, unsigned char)) return 0;
    found = false;
    for (i = 0; i < F_(l = F_(self, 0x23DC, int), 4, int); i++) {
        e = func_0044F290(l, i);
        if (e && !strcmp(self + 0x248C, e)) {
            found = true;
            if (!Connect(self, i)) return 0;
            break;
        }
    }
    if (!found) return 0;
    for (i = 0; i < F_(l = F_(self, 0x23E0, int), 4, int); i++) {
        e = func_0044F290(l, i);
        if (e && !strcmp(self + 0x250C, e + 4)) return func_00442840(self, i);
    }
    return 0;
}


