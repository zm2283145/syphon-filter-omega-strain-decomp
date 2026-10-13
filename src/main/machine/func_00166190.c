#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
int Hog_Register(char *, int, char *, int);
int Mem_Free(int, int, char *, int);
int RemoveIntcHandler(int, int);
int DeleteThread(int);
int TerminateThread(int);
int ChangeThreadPriority(int, int);
int func_00271CD0(int);
int func_002720A0(int, int);
int Archive_GetMemberName(char *, int);
int func_0036DEF0(char *);
int func_0036E220(char *, int);
int func_0036E5D0(char *);
int func_003816F0(int, char *);
int ArchiveList_CloseNamed(char *, char *);
extern int D_0048A030;
extern int D_0048A038;
extern int D_0048A048;
extern int D_0048A058;
extern char D_0049C390;
extern int D_004EE4E8;
extern int D_004EE500;
extern int D_004EE508;
extern char D_004FFB8C;
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_00539248;

typedef struct { char p0[0x148]; int *f148; unsigned char f14C; } M270_00166190;
typedef struct { char p0[624]; M270_00166190 *f270; int f274; } PS0_00166190;
void App_Teardown(PS0_00166190 *arg0) {
    int sp50[44];
    int n;
    int i;
    int h;

    if (arg0->f274 != 0) {
        if (D_0048A038 != -1) {
            Alloc_Lock(2);
            RemoveIntcHandler(2, D_0048A038);
            D_0048A038 = -1;
        }
        if (D_0048A030 != -1) {
            TerminateThread(D_0048A030);
            DeleteThread(D_0048A030);
            D_0048A030 = -1;
        }
        D_004EE500 = 0;
        D_004EE508 = 0;
        D_0048A058 = -1;
        h = D_004EE4E8;
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        Mem_Free(0, h, &D_0049C390, 0x7F3);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_004EE4E8 = 0;
        D_00533888 -= 1;
        ChangeThreadPriority(D_0048A048, 5);
        if (arg0->f274 != 0) {
            func_00271CD0(arg0->f274);
            h = arg0->f274;
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            func_002720A0(h, -1);
            Mem_Free(0, h, &D_0049C390, 0x7FD);
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            arg0->f274 = 0;
        }
        if (arg0->f270->f14C != 0) {
            func_0036E5D0((char *)sp50);
            n = arg0->f270->f148[1];
            for (i = 0; i < n; i++) {
                M270_00166190 *m = arg0->f270;
                Hog_Register((char *)sp50, Archive_GetMemberName((char *)m, i), (char *)m, 0);
                func_0036DEF0((char *)sp50);
                func_003816F0(D_00539248, (char *)sp50);
            }
            ArchiveList_CloseNamed(&D_004FFB8C, (char *)arg0->f270);
            func_0036E220((char *)sp50, -1);
        }
    }
}