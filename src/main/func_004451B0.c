#pragma cplusplus on
extern "C" {
int func_002D08D8(void *);
int func_003A6BB0(void);
int memset(void *, int, int);
int strncpy(void *, char *, int);
}
typedef struct { char name[0x15]; signed char f15; signed char f16; char pad[0x51]; } Req445;
#pragma bool off
static inline int nz445(int x) { return x != 0; }
extern "C" int func_004451B0(int d0, int d1, int d2, char *arg3) {
    Req445 r;
    memset(&r, 0, 0x68);
    strncpy(r.name, arg3, 0x15);
    r.f15 = nz445(func_003A6BB0()) ^ 1;
    r.f16 = 0;
    /* barrier: empty asm keeps the branchy return (b + delay slot) shape */
    int v; if (func_002D08D8(&r) != 0) { v = -0xC; asm { .set reorder } } else v = 0; return v;
}
#pragma bool reset