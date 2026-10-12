#include "types.h"
typedef struct { char pad[0x30]; int a30; int a34; int a38; } S369160;
extern int g_FrameCounter;
extern int D_00533860;
extern char D_004BBDE8[];
extern char D_004BBDF8[];
extern char D_004BBE00[];
extern int func_003A6ED0(void);
extern int func_003A6F70(int mode);
extern void func_003A6F10(void);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_00127358(char* tag, char* msg);
int func_00369160(S369160* o)
{
    char msg2[128];
    char msg1[128];
    int r = 1;
    int err = func_003A6ED0();
    int busy = func_003A6F70(r);
    o->a34 = g_FrameCounter;
    if (busy) {
        if (g_FrameCounter - o->a30 > o->a38) {
            sprintf(msg2, D_004BBDE8);
            func_00127358(D_004BBDF8, msg2);
            r = -1;
        } else {
            r = 0;
        }
    } else if (err) {
        sprintf(msg1, D_004BBE00, err);
        func_00127358(D_004BBDF8, msg1);
        r = -1;
    }
    if (r == -1) {
        func_003A6F10();
        func_003A6F70(0);
    }
    if (r) D_00533860 = 0;
    return r;
}
