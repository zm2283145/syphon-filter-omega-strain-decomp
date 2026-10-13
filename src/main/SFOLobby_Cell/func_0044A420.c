#include "types.h"
typedef struct { char p0[0x21C]; int f21C; int f220; char p224[0x24C - 0x224]; int f24C; char p250[0x16DC - 0x250]; char f16DC[0xEC]; signed char f17C8; char p17C9[0x2410 - 0x17C9]; int f2410; char p2414[4]; char name[0x17C]; char out[0xC8]; } S44A420;
typedef struct { int f0; int count; char p8[8]; int f10; int f14; signed char f18; } List44A420;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int sprintf(char*, const char*, ...);
extern int func_00443E70(void);
extern int func_00443100(S44A420*, char*, int);
extern void func_00451AE0(void);
extern void func_00451B00(S44A420*, int, char*, int);
extern void func_00452F70(S44A420*, int, int);
extern int func_00452FF0(S44A420*, int);
extern int func_004534A0(S44A420*, int, int, int);
extern List44A420* func_0044FA00(List44A420*);
extern void func_0044F880(List44A420*, int, int, int);
extern int* func_0044F290(List44A420*, int);
extern void func_0044F970(List44A420*, int);
extern int func_00467838(void*, void*);
extern int func_004673C8(void*, void*);
extern int func_00467278(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D28[];
extern char D_004C0D38[];
extern char func_004484B0[];
extern char func_00448470[];
extern char func_00448700[];
#pragma push
#pragma opt_common_subs off
int func_0044A420(S44A420* s, char* msg)
{
    List44A420 list;
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; } req1;
    struct { char f0[0x15]; char f15[0x13]; int f28; } req2;
    struct { char f0[0x15]; char f15[0x11]; char f26[0xC8]; } req3;
    int i;

    func_00451AE0();
    if (func_00443100(s, msg, 0) == 0) {
        func_00451B00(s, 3, D_004C0D10, 0x268);
        return 0;
    }
    func_0044FA00(&list);
    func_0044F880(&list, 0x20, 0, 0xF0);
    memset(&req1, 0, sizeof(req1));
    sprintf(req1.f0, D_004C0D28, &list);
    String_Copy(req1.f15, s->name);
    req1.f28 = 1;
    req1.f2C = 0x1E;
    s->f2410 = func_00443E70();
    memset(s->f16DC, 0, 0xF0);
    s->f24C = func_00467838(&req1, func_004484B0);
    if (s->f24C == 0) {
        while (s->f17C8 != 1) {
            func_00452F70(s, 0, 0);
            if (func_004534A0(s, s->f2410, D_00497890, 0) == 0)
                break;
        }
    }
    for (i = 0; i < list.count; i++) {
        int* e = func_0044F290(&list, i);
        memset(&req2, 0, sizeof(req2));
        String_Copy(req2.f0, D_004C0D38);
        String_Copy(req2.f15, s->name);
        req2.f28 = e[7];
        s->f2410 = func_00443E70();
        s->f21C = 0;
        s->f24C = func_004673C8(&req2, func_00448470);
        if (s->f24C == 0) {
            while ((s->f21C != 0) ^ 1) {
                func_00452F70(s, 0, 0);
                if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
                    i = 0x3E7;
                    break;
                }
            }
        }
    }
    memset(&req3, 0, sizeof(req3));
    String_Copy(req3.f0, D_004C0D38);
    String_Copy(req3.f15, s->name);
    strncpy(req3.f26, msg, 0xC7);
    s->f220 = 0;
    s->f2410 = func_00443E70();
    s->f24C = func_00467278(&req3, func_00448700);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x2BB);
        func_0044F970(&list, -1);
        return 0;
    }
    while ((s->f220 != 0) ^ 1) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x2C6);
            func_0044F970(&list, -1);
            return 0;
        }
    }
    memset(s->out, 0, 0xC8);
    strncpy(s->out, msg, 0xC7);
    if (func_00452FF0(s, 0)) {
        func_0044F970(&list, -1);
        return 0;
    }
    func_0044F970(&list, -1);
    return 1;
}
#pragma pop

