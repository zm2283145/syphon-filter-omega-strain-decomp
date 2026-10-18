/*
 * main/hotbox: range (2 files, 00172A60-00172AE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_member_base_dtor.h"
#pragma pop
#include "vslot_pad.h"

/* merge_units: begin func_00172A60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: member, then base, optionally delete. */
extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseLogicUpdate();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Hotbox_Contains();
extern "C" void Node_GetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cHotbox_v01();
extern "C" void cHotbox_v43();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C0A0();
extern "C" void Hotbox_Disable();
extern "C" void Hotbox_Enable();
extern "C" void func_0016FE50();
extern "C" void Hotbox_ScriptFilter();
extern "C" void func_001729A0();
extern "C" void func_001729B0();
extern "C" void func_00173640();
extern "C" void func_00173650();
extern "C" void Hotbox_GetBounds();
extern "C" void Hotbox_Enable_173670();
extern "C" void func_00173680();
extern "C" void func_00173690();
extern "C" void func_001736A0();
extern "C" void func_001736B0();
extern "C" void GObj_GetWorldMatrix();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void func_003CD4A0();
extern "C" void Node_GetWorldMatrix();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CEA00();
extern void * const D_004D9AC0[];
void* func_001363C0(void* self, short deleteFlag);
void* cGOBJ_dtor(void* self, short deleteFlag);
}
extern "C" VtableMemberObject* cHotbox_dtor(VtableMemberObject* self,
                                    short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9AC0);
        char* member = (char*)self + (0x60);
        if (member)
            func_001363C0(member, -1);
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9AC0[72] = { (void*)0x0, (void*)0x0, (void*)cHotbox_dtor, (void*)cHotbox_v01, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_001736B0, (void*)func_0012ED00, (void*)func_00173690, (void*)func_001736A0, (void*)Hotbox_Enable_173670, (void*)func_00173680, (void*)func_001729B0, (void*)func_0016FE50, (void*)Hotbox_ScriptFilter, (void*)func_003CEA00, (void*)func_00173640, (void*)func_00173650, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_001729A0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Hotbox_Enable, (void*)Hotbox_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)Hotbox_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)Hotbox_Contains, (void*)cHotbox_v43, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00172A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00172A60 */

/* merge_units: begin func_00172AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
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
#if 0 /* merge_units */
extern char D_004D9AC0[];
#endif /* merge_units */
#define D_004D9AC0 ((char*)&D_004D9AC0) /* merge_units */

extern char D_004E0860[];
extern char g_cDisableMsgClass[];
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
void cGOBJ_ctor(Hotbox*, int*, int, void*);
void PtrVec_InitEmpty(Items_172AE0*);
void Mtx_SetBasis(Mtx* m, V4* a, V4* b, V4* c);
void Mtx_SetTranslation(Mtx* m, V4* t);
int IdMgr_FindCollision(int, int);
void ZoneMgr_Associate(int, Hotbox*, int, int);
void PtrVec_PushBack_171C70(Items_172AE0*, int*);
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
    { Items_172AE0* it = &self->items; PtrVec_InitEmpty(it); it->bC = 1; }
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
            PtrVec_PushBack_171C70(&self->items, &c);
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
#undef D_004D9AC0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00172AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00172AE0 */
