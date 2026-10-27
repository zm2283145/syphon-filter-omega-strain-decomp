#include "types.h"
typedef struct Msg_002C9510 { void* vt; char pad4[0x2C]; } Msg_002C9510;
typedef struct PStr_002C9510 { unsigned char len; char s[0x80]; } PStr_002C9510;
typedef struct Self_002C9510 {
    char pad0[0x28]; unsigned char b28; char pad29[0xE]; unsigned char b37; unsigned char b38;
    char pad39[0x30C - 0x39]; int f30C;
} Self_002C9510;
typedef struct G_002C9510 { char pad[0x2409]; unsigned char b2409; } G_002C9510;
typedef struct W_002C9510 { char pad[0x278]; unsigned char b278; } W_002C9510;
extern char D_00571DC0[];
extern char D_0055A700[];
extern unsigned char D_0051EF68;
extern char g_LevelDirName[];
extern char g_Game[];
extern char D_004F2CC0[];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
extern int g_WeaponDatabase;
extern char g_Video[];
void cInterfaceManager_Refresh(void* p);
W_002C9510* GetMachine(void);
void cUSBKeybd_SetKeyMode(void* p);
G_002C9510* cDME_GetLobby(void);
void cDME_StartUpdateThread(void);
int Gui_Canvas(void);
void GuiWidget_SendMessage(int a, int b, int c, int d, int e);
char* strncpy(char* d, const char* s, int n);
void* cSystemContainer_GetSystem(void* a, void* b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cGameFrontEnd_PlayMusic(Self_002C9510* self, int v);
void cDME_StopUpdateThread(void);
void cMachine_InitFonts(W_002C9510* w);
void cGameFrontEnd_OpenZeusHog(Self_002C9510* self);
void cWeaponDB_OpenWeaponsHog(int a);
void cGameFrontEnd_LobbySendShutdownMessage(int a, int b, int c);
void XLib_NextFrame(void* p);
void cGameFrontEnd_Restore(Self_002C9510* self)
{
    if (self->b37) {
        cInterfaceManager_Refresh(D_00571DC0);
        GetMachine()->b278 = 0;
        cUSBKeybd_SetKeyMode(D_0055A700);
        switch (self->b38) {
        case 0: {
            unsigned char had = 0;
            G_002C9510* g = cDME_GetLobby();
            void* svc;
            int a;
            PStr_002C9510 buf;
            Msg_002C9510 m1;
            Msg_002C9510 m2;
            if (g) {
                had = 1;
                cDME_StartUpdateThread();
                if (D_0051EF68)
                    g->b2409 = 0;
            }
            D_0051EF68 = 0;
            a = Gui_Canvas();
            GuiWidget_SendMessage(a, Gui_Canvas(), 0x10, 5, 0);
            {
                char* d = buf.s;
                const char* s = g_LevelDirName;
                int n = 0;
                while ((*d++ = *s++) != 0) {
                    if (++n >= 0x7E) {
                        n++;
                        *d = '\n';
                        d[1] = 0;
                        break;
                    }
                }
                buf.len = n;
            }
            strncpy(g_LevelDirName, "FRONTEND", 0x80);
            svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
            cMessage_ctor_cMessageNameR(&m1, D_004F5370);
            m1.vt = D_004DE220;
            QueueMessage_cMessageR_cSystemP_int(&m1, svc, 1);
            m1.vt = D_004DE220;
            cMessage_dtor(&m1, 0);
            cMessage_ctor_cMessageNameR(&m2, D_004F5378);
            m2.vt = D_004DE200;
            QueueMessage_cMessageR_cSystemP_int(&m2, svc, 1);
            m2.vt = D_004DE200;
            cMessage_dtor(&m2, 0);
            strncpy(g_LevelDirName, buf.s, 0x80);
            {
                unsigned char o = *(unsigned char*)&self->f30C;
                self->f30C = 0xFF;
                cGameFrontEnd_PlayMusic(self, o);
            }
            if (had)
                cDME_StopUpdateThread();
            break;
        }
        case 1:
            cMachine_InitFonts(GetMachine());
            break;
        }
        cGameFrontEnd_OpenZeusHog(self);
        cWeaponDB_OpenWeaponsHog(g_WeaponDatabase);
        cGameFrontEnd_LobbySendShutdownMessage(0x2003, 0, 0);
        self->b37 = 0;
        self->b28 = 1;
        XLib_NextFrame(g_Video);
    }
}