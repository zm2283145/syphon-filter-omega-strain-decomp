#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"

typedef struct { signed char a; signed char b; } Pair4505;
typedef struct {
    unsigned char b0, b1, b2, b3;
    unsigned short h4, h6, h8, hA, hC, hE;
    int w10, w14, w18, w1C, w20, w24;
    Pair4505 pairs[0x60];
    int wE8, wEC, wF0, wF4;
    unsigned char bF8, bF9;
} Info4505;

typedef struct {
    char name[0x15];
    char user[0x11];
    char info[0xFC];
    char pad[4];
} Req4505;

extern "C" {
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);
char* strncpy(char*, const char*, unsigned int);
void String_Copy(char*, const char*);
int func_00443E70(void);
int func_004695C8(void*, void*);
void func_00446CC0(void);
void func_00451B00(char*, int, const char*, int);
void func_00452F70(char*, int, int);
int func_004534A0(char*, int, int, int);
int func_00443020(char*);
void func_00450880(char*, int, char*, int, Info4505*);
extern int D_00497890;
extern char D_004C0F68[];
extern char D_004C0F70[];
extern Info4505 D_00585E90;
}

#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" int func_004505E0(char* self, Info4505* info)
{
    Req4505 req;
    int t;

    F_(self, 0x2590, int) = func_00443E70();
    memset(&req, 0, sizeof(req));
    String_Copy(req.name, D_004C0F68);
    strncpy(req.user, self + 0x2418, 0x11);
    memcpy(&req.info, info, 0xFC);
    F_(self, 0x24C, int) = func_004695C8(&req, (void*)func_00446CC0);
    if (F_(self, 0x24C, int) != 0) {
        func_00451B00(self, 1, D_004C0F70, 0x428);
        return 0;
    }
    t = func_00443E70();
    F_(self, 0x1C8, int) = 0;
    while (F_(self, 0x208, int) == 0) {
        func_00452F70(self, 0, 0);
        if (!func_004534A0(self, t, D_00497890, 0)) {
            func_00451B00(self, 2, D_004C0F70, 0x436);
            return 0;
        }
    }
    D_00585E90 = *info;
    func_00450880(self, F_(self, 0x2480, int), self + 0x243D, func_00443020(self + 0x2429), &D_00585E90);
    return 1;
}





