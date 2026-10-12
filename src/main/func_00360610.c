#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on

typedef struct { char c[16]; } C16;
typedef struct { Q q[64]; } Q64;
typedef struct { C16 a; __int128 b; C16 c; C16 d; Q64 e; } Blk;

extern void func_00360510(char*);
extern int String_CtorCStr_13B480(char*, char*);
extern int func_00138B70(char*, int);
extern int func_0013D680(char*, char*);
extern char* func_004294C0(void);
extern int func_0044A1D0(char*);
extern int func_00452FF0(char*, int);
extern char* func_0044A070(char*);
extern char* func_00448FF0(char*, int);
extern void* memset(void*, int, int);
extern void* memcpy(void*, void*, int);
extern void* Agent_GetSelected(void*, int);
extern void func_00406EC0(Blk*, char*);
extern void Skl_Load(void*, char*, char*);
extern void func_00361000(char*);
extern char D_004BB868[];
extern char D_004BB870[];
extern char D_004BB890[];
extern char D_004FFB50[];
extern char D_0055DDA0[];
extern C16 D_0055D510;
extern __int128 D_0055D520;
extern C16 D_0055D530;
extern C16 D_0055D540;
extern Q64 D_0055D550;

typedef struct { unsigned char type, b1, b2, b3; unsigned short h4, h6, h8, hA, hC, hE; int x10, x14, x18, x1C, x20, mask; char data[0xC0]; int xE8; } Msg;
void func_00360610(char* self, int* arg1, Msg* arg2) {
    char s1[16];
    char s2[16];
    char s3[16];
    char s4[16];
    char buf[0x100];
    char* o;
    char* r;
    Blk* p;
    int i, j;

    func_00360510(self + 0x88);
    F_(self, 0xD0, int) = arg2->b1;
    String_CtorCStr_13B480(s1, (char*)(arg1 + 1));
    func_0013D680(self + 0xB8, s1);
    func_00138B70(s1, 0);
    o = func_004294C0();
    if (o) {
        F_(self, 0xF4, char) = func_0044A1D0(o);
        if (!(unsigned char)func_00452FF0(o, 0)) {
            if (arg1[0] == F_(o, 0x2480, int)) {
                F_(self, 0xF8, int) = -1;
                String_CtorCStr_13B480(s2, func_0044A070(o));
                func_0013D680(self + 0xC4, s2);
                func_00138B70(s2, 0);
            } else {
                F_(self, 0xF8, int) = arg1[0];
                String_CtorCStr_13B480(s3, D_004BB868);
                func_0013D680(self + 0xC4, s3);
                func_00138B70(s3, 0);
                if (arg2->xE8 != -1) {
                    r = func_00448FF0(o, arg2->xE8);
                    if (r) {
                        String_CtorCStr_13B480(s4, r);
                        func_0013D680(self + 0xC4, s4);
                        func_00138B70(s4, 0);
                    }
                }
            }
        }
    }
    if (arg2->type == 11) {
        F_(self, 0x88, int) = arg2->h4;
        F_(self, 0x8C, int) = arg2->x10;
        F_(self, 0x90, int) = arg2->x14;
        F_(self, 0x94, int) = arg2->x18;
        F_(self, 0x98, int) = arg2->h6;
        F_(self, 0x9C, int) = arg2->h8;
        F_(self, 0xA0, int) = arg2->b2;
        F_(self, 0xA4, int) = arg2->b3;
        F_(self, 0xA8, int) = arg2->hA;
        F_(self, 0xAC, int) = arg2->hC;
        F_(self, 0xB0, int) = arg2->x20;
        F_(self, 0xB4, int) = arg2->x1C;
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 4; j++) {
                if (arg2->mask & (1 << (j + i * 4))) {
                    (self + i * 4)[0xD4 + j] = 1;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            if (arg2->mask & (1 << (i + 24))) {
                (self + 0xEC)[i] = 1;
            }
        }
        memset(buf, 0, 0x100);
        memcpy(buf, arg2->data, 0xC0);
        Agent_GetSelected(D_004FFB50, -1);
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        memset(p, 0, 0x440);
        func_00406EC0(p, buf);
    } else {
        Skl_Load(D_0055DDA0, D_004BB870, D_004BB890);
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        p->a = D_0055D510;
        p->b = D_0055D520;
        p->c = D_0055D530;
        p->d = D_0055D540;
        p->e = D_0055D550;
    }
    F_(self, 0xFC, int) = 1;
    func_00361000(self);
}
