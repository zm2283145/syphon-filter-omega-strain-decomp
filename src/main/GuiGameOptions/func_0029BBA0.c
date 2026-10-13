#include "types.h"
typedef struct { void* vt; char pad[0x20]; int id; int arg; char pad2c[4]; } Msg_BBA0;
typedef struct { char pad[0x90]; } Name_BBA0;
int Event_Construct(Msg_BBA0*, void*);
int Stream_ReadU32(int*);
int cMessage_dtor(Msg_BBA0*, int);
void* func_0029BDA0(void*);
void* func_0029BD70(void*);
int func_0012F2E0(void*);
char* Loc_LookupText(char*);
void Game_EndLevel(void*, int);
void GameOptions_QueueDialog(int, char*, char*);
void func_0012F2D0(Name_BBA0*);
void func_002C9170(Name_BBA0*, int, int);
char* func_0012F2A0(Name_BBA0*);
int sprintf(char*, const char*, ...);
extern char D_00506440[];
extern char D_004DD5E0[];
extern char D_004DCF10[];
extern char D_004FFB50[];
extern char D_004AA960[];
extern char D_004AA970[];

void func_0029BBA0(void) {
    Msg_BBA0 m;
    Name_BBA0 nm;
    char buf[0x80];
    char* fmt;
    Event_Construct(&m, D_00506440);
    m.vt = D_004DD5E0;
    Stream_ReadU32(&m.id);
    Stream_ReadU32(&m.arg);
    if (func_0029BDA0(D_004FFB50) && func_0029BD70(func_0029BDA0(D_004FFB50))
        && m.arg == func_0012F2E0(func_0029BD70(func_0029BDA0(D_004FFB50)))) {
        fmt = Loc_LookupText(D_004AA960);
        if (!fmt) {
            Game_EndLevel(D_004FFB50, 2);
            GameOptions_QueueDialog(1, D_004AA970, 0);
        } else {
            func_0012F2D0(&nm);
            func_002C9170(&nm, m.id, 0);
            sprintf(buf, fmt, func_0012F2A0(&nm));
            Game_EndLevel(D_004FFB50, 2);
            GameOptions_QueueDialog(1, D_004AA970, buf);
        }
    }
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}