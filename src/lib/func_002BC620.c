typedef struct { int x8; int xC; int x10; int x14; } Sub;
typedef struct { int used; int sock; Sub s; int x18; } SBBBB0;
typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24; char data[0x2000]; } PBBBB0;
typedef struct { int a; void *b; } LBBBB0;
typedef struct { int gen; int x4; int x8; } E2BB520;
extern SBBBB0 D_00518A08[];
extern PBBBB0 D_00518A40;
extern char D_0051AAC0[];
extern int D_0048C09C;
extern int func_0026A8C8(int);
extern void *memset(void *, int, unsigned int);
extern int sceDbcSendData3(int, int, void *, void *, void *);
extern void func_002BB660(void);
extern E2BB520 *func_002BB520(int);
extern char D_004AC248[];
extern int func_0010F388(const char *, ...);
extern void *memcpy(void *, const void *, unsigned int);
extern void SyncDCache(void *, void *);
int func_002BC620(int i, int a)
{
    int l;
    if (func_0026A8C8(D_00518A08[i].sock) == 3) return 0;
    D_00518A40.x0 = 0;
    D_00518A40.x4 = 1;
    D_00518A40.x8 = D_00518A08[i].s.x8;
    D_00518A40.xC = D_00518A08[i].s.xC;
    D_00518A40.x10 = D_00518A08[i].s.x10;
    D_00518A40.x1C = 0;
    D_00518A40.x20 = a;
    l = 0x2080;
    memset(D_0051AAC0, 0, 0x100);
    SyncDCache(D_0051AAC0, D_0051AAC0 + 0xFF);
    D_0048C09C = 9;
    while (sceDbcSendData3(D_00518A08[i].sock, D_0048C09C, &l, &D_00518A40, func_002BB660) != 1);
    return func_002BB520(D_00518A08[i].sock)->x8 != 0;
}
