#pragma cplusplus on
#include "types.h"
typedef unsigned long long U64;
typedef unsigned int u32;

struct cJoystick { char pad[0x14C]; u32 buttons; };
struct FrontEnd { char pad[0x30]; unsigned char multi; char p31; unsigned char x32; unsigned char x33; unsigned char x34; unsigned char done; char p36[3]; char name[1]; };
struct VObj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Render();                          /* 0x5C */
    virtual void NextFrame(float);                  /* 0x60 */
    virtual void AddWidget(void*, int);             /* 0x64 */
    virtual void RemoveWidget(void*);               /* 0x68 */
    virtual void v1B(); virtual void v1C();
    virtual void SetState(int);                     /* 0x74 */
};
struct cSKM_GOBJ { char pad[0x2C3B]; signed char loading; };
struct Player { char pad[0x30]; cSKM_GOBJ* man; };
struct cScene { char pad[8]; void* activation; };
struct Fader { int pad; float level; };
struct Opts { char pad[0x1C]; float scale; };
struct EOLFlags { unsigned char quitLevel; unsigned char skipStats; unsigned char skipEOL; unsigned char restartLevel; };
struct Msg { void* vt; char pad[0x2C]; };
struct tServer { char pad[0x10]; int port; char pad14[0xC]; };
struct cString { char pad[0x10]; };
struct tRECT { float x0, y0, x1, y1; };
struct Viewport { tRECT win; char pad10[0xF0 - 0x10]; int ominz; int pminz; float omaxz; float pmaxz; float fov; unsigned char isOrtho; unsigned char isOnScreen; unsigned char isDirty; char pad107[0x110 - 0x107]; };
struct XLibT { char pad[0x1F0]; Viewport vp[8]; char padA70[0xA80 - 0xA70]; __int128 view[16][4]; };
struct cMachine {
    char pad0[0x2C];
    char mConsole[0x250 - 0x2C];
    unsigned char mVideoMode;   /* 0x250 */
    int mScrResX;               /* 0x254 */
    int mScrResY;               /* 0x258 */
    float mTimeStep;            /* 0x25C */
    int mFrameRateCap;          /* 0x260 */
    char pad264[0x278 - 0x264];
    unsigned char mKeyboardHandlerEnabled; /* 0x278 */
};

extern "C" {
extern cJoystick D_0055A300;
extern signed char g_GameState;
extern signed char g_PrevGameState;
extern unsigned char g_IsMultiplayer;
extern signed char g_LoadoutPending;
extern Player* g_LocalPlayer;
extern void* g_Hud;
extern Fader* g_Fader;
extern char g_Game[];
extern XLibT g_Video;
extern Opts* g_OptionsRecord;
extern long g_TickCounter64;
extern int g_TimerAccum;
extern FrontEnd* D_004FFC04;
extern int D_004FFC00;
extern unsigned char D_004FFBB7;
extern unsigned char D_004FFBB2;
extern int D_0048A018;
extern unsigned char D_0048A008;
extern unsigned char D_0048A020;
extern int D_0048A028;
extern int D_005383D4;
extern int D_005383C0;
extern const float D_004C1FC8[];
extern unsigned char D_004EE480;
extern int D_004EE470;
extern U64 D_004EE478;
extern unsigned char D_004EE488;
extern unsigned char D_004EE490;
extern unsigned char D_005721B8;
extern unsigned char D_005721C0;
extern unsigned char D_005723B0;
extern unsigned char D_005723B8;
extern int D_005723F0;
extern unsigned char D_00572400;
extern int D_00533CA0;
extern char D_00533CB0[];
extern char D_004FFB8C[];
extern EOLFlags D_004FFD14;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern tRECT D_00539170;
extern char D_004F2CC0[];
extern char D_005436B0[];
extern char D_004F5380[];
extern char D_00555070[];
extern U64 D_004BC1B0;
extern U64 D_005392D8;
extern char D_004D97F0[];
extern char D_004D9160[];
extern char D_004DADD0[];
extern char D_0049C458[], D_0049C460[], D_0049C468[], D_0049C470[], D_0049C488[], D_0049C490[], D_0049C4A8[];
extern char D_0049C4B8[], D_0049C4C8[], D_0049C4D8[], D_0049C4E8[];

void cJoystick_Poll(cJoystick*);
void cJoystick_Debounce(cJoystick*);
void nGobjManager_PurgeRemovals(void);
void nCallback_Process(int, int);
void cMachine_KeyboardHandler(cMachine*);
void* GetFileStreamMan(void);
int cFileStreamMan_Process(void*);
void cPauseMusicMsg_ctor(Msg*, int);
}
struct cPauseMusicMsg;
static inline Msg* cPauseMusicMsg_ctor2(cPauseMusicMsg* m, int on) { cPauseMusicMsg_ctor((Msg*)m, on); return (Msg*)m; }
extern "C" {
void QueueMessage_cMessageR_cSystemP_int(Msg*, void*, int);
void cMessage_dtor(Msg*, int);
void cMessage_ctor_cMessageNameR(Msg*, void*);
void App_BindIopRpc(cMachine*);
void XLib_Init(XLibT*, int, int, int, int, int, int, int);
void cMachine_InitFonts(cMachine*);
void FrontEnd_CreateCanvas(FrontEnd*, int);
void FrontEnd_SetLoadingScreen(FrontEnd*, int, int, int);
void func_002C7C40(char*, int);
int func_002C7CB0(FrontEnd*);
void cGameSystem_InitFrontEnd(void*);
void cGameSystem_UpdateFrontEnd(void*);
int cGameSystem_FrontEndRunning(void*);
void Renderer_Teardown(XLibT*);
void cGameSystem_ShutdownFrontEnd(void*);
void cGameFrontEnd_LobbyUpdate(FrontEnd*);
int String_CompareNoCase(const char*, const char*);
void cGameFrontEnd_BuildFinalMovie(FrontEnd*);
void cGameFrontEnd_Suspend(FrontEnd*, int);
void cGameSystem_PlayMovie_void(void*);
void cGameSystem_EndMovie(void*);
void cGameSystem_UpdateMovie(void*);
void cHogList_CloseAll(void*);
U64 cMemBin_GetTotalFreeMem(void*);
void cMemMan_Init_int_uint_uint(int, u32, u32);
cMachine* GetMachine(void);
void cMachine_NetInit(cMachine*);
void cMachine_NetUpdate(cMachine*);
void cMan_CheckLoading(void*);
void cMachine_UnloadLoadingScreen(cMachine*);
VObj* Gui_Manager(void);
VObj* Gui_Canvas(void);
void* GuiManager_OpenGui(VObj*, const char*, const char*);
void* GuiManager_FindOpenGui(VObj*, const char*);
void GuiManager_DestroyWidget(VObj*, void*, int);
void GuiManager_NextFrame(VObj*, float);
void GuiCanvas_ProcessInput_void(VObj*);
void XLib_NextFrame(XLibT*);
float _f_ulltof(U64);
void DequeueMessages(void);
void cMotionManager_NextFrame(float);
void* cSystemContainer_GetSystem(void*, void*);
void cHeadSet_NextFrame(int);
int cGameFrontEnd_PopMessageBox(FrontEnd*, int);
int cDME_Quit(void);
char* cDME_GetQuitTitle(void);
char* cDME_GetQuitMessage(void);
char* nGlobalization_GetString_charP(const char*);
void cGameFrontEnd_PushMessageBox(FrontEnd*, int, const char*, const char*, VObj*, int);
void cGameFrontEnd_LobbyDestroy(FrontEnd*, int);
void std_basic_string_char_char_traits_char_ctor_charP(cString*, const char*);
const char* std_basic_string_char_char_traits_char_c_str(cString*);
void String_Dtor(cString*, int);
void* GetSceneManager(void);
cScene* cSceneManager_GetSceneBelongingTo(void*, cSKM_GOBJ*);
int nActivation_IsActivationLoaded(void*);
void cHud_LoadScopes(void*);
void cScreenFader_StartFade(Fader*, float, int);
void cScriptInterpreter_StartLevel(void*);
void Game_ClearOtherAgentsB70(void*);
void cBackpack_SaveCratesInfo(void);
void cMachine_ChooseNetworkServer(cMachine*);
void cMachine_InitDME(void);
char* cSFOini_GetKeyValue(const char*);
int atoi(const char*);
void cDME_ConnectToGame(int);
void cMachine_CreateNetworkLobbyScreen(cMachine*);
void cDME_CreateServerList(void);
int cDME_GetServerFromList(tServer*);
void Net_RetryConnect(tServer*);
void cMachine_UpdateNetworkLobbyScreen(cMachine*, int, int);
void cMachine_DestroyNetworkLobbyScreen(cMachine*);
void cNetObj_NextFrame(void);
int cGameSystem_AllAgentDataReceived(void*);
void cGameSystem_Render(void*);
void* GetTextSystem(void);
void cTextSystem_Render(void*);
void cMachine_CalcFrameTime(cMachine*, int);
void cConsole_Deactivate(void*);
void cGameSystem_Reset(void*);
void DELETE_DELAYS(void);
void cMemMan_ReleaseBin(int);
}

enum eGS { GS_0 = 0, GS_FF = 0xFF };
#define STATE ((unsigned char)g_GameState)
static inline void SetGameState(int s) { g_PrevGameState = g_GameState; g_GameState = s; }
static inline int DivTime(void)
{
    int bit;
    long d;
    int q;
    int i;
    long n;
    int sh;
    int c = (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
    n = g_TickCounter64;
    n += c;
    sh = 30;
    d = 100;
    bit = 1 << sh;
    d <<= sh;
    q = 0;
    sh++;
    #pragma opt_rotateloops off
    for (i = 0; i < sh; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}
static inline U64 GetTicks(void) { return g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f); }
static inline void InitVideo(cMachine* self, int flags, int a, int b, int c)
{
    XLib_Init(&g_Video, self->mScrResX, self->mScrResY, 0x20, a, flags, b, c);
}
static inline void SetFontScale(void) { D_005383C0 = (unsigned char)(int)(D_004C1FC8[0] * g_OptionsRecord->scale); }

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vt; char pad[0x2C];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR((Msg*)this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor((Msg*)this, 0); }
};
struct cGameSoundMsg : MsgB {
    cGameSoundMsg() : MsgB(D_005436B0) { vt = D_004D9160; }
    __declspec(weak) __declspec(MSG_DTOR) ~cGameSoundMsg() { vt = D_004D9160; }
};
struct cPauseMusicMsg : MsgB {
    cPauseMusicMsg() {}
    __declspec(weak) __declspec(MSG_DTOR) ~cPauseMusicMsg() { vt = D_004D97F0; }
};
struct cStartLevelMsg : MsgB {
    cStartLevelMsg() : MsgB(D_004F5380) { vt = D_004DADD0; }
    __declspec(weak) __declspec(MSG_DTOR) ~cStartLevelMsg() { vt = D_004DADD0; }
};

static inline void ResetViewportA(void) { int i = D_00538C60; const tRECT& r = D_00539170; int j = i; Viewport* v = &g_Video.vp[j]; v->win = r; v->isOnScreen = 1; v->isDirty = 1; }
static inline void ResetViewport(void)
{
    const tRECT& r = D_00539170; Viewport* v = &g_Video.vp[D_00538C60]; v->win = r;
    v->isOnScreen = 1;
    v->isDirty = 1;
}
static inline bool TestAndClear(unsigned char& f) { if (f) { f = 0; return true; } return false; }
static inline unsigned char B3() { if (g_IsMultiplayer) return D_005721C0; return 1; }
static inline unsigned short B4() { if (g_IsMultiplayer) return D_005721C0; return 1; }
static inline int B5() { if (g_IsMultiplayer) return D_005721C0; return 1; }
static inline unsigned char B6() { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline bool B1() { if (g_IsMultiplayer) return D_005721C0; return true; }
static inline bool B2() { return g_IsMultiplayer ? D_005721C0 : true; }
static inline unsigned short R1() { if (D_005723B0 == 1) return 0x668; return 0x667; }
static inline unsigned short R2() { return D_005723B0 == 1 ? 0x668 : 0x667; }
static inline int R3() { if (D_005723B0 == 1) return 0x668; return 0x667; }
static inline unsigned short R4() { unsigned short r; if (D_005723B0 == 1) r = 0x668; else r = 0x667; return r; }
static inline void PushQ(FrontEnd* fe, char* title, char* msg, int resetID) { cGameFrontEnd_PushMessageBox(fe, 2, title, msg, Gui_Canvas(), resetID); }
static inline FrontEnd* FE() { return D_004FFC04; }
static inline void PQP(char* title, int resetID, char* msg, FrontEnd* fe) { cGameFrontEnd_PushMessageBox(fe, 2, title, msg, Gui_Canvas(), resetID); }
static inline void QuitBoxA(void)
{
    char* title; int resetID; title = ((char*(*)())cDME_GetQuitTitle)() ? ((char*(*)())cDME_GetQuitTitle)() : nGlobalization_GetString_charP(D_0049C4B8); resetID = R1(); PQP(title, resetID, ((char*(*)())cDME_GetQuitMessage)(), D_004FFC04);
}

static inline void QuitBoxB(void)
{
    char* title; int resetID; FrontEnd* fe; char* msg; title = ((char*(*)())cDME_GetQuitTitle)() ? ((char*(*)())cDME_GetQuitTitle)() : nGlobalization_GetString_charP(D_0049C4B8); resetID = R1(); fe = D_004FFC04; msg = ((char*(*)())cDME_GetQuitMessage)(); cGameFrontEnd_PushMessageBox(fe, 2, title, msg, Gui_Canvas(), resetID);
}

extern "C" int cMachine_NextFrame(cMachine* self)
{
    int currentTime;
    int step;

    cJoystick_Poll(&D_0055A300);
    nGobjManager_PurgeRemovals();
    currentTime = DivTime();
    if (D_0048A018 == -1) D_0048A018 = currentTime;
    step = currentTime - D_0048A018;
    step = (0 > step) ? 0 : step;
    nCallback_Process(step, D_004FFBB7 ? 0 : step);
    D_0048A018 = currentTime;
    nGobjManager_PurgeRemovals();
    if (self->mKeyboardHandlerEnabled) cMachine_KeyboardHandler(self);
    {
        int streamProcessCnt = cFileStreamMan_Process(GetFileStreamMan());
        if (streamProcessCnt > 40) {
            QueueMessage_cMessageR_cSystemP_int(cPauseMusicMsg_ctor2(&cPauseMusicMsg(), 1), g_Game, 1);
        } else if (streamProcessCnt == 0) {
            QueueMessage_cMessageR_cSystemP_int(cPauseMusicMsg_ctor2(&cPauseMusicMsg(), 0), g_Game, 1);
        }
    }
    if (STATE == 1) {
        App_BindIopRpc(self);
        InitVideo(self, self->mVideoMode, 0x10, 0xFA0, 0x1F4);
        D_005383D4 = self->mFrameRateCap;
        SetFontScale();
        cMachine_InitFonts(self);
        if (D_004FFBB2) {
            FrontEnd_CreateCanvas(D_004FFC04, 0);
            FrontEnd_SetLoadingScreen(D_004FFC04, 1, 0, 0);
        } else {
            func_002C7C40(D_0049C458, 3000);
        }
        cGameSystem_InitFrontEnd(g_Game);
        SetGameState(2);
    }
    if (STATE == 2) {
        cGameSystem_UpdateFrontEnd(g_Game);
        if (!cGameSystem_FrontEndRunning(g_Game)) {
            Renderer_Teardown(&g_Video);
            SetGameState(11);
        }
    }
    if (STATE == 3) {
        cGameSystem_ShutdownFrontEnd(g_Game);
        if (D_004FFC04->done) {
            if (D_004FFC04->multi) {
                g_IsMultiplayer = 1;
                if (D_004FFC04->x32 && !D_004FFC04->x33) {
                    D_0048A008 = 1;
                    SetGameState(5);
                } else {
                    SetGameState(14);
                }
            } else {
                if (D_004FFC04->x34) SetGameState(14);
                else SetGameState(11);
                g_IsMultiplayer = 0;
                D_005721B8 = 0;
            }
        }
    } else {
        cGameFrontEnd_LobbyUpdate(D_004FFC04);
    }
    if (STATE == 4) {
        if (!String_CompareNoCase(D_004FFC04->name, D_0049C460)) {
            SetGameState(7);
        } else {
            if (!String_CompareNoCase(D_004FFC04->name, D_0049C468)) cGameFrontEnd_BuildFinalMovie(D_004FFC04);
            SetGameState(8);
        }
        cGameFrontEnd_Suspend(D_004FFC04, 0);
    }
    {
        if (STATE == 9 || STATE == 10 || STATE == 11 || STATE == 12 || STATE == 8 || STATE == 7) {
            u32 movieXInitFlags;
            if (STATE == 9) {
                while (!func_002C7CB0(D_004FFC04)) ;
                FrontEnd_SetLoadingScreen(D_004FFC04, 0, 0, 0);
            }
            movieXInitFlags = self->mVideoMode | 8;
            if (!(self->mVideoMode & 4)) movieXInitFlags |= 1;
            InitVideo(self, movieXInitFlags, 0, -1, -1);
            D_005383D4 = self->mFrameRateCap;
            SetFontScale();
            cMachine_InitFonts(self);
            {
                cJoystick& js = D_0055A300;
                D_004EE480 = (js.buttons & 0x40) == 0;
            }
            cGameSystem_PlayMovie_void(g_Game);
            SetGameState(13);
        }
    }
    if (STATE == 13) {
        if (D_004FFC00) {
            cJoystick& js = D_0055A300;
            if (!D_004EE480) {
                D_004EE480 = (js.buttons & 0x40) == 0;
            } else if (js.buttons & 0x40) {
                cGameSystem_EndMovie(g_Game);
                cJoystick_Debounce(&js);
            }
        }
        cGameSystem_UpdateMovie(g_Game);
        if (!D_004FFC00) {
            switch ((unsigned char)g_PrevGameState - 7) { /* states 7..12 */
            case 0:
            case 1:
            case 2:
                SetGameState(1);
                break;
            case 4:
                SetGameState(14);
                break;
            case 5:
                SetGameState(1);
                break;
            case 3:
                SetGameState(2);
                break;
            default:
                SetGameState(14);
                break;
            }
            Renderer_Teardown(&g_Video);
        }
    }
    if (STATE == 14) {
        App_BindIopRpc(self);
        cHogList_CloseAll(D_004FFB8C);
        Renderer_Teardown(&g_Video);
        InitVideo(self, self->mVideoMode, 0x10, 0x157C, -1);
        D_005383D4 = self->mFrameRateCap;
        cMemMan_Init_int_uint_uint(3, cMemBin_GetTotalFreeMem(D_00533CB0) - 0x1000, 0x10); { Opts* o = g_OptionsRecord; D_00533CA0 = 3; D_005383C0 = (unsigned char)(int)(D_004C1FC8[0] * o->scale); }
        cMachine_InitFonts(self);
        cMachine_NetInit(GetMachine());
        SetGameState(18);
        D_004EE470 = 1;
    }
    cMachine_NetUpdate(self);
    if (STATE == 18) {
        cSKM_GOBJ* man = g_LocalPlayer->man;
        if (man) {
            if (D_004EE470 && man->loading) {
                cMan_CheckLoading((char*)man + 0x60);
                if (!man->loading) {
                    void* gui;
                    cMachine_UnloadLoadingScreen(self);
                    D_004EE470 = 0;
                    g_LoadoutPending = 1;
                    D_004EE478 = 0;
                    cJoystick_Poll(&D_0055A300);
                    if (g_IsMultiplayer) {
                        gui = GuiManager_OpenGui(Gui_Manager(), D_0049C470, D_0049C488);
                    } else {
                        gui = GuiManager_OpenGui(Gui_Manager(), D_0049C490, D_0049C4A8);
                    }
                    Gui_Canvas()->AddWidget(gui, 0);
                }
            } else if ((unsigned char)g_LoadoutPending == 1) {
                U64 time;
                float fstep;
                XLib_NextFrame(&g_Video);
                ResetViewportA();
                time = GetTicks();
                fstep = _f_ulltof(time - D_004EE478) / 100000.0f;
                DequeueMessages();
                nGobjManager_PurgeRemovals();
                cMotionManager_NextFrame(fstep);
                GuiManager_NextFrame(Gui_Manager(), fstep);
                GuiCanvas_ProcessInput_void(Gui_Canvas());
                Gui_Canvas()->NextFrame(fstep);
                {
                    void* gameSound = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
                    QueueMessage_cMessageR_cSystemP_int((Msg*)&cGameSoundMsg(), gameSound, 1);
                }
                if (g_IsMultiplayer) {
                    cHeadSet_NextFrame(0);
                    if (D_00572400) {
                        void* gui;
                        g_LoadoutPending = 0;
                        gui = GuiManager_FindOpenGui(Gui_Manager(), D_0049C470);
                        if (gui) {
                            Gui_Canvas()->RemoveWidget(gui);
                            GuiManager_DestroyWidget(Gui_Manager(), gui, 1);
                        }
                        gui = GuiManager_FindOpenGui(Gui_Manager(), D_0049C490);
                        if (gui) Gui_Canvas()->RemoveWidget(gui);
                        while (cGameFrontEnd_PopMessageBox(D_004FFC04, -1)) ;
                        ((VObj*)g_LocalPlayer->man)->SetState(4);
                    }
                    if (((int(*)())cDME_Quit)()) QuitBoxA();
                    if (TestAndClear(D_005723B8)) {
                        cGameFrontEnd_LobbyDestroy(D_004FFC04, 0);
                        if (B3()) {
                            cString title;
                            cString message;
                            std_basic_string_char_char_traits_char_ctor_charP(&title, nGlobalization_GetString_charP(D_0049C4C8));
                            std_basic_string_char_char_traits_char_ctor_charP(&message, nGlobalization_GetString_charP(D_0049C4D8));
                            {
                                const char* m = std_basic_string_char_char_traits_char_c_str(&message);
                                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&title), m, 0, 0);
                            }
                            String_Dtor(&message, 0);
                            String_Dtor(&title, 0);
                        }
                    }
                }
                Gui_Canvas()->Render();
                D_004EE478 = time;
            } else {
                cSKM_GOBJ* m = g_LocalPlayer->man;
                cScene* scene = cSceneManager_GetSceneBelongingTo(GetSceneManager(), m);
                if (nActivation_IsActivationLoaded(scene->activation)) {
                    cHud_LoadScopes(g_Hud);
                    cJoystick_Debounce(&D_0055A300);
                    SetGameState(15);
                    QueueMessage_cMessageR_cSystemP_int((Msg*)&cStartLevelMsg(), g_Game, 1);
                    cScreenFader_StartFade(g_Fader, 2.0f, 1);
                    cScriptInterpreter_StartLevel(D_00555070);
                    Game_ClearOtherAgentsB70(g_Game);
                    cBackpack_SaveCratesInfo();
                }
            }
        }
    }
    if (STATE == 5) {
        if (D_0048A008) {
            InitVideo(self, self->mVideoMode, 0x10, -1, -1);
            D_005383D4 = self->mFrameRateCap;
            SetFontScale();
            cMachine_InitFonts(self);
            D_0048A008 = 0;
        }
        cMachine_ChooseNetworkServer(self);
    }
    if (STATE == 6) {
        if (D_0048A020) {
            char* value;
            cMachine_InitDME();
            value = cSFOini_GetKeyValue(D_0049C4E8);
            D_004EE488 = value && atoi(value) == 1;
            if (D_004EE488) cDME_ConnectToGame(0);
            cMachine_CreateNetworkLobbyScreen(self);
            D_0048A020 = 0;
        }
        if (!D_004EE488 && !D_004EE490) {
            tServer server;
            cDME_CreateServerList();
            server.port = 0xE4A;
            if (cDME_GetServerFromList(&server)) {
                Net_RetryConnect(&server);
                D_004EE490 = 1;
            }
        }
        cMachine_UpdateNetworkLobbyScreen(self, D_005723F0, D_0048A028);
        if (D_004EE488 || D_004EE490) {
            int n = D_005723F0;
            if (D_0048A028 - 1 == n) {
                cMachine_DestroyNetworkLobbyScreen(self);
                Renderer_Teardown(&g_Video);
                SetGameState(9);
            }
        }
    }
    {
        if (STATE == 15 || STATE == 19) {
            if (g_IsMultiplayer) {
                cNetObj_NextFrame();
                if (STATE != 19 && ((int(*)())cDME_Quit)()) QuitBoxB();
                if (TestAndClear(D_005723B8)) cGameFrontEnd_LobbyDestroy(D_004FFC04, 0);
            }
            if (STATE == 19 && g_Fader->level == 0.0f && cGameSystem_AllAgentDataReceived(g_Game)) SetGameState(20);
            XLib_NextFrame(&g_Video);
            ResetViewport();
            DequeueMessages();
            nGobjManager_PurgeRemovals();
            QueueMessage_cMessageR_cSystemP_int((Msg*)&cGameSoundMsg(), g_Game, 1);
            g_TimerAccum += *(volatile int*)0x10000800;
            *(volatile int*)0x10000800 = 0;
            cGameSystem_Render(g_Game);
            D_005392D8 = D_004BC1B0;
            {
                Viewport* v = &g_Video.vp[D_00538C60];
                v->ominz = 0;
                v->omaxz = 1.0f;
                v->isDirty = 1;
                v->isOrtho = 1;
            }
            {
                void* m = &g_Video.view[D_00538C64];
                __int128 t;
                __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $0; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $0; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory");
                D_00538C68 = 1;
            }
            cTextSystem_Render(GetTextSystem());
            cMachine_CalcFrameTime(self, 1);
        }
    }
    if (STATE == 20) {
        EOLFlags* eolFlags;
        cConsole_Deactivate(self->mConsole);
        cMachine_UnloadLoadingScreen(self);
        cGameSystem_Reset(g_Game);
        DELETE_DELAYS();
        cHogList_CloseAll(D_004FFB8C);
        Renderer_Teardown(&g_Video);
        cMemMan_ReleaseBin(1);
        D_00533CA0 = 0;
        cMemMan_ReleaseBin(3);
        eolFlags = &D_004FFD14;
        if (eolFlags->skipEOL) SetGameState(1);
        else SetGameState(12);
    }
    if (*(unsigned char*)&g_GameState == 16) {
        signed char t = g_PrevGameState; g_PrevGameState = g_GameState; g_GameState = t;
    }
    return 1;
}
