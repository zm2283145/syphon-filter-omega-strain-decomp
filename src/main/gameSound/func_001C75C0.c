/* cGameSound_AddToPlaylist: find a free voice slot (stopping finished streamed
 * voices on the way), initialise it from the request and mark it in use. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Q16 { __int128 q; };
struct Obj { char p0[0xC]; int serial; char p10[0x49 - 0x10]; unsigned char b49; char p4A[0x2DC8 - 0x4A]; int x2DC8; };
struct Ref { Obj* obj; int serial; };
struct Inst {
    int kind; char p4[0xC]; Q16 v10; Ref ref; char p28[8]; V pos; int busy; unsigned char used; char p45[0xE4 - 0x45];
    char stream[0x178 - 0xE4]; unsigned char b178; char p179[7]; int x180; short x184; unsigned char b186; char p187[0x190 - 0x187];
};
struct Req {
    int kind; char p4[0xC]; Q16 v10; Ref ref; char p28[8]; V pos; char p40[0x180 - 0x40]; int x180; char p184[2]; unsigned char b186;
};
struct Slot { int f0; int f4; char p8[0xC]; unsigned char b14; char p15[0xB]; Inst in; };
struct SoundMgr { char p0[0x30]; Slot slots[50]; };
extern "C" {
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void* ld, void* s, int f);
Obj* cSafePtr_cGOBJ_opCast_cGOBJPtr(Ref* r);
Inst* cGameSound_AddToPlaylist(SoundMgr* self, Req* req, unsigned char flag);
}
static inline bool Eq(int a, int b) { return a == b; }
/* weak reference: object if its serial still matches, else 0 */
static inline Obj* Get(Ref* r)
{
    unsigned char v = !r->obj || Eq(r->obj->serial, r->serial);
    return v ? r->obj : 0;
}
/* header copy: the quadword is loaded before the kind store (retail order) */
static inline void SetHdr(Inst* d, Req* r) { int k; __int128 t = r->v10.q; k = r->kind; d->kind = k; d->v10.q = t; }
static inline const int& IdOf(Obj* p) { if (p) return p->serial; int m = -1; return m; }

Inst* cGameSound_AddToPlaylist(SoundMgr* self, Req* req, unsigned char flag)
{
    int found = -1;
    Inst* s = 0;
    int i;
    for (i = 0; i < 50; i++) {
        Inst* p = &self->slots[i].in;
        if (p->kind == 4 && !p->used && !p->busy && p->b178) {
            Obj* o = Get(&p->ref);
            if (o && o->b49 == 2)
                o->x2DC8 = 0;
            { void* st = p->stream; cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), st, 1); }
        }
        if (!p->busy && !p->used) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        s = &self->slots[found].in;
        if (Get(&req->ref)) {
            int x = req->x180;
            Obj* o = cSafePtr_cGOBJ_opCast_cGOBJPtr(&req->ref);
            SetHdr(s, req);
            s->ref.obj = o;
            s->ref.serial = IdOf(o);
            s->pos.x = 0.0f;
            s->pos.y = 0.0f;
            s->pos.z = 0.0f;
            s->used = flag;
            s->x184 = -1;
            s->x180 = x;
        } else {
            V t = req->pos;
            int x = req->x180;
            SetHdr(s, req);
            s->ref.obj = 0;
            s->ref.serial = IdOf(0);
            s->pos = t;
            s->used = flag;
            s->x184 = -1;
            s->x180 = x;
        }
        s->b186 = req->b186;
        s->x184 = found;
        self->slots[found].f0 = 0;
        self->slots[found].f4 = 0;
        self->slots[found].b14 = 1;
    }
    return s;
}
