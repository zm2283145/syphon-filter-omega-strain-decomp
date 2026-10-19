#pragma cplusplus on
#include "types.h"
/* func_003B1290: add a clip's contribution to a channel, merging it into an existing entry for the same clip */
struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
typedef struct { char pad[0x45]; unsigned char b45; } Obj;
typedef struct { Obj* id; float weight; unsigned char active; char pad[7]; V4 v; } Ent;
typedef struct { int cap; int count; Ent* data; } EVec;
typedef struct Contrib {
    int id;
    EVec vec;
    int pad10;
    unsigned char active;
    char pad15[3];
    float sum;
    float wsum;
    int f20[3];
    int f2C;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
} Contrib;
extern "C" {
Ent** func_003B14D0(EVec* v);
Ent* func_003B14A0(Ent* d, Ent* s);
V4 func_003B1450(Ent* e);
V4 Vec4_Add_3B1420(V4* a, V4* b);
V4* Quat_Assign(V4* d, V4* s);
int func_003B7470(EVec* v, Ent* pos, int n, Ent* value);
void func_003B1290(Contrib* c, Ent* e, float k);
}
static inline bool Ne(Ent* a, Ent* b) { return !(a == b); }
void func_003B1290(Contrib* c, Ent* e, float k)
{
    bool found = 0;
    float w = e->weight;
    c->active = 1;
    c->sum += w;
    c->wsum += k * w;
    Ent* it = *func_003B14D0(&c->vec);
    Ent* end = *func_003B14D0(&c->vec) + c->vec.count;
    while (Ne(it, end)) {
        if (it->id == e->id) {
            if (it->weight == 0.0f) {
                func_003B14A0(it, e);
            } else {
                Quat_Assign(&it->v, &Vec4_Add_3B1420(&func_003B1450(it), &func_003B1450(e)));
                it->weight += e->weight;
                it->active = 0;
            }
            found = 1;
            break;
        }
        it++;
    }
    if (!found) {
        func_003B7470(&c->vec, c->vec.data + c->vec.count, 1, e);
        c->f32 = c->f32 && e->id->b45;
    }
}
