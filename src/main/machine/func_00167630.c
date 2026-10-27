/* cMachine_ChooseNetworkServer (machine): lobby loading-screen tick. The quad copy and identity-matrix store are GCC-style __asm__ volatile: MW does no CSE across them, so the base address and constant are rematerialised as in retail. */
#pragma opt_rotateloops off
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef struct V4_00167630 { float x, y, z, w; } V4_00167630;
typedef struct Mtx_00167630 { __int128 q[4]; } Mtx_00167630;
typedef struct Slot_00167630 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_00167630;
typedef struct Rs_00167630 {
    char pad[0xA80];
    Mtx_00167630 mtx[1];
} Rs_00167630;
typedef struct Name_00167630 { char c[16]; } Name_00167630;
typedef struct Obj_00167630 {
    char pad[0x40];
    Name_00167630 name;
    int f50;
    unsigned char f54;
    unsigned char f55;
} Obj_00167630;
typedef struct Sess_00167630 { Name_00167630 name; int id; } Sess_00167630;

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00167630 D_00539170;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int g_TimerAccum;
extern unsigned long long g_TickCounter64;
extern Obj_00167630* D_004EE498;
extern unsigned char D_004EE4A0;
extern unsigned long long D_004EE4A8;
extern signed char D_004EE4B0;
extern char D_0048B2F8[];
extern char D_0049C390[];
extern char D_0049C430[];
extern char D_0049C448[];
extern char D_004FFB8C[];
extern signed char g_GameState;
extern signed char g_PrevGameState;
extern float g_TextColourBlock;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
extern char D_0055A300[];
extern unsigned char D_005724B0;
int sprintf(char* d, const char* f, ...);
void cFileMan_ctor_charP_cFileIOP_bool(void* a, char* p, int b, int c);
int cFileMan_Open(void* a);
void cFileMan_dtor(void* a, int b);
int cHogList_Open(void* a, char* p, int b, int c);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
Obj_00167630* cHudNetLobby_ctor(void* p, int ar, char* name);
void func_0027B680(Obj_00167630* o);
void cHudNetLobby_dtor(Obj_00167630* o, int flags);
void cMachine_InitDME(void);
void XLib_NextFrame(void* p);
void cHudNetLobby_HandleInput(Obj_00167630* o, void* pad);
float _f_ulltof(unsigned long long t);
void cHudNetLobby_NextFrame(Obj_00167630* o, float dt);
void cHudNetLobby_Render(Obj_00167630* o);
int GetTextSystem(void);
void cTextSystem_Render(int a);
void cDME_ConnectToGame(int a);
void Net_RetryConnect(Sess_00167630* s);
void cMachine_NetUpdate(void* p);
}

#define RS_00167630 ((Rs_00167630*)g_Video)
#define SLOT_00167630(i) ((Slot_00167630*)(g_Video + (i) * 0x110))

static inline void UM_00167630(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_00167630(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

static inline unsigned long long Now_00167630(void)
{
    return g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
}

struct V4c_00167630 {
    float x, y, z, w;
    V4c_00167630(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

static inline void SetCol_00167630(const V4c_00167630& c)
{
    g_TextColourBlock = c.x;
    D_0055A284 = c.y;
    D_0055A288 = c.z;
    D_0055A28C = c.w;
}

extern "C" void cMachine_ChooseNetworkServer(void* arg)
{
    if (!D_004EE4B0) {
        D_004EE4A8 = Now_00167630();
        D_004EE4B0 = 1;
    }
    if (!D_004EE4A0) {
        cMachine_InitDME();
        D_004EE4A0 = 1;
    }
    if (D_004EE498 == 0) {
        char path[0x90];
        char ar[0xA0];
        sprintf(path, D_0049C430, D_0048B2F8);
        cFileMan_ctor_charP_cFileIOP_bool(ar, path, 0, 0);
        if (!(cFileMan_Open(ar) & 0xFF)) {
            int h = cHogList_Open(D_004FFB8C, path, 0, 0);
            void* p;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            p = cMemMan_Allocate(0, 0x58, D_0049C390, 0x567);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            if (p) p = cHudNetLobby_ctor(p, h, D_0049C448);
            D_004EE498 = (Obj_00167630*)p;
            func_0027B680(D_004EE498);
        }
        cFileMan_dtor(ar, -1);
        return;
    }
    {
        int vpi = (int)&D_00539170;
        Slot_00167630* s = SLOT_00167630(D_00538C60);
        V4_00167630* vp = (V4_00167630*)vpi;
        s->r[0] = vp->x;
        s->r[1] = vp->y;
        s->r[2] = vp->z;
        s->r[3] = vp->w;
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    {
        Slot_00167630* s = SLOT_00167630(D_00538C60);
        s->f2E0 = 0;
        *(int*)&s->f2E8 = 0x3F800000;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_00167630(&RS_00167630->mtx[D_00538C64 + 1], &RS_00167630->mtx[D_00538C64]);
    D_00538C64++;
    UM_00167630(&RS_00167630->mtx[D_00538C64]);
    D_00538C68 = 1;
    D_005392D8 = D_004BC1B0;
    XLib_NextFrame(g_Video);
    {
        V4c_00167630 c(1.0f, 1.0f, 0.0f, 1.0f);
        SetCol_00167630(c);
    }
    cHudNetLobby_HandleInput(D_004EE498, D_0055A300);
    {
        unsigned long long now = Now_00167630();
        cHudNetLobby_NextFrame(D_004EE498, _f_ulltof(now - D_004EE4A8) / 100000.0f);
        D_004EE4A8 = now;
    }
    cHudNetLobby_Render(D_004EE498);
    D_005392D8 = D_004BC1B0;
    cTextSystem_Render(GetTextSystem());
    D_00538C68 = 1;
    D_00538C64--;
    {
        Slot_00167630* s = SLOT_00167630(D_00538C60);
        s->f2F6 = 1;
        s->f2F4 = 0;
    }
    {
        Obj_00167630* q = D_004EE498;
        if (q->f54) {
        if (q->f55) {
            cDME_ConnectToGame(0);
        } else {
            Sess_00167630 ss;
            ss.name = q->name;
            ss.id = q->f50;
            Net_RetryConnect(&ss);
            while (D_005724B0 == 5) cMachine_NetUpdate(arg);
        }
        {
            Obj_00167630* o;
            g_PrevGameState = g_GameState;
            o = D_004EE498;
            g_GameState = 0xE;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cHudNetLobby_dtor(o, -1);
            cMemMan_Deallocate(0, o, D_0049C390, 0x5A2);
            if (g_ProfileLockEnabled) EnableIntc(9);
            D_004EE498 = 0;
            g_ProfileLockDepth--;
        }
    }
}
}
