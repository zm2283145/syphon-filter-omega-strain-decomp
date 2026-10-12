#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef struct { char pad[0x90]; void* ptr; unsigned char flag; char pad2[0x1B0 - 0x95]; } E1C9710;
extern void func_003A7FE0(void);
extern void func_003A7310(void);
extern void func_003A7200(void);
extern void func_003A8210(int);
extern int func_003A85E0(void);
extern void func_003F9530(void* a, char* name);
extern int sprintf(char*, const char*, ...);
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char D_004FFC90[];
extern char D_0049F550[];
extern char D_0049F570[];
extern char D_0049F590[];
#pragma opt_propagation off
void func_001C9710(char* arg0) {
    int i;
    func_003A7FE0();
    func_003A7310();
    func_003A7200();
    {
        E1C9710* e;
        i = 0;
        e = (E1C9710*)arg0;
        do {
            e[0].flag = 0; e[0].ptr = 0;
            i += 8;
            e[1].flag = 0; e[1].ptr = 0;
            e[2].flag = 0; e[2].ptr = 0;
            e[3].flag = 0; e[3].ptr = 0;
            e[4].flag = 0; e[4].ptr = 0;
            e[5].flag = 0; e[5].ptr = 0;
            e[6].flag = 0; e[6].ptr = 0;
            e[7].flag = 0; e[7].ptr = 0;
            e += 8;
        } while (i < 42);
        e = &((E1C9710*)arg0)[i];
        e[0].flag = 0; e[0].ptr = 0;
        e[1].flag = 0; e[1].ptr = 0;
    }
    if (F_(arg0, 0x5494, int)) func_003A8210(F_(arg0, 0x5494, int));
    if (F_(arg0, 0x5490, int)) func_003A8210(F_(arg0, 0x5490, int));
    if (F_(arg0, 0x5498, int)) func_003A8210(F_(arg0, 0x5498, int));
    if (F_(arg0, 0x549C, int)) func_003A8210(F_(arg0, 0x549C, int));
    while (func_003A85E0()) {
    }
    {
    char a[0x80];
    char b[0x80];
    char c[0x80];
    char* fs = D_004FFB8C;
    sprintf(a, D_0049F550, D_0048B2F8, D_004FFC90);
    sprintf(b, D_0049F570);
    sprintf(c, D_0049F590, D_004FFC90);
    func_003F9530(fs, a);
    func_003F9530(fs, b);
    func_003F9530(fs, c);
    }
    F_(arg0, 0x54A8, int) = 0;
    F_(arg0, 0x54AC, int) = 0;
    F_(arg0, 0x54B0, int) = 0;
}





