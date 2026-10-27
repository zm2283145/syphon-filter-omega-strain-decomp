#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"
struct Msg3D0 { void* vt; char pad4[0x2C]; };
struct PStr3D0 { unsigned char len; char s[0x80]; };
class Scr3D0 {
public:
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
};
class Stk3D0 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Push(Scr3D0* s, int f);
    char p4[0x4D];
    unsigned char b51;
    char p52[0x16];
    int x68;
};
struct Slot3D0 {
    char pad[0x1F0];
    float v[4];
    char pad200[0x2F5 - 0x200];
    char f2F5;
    char f2F6;
};
struct Self3D0 {
    char p0[0x20];
    long long x20;
    unsigned char b28;
    char p29[3];
    unsigned char b2C;
    char p2D[3];
    unsigned char b30;
    char p31;
    unsigned char b32;
    char p33[2];
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    char p38[0x258 - 0x38];
    Scr3D0* p258;
    char p25C[0x30C - 0x25C];
    int x30C;
};
struct W3D0 { char pad[0x278]; unsigned char b278; };
extern "C" {
extern char D_004ACFE8[];
extern char D_004ACFF8[];
extern char D_004AD1F8[];
extern char D_004AD000[];
extern char D_004AD010[];
extern char D_004AD020[];
extern char D_004AD038[];
extern char g_Video[];
extern int D_00538C60;
extern float D_00539170[4];
extern char g_LevelDirName[];
extern char D_004ACF48[];
extern char g_Game[];
extern char D_004F2CC0[];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
extern int g_WeaponDatabase;
extern char D_0055A700[];
void cGameFrontEnd_Restore(Self3D0* self);
void FrontEnd_CreateCanvas(Self3D0* self, unsigned char flag);
Stk3D0* Gui_Canvas(void);
int Gui_Manager(void);
void GuiCanvas_Activate(Stk3D0* s, int x);
Scr3D0* GuiManager_ConstructGui(int l, char* a, char* b);
Scr3D0* GuiManager_OpenGui(int l, char* a, char* b);
int cDME_GetLobby(void);
void SFOLobby_InitLists(int g);
void cDME_StartUpdateThread(void);
long long cTimer_GetMillisecondTime(void);
void FrontEnd_SetLoadingScreen(Self3D0* self, int a, int b, int c);
char* strncpy(char* d, const char* s, int n);
void* cSystemContainer_GetSystem(void* a, void* b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void GuiWidget_SendMessage(Stk3D0* a, Stk3D0* b, int c, int d, int e);
void FrontEnd_GetCharacterData(Self3D0* self);
void cGameFrontEnd_OpenZeusHog(Self3D0* self);
void cWeaponDB_OpenWeaponsHog(int a);
void cDME_StopUpdateThread(void);
void func_002CA6F0(Self3D0* self);
void cDME_ActivateLobby(int a);
void FrontEnd_FlushMessages(Self3D0* self);
void SFOLobby_Reset(int g, int a);
W3D0* GetMachine(void);
void cUSBKeybd_SetKeyMode(void* p);
}
extern "C" void cGameFrontEnd_InitGui(Self3D0* self, unsigned char flag)
{
    Scr3D0* scr;
    if (self->b28) return;
    if (self->b37) {
        cGameFrontEnd_Restore(self);
        return;
    }
    FrontEnd_CreateCanvas(self, flag);
    { Stk3D0* st = Gui_Canvas(); st->b51 = !flag; }
    GuiCanvas_Activate(Gui_Canvas(), 0);
    GuiCanvas_Activate(Gui_Canvas(), 1);
    Gui_Canvas()->x68 = 0;
    if (!flag) Gui_Canvas()->x68 |= 0xF000;
    scr = GuiManager_ConstructGui(Gui_Manager(), D_004ACFE8, D_004ACFF8);
    scr = (scr && scr->IsA(D_004AD1F8)) ? scr : 0;
    self->p258 = scr;
    if (!flag) {
        unsigned char had;
        unsigned char go;
        Scr3D0* next;
        void* svc;
        PStr3D0 buf;
        Msg3D0 m1;
        Msg3D0 m2;
        {
            Slot3D0* s = (Slot3D0*)(g_Video + D_00538C60 * 0x110);
            float* v = D_00539170;
            s->v[0] = v[0];
            s->v[1] = v[1];
            s->v[2] = v[2];
            s->v[3] = v[3];
            s->f2F5 = 1;
            s->f2F6 = 1;
        }
        had = 0;
        if (cDME_GetLobby()) {
            SFOLobby_InitLists(cDME_GetLobby());
            cDME_StartUpdateThread();
            had = 1;
        }
        self->x20 = cTimer_GetMillisecondTime();
        go = 0;
        FrontEnd_SetLoadingScreen(self, 1, 0, 0);
        self->x30C = -1;
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
        strncpy(g_LevelDirName, D_004ACF48, 0x80);
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
            Stk3D0* a = Gui_Canvas();
            GuiWidget_SendMessage(a, Gui_Canvas(), 0x10, 5, 0);
        }
        if (self->b2C) {
            GuiManager_OpenGui(Gui_Manager(), D_004AD000, D_004AD010);
            GuiManager_OpenGui(Gui_Manager(), D_004AD020, D_004AD038);
            FrontEnd_GetCharacterData(self);
        }
        if (self->b35) {
            self->b35 = 0;
            next = GuiManager_OpenGui(Gui_Manager(), D_004AD020, D_004AD038);
            if (self->b30 && !self->b32) go = 1;
        } else {
            next = GuiManager_OpenGui(Gui_Manager(), D_004AD000, D_004AD010);
        }
        cGameFrontEnd_OpenZeusHog(self);
        cWeaponDB_OpenWeaponsHog(g_WeaponDatabase);
        FrontEnd_SetLoadingScreen(self, 0, 0, 0);
        if (had) cDME_StopUpdateThread();
        Gui_Canvas()->Push(next, 0);
        if (go && !cDME_GetLobby()) {
            func_002CA6F0(self);
            cDME_ActivateLobby(1);
            if (cDME_GetLobby()) {
                FrontEnd_FlushMessages(self);
                SFOLobby_Reset(cDME_GetLobby(), 1);
                cDME_ActivateLobby(0);
            }
        }
    }
    GetMachine()->b278 = flag;
    if (!flag) cUSBKeybd_SetKeyMode(D_0055A700);
    self->b28 = 1;
    self->b36 = flag;
}
