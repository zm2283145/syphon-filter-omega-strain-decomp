extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern void SFOLobby_CallUpdateHook(void*, int, int);
extern int Lobby_GetTime(void);
extern int func_00476998(void);
extern void func_004472C0(void);
extern int func_0046AB38(void*, void*);
extern void SFOLobby_SetError(void*, int, char*, int);
extern int SFOLobby_Poll(void*, int, int, int);
typedef struct {
    char a[0x15];
    char b[0x11];
    int t;
} Msg_445570;
int func_00445570(char* s)
{
    Msg_445570 m;
    SFOLobby_CallUpdateHook(s, 2, 6);
    memset(&m, 0, sizeof(m));
    memset(s + 0x5A4, 0, 0x40C);
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    m.t = func_00476998();
    *(int*)(s + 0x1BC) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_0046AB38(&m, func_004472C0);
    while (*(signed char*)(s + 0x9AC) != 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C) != 0) {
            SFOLobby_SetError(s, 0x29, D_004C0B60, 0x273);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x27A);
            return 0;
        }
    }
    SFOLobby_SetError(s, 0, D_004C0B60, 0x27E);
    return 1;
}

