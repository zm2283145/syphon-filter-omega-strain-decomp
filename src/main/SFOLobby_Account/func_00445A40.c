extern char D_004C0B60[];
extern char* strncpy(char*, const char*, unsigned int);
extern int func_00445420(char*);
extern int func_004452F0(char*);
extern void SFOLobby_SetError(void*, int, char*, int);
extern int func_0044CA30(void*);
extern int SFOLobby_ConnectLobby(void*);
int func_00445A40(char* s, const char* a, const char* b)
{
    strncpy(s + 0x243D, a, 0x20);
    strncpy(s + 0x245D, b, 0x20);
    if (!func_00445420(s)) {
        if (*(int*)(s + 0x268) == -0x3DF) {
            func_004452F0(s);
            SFOLobby_SetError(s, 1, D_004C0B60, 0x187);
            return 0;
        } else if (*(int*)(s + 0x268) == -0x3E5) {
            if (func_004452F0(s)) {
                if (!func_00445420(s)) return 0;
            } else {
                SFOLobby_SetError(s, 1, D_004C0B60, 0x194);
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (!func_0044CA30(s)) return 0;
    if (!SFOLobby_ConnectLobby(s)) return 0;
    SFOLobby_SetError(s, 0, D_004C0B60, 0x1AB);
    return 1;
}
