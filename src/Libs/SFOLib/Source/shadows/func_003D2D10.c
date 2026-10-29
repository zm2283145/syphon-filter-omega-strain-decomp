#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V { float x, y, z, w; V() {} V(const V& o) { Q16(this, &o); } } __attribute__((aligned(16)));
struct M { V r[4]; } __attribute__((aligned(16)));

struct Tex { char pad[0x50]; unsigned long q50; };
struct TexList { char pad[8]; Tex** tex; char padC[0xA]; unsigned char b16; char pad17; int n; short ids[0x200]; };
struct RT { int id; char pad[0x10]; };
struct Cam { int near; int pad; float far; float dist; unsigned char b10; char pad11; unsigned char b12; char pad13[0xFD]; };
struct Rend {
    char pad[0x2E4];
    Cam cams[1];
};
struct RendM { char pad[0xA80]; M mtx[16]; };
struct RendBufs { char pad[0x1068]; RT bufs[5]; };
struct Shp { VPAD16(a) VPAD4(b) virtual void Upd(); char pad4[0x3C]; V pos40; unsigned char b50; };
struct Mdl { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) virtual V GetPos(); char pad4[0x4C]; Shp* shp; };
struct Lvl {
    Mdl* mdl;               /* 0x00 */
    float f4;               /* 0x04 */
    float f8;               /* 0x08 */
    short tex;              /* 0x0C */
    unsigned char kind;     /* 0x0E */
    char padF;
    M m10;                  /* 0x10 */
    char pad50[0x4C];
    float f9C;              /* 0x9C */
    char padA0[8];
    float fA8;              /* 0xA8 */
    float fAC;              /* 0xAC */
    char padB0[0xC];
    float fBC;              /* 0xBC */
};
struct Cnt { char pad[8]; int n; };
struct S1760 { int a; Cnt* c; Cnt* Get() { return c; } };
struct Shadow {
    char pad[0x10540];
    Lvl lv[0x18];
    char pad11740[8];
    int ids[5];
    int w175C;
    S1760 s1760;
    char pad1768[4];
    int* list;
    int base;
};
struct ShadowTail { int ids[5]; int w175C; int pad1760; Cnt* c1764; char pad1768[4]; int* list; int base; };

extern "C" {
extern RendBufs g_Video;
extern TexList* g_TextureMgr;
extern int D_00539254, D_00538C60, D_00538C64, g_DrawMode, D_005382E4;
extern unsigned char D_00538C68, D_00535D60, D_00535D61;
extern float D_00539180, D_00539184;
extern V D_00535D40;
void cTexMan_EndBatch(TexList*);
int cUserFrameEnv_IsVram(RT*);
float XLib_GetFogVal(void*, V*);
void cUserFrameEnv_Activate(RT*);
int cUserFrameEnv_GetWidth(RT*);
int cUserFrameEnv_GetHeight(RT*);
int cUserFrameEnv_GetPSM(RT*);
int cUserFrameEnv_GetVramAddr(RT*);
int cUserFrameEnv_GetZPSM(RT*);
int cUserFrameEnv_GetVramZAddr(RT*);
int cUserFrameEnv_HasZBuffer(RT*);
void XLib_SetFrameEnv(void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned char);
void XLib_SetDepthTest(void*, int, int);
void XLib_PushViewport(void*);
void* XLib_EditViewport(void*);
void* tRECT_ctor(void*, float, float, float, float);
void cXViewport_SetWindow(void*, void*, int);
void XLib_SetAspectRatio(void*, float);
void cUserFrameEnv_Clear(RT*, int*);
void cMan_ManRender(void*, void*, int, int, int, int);
void cUserFrameEnv_Deactivate(RT*, int);
void XLib_RestoreFrameEnv(void*);
int* cLList_int_Back(void*);
void cLList_int_Remove(void*, int*);
void cLList_int_PushBackActual(void*, int*);
void cShadowMan_BuildShadowMap(char* self, int idx);
}

#define TAIL(s) ((ShadowTail*)((s) + 0x11748))
#define REND ((Rend*)&g_Video)
#define MTX (((RendM*)&g_Video)->mtx)

static inline void Q16x(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void MCopy(M* d, const M* s) { __int128 qa; __int128 qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline unsigned char VecEq(V* a, V* b) {
    int m, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori m, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne m, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Q16c(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline int F2I(float f) { int r = 0; asm { cvt.w.s f, f; mfc1 r, f } return r; }
static inline void Reset(TexList* g) { g->n = 0; g->b16 = 0; }
static inline void Push(TexList* g, int tx) {
    if ((unsigned)g->n < 0x200 && (g->n == 0 || g->ids[g->n - 1] != tx))
        g->ids[g->n++] = tx;
}
static inline void SetTex(Lvl* lv) {
    int tx = lv->tex;
    TexList* g = g_TextureMgr;
    unsigned long q = g->tex[tx]->q50;
    int lo = (int)(q & 0xFFFFFFFF);
    lv->f9C = *(float*)&lo;
    int hi = (int)(q >> 32);
    lv->fAC = *(float*)&hi;
    int k = lv->kind;
    lv->fBC = *(float*)&k;
    if (lv->kind == 2 || lv->kind == 3) lv->fA8 = 128.0f * lv->f4;
}

static inline void UseTex(void* w, int key) {
    if (key != *cLList_int_Back(w)) {
        cLList_int_Remove(w, &key);
        cLList_int_PushBackActual(w, &key);
    }
}
static inline void SetVp(void* cam, RT* rt) {
    V vp;
    float fw = (float)(cUserFrameEnv_GetWidth(rt) - 2);
    cXViewport_SetWindow(cam, tRECT_ctor(&vp, 1.0f, 1.0f, fw, (float)(cUserFrameEnv_GetHeight(rt) - 2)), 0);
}

void cShadowMan_BuildShadowMap(char* self, int idx)
{
    Shadow* t = (Shadow*)self;
    int id = t->list[t->base + idx + 1];
    Lvl* lv = &t->lv[id];
    if (lv->kind == 3) {
        Reset(g_TextureMgr);
        Push(g_TextureMgr, lv->tex);
        cTexMan_EndBatch(g_TextureMgr);
        SetTex(lv);
        return;
    }
    int slot = -1;
    for (int i = 0; i < 5; i++) {
        if (t->ids[i] == id) { slot = i; break; }
    }
    if (slot != -1 && !cUserFrameEnv_IsVram(&g_Video.bufs[slot])) slot = -1;
    if (slot == -1) {
        float fog = 1.0f;
        { S1760* sp = &t->s1760; slot = sp->Get()->n; }
        if (lv->kind == 1) {
            Shp* s = lv->mdl->shp;
            if (s->b50) s->Upd();
            float ff = XLib_GetFogVal(&g_Video, &s->pos40);
            ff *= 0.0039215689f;
            fog = ff;
        }
        RT* rt = &g_Video.bufs[slot];
        D_00539254 = slot;
        cUserFrameEnv_Activate(rt);
        XLib_SetFrameEnv(&g_Video, cUserFrameEnv_GetWidth(rt), cUserFrameEnv_GetHeight(rt), cUserFrameEnv_GetPSM(rt), cUserFrameEnv_GetVramAddr(rt), 0, cUserFrameEnv_GetZPSM(rt), cUserFrameEnv_GetVramZAddr(rt), !cUserFrameEnv_HasZBuffer(rt), 0);
        if (!cUserFrameEnv_HasZBuffer(rt)) XLib_SetDepthTest(&g_Video, 1, 1);
        XLib_PushViewport(&g_Video);
        void* cam = XLib_EditViewport(&g_Video);
        SetVp(cam, rt);
        XLib_SetAspectRatio(&g_Video, 1.0f);
        if (lv->kind == 1) {
            int c[4]; c[3] = 0x80; c[0] = 0; c[1] = 0; c[2] = 0;
            cUserFrameEnv_Clear(&g_Video.bufs[D_00539254], c);
        } else {
            int c[4]; c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0;
            cUserFrameEnv_Clear(&g_Video.bufs[D_00539254], c);
        }
        {
            Cam* c = &REND->cams[D_00538C60];
            c->dist = lv->f8;
            *(float*)&c->near = 2.0f;
            c->far = 1000.0f;
            c->b12 = 1;
            c->b10 = 0;
        }
        MCopy(&MTX[D_00538C64 + 1], &MTX[D_00538C64]);
        D_00538C64++;
        MCopy(&MTX[D_00538C64], &lv->m10);
        D_00538C68 = 1;
        {
            void* a = (char*)lv->mdl + 0x60;
            void* b = (char*)lv->mdl + 0x2E50;
            if (lv->kind == 1) {
                float k = 127.0f;
                g_DrawMode &= ~0x10;
                int al = F2I(1.0f + fog * (k * lv->f4));
                cMan_ManRender(a, b, 2, al, 0, 0);
            } else {
                g_DrawMode |= 0x10;
                V p = lv->mdl->GetPos();
                int ne = (bool)VecEq(&D_00535D40, &p) ^ 1;
                if (ne) {
                    Q16c(&D_00535D40, &p);
                    D_00535D60 = 1;
                    D_00535D61 = 1;
                }
                cMan_ManRender(a, b, 2, 0, 1, 0);
            }
        }
        D_00538C64--;
        D_00538C68 = 1;
        cUserFrameEnv_Deactivate(&g_Video.bufs[D_00539254], 1);
        D_00539254 = -1;
        XLib_RestoreFrameEnv(&g_Video);
        D_005382E4 = 2;
        D_00538C60--;
        { Cam* c = &REND->cams[D_00538C60]; c->b12 = 1; }
        D_00539184 = D_00539180;
        t->ids[slot] = id;
        lv->tex = ((RendBufs*)&g_Video)->bufs[slot].id;
        SetTex(lv);
    }
    UseTex(&t->w175C, slot);
}

