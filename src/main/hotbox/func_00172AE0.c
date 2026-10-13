#pragma cplusplus on
#pragma exceptions off
#include "types.h"
#include "vslot_pad.h"
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { V4 r[4]; };
struct H_172AE0 { int v; };
struct Reader { int version; int a, b; char* cur; };
struct Msg_172AE0 { void* vt; char pad[0x18]; int f1c; unsigned char b20; char p21[3]; int f24; int f28; int f2c; };
struct Leaf_172AE0 { char pad[0x68]; int f68; PtrVec f6C; char pad78[0x118 - 0x78]; PtrVec f118; };
struct Item_172AE0 { char pad[0x49]; unsigned char f49; char pad4A[0x4E]; PtrVec f98; };
struct Items_172AE0 { int unk0; int count; Item_172AE0** data; unsigned char bC; };
struct Hotbox {
    VPAD16(a) VPAD4(b) VPAD2(c) virtual void Enable(int); VPAD8(d) VPAD2(e) VPAD1(f) virtual void SetMatrix(Mtx*, int);
    char p4[8]; H_172AE0 hC; H_172AE0 h10; unsigned char b14; char p15[0x2C - 0x15]; unsigned char b2C; char p2D[0x60 - 0x2D];
    Items_172AE0 items;
    V4 bmin;
    V4 bmax;
    int type;
    int f94;
    int f98;
    int f9C;
    int fA0;
};
extern "C" {
extern char D_004EE6B8[];
extern char D_004D9AC0[];
extern char D_004E0860[];
extern char g_cDisableMsgClass[];
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
void cGOBJ_ctor(Hotbox*, int*, int, void*);
void func_001365C0(Items_172AE0*);
void Mtx_SetBasis(Mtx* m, V4* a, V4* b, V4* c);
void Mtx_SetTranslation(Mtx* m, V4* t);
int IdMgr_FindCollision(int, int);
void ZoneMgr_Associate(int, Hotbox*, int, int);
void func_00171C70(Items_172AE0*, int*);
void Event_Construct(void*, char*);
void Event_Send(void*, int, int);
void cMessage_dtor(void*, int);
int* func_00171EA0(PtrVec* v, int i);
int func_00171EB0(PtrVec* v);
Item_172AE0*** func_00171EC0(Items_172AE0* v);
int func_001734D0(PtrVec* v, Hotbox** value);
int NetMap_BindReceiver(int, int, Hotbox*);
int NetGame_InitLocalSlot(int*, int);
int func_002EBBA0(int, int*);
}
static inline int Read(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(Reader* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF(Reader* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void ReadV(Reader* r, V4* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x; v->y = y; v->z = z; v->w = w;
}
static inline void QR(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void GC1L(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline void Init(Msg_172AE0* pm) { Event_Construct(pm, g_cDisableMsgClass); pm->vt = D_004E0860; pm->f24 = -1; pm->f1c = 0x40; }
static inline bool IsIdent(float* m) {
    return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
           m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
           m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
           m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
}
static inline Leaf_172AE0* First(PtrVec* v) { return func_00171EB0(v) ? (Leaf_172AE0*)*func_00171EA0(v, 0) : 0; }
static inline unsigned char IsLocal(void) { unsigned char v; if (D_005721C8) v = D_005721C0; else v = 1; return v; }
#pragma inline_depth(10)
static inline int LocalId() { int r=0;int a=D_005721A8;if(D_005721C8) { if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
extern "C" Hotbox* cHotbox_ctor(Hotbox* self, Reader* r, int type)
{
    int c;
    H_172AE0 id;
    int gid = -1;
    V4 vmin;
    V4 vmax;
    int regions[0x100];
    int ids[0x100];
    V4 r0, r1, r2, pos;
    Mtx m;
    V4 zero;
    Msg_172AE0 msg;
    int hi, lo, n, i, n2, j;
    int tmp;
    Msg_172AE0* pm;
    cGOBJ_ctor(self, &gid, 8, D_004EE6B8);
    *(void**)self = D_004D9AC0;
    { Items_172AE0* it = &self->items; func_001365C0(it); it->bC = 1; }
    self->bmin.x = 3.4028235e38f;
    self->bmin.y = 3.4028235e38f;
    self->bmin.z = 3.4028235e38f;
    self->bmin.w = 1.0f;
    self->bmax.x = -3.4028235e38f;
    self->bmax.y = -3.4028235e38f;
    self->bmax.z = -3.4028235e38f;
    self->bmax.w = 1.0f;
    self->f98 = 0;
    self->fA0 = 0;
    self->f9C = 10;
    hi = Read(r);
    lo = Read(r);
    n = Read(r);
    for (j = 0; j < n; j++) {
        ReadInt(r, &regions[j]);
        ReadInt(r, &ids[j]);
    }
    if (r->version < 0x36) type = Read(r);
    ReadInt(r, &self->f94);
    ReadV(r, &vmin, 1.0f);
    ReadV(r, &vmax, 1.0f);
    if (r->version >= 0x3D) {
        ReadV(r, &r0, 0.0f);
        ReadV(r, &r1, 0.0f);
        ReadV(r, &r2, 0.0f);
        ReadV(r, &pos, 1.0f);
        zero.x = 0.0f; zero.y = 0.0f; zero.z = 0.0f; zero.w = 1.0f;
        Mtx_SetBasis(&m, &r0, &r1, &r2);
        Mtx_SetTranslation(&m, &zero);
        if (!IsIdent(&m.r[0].x)) {
            Mtx_SetBasis(&m, &r0, &r1, &r2);
            Mtx_SetTranslation(&m, &pos);
            self->SetMatrix(&m, 0);
        }
    }
    self->type = type;
    GC1L(&self->bmin, &vmin);
    QR(&self->bmax, &vmax);
    n2 = Read(r);
    for (i = 0; i < n2; i += 2) {
        int a = Read(r);
        int b = Read(r);
        c = IdMgr_FindCollision(a, b);
        if (c) {
            func_00171C70(&self->items, &c);
            if (self->type == 1 || self->type == 6 || self->type == 7) {
                pm = &msg;
                Init(pm);
                Event_Send(&msg, c, 0);
                msg.vt = D_004E0860;
                cMessage_dtor(&msg, 0);
            }
        }
    }
    id.v = lo | (hi << 16);
    self->hC = id;
    for (i = 0; i < n; i++) {
        if (regions[i] > 0) {
            int c2 = IdMgr_FindCollision(regions[i], ids[i]);
            if (c2) ZoneMgr_Associate(c2, self, 0, 0);
        } else if (regions[i] == -1 && ids[i] == -1) {
            self->b2C = 0;
        }
    }
    if (self->type == 8) {
        for (i = 0; i < self->items.count; i++) {
            if (self->items.data[i]->f49 == 0xE) {
                Item_172AE0* it = (*func_00171EC0(&self->items))[i];
                if (First(&it->f98)) {
                    Item_172AE0* it2 = self->items.data[i];
                    Leaf_172AE0* lf = First(&it2->f98);
                    if (lf->f68 == 3) {
                        Hotbox* s = self;
                        func_001734D0(&lf->f118, &s);
                    }
                }
            }
        }
    }
    self->h10 = id;
    if (!IsLocal()) self->b14 = 0;
    if (D_005721C8) {
        int t = self->h10.v;
        int nid;
        if (IsLocal()) nid = LocalId(); else { func_002EBBA0(D_005721A8, &tmp); nid = tmp; }
        NetMap_BindReceiver(t, nid, self);
    }
    return self;
}
