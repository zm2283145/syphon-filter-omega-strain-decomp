#pragma cplusplus on
/* WaterFx_PointSplash: claim a free splash record slot, construct it, and initialise it at pos. */
typedef int u128_t __attribute__((mode(TI)));
struct Vec4_2B2B70 {
    float x, y, z, w;
    Vec4_2B2B70() {}
    Vec4_2B2B70(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(const Vec4_2B2B70& o) { u128_t q; __asm__ volatile("lq %0, 0x0(%1)\n sq %0, 0x0(%2)" : "=&r"(q) : "r"(&o), "r"(this) : "memory"); }
    Vec4_2B2B70& operator=(const Vec4_2B2B70& o) { u128_t q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Owner_2B2B70 { int pad[3]; int id; };
struct WaterFxRecord {
    Owner_2B2B70 *f0;
    int f4;
    float f8;
    int pad;
    Vec4_2B2B70 pos;
    Vec4_2B2B70 vel;
    float f30;
    int pad2[3];
    char f40[0x40];
    float f80;
    float f84;
    float f88;
};
struct WaterFx {
    char pad[0x400];
    WaterFxRecord *recs[20];
    int count;
};

extern "C" {
extern char D_004ABFF0[];
void *opNew_uint_int_charP_int(int size, int pool, char *file, int line);
WaterFxRecord *WaterFxRecord_Construct(void *p);
void WaterFx_InitSplash(void *a, Vec4_2B2B70 *pos, float f, float g);
void WaterFx_PointSplash(WaterFx *fx, Vec4_2B2B70 *pos, float a, float b);
}

static inline void SetOwner_2B2B70(WaterFxRecord *r, Owner_2B2B70 *o) { r->f0 = o; int t; const int& v = o ? o->id : (t = -1); r->f4 = v; }

void WaterFx_PointSplash(WaterFx *fx, Vec4_2B2B70 *pos, float a, float b)
{
    WaterFxRecord *rec;
    int slot;
    int i;
    float aa;
    float bb;

    slot = -1;
    bb = 0.2f + b;
    aa = a;
    for (i = 0; i < 20; i++) {
        if (fx->recs[i] == 0) {
            void *p;
            slot = i;
            p = opNew_uint_int_charP_int(0xA0, 0, D_004ABFF0, 0x1AA);
            if (p) p = WaterFxRecord_Construct(p);
            fx->recs[slot] = (WaterFxRecord *)p;
            fx->count++;
            break;
        }
    }
    if (slot < 0) return;
    rec = fx->recs[slot];
    SetOwner_2B2B70(rec, 0);
    rec->f8 = aa;
    { Vec4_2B2B70 *d = &rec->pos; d->Set(*pos); }
    rec->vel = Vec4_2B2B70(0.0f, 0.0f, 0.0f, 0.0f);
    rec->f30 = bb;
    WaterFx_InitSplash(rec->f40, &rec->pos, rec->f8, rec->f30);
    {
        float t = rec->f8;
        float s = rec->f30;
        float lo;
        float hi = 3.8f * t - (lo = 0.6f * t);
        rec->f80 = lo;
        rec->f84 = hi;
        rec->f88 = s;
    }
}
