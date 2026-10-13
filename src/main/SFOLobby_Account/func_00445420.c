extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern void SFOLobby_CallUpdateHook(void*, int, int);
extern int Lobby_GetTime(void);
extern void func_004475E0(void);
extern int func_00469260(void*, void*);
extern void SFOLobby_SetError(void*, int, char*, int);
extern int SFOLobby_Poll(void*, int, int, int);
typedef struct {
    char a[0x15];
    char b[0x11];
    char c[0x20];
    char d[0x20];
} Msg_445420;
int func_00445420(char* s)
{
    Msg_445420 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    memset(&m, 0, sizeof(m));
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    String_Copy(m.c, s + 0x243D);
    String_Copy(m.d, s + 0x245D);
    *(int*)(s + 0x18C) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_00469260(&m, func_004475E0);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 10, D_004C0B60, 0x2B0);
        return 0;
    }
    while (*(int*)(s + 0x18C) == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C)) {
            SFOLobby_SetError(s, 10, D_004C0B60, 0x2BA);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x2C1);
            return 0;
        }
    }
    return *(int*)(s + 0x268) == 0;
}
