/*
 * lib/medius: 2 files, 0046B8F0-0046BA68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046B8F0 */
extern char D_004C3040[], D_004C3090[], D_004C30A0[], D_004C30B8[], D_004C30D0[], D_004C30F0[], D_004C3108[], D_004C3128[], D_004C3140[], D_004C3160[], D_004C3180[], D_004C3198[], D_004C31B8[], D_004C31D0[], D_004C31F0[], D_004C3208[], D_004C3228[], D_004C3240[], D_004C3260[], D_004C3290[], D_004C32C8[];

/* MediusErrorType -> name */
const char* MediusGetErrorCodeString(int err)
{
    switch (err) {
    case 0: return D_004C3090;
    case -1: return D_004C30A0;
    case -2: return D_004C30B8;
    case -3: return D_004C30D0;
    case -4: return D_004C30F0;
    case -5: return D_004C3108;
    case -6: return D_004C3128;
    case -7: return D_004C3140;
    case -8: return D_004C3160;
    case -10: return D_004C3180;
    case -11: return D_004C3198;
    case -12: return D_004C31B8;
    case -13: return D_004C31D0;
    case 3: return D_004C3040;
    case -14: return D_004C31F0;
    case -15: return D_004C3208;
    case -16: return D_004C3228;
    case -17: return D_004C3240;
    case -18: return D_004C3260;
    case -19: return D_004C3290;
    default: return D_004C32C8;
    }
}
/* merge_units: end func_0046B8F0 */

/* merge_units: begin func_0046BA68 */
typedef unsigned int size_t;
typedef struct { int d[0x27]; } BlkA;
typedef struct { int d[0x15]; } BlkB;
typedef struct {
    int pad0;
    int arg;
    BlkA a;
    void (*cb)(void);
    int padA8[3];
    int f8;
    int padB8;
    int fc;
    int padC0[3];
    BlkB b;
    int pad120[4];
} ConnParam;
typedef struct {
    int f0;
    int f4;
    char name[0x10];
    int f18;
    int f1C;
    char f20;
    char pad21[0xF];
    int f30;
    int f34;
    char f38[0x40];
    char f78[0x11];
    char f89;
    char pad8A[0x12];
    BlkB b;
    int fF0;
    int fF4;
    int fF8;
    int fFC;
} ConnSetup;
void *memset(void *, int, size_t);
size_t strlen(const char *);
char *strncpy(char *, const char *, size_t);
int NetSetDefaultConnectParams(ConnParam *);

void MediusSetDefaultConnectInParams(ConnSetup *o, const char *s1, const char *s2, int a3, int a4)
{
    ConnParam p;
    memset(o, 0, 0x100);
    NetSetDefaultConnectParams(&p);
    o->b = p.b;
    o->f0 = 1;
    o->f34 = a4;
    if (s1)
        strncpy(o->f78, s1, strlen(s1) + 1);
    else
        o->f78[0] = 0;
    o->fF0 = 0x100;
    memset(o->f38, 0, 0x40);
    o->f89 = 0;
    o->f4 = 1;
    strncpy(o->name, s2, strlen(s2) + 1);
    o->f18 = a3;
    o->f1C = 0;
    o->f20 = 0;
    o->f30 = 0;
    o->fF4 = 0;
    o->fF8 = 0;
    o->fFC = 0;
}
/* merge_units: end func_0046BA68 */
