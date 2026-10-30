typedef struct { short v[4]; } B8;
typedef struct { B8 a; B8 b; int x10; short x14; char pad16[2]; char name[0x20]; } Ent;
typedef struct { unsigned short x0; int x4; B8 a; char pad10[8]; B8 b; char pad20[0x20]; char name[0x1C0]; } Info;
typedef struct { int a; int op; int x8; int xC; int x10; int x14; int x18; char p[0x400]; char name[0x80]; char name2[0x80]; } RQ;
typedef struct { int x0; int x4; int x8; } TH;
extern RQ D_00506640;
extern TH D_00506B60;
extern int SignalSema(int);
extern void func_002BC7C8(void);
extern int _sceMcFatGetInfo(int, int);
extern int _sceMcFatReadFile(int, char *, int, int, int);
extern int func_002B98D0(int, char *, int, int, int);
extern int _sceMcFatFormat(int);
extern int _sceMcFatCreateFile(int, char *, int);
extern int func_002B9F10(int, char *);
extern int _sceMcFatChDir(int, char *, int);
extern int _sceMcFatGetDir(int, char *, int, int, int, int);
extern int func_002BA6C8(int, char *, unsigned short);
extern int _sceMcFatRename(int, char *, char *);
extern int _sceMcFatUnFormat(int);
extern int _sceMcFatSearchFile(int, char *, Info *, int, int);
extern int func_002BA950(int, char *);
extern int _sceMcCoreReadPage2(int, int, int, int, int);
extern int _sceMcCoreWritePage(int, int, int, int);
extern void *memcpy(void *, const void *, unsigned int);
extern void Libc_Strcpy(char *, char *);

void basic_thread(void)
{
    Info info;
    for (;;) {
        register int op asm("$2");
        /* empty asm insns: lengthen the loop by 6 RTL insns so global-alloc's
           live-length priorities give retail's callee-saved register order */
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        func_002BC7C8();
        op = D_00506640.op - 2;
        __asm__("" : "+r"(op)); /* keep the switch index in v0 */
        switch (op) {
        case 0:
            D_00506640.x8 = _sceMcFatGetInfo(D_00506640.a, D_00506640.xC);
            break;
        case 3:
            D_00506640.x8 = _sceMcFatReadFile(D_00506640.a, D_00506640.name, D_00506640.xC, D_00506640.x10, D_00506640.x14);
            break;
        case 4:
            D_00506640.x8 = func_002B98D0(D_00506640.a, D_00506640.name, D_00506640.xC, D_00506640.x10, D_00506640.x14);
            break;
        case 1:
            D_00506640.x8 = _sceMcFatFormat(D_00506640.a);
            break;
        case 5:
            D_00506640.x8 = _sceMcFatCreateFile(D_00506640.a, D_00506640.name, D_00506640.xC);
            break;
        case 6:
            D_00506640.x8 = func_002B9F10(D_00506640.a, D_00506640.name);
            break;
        case 9:
            D_00506640.x8 = _sceMcFatCreateFile(D_00506640.a, D_00506640.name, D_00506640.xC);
            break;
        case 10:
            D_00506640.x8 = _sceMcFatChDir(D_00506640.a, D_00506640.name, D_00506640.xC);
            break;
        case 8:
            D_00506640.x8 = _sceMcFatGetDir(D_00506640.a, D_00506640.name, D_00506640.xC, D_00506640.x10, D_00506640.x14, D_00506640.x18);
            break;
        case 11:
            D_00506640.x8 = func_002BA6C8(D_00506640.a, D_00506640.name, D_00506640.xC);
            break;
        case 7:
            D_00506640.x8 = _sceMcFatRename(D_00506640.a, D_00506640.name, D_00506640.name2);
            break;
        case 2:
            D_00506640.x8 = _sceMcFatUnFormat(D_00506640.a);
            break;
        case 12: {
            Ent *e;
            D_00506640.x8 = _sceMcFatSearchFile(D_00506640.a, D_00506640.name, &info, 0, 0);
            if (D_00506640.x8 == 0x81010011) D_00506640.x8 = 0;
            if (D_00506640.x8 == 0x81019FFF) D_00506640.x8 = 0x81010002;
            e = (Ent *)D_00506640.xC;
            if (e) {
                Libc_Strcpy(e->name, info.name);
                e->a = info.a;
                e->b = info.b;
                e->x10 = info.x4;
                e->x14 = info.x0;
            }
            break;
        }
        case 13:
            D_00506640.x8 = func_002BA950(D_00506640.a, D_00506640.name);
            break;
        case 14:
            D_00506640.x8 = _sceMcCoreReadPage2(D_00506640.a, D_00506640.xC, D_00506640.x10, 1, D_00506640.x14);
            break;
        case 15:
            D_00506640.x8 = _sceMcCoreWritePage(D_00506640.a, D_00506640.xC, D_00506640.x10, D_00506640.x14);
            break;
        case 98:
            break;
        }
        SignalSema(D_00506B60.x8);
    }
}


