extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern void SFOLobby_CallUpdateHook(void*, int, int);
extern int Lobby_GetTime(void);
extern void func_004474C0(void);
extern int func_00469318(void*, void*);
extern void SFOLobby_SetError(void*, int, char*, int);
extern int SFOLobby_Poll(void*, int, int, int);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_4452F0;
int func_004452F0(char* s)
{
    Msg_4452F0 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    memset(&m, 0, sizeof(m));
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    *(int*)(s + 0x190) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_00469318(&m, func_004474C0);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 9, D_004C0B60, 0x2F9);
        return 0;
    }
    while (*(int*)(s + 0x190) == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C)) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x303);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x30A);
            return 0;
        }
    }
    return *(int*)(s + 0x34C) == 0;
}
