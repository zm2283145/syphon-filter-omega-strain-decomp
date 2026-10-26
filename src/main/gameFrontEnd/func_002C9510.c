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
W_002C9510* App_GetInstance(void);
void cUSBKeybd_SetKeyMode(void* p);
G_002C9510* DME_GetLobby(void);
void DME_StartThread(void);
int Gui_GetScreenStack(void);
void GuiWidget_SendEvent(int a, int b, int c, int d, int e);
char* strncpy(char* d, const char* s, int n);
void* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void FrontEnd_SetMusic(Self_002C9510* self, int v);
void DME_StopThread(void);
void Boot_LoadFonts(W_002C9510* w);
void FrontEnd_LoadZeusHog(Self_002C9510* self);
void WeaponDb_LoadWpnHog(int a);
void App_Broadcast(int a, int b, int c);
void Video_BeginFrame(void* p);
void FrontEnd_ResumeGui(Self_002C9510* self)
{
    if (self->b37) {
        cInterfaceManager_Refresh(D_00571DC0);
        App_GetInstance()->b278 = 0;
        cUSBKeybd_SetKeyMode(D_0055A700);
        switch (self->b38) {
        case 0: {
            unsigned char had = 0;
            G_002C9510* g = DME_GetLobby();
            void* svc;
            int a;
            PStr_002C9510 buf;
            Msg_002C9510 m1;
            Msg_002C9510 m2;
            if (g) {
                had = 1;
                DME_StartThread();
                if (D_0051EF68)
                    g->b2409 = 0;
            }
            D_0051EF68 = 0;
            a = Gui_GetScreenStack();
            GuiWidget_SendEvent(a, Gui_GetScreenStack(), 0x10, 5, 0);
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
            svc = Service_Lookup(g_Game, D_004F2CC0);
            Event_Construct(&m1, D_004F5370);
            m1.vt = D_004DE220;
            Event_Send(&m1, svc, 1);
            m1.vt = D_004DE220;
            cMessage_dtor(&m1, 0);
            Event_Construct(&m2, D_004F5378);
            m2.vt = D_004DE200;
            Event_Send(&m2, svc, 1);
            m2.vt = D_004DE200;
            cMessage_dtor(&m2, 0);
            strncpy(g_LevelDirName, buf.s, 0x80);
            {
                unsigned char o = *(unsigned char*)&self->f30C;
                self->f30C = 0xFF;
                FrontEnd_SetMusic(self, o);
            }
            if (had)
                DME_StopThread();
            break;
        }
        case 1:
            Boot_LoadFonts(App_GetInstance());
            break;
        }
        FrontEnd_LoadZeusHog(self);
        WeaponDb_LoadWpnHog(g_WeaponDatabase);
        App_Broadcast(0x2003, 0, 0);
        self->b37 = 0;
        self->b28 = 1;
        Video_BeginFrame(g_Video);
    }
}