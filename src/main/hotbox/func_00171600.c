#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
struct V4_1600 { __int128 q;
    V4_1600() {}
    V4_1600(const V4_1600& o) { const __int128* s = &o.q; __int128* d = &q; __int128 t; asm {  lq t, 0(s) } asm {  sq t, 0(d) } } };
struct M4_1600 { V4_1600 r[4];
    M4_1600() {}
    M4_1600(const M4_1600& o) { const __int128* s = &o.r[0].q; __int128* d = &r[0].q; __int128 qa, qb;
        asm { .set reorder;
            lq qa, 0x0(s)
            lq qb, 0x10(s)
            sq qa, 0x0(d)
            lq qa, 0x20(s)
            sq qb, 0x10(d)
            lq qb, 0x30(s)
            sq qa, 0x20(d)
            sq qb, 0x30(d)
        } } };
struct Trk_1600 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC]; M4_1600 mat; unsigned char active; };
typedef struct { char pad[0x14]; unsigned char on; char pad15[0x3B]; Trk_1600* trk; } Src_1600;
typedef struct { char pad[0x20]; Src_1600* src; } HT_1600;
extern "C" int* Event_GetType(void* e);
extern "C" int D_005436B0;
extern "C" void Hotbox_UpdateTracker(HT_1600* self, V4_1600 pos, int f);
static inline V4_1600 Trans_1600(M4_1600 m) { return m.r[3]; }
static inline V4_1600 TransR_1600(const M4_1600& m) { return m.r[3]; }
extern "C" int HotboxTracker_HandleMessage(HT_1600* self, void* e)
{
    int ty = *Event_GetType(e);
    if (ty == D_005436B0) {
        Src_1600* s = self->src;
        if (s && s->on) {
            Trk_1600* t = s->trk;
            if (t->active) t->Update();
            M4_1600 m(t->mat);
            Hotbox_UpdateTracker(self, TransR_1600(m), 0);
        }
        return 1;
    }
    return 0;
}
