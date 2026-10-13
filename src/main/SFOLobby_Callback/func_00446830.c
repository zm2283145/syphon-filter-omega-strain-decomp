#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
extern "C" {
int String_Copy(char *, char *);
char *func_0044F0C0(char *, int, int *);
void func_0044F160(char *, int);
void func_0044F180(char *, char *);
void func_0044F280(char *, int);
int func_0044F470(char *, void *);
int func_004505C0();
void *memset(void *, int, int);
extern char D_004C0CC8[];
extern char *D_00585E60;
}

typedef struct {
    signed char a, b;
} Pair446830;

typedef struct {
    char name[0x15];
    int f18;
    int f1C;
    Pair446830 pairs[0x10];
    int w[0x23];
    signed char cc;
} Msg446830;

typedef struct {
    int id;
    char name[0x20];
    int f24;
    int f28;
    char *f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
} Req446830;

extern "C" void func_00446830(int d0, int d1, int d2, Msg446830 *msg)
{
    Req446830 req;
    char *list;
    char *e;

    if (func_004505C0() == 0) {
        list = D_00585E60 + 0xE0;
        if (list != NULL) {
            if (msg->f18 == 0) {
                memset(&req, 0, 0x50);
                req.id = msg->f1C;
                String_Copy(req.name, (char *)msg->pairs);
                req.f30 = 0;
                req.f34 = -1;
                req.f38 = -1;
                req.f3C = -1;
                req.f40 = -1;
                req.f44 = 5;
                req.f28 = 2;
                req.f24 = 3;
                req.f2C = D_004C0CC8;
                switch (msg->w[0]) {
                case 0:
                case 1:
                    break;
                case 2:
                    req.f24 = 2;
                    break;
                case 3:
                    req.f24 = 1;
                    req.f48 = msg->w[2];
                    e = func_0044F0C0(D_00585E60, req.f48, &req.f24);
                    if (e != NULL) {
                        req.f30 = F_(e, 0x24, int);
                        req.f34 = F_(e, 0x4, int);
                        req.f38 = F_(e, 0x8, int);
                        req.f3C = F_(e, 0x1C, int);
                        req.f40 = F_(e, 0x10, int);
                        req.f44 = F_(e, 0x18, int);
                    }
                    break;
                }
                func_0044F470(list, &req);
            }
            if (msg->cc != 0) {
                func_0044F160(list, 0);
                if (F_(list, 4, int) > 0)
                    func_0044F280(list, 1);
                if (F_(D_00585E60, 0x23E8, char *) != NULL)
                    func_0044F180(F_(D_00585E60, 0x23E8, char *), list);
                func_0044F180(D_00585E60 + 0x150, list);
            }
            *(Msg446830 *)(D_00585E60 + 0xC28) = *msg;
        }
    }
}
