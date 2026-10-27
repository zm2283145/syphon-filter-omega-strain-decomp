/* cMachine::ShowLoadingScreen: draws a few frames of the loading screen (the hud loading bar,
   or the screen fader plus the level name and loading text) inside a pushed full-screen
   viewport and identity view matrix. Render-state idioms as in cMachine_ChooseNetworkServer. */
#pragma opt_rotateloops off
#pragma cplusplus on
#include "types.h"

typedef struct V4_00165E60 { float x, y, z, w; } V4_00165E60;
typedef struct Mtx_00165E60 { __int128 q[4]; } Mtx_00165E60;
typedef struct Slot_00165E60 {
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
} Slot_00165E60;
typedef struct Rs_00165E60 {
    char pad[0xA80];
    Mtx_00165E60 mtx[1];
} Rs_00165E60;
struct tRGBA { float r, g, b, a; tRGBA(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
struct cScreenFader { char pad[0xC]; unsigned char active; void Enable(unsigned char e) { active = e; } };
struct cMachine { char pad[0x274]; void* hudLoading; char pad278[0x280 - 0x278]; void* font; };

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00165E60 D_00539170;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int g_DrawMode;
extern cScreenFader* g_Fader;
extern char g_LevelDirName[];
extern char D_0049C378[];
extern char D_0049C380[];
extern unsigned char D_004EE4E0;
extern unsigned char D_004EE4F0;
extern int D_0048A030;
extern int D_004EE4C8;
extern int D_004EE4D0;
int strcmp(const char* a, const char* b);
void cHudLoading_SetProgress(void* hud, float f);
void XLib_NextFrame(void* p);
void cHudLoading_Render(void* hud);
int GetTextSystem(void);
void cTextSystem_Render(int a);
void cScreenFader_Render(cScreenFader* f);
void cFont_Display_charP_tRGBAR_int_int_etc(float scale, void* font, const char* s, const tRGBA& c, int x, int y);
void cMachine_ShowLoadingScreen(cMachine* self, const char* strLoading, unsigned char lastMessage);
}

#define RS_00165E60 ((Rs_00165E60*)g_Video)
#define SLOT_00165E60(i) ((Slot_00165E60*)(g_Video + (i) * 0x110))

/* identity-matrix store and 64-byte quad copy: VU0/128-bit moves have no C equivalent */
static inline void UM_00165E60(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_00165E60(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

extern "C" void cMachine_ShowLoadingScreen(cMachine* self, const char* strLoading, unsigned char lastMessage)
{
    int i;
    {
        int cmp = strcmp(D_0049C380, strLoading ? strLoading : D_0049C378);
        D_004EE4F0 = lastMessage;
        D_004EE4E0 = cmp == 0;
    }
    if (D_0048A030 != -1)
        return;
    {
        int vpi = (int)&D_00539170;
        if (self->hudLoading)
            cHudLoading_SetProgress(self->hudLoading, (float)D_004EE4C8 / (float)D_004EE4D0);
        {
            Slot_00165E60* s = SLOT_00165E60(D_00538C60);
            V4_00165E60* vp = (V4_00165E60*)vpi;
            s->r[0] = vp->x;
            s->r[1] = vp->y;
            s->r[2] = vp->z;
            s->r[3] = vp->w;
            s->f2F5 = 1;
            s->f2F6 = 1;
        }
    }
    {
        Slot_00165E60* s = SLOT_00165E60(D_00538C60);
        s->f2E0 = 0;
        *(int*)&s->f2E8 = 0x3F800000;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_00165E60(&RS_00165E60->mtx[D_00538C64 + 1], &RS_00165E60->mtx[D_00538C64]);
    D_00538C64++;
    UM_00165E60(&RS_00165E60->mtx[D_00538C64]);
    D_00538C68 = 1;
    D_005392D8 = D_004BC1B0;
    for (i = 0; i < 3; i++) {
        XLib_NextFrame(g_Video);
        if (self->hudLoading) {
            cHudLoading_Render(self->hudLoading);
            cTextSystem_Render(GetTextSystem());
        } else {
            g_Fader->Enable(1);
            cScreenFader_Render(g_Fader);
            {
                tRGBA kStrCol(1.0f, 1.0f, 1.0f, 1.0f);
                g_DrawMode = 1;
                cFont_Display_charP_tRGBAR_int_int_etc(0.001f, self->font, g_LevelDirName, kStrCol, -280, -160);
                cFont_Display_charP_tRGBAR_int_int_etc(0.001f, self->font, strLoading, kStrCol, -280, -184);
            }
        }
    }
    D_00538C68 = 1;
    D_00538C64--;
    {
        Slot_00165E60* s = SLOT_00165E60(D_00538C60);
        s->f2F6 = 1;
        s->f2F4 = 0;
    }
    g_Fader->active = 0;
    cScreenFader_Render(g_Fader);
}
