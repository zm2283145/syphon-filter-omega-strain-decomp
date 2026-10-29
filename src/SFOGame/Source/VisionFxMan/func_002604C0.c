#include "types.h"

typedef struct {
    unsigned char active;
    unsigned char done;
    char pad2[2];
    float t;
    float delay;
    float in;
    float hold;
    float out;
} Fade_04C0;

typedef struct { char pad0[0x22]; unsigned short count; } TexInfo_04C0;
typedef struct { char pad0[0x44]; TexInfo_04C0* info; char pad48[4]; int frame; char pad50[0x60 - 0x50]; unsigned char b60; unsigned char b61; } TexEnt_04C0;
typedef struct { char pad0[8]; TexEnt_04C0** entries; } TexReg_04C0;

typedef struct {
    int state;
    int next;
    unsigned char b8;
    char pad9[3];
    Fade_04C0 f1;
    char pad24[4];
    int x28;
    float level;
    Fade_04C0 f2;
    char pad48[0x198 - 0x48];
    float scroll;
    int tex;
    char pad1A0[0x1A8 - 0x1A0];
    float x1A8;
    int frame;
    float timer;
    float period;
} O_04C0;

extern TexReg_04C0* g_TextureMgr;
extern int D_00538C60;
extern char g_Video[];
unsigned char cVisionFxMan_cFxTimer_Complete(Fade_04C0*);
void cVisionFxMan_cFxTimer_Set(Fade_04C0*, float, float, float, float);
void cVisionFxMan_cFxTimer_Reset(Fade_04C0*);

static inline void Fade_Update(Fade_04C0* f, float dt) {
    if ((f->in + f->hold + f->out) && !f->done) {
        f->t += dt;
        if (!f->active && f->t > f->delay) {
            f->t -= f->delay;
            f->active = 1;
        }
        if (f->active && f->t >= f->in + f->hold + f->out) f->done = 1;
    }
}

static inline float Fade_Value(Fade_04C0* f) {
    float v = 0.0f;
    if (f->active) {
        if (f->done) {
            v = 1.0f;
            if (f->out > 0.0f) v = 0.0f;
        } else {
            float w;
            v = f->t / f->in;
            v = (1.0f < v) ? 1.0f : v;
            w = (f->t - f->in - f->hold) / f->out;
            v -= (0.0f > w) ? 0.0f : w;
        }
    } else {
        if (f->out > v) v = 1.0f;
    }
    return v;
}

static inline void Fade_Reset(Fade_04C0* f) {
    *(int*)&f->t = 0;
    *(int*)&f->out = 0;
    *(int*)&f->hold = 0;
    *(int*)&f->in = 0;
    *(int*)&f->delay = 0;
    f->active = 0;
    f->done = 0;
}

void cVisionFxMan_NextFrame(O_04C0* o, float dt) {
    Fade_Update(&o->f2, dt);
    Fade_Update(&o->f1, dt);
    if (o->state != o->next) {
        int none;
        if (o->next != 0 && o->next != (none = -1)) {
            cVisionFxMan_cFxTimer_Reset(&o->f2);
            cVisionFxMan_cFxTimer_Set(&o->f2, 0.0f, 1.5f, 0.0f, 0.0f);
            o->state = o->next;
        } else if (o->next != (none = -1)) {
            cVisionFxMan_cFxTimer_Reset(&o->f2);
            cVisionFxMan_cFxTimer_Set(&o->f2, 0.0f, 0.0f, 0.0f, 0.8f);
            o->next = -1;
        }
        if (cVisionFxMan_cFxTimer_Complete(&o->f2) && o->next == none) {
            o->state = 0;
            o->next = 0;
        }
    }
    o->level = Fade_Value(&o->f2);
    o->x1A8 = 0.65f * o->level;
    if (o->f1.done) {
        Fade_Reset(&o->f1);
        o->b8 = 0;
        o->x28 = 0;
    }
    switch (o->state) {
    case 1: case 2: {
        int n = g_TextureMgr->entries[o->tex]->info->count;
        if (n > 1) {
            o->timer += dt;
            if (o->timer > o->period) {
                o->timer -= o->period;
                if (++o->frame == n) o->frame = 0;
                {
                    TexEnt_04C0* e = g_TextureMgr->entries[o->tex];
                    unsigned int fr = o->frame;
                    if (fr != e->frame && fr < e->info->count) {
                        e->b60 = 0;
                        e->b61 = 0;
                        e->frame = fr;
                    }
                }
            }
        }
        {
            float s;
            float h = *(float*)(g_Video + D_00538C60 * 0x110 + 0x1FC);
            h = (0.5f) * (float)h;
            s = dt * h;
            s = o->scroll - s;
            o->scroll = s;
            if (s < -h) o->scroll = h;
        }
    } break;
    }
}


