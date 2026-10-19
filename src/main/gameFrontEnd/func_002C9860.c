
extern void* Service_Lookup(void* a, void* b);
extern void WeaponDb_UnloadWpnHog(int);
extern char* App_GetInstance(void);
extern void SoundMgr_UnloadLevel(void*);
extern void func_002C9C80(void*, int);
extern void FrontEnd_UnloadZeusHog(void*);
extern void func_003D1700(void*);
extern unsigned char* DME_GetLobby(void);
extern char* strncpy(char*, const char*, int);
extern char D_004ACF48[];
extern char D_004F2CC0[];
extern char g_Game[];
extern char g_LevelDirName[];
extern int g_WeaponDatabase;
extern unsigned char D_0051EF68;
extern char D_0055A700[];

typedef struct {
    char pad0[0x28];
    unsigned char f28;
    char pad29[0xE];
    unsigned char f37;
    unsigned char f38;
} Obj9860;

typedef struct {
    signed char len;
    char text[0x80];
} PStr;

static inline void Copy(PStr* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = buf->text;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

void FrontEnd_SuspendGui(Obj9860* self, unsigned char mode)
{
    if (self->f37 == 0) {
        { char* q = App_GetInstance(); q[0x278] = 1; }
        func_003D1700(D_0055A700);
        switch (mode) {
        case 0: {
            void* svc;
            D_0051EF68 = 0;
            svc = Service_Lookup(g_Game, D_004F2CC0);
            if (svc) {
                PStr save;
                unsigned char* g;
                Copy(&save, g_LevelDirName);
                strncpy(g_LevelDirName, D_004ACF48, 0x80);
                SoundMgr_UnloadLevel(svc);
                strncpy(g_LevelDirName, save.text, 0x80);
                g = DME_GetLobby();
                if (g && g[0x2409] == 0) {
                    D_0051EF68 = 1;
                    g[0x2409] = 1;
                }
            }
            break;
        }
        case 1:
            break;
        }

        FrontEnd_UnloadZeusHog(self);
        WeaponDb_UnloadWpnHog(g_WeaponDatabase);
        func_002C9C80(self, 1);
        self->f37 = 1;
        self->f28 = 0;
        self->f38 = mode;
    }
}

