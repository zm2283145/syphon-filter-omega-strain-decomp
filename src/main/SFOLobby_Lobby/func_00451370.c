#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern unsigned int strlen(const char*);
extern int strcmp(const char*, const char*);
extern char* strncpy(char*, const char*, int);
extern void* memset(void*, int, int);
extern char* String_Copy(char*, const char*);
extern void func_00451B00(char*, int, char*, int);
extern int* func_0044F290(char*, int);
extern int func_0046B140(void*, void*);
extern void func_00446E00(void);
extern int func_00443E70(void);
extern void func_00452F70(char*, int, int);
extern int func_004534A0(char*, int, int, int);
extern char D_004C0F68[];
extern char D_004C0F70[];
extern int D_00497890;


static inline int* Find(char* o, char* name) {
    int n = F_(o, 0x100, int);
    int i;
    for (i = 0; i < n; i++) {
        int* e = func_0044F290(o + 0xFC, i);
        if (strcmp(name, (char*)(e + 1)) == 0) return e;
    }
    return 0;
}

typedef struct {
    char a[0x15];
    char b[0x11];
    char c[0x20];
} Req;

int func_00451370(char* o, char* name) {
    int st;
    int i;
    int n;
    int* e;
    int h;
    Req r;

    st = F_(o, 0x255C, int);
    if (st != 5 && st != 6 && st != 7) {
        func_00451B00(o, 0x23, D_004C0F70, 0x101);
        return -1;
    }
    if (name == 0 || *name == 0 || strlen(name) > 0x1F) {
        func_00451B00(o, 0x22, D_004C0F70, 0x108);
        return -1;
    }
    e = Find(o, name);
    if (e != 0) {
        return *e;
    }
    memset(&r, 0, sizeof(r));
    String_Copy(r.a, D_004C0F68);
    strncpy(r.b, o + 0x2418, 0x11);
    strncpy(r.c, name, 0x1F);
    F_(o, 0x24C, int) = func_0046B140(&r, func_00446E00);
    if (*(int*)(o + 0x248 + 4) != 0) {
        func_00451B00(o, 1, D_004C0F70, 0x11B);
        return -1;
    }
    h = func_00443E70();
    F_(o, 0x1C4, int) = 0;
    while (*(int*)(o + 0x1C0 + 4) == 0) {
        func_00452F70(o, 0, 0);
        if (func_004534A0(o, h, D_00497890, 0) == 0) {
            func_00451B00(o, 2, D_004C0F70, 0x129);
            return -1;
        }
    }
    if (F_(o, 0xA84, int) != 0) {
        func_00451B00(o, 0x1D, D_004C0F70, 0x130);
        return -1;
    }
    func_00451B00(o, 0, D_004C0F70, 0x135);
    return F_(o, 0xA80, int);
}



