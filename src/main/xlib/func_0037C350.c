#pragma opt_propagation off
#pragma opt_common_subs off
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;

typedef struct R7C350 {
    char pad0[0xD0];
    unsigned char restore;      /* 0xD0 */
    char padD1[0x120 - 0xD1];
    unsigned int prim;          /* 0x120 */
    unsigned int alphaFix;      /* 0x124 */
    unsigned int fog;           /* 0x128 */
    char pad12C[0x160 - 0x12C];
    int fogR, fogG, fogB;       /* 0x160 */
    char pad16C[0x1060 - 0x16C];
    int tex;                    /* 0x1060 */
    char pad1064[0x10E0 - 0x1064];
    unsigned int baseFlags;     /* 0x10E0 */
    int dirty;                  /* 0x10E4 */
    u64_t alpha;                /* 0x10E8 */
} R7C350;

extern char D_00537F80[];
extern char g_LightMgr[];
extern u64_t D_004BC1B0;
extern int D_00554F04;
extern int D_00537E50;
extern void Renderer_RestoreRenderState(R7C350*);
extern u64_t* DmaPacket_Reserve(void* q, int a, int b, int c, int d, int e);
extern u64_t Renderer_SetPrmodeReg(R7C350*);
extern u64_t Renderer_SetTestReg(R7C350*);
extern int func_003797D0(R7C350*);
extern u64_t* func_003797B0(int reg, int index);
extern u64_t* func_00379790(int reg, int index);
extern void func_00379780(void* q, int n);
extern void LightMgr_GatherModelLights(void* m, unsigned int mask, unsigned int flags, void* out);
extern void Renderer_SetReceiverConsts(R7C350*, unsigned int);
static inline u64_t Dup2_7C350(u64_t v) { return v | (v << 2); }

unsigned int Renderer_SetDrawState(R7C350* r, void* model0, unsigned int req0, unsigned int extra)
{
    R7C350* self = r;   /* parameter copies: give retail s5/s4/s3 and keep r in a0 for the call */
    void* mdl = model0;
    unsigned int rq = req0;
    unsigned int f;
    int n;
    GsQ* q;
    if (rq & 0x80) {
        return 0x80000000;
    }
    f = (self->baseFlags | extra) & 0xBFFFFFFF;
    if (f & 0x80000) {
        self->alpha = D_004BC1B0;
        self->alphaFix = 1;
        self->fog = 0;
        if (self->restore) {
            Renderer_RestoreRenderState(r);
            self->restore = 0;
        }
        n = 9;
        if (self->tex != -1) {
            n += 2;
        }
        {
            int one = 1;
            q = (GsQ*)DmaPacket_Reserve(D_00537F80, one, one, n + 2, 0, one);
        }
        q->lo = 0x11000000;
        q->hi = 0x300002E | ((u64_t)0x20001E9 << 32);
        q++;
        q->lo = 0x1000404 | ((u64_t)(unsigned int)((n + 1) | 0x50000000) << 32);
        q->hi = (long long)n | (0x8000 | ((u64_t)0x10000000 << 32));
        q++;
        q->lo = 0xE;
        q->hi = self->prim;
        q++;
        q->lo = 0x1A;
        q->hi = Renderer_SetPrmodeReg(self);
        q++;
        q->lo = 0x1B;
        q->hi = Renderer_SetTestReg(self);
        q++;
        q->lo = 0x47;
        q->hi = self->alphaFix;
        q++;
        q->lo = 0x46;
        if (self->alpha == D_004BC1B0) {
            q->hi = (long long)self->fogR | ((long long)self->fogG << 8) | ((long long)self->fogB << 16);
            q++;
        } else {
            q->hi = 0;
            q++;
        }
        q->lo = 0x3D;
        q->hi = Dup2_7C350(self->fog);
        q++;
        q->lo = 8;
        q->hi = Dup2_7C350(self->fog);
        q++;
        q->lo = 9;
        q->hi = 0;
        q++;
        q->lo = 0x3F;
        q->hi = self->alpha;
        q++;
        q->lo = 0x42;
        n = self->tex;
        if (n != -1) {
            q->hi = *func_003797B0(func_003797D0(self), n);
            q++;
            q->lo = 6;
            q->hi = *func_00379790(func_003797D0(self), self->tex);
            q++;
            q->lo = 0x14;
            self->tex = -1;
        }
        func_00379780(D_00537F80, 1);
        if ((f & 0x80) || (f & 0x100)) {
            if (!(rq & 0x10)) {
                f &= ~0x180;
            }
        }
        if (rq & 4) {
            f |= 0x40000000;
        }
        if (f & 0x10) {
            LightMgr_GatherModelLights(g_LightMgr, 0x17, 3, mdl);
        }
        self->dirty = 0;
    } else {
        unsigned int lights = 0;
        if (rq & 1) {
            f |= 0x20000000;
        }
        self->alphaFix = 1;
        self->fog = 0;
        if (rq & 4) {
            f |= 0x40000000;
        }
        if (f & 0x4000) {
            f &= 0xBFFFFFFF;
        }
        if (f & 0x10000000) {
            f &= 0xBFFFFFFF;
        }
        if ((f & 0x80) && !(rq & 0x10)) {
            f &= ~0x80;
        }
        if (f & 0x100) {
            if (!(rq & 0x10)) {
                f &= ~0x100;
            } else {
                f &= 0xBFFFFFFF;
            }
        }
        if (f & 0x100000) {
            f &= 0xFF3FFE0F;
            f |= 0x10000000;
        }
        if (f & 0x800000) {
            f &= ~0x20;
        }
        if (D_00554F04) {
            f &= 0xBF9DE3EF;
            f |= 0x10800000;
            self->fog = 1;
        } else {
            f &= ~0x60;
        }
        if (f & 0x20000) {
            f &= 0xFF1FE27F;
        }
        if (f & 0x1000) {
            lights |= 6;
            f &= 0xFFFDF3FF;
        } else if (f & 0xC00) {
            f &= 0xFFFDEFFF;
        }
        if (f & 0x10) {
            unsigned int m = lights | 4;
            LightMgr_GatherModelLights(g_LightMgr, m, m, mdl);
            if (!D_00537E50) {
                f &= ~0x10;
            }
        }
        Renderer_SetReceiverConsts(self, f);
    }
    return f;
}
