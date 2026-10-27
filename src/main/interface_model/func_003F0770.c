#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* CreateFeature: interface-model chunk reader for the two direction tags - a line (two points read
 * from the stream, second point zeroed when the segment is degenerate) or a single point. */

typedef struct { signed char len; char text[0x80]; } PStr0770;
struct V4 {
    float x, y, z, w;
    V4() {}
    /* quadword copies; the unused xx reproduces retail's duplicated destination address */
    V4(const V4& o) { void* xx = this; __int128 q; V4* pd = this; const V4* ps = &o; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4& operator=(const V4& o) { void* xx = this; V4* pd = this; const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
typedef struct { char pad[0xD0]; V4* line; V4* point; } Self0770;

extern "C" {
extern char D_004BE030[];
extern char D_004BE050[];
extern char D_004BE058[];
extern int D_0055C0B8;
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern int strcmp(const char* a, const char* b);
int CreateFeature(Self0770* self, char** cursor);
}

static inline void Copy(PStr0770* buf, char* t, const char* s)
{
    const char* p;
    int n;
    char* d;
    n = 0;
    d = t;
    p = s;
    if (n < 0x7E) {
        while ((*d++ = *p++) != 0) {
            if (++n >= 0x7E) {
                n++;
                *d++ = '\n';
                *d = 0;
                break;
            }
        }
    }
    buf->len = n;
}

static inline float ReadF(char** c) { float f = *(float*)*c; *c += 4; return f; }
static inline int ReadI(char** c) { return *(*(int**)c)++; }
/* point stored with y and z swapped (file is z-up) */
static inline void SetPt(V4* p, float x, float y, float z) { if (p) { p->x = x; p->y = z; p->z = y; p->w = 1.0f; } }

static inline void SubV(V4* r, V4* a, V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1)\n\tlqc2 $vf2, 0x0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline V4 Sub(V4* a, V4* b)
{
    V4 r;
    SubV(&r, a, b);
    return r;
}
/* squared length (VU0 macro mode); by-value parameter like retail */
static inline float LenSq(V4 v)
{
    V4* p = &v;
    int rv;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv, vf4
        mtc1 rv, ret
    }
    return ret;
}

extern "C" int CreateFeature(Self0770* self, char** cursor)
{
    PStr0770 s;
    char* start = *cursor;
    while (*(*cursor)++) ;
    Copy(&s, s.text, start);
    *cursor = (char*)(((int)*cursor + 3) & ~3);
    if (strcmp(s.text, D_004BE050) == 0) {
        V4* a;
        V4* v;
        int n;
        { AllocGuard g; a = (V4*)cMemMan_Allocate(0, 0x20, D_004BE030, 0xC4); }
        self->line = a;
        v = self->line;
        if (D_0055C0B8 > 1) n = ReadI(cursor);
        else n = 1;
        {
            float x = ReadF(cursor);
            float y = ReadF(cursor);
            float z = ReadF(cursor);
            SetPt(v, x, y, z);
        }
        if (n > 1) {
            int i;
            {
                V4* q = (V4*)((char*)v + 16);
                float x = ReadF(cursor);
                float y = ReadF(cursor);
                float z = ReadF(cursor);
                SetPt(q, x, y, z);
            }
            if (0.0f == LenSq(Sub(&v[1], &v[0]))) v[1] = V4(0.0f, 0.0f, 0.0f, 0.0f);
            for (i = 2; i < n; i++) {
                *cursor += 4;
                *cursor += 4;
                *cursor += 4;
            }
        } else {
            v[1] = V4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    } else if (strcmp(s.text, D_004BE058) == 0) {
        V4* v;
        float x = ReadF(cursor);
        float y = ReadF(cursor);
        float z = ReadF(cursor);
        { AllocGuard g; v = (V4*)cMemMan_Allocate(0, 0x10, D_004BE030, 0xE6); }
        SetPt(v, x, y, z);
        self->point = v;
    } else {
        return 0;
    }
    return 1;
}
