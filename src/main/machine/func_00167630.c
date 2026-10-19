/* GameFlow_EnterMpLobby (machine): lobby loading-screen tick. The quad copy and identity-matrix store are GCC-style __asm__ volatile: MW does no CSE across them, so the base address and constant are rematerialised as in retail. */
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
extern char D_005381F0[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00167630 D_00539170;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int D_00533870;
extern unsigned long long D_00533878;
extern Obj_00167630* D_004EE498;
extern unsigned char D_004EE4A0;
extern unsigned long long D_004EE4A8;
extern signed char D_004EE4B0;
extern char D_0048B2F8[];
extern char D_0049C390[];
extern char D_0049C430[];
extern char D_0049C448[];
extern char D_004FFB8C[];
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern float D_0055A280;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
extern char D_0055A300[];
extern unsigned char D_005724B0;
int sprintf(char* d, const char* f, ...);
void func_0036E4B0(void* a, char* p, int b, int c);
int FileMan_FindMember(void* a);
void FileMan_Release(void* a, int b);
int Archive_Open(void* a, char* p, int b, int c);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
Obj_00167630* func_0027B900(void* p, int ar, char* name);
void func_0027B680(Obj_00167630* o);
void func_0027B690(Obj_00167630* o, int flags);
void App_InitSystemsOnce(void);
void Video_BeginFrame(void* p);
void func_0027A740(Obj_00167630* o, void* pad);
float SoftFloat_U64ToFloat(unsigned long long t);
void func_0027A830(Obj_00167630* o, float dt);
void func_0027A7F0(Obj_00167630* o);
int TextManager_Get(void);
void TextManager_DrawImmediate(int a);
void Net_StartSession(int a);
void Net_RetryConnect(Sess_00167630* s);
void func_00169390(void* p);
}

#define RS_00167630 ((Rs_00167630*)D_005381F0)
#define SLOT_00167630(i) ((Slot_00167630*)(D_005381F0 + (i) * 0x110))

static inline void UM_00167630(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_00167630(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

static inline unsigned long long Now_00167630(void)
{
    return D_00533878 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f);
}

struct V4c_00167630 {
    float x, y, z, w;
    V4c_00167630(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

static inline void SetCol_00167630(const V4c_00167630& c)
{
    D_0055A280 = c.x;
    D_0055A284 = c.y;
    D_0055A288 = c.z;
    D_0055A28C = c.w;
}

extern "C" void GameFlow_EnterMpLobby(void* arg)
{
    if (!D_004EE4B0) {
        D_004EE4A8 = Now_00167630();
        D_004EE4B0 = 1;
    }
    if (!D_004EE4A0) {
        App_InitSystemsOnce();
        D_004EE4A0 = 1;
    }
    if (D_004EE498 == 0) {
        char path[0x90];
        char ar[0xA0];
        sprintf(path, D_0049C430, D_0048B2F8);
        func_0036E4B0(ar, path, 0, 0);
        if (!(FileMan_FindMember(ar) & 0xFF)) {
            int h = Archive_Open(D_004FFB8C, path, 0, 0);
            void* p;
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            p = Mem_Alloc(0, 0x58, D_0049C390, 0x567);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
            if (p) p = func_0027B900(p, h, D_0049C448);
            D_004EE498 = (Obj_00167630*)p;
            func_0027B680(D_004EE498);
        }
        FileMan_Release(ar, -1);
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
    Video_BeginFrame(D_005381F0);
    {
        V4c_00167630 c(1.0f, 1.0f, 0.0f, 1.0f);
        SetCol_00167630(c);
    }
    func_0027A740(D_004EE498, D_0055A300);
    {
        unsigned long long now = Now_00167630();
        func_0027A830(D_004EE498, SoftFloat_U64ToFloat(now - D_004EE4A8) / 100000.0f);
        D_004EE4A8 = now;
    }
    func_0027A7F0(D_004EE498);
    D_005392D8 = D_004BC1B0;
    TextManager_DrawImmediate(TextManager_Get());
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
            Net_StartSession(0);
        } else {
            Sess_00167630 ss;
            ss.name = q->name;
            ss.id = q->f50;
            Net_RetryConnect(&ss);
            while (D_005724B0 == 5) func_00169390(arg);
        }
        {
            Obj_00167630* o;
            D_004FFBA1 = D_004FFBA0;
            o = D_004EE498;
            D_004FFBA0 = 0xE;
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            func_0027B690(o, -1);
            Mem_Free(0, o, D_0049C390, 0x5A2);
            if (D_00533880) Alloc_Unlock(9);
            D_004EE498 = 0;
            D_00533888--;
        }
    }
}
}
