extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern void SFOLobby_CallUpdateHook(void*, int, int);
extern int Lobby_GetTime(void);
extern void func_00447470(void);
extern int func_004690A0(void*, void*);
extern void SFOLobby_SetError(void*, int, char*, int);
extern int SFOLobby_Poll(void*, int, int, int);
extern int func_0044C9D0(void*);
extern void func_004537D0(void*);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_445850;
int func_00445850(char* s)
{
    Msg_445850 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    if (*(int*)(s + 0x1A4) == 1) {
        memset(&m, 0, sizeof(m));
        String_Copy(m.a, D_004C0B50);
        String_Copy(m.b, s + 0x2418);
        *(int*)(s + 0x2410) = Lobby_GetTime();
        *(int*)(s + 0x24C) = func_004690A0(&m, func_00447470);
        if (*(int*)(s + 0x24C) != 0) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x1E8);
            return 0;
        }
        while (*(int*)(s + 0x1A8) == 0) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
                SFOLobby_SetError(s, 2, D_004C0B60, 0x1F2);
                return 0;
            }
        }
        if (*(int*)(s + 0x398) != 0) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x1FE);
            return 0;
        }
    }
    if (!func_0044C9D0(s)) return 0;
    func_004537D0(s);
    SFOLobby_SetError(s, 0, D_004C0B60, 0x208);
    return 1;
}
