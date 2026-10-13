#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int String_Copy(char *, char *);
int Lobby_GetTime();
int SFOLobby_SetError(char * , int, char *, int);
int func_00466F50(char *, char *);
int memset(char *, int, int);
int strncpy(char *, char * , int);
void func_00453FE0(char*);
void func_00449A00(char*);
void func_00449D20(char*, int);
void func_0044A290(char*);
void func_00451B30(char*);
void func_00453FA0(char*, char*);
void func_0044EBD0(char*, char*);
void func_0044D700(char*, int);
extern int D_004977E8;
extern int D_00497800;
extern int D_00497818;
extern char D_004C0D10;
extern char D_004C0D38;
extern char func_004482E0;

typedef struct { char p0[0xC4]; char c4[0x188]; int f24C; char p250[0x2409-0x250]; unsigned char f2409; char p240A[0x2418-0x240A]; char ip[0x255C-0x2418]; int st; char p2560[0x2584-0x2560]; int t84; int t88; int t8C; } Cell;
void func_0044B180(Cell * c) { char* arg0 = (char*)c;
    struct { char name[0x15]; char ip[0x13]; int f58; int f5C; } sl;
    int temp_a0;
    int temp_s1;

    int st = c->st;
    if (st == 7 && c->f2409 == 0) {
        func_00453FE0(arg0);
        temp_s1 = c->t88;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if ((temp_s1 == 0) || (D_00497800 < temp_a0)) {
            func_00449A00(arg0);
        }
        temp_s1 = c->t8C;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if (c->st == 7) {
            if ((temp_s1 == 0) || (D_00497800 < temp_a0)) {
                func_00449D20(arg0, 0);
                func_0044A290(arg0);
                c->t8C = Lobby_GetTime();
            }
        } else {
            if ((temp_s1 == 0) || (D_00497818 < temp_a0)) {
                func_00449D20(arg0, 0);
                c->t8C = Lobby_GetTime();
            }
        }
        temp_s1 = c->t84;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if ((temp_s1 == 0) || (D_004977E8 < temp_a0)) {
            memset((char*)&sl, 0, 0x30);
            String_Copy(sl.name, &D_004C0D38);
            strncpy(sl.ip, arg0 + 0x2418, 0x11);
            sl.f58 = 1;
            sl.f5C = 0x3E7;
            c->f24C = func_00466F50((char*)&sl, &func_004482E0);
            if (c->f24C != 0) {
                SFOLobby_SetError(arg0, 1, &D_004C0D10, 0x53F);
            }
            c->t84 = Lobby_GetTime();
        }
        func_00451B30(arg0);
        func_00453FA0(arg0, arg0 + 0xC4);
        func_0044EBD0(arg0, arg0 + 0xC4);
        func_0044D700(arg0, 0);
    }
}

