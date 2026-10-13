static inline void Q43(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 min;
    Vec4 max;
} Box;
typedef struct {
    char pad[0x64];
    void *mdl;
    char pad68[8];
    float scale;
} Obj;
extern Box *func_003A2A90(void *);
extern signed char D_0053B4C0;
extern Box D_0053B4D0;
Box *func_003943A0(Obj *o)
{
    if (o->mdl != 0) {
    if (o->scale == 1.0f) return func_003A2A90(o->mdl);
    if (!D_0053B4C0) {
        D_0053B4D0.min.x = 3.4028235e38f;
        D_0053B4D0.min.y = 3.4028235e38f;
        D_0053B4D0.min.z = 3.4028235e38f;
        D_0053B4D0.min.w = 1.0f;
        D_0053B4D0.max.x = -3.4028235e38f;
        D_0053B4D0.max.y = -3.4028235e38f;
        D_0053B4D0.max.z = -3.4028235e38f;
        D_0053B4D0.max.w = 1.0f;
        D_0053B4C0 = 1;
    }
    Q43(&D_0053B4D0.min, &func_003A2A90(o->mdl)->min);
    D_0053B4D0.min.x = o->scale * func_003A2A90(o->mdl)->min.x;
    D_0053B4D0.min.y = o->scale * func_003A2A90(o->mdl)->min.y;
    Q43(&D_0053B4D0.max, &func_003A2A90(o->mdl)->max); { void* xx = &D_0053B4D0.max; /* dead on purpose: retail keeps this addiu */ }
    D_0053B4D0.max.x = o->scale * func_003A2A90(o->mdl)->max.x;
    D_0053B4D0.max.y = o->scale * func_003A2A90(o->mdl)->max.y;
    return &D_0053B4D0;
    }
    return 0;
}


