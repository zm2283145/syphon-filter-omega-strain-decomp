#include "types.h"
typedef unsigned long u64x;
typedef struct { float x, y, z, w; } Col_66840;
typedef struct { u64x a, b; } __attribute__((aligned(16))) Q_66840;
typedef struct { Q_66840 r[4]; } Mtx_66840;
typedef struct {
    float vp[4];
    char p10[0xF0 - 0x10];
    float fF0;
    float fF4;
    float fF8;
    char pFC[0x104 - 0xFC];
    unsigned char b104;
    unsigned char b105;
    unsigned char b106;
    char p107[0x110 - 0x107];
} Slot_66840;
typedef struct {
    char p0[0x1F0];
    Slot_66840 slot[8];
    char pad[0xA80 - 0x1F0 - 8 * 0x110];
    Mtx_66840 mtx[1];
} Gs_66840;
typedef struct { char p0[0x24]; int f24; int f28; } Fx_66840;

extern Gs_66840 g_Video;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern Col_66840 D_00539170;
extern int g_DrawMode;
extern long D_005392D8;
extern long D_004BC1B0;
extern int D_0048A048;
extern int D_0048A050;
extern int D_004EE4C8;
extern int D_004EE4D0;
extern unsigned char D_004EE4E0;
extern unsigned char D_004EE4F0;
extern int D_004EE4F8;
extern Fx_66840* D_004EE500;
extern int D_004EE508;
extern int D_004EE518;
extern u64x D_004EE520;
extern char D_004EE528;
extern int g_TimerAccum;
extern u64x g_TickCounter64;
extern float _f_ulltof(u64x);
extern void SleepThread(void);
extern void SuspendThread_2(int);
extern void ResumeThread(int);
extern void cHudLoading_SetProgress(float, Fx_66840*);
extern void cHudLoading_NextFrame(float, Fx_66840*);
extern void cHudLoading_Render(Fx_66840*);
extern void cHudLoading_ActivatePressX(Fx_66840*, unsigned char);
extern void cHudLoading_ActivateHost(Fx_66840*, unsigned char);
extern void cFont_Display_charP_tRGBAR_int_int_etc(float, int, int, Col_66840*, int, int);
extern void XLib_NextFrame(Gs_66840*);
extern void cTextSystem_Render(int);
extern int GetTextSystem(void);

static inline u64x Now_66840(void) {
    return g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
}

static inline void SetVp_66840(Slot_66840* s, Col_66840* r) {
    float hh = 0.5f * r->w;
    float hw = 0.5f * r->z;
    s->vp[0] = r->x;
    s->vp[1] = r->y;
    s->vp[2] = r->z;
    s->vp[3] = r->w;
    s->b105 = 1;
    s->b106 = 1;
}
static inline void Push_66840(void) {
    Mtx_66840* dst;
    Mtx_66840* src;
    src = &g_Video.mtx[D_00538C64];
    dst = &g_Video.mtx[D_00538C64 + 1];
    { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(qa), "=&r"(qb) : "r"(src), "r"(dst) : "memory"); }
    D_00538C64++;
}
static inline void UnitMtx_66840(void* m) {
    int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory");
}

static inline void Depth_66840(Slot_66840* s, float n, float f) {
    s->fF0 = n;
    s->fF8 = f;
    s->b106 = 1;
    s->b104 = 1;
}
static inline void ZOff_66840(Slot_66840* s) {
    s->b106 = 1;
    s->b104 = 0;
}
static inline void Dirty_66840(void) { D_00538C68 = 1; }
/* Same-unit context: MW carries soft-double helper state between functions; an earlier
 * implicit 2-argument helper call (_dpfge) is needed for this function's register colouring.
 * The stub lives in .dtors_drop, which the link discards. */
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
__declspec(weak) __declspec(DROPDTOR) int k7_ctx(double a, double b) { return a >= b; }
void loadingThread(void) {
    Q_66840 spr[1032];
    Col_66840 base;
    Col_66840 col;
    int i;
    for (;;) {
        if (!D_004EE528) {
            D_004EE520 = Now_66840();
            D_004EE528 = 1;
        }
        SuspendThread_2(D_0048A048);
        while (*(volatile int*)0x1000D000 & 0x100)
            ;
        while (*(volatile int*)0x1000D400 & 0x100)
            ;
        *(volatile int*)0x1000D020 = 0x400;
        *(volatile int*)0x1000D080 = 0x70000000;
        *(volatile int*)0x1000D010 = (unsigned int)&spr[4] & 0x0FFFFFFF;
        *(volatile int*)0x1000D000 = 0x100;
        __asm__ volatile ("sync");
        {
            Col_66840* fullScreen = &D_00539170;
            float halfWidth = 0.5f * fullScreen->z;
            float halfHeight = 0.5f * fullScreen->w;
            Slot_66840* s = &g_Video.slot[D_00538C60];
            s->vp[0] = fullScreen->x;
            s->vp[1] = fullScreen->y;
            s->vp[2] = fullScreen->z;
            s->vp[3] = fullScreen->w;
            s->b105 = 1;
            s->b106 = 1;
        }
        Depth_66840(&g_Video.slot[D_00538C60], 0.0f, 1.0f);
        Push_66840();
        UnitMtx_66840(&g_Video.mtx[D_00538C64]);
        D_00538C68 = 1;
        D_005392D8 = D_004BC1B0;
        while (*(volatile int*)0x1000D400 & 0x100)
            ;
        for (i = 0; i < 1; i++) {
            unsigned char show;
            short on;
            int h;
            D_004EE4F8 = D_0048A050 + 1;
            XLib_NextFrame(&g_Video);
            g_DrawMode = 0;
            base.x = 1.0f;
            base.y = 1.0f;
            base.z = 1.0f;
            base.w = 1.0f;
            show = 1;
            if (D_004EE4F0 && D_004EE500) {
                if (D_004EE4E0) {
                    if (D_004EE500->f28) {
                        cHudLoading_ActivateHost(D_004EE500, 1);
                        show = 0;
                    }
                } else if (D_004EE500->f24) {
                    cHudLoading_ActivatePressX(D_004EE500, 1);
                    show = 0;
                }
            }
            if (show) {
                h = D_004EE4F0 ? D_004EE518 : D_004EE518;
                if (h) {
                    float t = (float)(u64x)((int)Now_66840() % 100000) / 100000.0f;
                    col.x = base.x;
                    col.y = base.y;
                    col.z = base.z;
                    col.w = base.w;
                    if (!D_004EE4F0)
                        col.w = (t > 0.5f) ? 2.0f * (1.0f - t) : 2.0f * t;
                    cFont_Display_charP_tRGBAR_int_int_etc(0.001f, D_004EE508, h, &col, -0x10E, -0xBE);
                }
            }
            if (D_004EE500) {
                u64x now = Now_66840();
                cHudLoading_NextFrame((float)(now - D_004EE520) / 100000.0f, D_004EE500);
                D_004EE520 = now;
                cHudLoading_SetProgress((float)D_004EE4C8 / (float)D_004EE4D0, D_004EE500);
                cHudLoading_Render(D_004EE500);
                cTextSystem_Render(GetTextSystem());
            }
        }
        D_00538C68 = 1;
        D_00538C64--;
        {
            ZOff_66840(&g_Video.slot[D_00538C60]);
            *(volatile int*)0x1000D420 = 0x400;
            *(volatile int*)0x1000D480 = 0x70000000;
            *(volatile int*)0x1000D410 = (int)&spr[4];
            *(volatile int*)0x1000D400 = 0x100;
            __asm__ volatile ("sync");
            while (*(volatile int*)0x1000D400 & 0x100)
                ;
            ResumeThread(D_0048A048);
        }
        SleepThread();
    }
}



