typedef struct { float x, y, z, w; } V4_A8F0;
extern V4_A8F0 D_004BF1A0;
extern V4_A8F0 D_004BF1B0;
extern float D_004BF1C0;
extern float D_00572100;
extern V4_A8F0 D_005720E0;
extern void func_0041E3B0(void* self, float dt);
extern float Math_FMod(float x, float y);
static inline float Abs_A8F0(float x) { float r; asm { abs.s r, x } return r; }
static inline void Set(V4_A8F0* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
static inline void Lerp(V4_A8F0* out, V4_A8F0* a, V4_A8F0* b, float t)
{
    float aw = a->w, az = a->z, ay = a->y, ax = a->x;
    Set(out, ax + t * (b->x - ax), ay + t * (b->y - ay), az + t * (b->z - az), aw + t * (b->w - aw));
}
void func_0041A8F0(void* self, float dt)
{
    float t;
    float m;
    func_0041E3B0(self, dt);
    m = Math_FMod(D_00572100 += 33.333332f * dt, D_004BF1C0);
    D_00572100 = m;
    t = Abs_A8F0(1.0f - 2.0f * m / D_004BF1C0);
    Lerp(&D_005720E0, &D_004BF1A0, &D_004BF1B0, t);
}




