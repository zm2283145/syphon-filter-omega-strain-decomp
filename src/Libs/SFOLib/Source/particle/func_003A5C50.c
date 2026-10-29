typedef struct {
    float v[3];
    float pad;
} Row;

typedef struct {
    Row pos[4];
    Row per[4];
    float vel[2];
    float amp;
    char pad8C[8];
    float t;
} Wave;

float Libc_Sinf(float);

static inline float Sin(float x) { return Libc_Sinf(x); }
static inline float Osc(float amp, float a)
{
    float r = Sin(0.5f * a) * Sin(a);
    return r * amp;
}

static inline float Osc2(float amp, float per, float t) { float a = (3.1415927f * (2.0f * (float)t)) / per; float r = Sin(0.5f * a) * Sin(a); return r * amp; }

void cWind_NextFrame(Wave* w, float dt)
{
    int i;
    Wave* p;

    i = 0;
    p = w;
    do {
        p->pos[0].v[0] = Osc2(w->amp, p->per[0].v[0], w->t);
        p->pos[0].v[1] = Osc2(w->amp, p->per[0].v[1], w->t);
        p->pos[0].v[2] = Osc2(w->amp, p->per[0].v[2], w->t);
        i++;
        p = (Wave*)&p->pos[1];
    } while (i < 4);
    w->pos[0].v[0] += w->vel[0];
    w->pos[0].v[1] += w->vel[1];
    w->pos[0].v[2] *= 0.1f;
    w->t += dt;
}
