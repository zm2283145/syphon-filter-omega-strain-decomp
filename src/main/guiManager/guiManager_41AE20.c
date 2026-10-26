typedef struct { float x, y, z, w; } V4_r8;
static inline void Set(V4_r8* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
void InterpolateColor_tRGBAR_tRGBAR_float_2(V4_r8* out, V4_r8* a, V4_r8* b, float t)
{
    Set(out, a->x + t * (b->x - a->x), a->y + t * (b->y - a->y), a->z + t * (b->z - a->z), a->w + t * (b->w - a->w));
}
