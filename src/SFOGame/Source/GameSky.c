/*
 * SFOGame/Source/GameSky: 2 files, 001C5E50-001C6140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C5E50 */
#pragma push /* merge_units */
// cGameSky::cGameSky(cHogFile&, cHogFile&, cPopulation&, int) (GameSky.cc). Locals follow the prototype (levelID, itemID, x, y, rot, b,
// SKYInit, skyLevel, done); stream reads are written out in place (no inline helper locals) so done stays in v0.
#pragma cplusplus on
#pragma exceptions off
#include "types.h"
#include "vslot_pad.h"

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Reader { int version; int a, b; char* cur; };
struct SkyEnt {
    char* name;
    int pad[3];
    V4 a;
    V4 b;
    int flags;
} __attribute__((aligned(16)));
struct SkyDesc {
    int p0;
    int p1;
    int count;
    int pad;
    SkyEnt ents[8];
};
class Sky {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void Setup(SkyDesc*); virtual void Finish(int);
    char p4[8];
    int id;
    char p10[0x50];
    int p60;
    int p64;
    char p68[0x28];
    int count;
};

extern "C" {
extern char D_004DAB20[];
Sky* cSKYBOX_GOBJ_ctor(Sky* self);
int cPopulation_Rewind(Reader* r, int tag);
}

static inline void SetV(V4* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
static inline void Align(Reader* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}

extern "C" Sky* cGameSky_ctor(Sky* self, int p0, int p1, Reader* r, int n)
{
    int levelID;
    int itemID;
    float x;
    float y;
    float rot;
    unsigned char b;
    SkyDesc d;
    int skyLevel;
    unsigned char done;

    cSKYBOX_GOBJ_ctor(self);
    *(void**)self = D_004DAB20;
    if (n) {
        self->count = 0;
        done = 0;
        d.p0 = p0;
        d.p1 = p1;
        levelID = *(int*)r->cur; r->cur += 4;
        do {
            char* name;
            itemID = *(int*)r->cur; r->cur += 4;
            name = r->cur;
            while (*r->cur++)
                ;
            Align(r);
            d.ents[self->count].name = name;
            x = *(float*)r->cur; r->cur += 4;
            y = *(float*)r->cur; r->cur += 4;
            SetV(&d.ents[self->count].a, x, y, 0.0f, 0.0f);
            rot = *(float*)r->cur; r->cur += 4;
            SetV(&d.ents[self->count].b, 0.0f, 0.0f, rot, 0.0f);
            d.ents[self->count].flags = 0;
            b = *(unsigned char*)r->cur; r->cur += 1;
            if (b)
                d.ents[self->count].flags |= 0x10;
            else
                d.ents[self->count].flags |= 4;
            d.ents[self->count].flags |= 1;
            if (rot != 0.0f && !b)
                d.ents[self->count].flags |= 8;
            Align(r);
            self->count++;
            if (self->count == n) {
                done = 1;
            } else {
                skyLevel = *(int*)r->cur; r->cur += 4;
                if (skyLevel != levelID) {
                    cPopulation_Rewind(r, 4);
                    done = 1;
                }
            }
        } while (!done);
        d.count = self->count;
        self->id = itemID | (levelID << 16);
        self->p60 = p0;
        self->p64 = p1;
        self->Setup(&d);
        self->Finish(0);
    }
    return self;
}
static inline void merge_flush_func_001C5E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C5E50 */

/* merge_units: begin func_001C6140 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cGameSky_dtor, D_004DAB20, cSKYBOX_GOBJ_dtor)
static inline void merge_flush_func_001C6140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C6140 */
