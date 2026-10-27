extern int cDME_GetLobby(void);
extern int Iop_LoadNetModules(int a);
extern void sceSifMInitRpc(int a);
extern void NetRegisterMallocFreeCallbacks(void* a, void* b);
extern void cDME_CreateLobby(void);
extern char* cSFOini_GetKeyValue(int id);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Libc_Strcat(char* d, const char* s);
extern unsigned int strlen(const char* s);
extern char* cGameSystem_GetAgentData(void* a, int idx);
extern void Libc_Strcpy(char* d, const char* s);
extern void SFOLobby_Init(char* o, int a, void* info, char* text, int len, int flag);
extern void func_00442670(char* o, int v);
extern unsigned char Loc_GetLanguage(void);
extern void SFOLobby_SetStatsCallback(char* o, void* cb);
extern void func_002C7FC0(void* self);
extern int Sfo_Malloc();
extern int sfo_free();
extern int cGameFrontEnd_LobbyStatsCallback();

typedef struct {
    int v[10];
} Ids;

typedef struct {
    int f0;
    char name[0x80];
    char name2[0x40];
} Info;

extern unsigned char D_0048C250;
extern int D_0048C160[];
extern Ids D_0048C260;
extern char D_004ACFA0[];
extern char D_004ACFA8[];
extern int g_OnlineMissionTable[];
extern char g_Game[];
extern unsigned char D_0051EEA8;

int cGameFrontEnd_LobbyCreate(void* self)
{
    Ids ids;
    char text[0x400];
    char line[0x80];
    Info info;
    char* o;
    unsigned int i;
    int* p;
    int j;
    int len;
    char* ag;

    if (cDME_GetLobby()) {
        return 0;
    }
    if (D_0048C250) {
        if (Iop_LoadNetModules(0)) {
            D_0051EEA8 = 1;
            sceSifMInitRpc(0);
            D_0048C250 = 0;
        } else {
            return 0;
        }
    }
    NetRegisterMallocFreeCallbacks(Sfo_Malloc, sfo_free);
    cDME_CreateLobby();
    o = (char*)cDME_GetLobby();
    p = ids.v;
    ids = D_0048C260;
    text[0] = 0;
    for (i = 0; i < 10; i++, p++) {
        char* s = cSFOini_GetKeyValue(*p);
        if (s && *s) {
            sprintf(line, D_004ACFA0, *p, s);
            Libc_Strcat(text, line);
        }
    }
    len = strlen(text);
    ag = cGameSystem_GetAgentData(g_Game, -1) + 0x8DC;
    __clear((char*)&info, 0xC4);

    {
        char* s = cSFOini_GetKeyValue((int)D_004ACFA8);
        if (s) {
            Libc_Strcpy(info.name, s);
        }
    }
    Libc_Strcpy(info.name2, ag + 0x80);
    SFOLobby_Init(o, 0, &info, text, len, 1);
    {
        int* q = g_OnlineMissionTable;
        for (j = 0; j < 9; j++, q++) {
            func_00442670(o, D_0048C160[*q]);
        }
    }
    {
        int lang;
        switch (Loc_GetLanguage()) {
        case 0: lang = 1; break;
        case 1: lang = 2; break;
        case 2: lang = 8; break;
        case 3: lang = 5; break;
        case 4: lang = 7; break;
        case 5: lang = 6; break;
        case 6: lang = 3; break;
        default: lang = 1; break;
        }
        *(int*)(o + 0x26A4) = lang;
    }
    SFOLobby_SetStatsCallback(o, cGameFrontEnd_LobbyStatsCallback);
    func_002C7FC0(self);
    return 1;
}
