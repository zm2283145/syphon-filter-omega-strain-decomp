#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

typedef struct Arc1C98D0 {
    char pad0[0x84];
    int f84;
    char pad88[0x148 - 0x88];
    char* f148;
    unsigned char f14C;
} Arc1C98D0;

extern Arc1C98D0* Archive_Open(void* a, char* name, int b, int c);
extern char* Loc_GetLanguageSuffix(void);
extern int func_0036D2A0(Arc1C98D0* a, char* name, int c);
extern int func_0036D520(Arc1C98D0* a, int idx);
extern void func_003A7330(int, int, int);
extern void func_003A7370(int, int, int, int);
extern void func_003A8240(void);
extern int func_003A85E0(void);
extern void func_003F9530(void* a, char* name);
extern int func_003F9600(void* a, char* name);
extern int snd_BankLoadByLoc(int loc, int size);
extern int sprintf(char*, const char*, ...);
extern signed char D_0048A330;
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char D_004FFC90[];
extern char D_0049F590[];

int func_001C98D0(char* arg0) {
    char snd[0x80];
    char vag[0x80];
    char vagloc[0x80];
    char music[0x80];
    char* fs = D_004FFB8C;
    Arc1C98D0* arc;

    func_003A7370(4, 0xE000, 1, 1);
    D_0048A330 = 1;
    func_003A7330(1, 0, 1);
    func_003A7330(2, 2, 2);
    func_003A7330(0xE, 2, 2);
    sprintf(snd, "%s\\%s\\SND.HOG", D_0048B2F8, D_004FFC90);
    sprintf(vag, "%s\\%s\\SNDVAG.HOG%s", D_0048B2F8, D_004FFC90, Loc_GetLanguageSuffix());
    sprintf(vagloc, "ZMEDIA\\SNDVAG%s.HOG", Loc_GetLanguageSuffix());
    sprintf(music, D_0049F590);
    arc = Archive_Open(fs, snd, 1, 0);
    if (arc->f14C) {
        if (func_0036D2A0(arc, "WEPS.BNK", 0) != -1) {
            F_(arg0, 0x5494, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + func_0036D520(arc, func_0036D2A0(arc, "WEPS.BNK", 0)));
        }
        if (func_0036D2A0(arc, "ENVIRON.BNK", 0) != -1) {
            F_(arg0, 0x5490, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + func_0036D520(arc, func_0036D2A0(arc, "ENVIRON.BNK", 0)));
        }
        if (func_0036D2A0(arc, "VOX.BNK", 0) != -1) {
            F_(arg0, 0x5498, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + func_0036D520(arc, func_0036D2A0(arc, "VOX.BNK", 0)));
        }
        if (func_0036D2A0(arc, "SHELL.BNK", 0) != -1) {
            F_(arg0, 0x549C, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + func_0036D520(arc, func_0036D2A0(arc, "SHELL.BNK", 0)));
        }
        func_003F9530(fs, snd);
        Archive_Open(fs, vag, 1, 0);
        F_(arg0, 0x54A8, int) = func_003F9600(fs, vag);
        Archive_Open(fs, vagloc, 1, 0);
        F_(arg0, 0x54AC, int) = func_003F9600(fs, vagloc);
        Archive_Open(fs, music, 1, 0);
        F_(arg0, 0x54B0, int) = func_003F9600(fs, music);
    }
    func_003A8240();
    while (func_003A85E0()) {
    }
    return 1;
}
