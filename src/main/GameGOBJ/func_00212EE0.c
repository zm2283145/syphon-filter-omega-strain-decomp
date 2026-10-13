#pragma cplusplus on
#pragma exceptions off
/* undocumented mwcc pragma: keeps the temp handle copy as addiu+lw 0(reg) like retail */
#pragma opt_prelinearize off
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
struct V4 { float x, y, z, w; };
struct Mtx { V4 r[4]; };
struct H_212EE0 { int v; };
struct HT_212EE0 { int v; HT_212EE0() { v = -1; } };
struct Act_212EE0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_212EE0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
    char pad187[9];
};
struct Node_212EE0 { int a; int b; int c; };
struct Reader { int version; int a, b; char* cur; };
struct SoundGOBJ {
    VPAD16(a) VPAD4(b) VPAD2(c) virtual void Enable(int); VPAD8(d) VPAD2(e) VPAD1(f) virtual void SetMatrix(Mtx*, int);
    char p4[8]; int id; char p10[8]; Node_212EE0* node; char p1c[0x60 - 0x1C];
    Act_212EE0 snd;
    unsigned char b1F0; unsigned char type; unsigned char b1F2;
};
extern "C" {
extern char D_004F54B8[], D_004DAF30[], D_0049C088[];
void cGOBJ_ctor(SoundGOBJ*, int*, int, void*);
void func_0036E5D0(void* m);
void* Mem_Alloc(int, int, char*, int);
void func_003D9D30(Node_212EE0* n, char* name);
void Mtx_SetBasis(Mtx* m, V4* a, V4* b, V4* c);
void Mtx_SetTranslation(Mtx* m, V4* t);
void SoundAction_CtorVoice(void* action, int kind, char* name, void* a, int b);
void func_003CDF20(SoundGOBJ*);
int IdMgr_FindCollision(int, int);
void ZoneMgr_Associate(int, SoundGOBJ*, int, int);
}
static inline int Read(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(Reader* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF(Reader* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void Align(Reader* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline void ReadV(Reader* r, V4* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x; v->y = y; v->z = z; v->w = w;
}
#pragma push
//#pragma opt_propagation off
extern "C" SoundGOBJ* cSoundGOBJ_ctor(SoundGOBJ* obj, Reader* r, unsigned char type)
{
    int regions[0x100];
    int ids[0x100];
    V4 r0, r1, r2, pos;
    Mtx m;
    int hi, lo, n, i, ver;
    char* name;
    char* tag;
    Act_212EE0* p;
    int gid = -1;
    cGOBJ_ctor(obj, &gid, 0xB, D_004F54B8);
    *(void**)obj = D_004DAF30;
    p = &obj->snd;
    obj->snd.h24.v = -2;
    obj->snd.w20 = 0;
    func_0036E5D0(p->memberA);
    func_0036E5D0(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    p->h24 = *(H_212EE0*)&HT_212EE0();
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    ReadInt(r, &hi);
    ReadInt(r, &lo);
    name = r->cur;
    while (*r->cur++) ;
    Align(r);
    tag = r->cur;
    while (*r->cur++) ;
    if (tag) {
        if (!obj->node) {
            Node_212EE0* nd;
            {
                AllocGuard g;
                nd = (Node_212EE0*)Mem_Alloc(0, 12, D_0049C088, 0x49);
            }
            if (nd) { nd->a = 0; nd->b = 0; nd->c = -1; }
            obj->node = nd;
        }
        func_003D9D30(obj->node, tag);
    }
    Align(r);
    ReadV(r, &pos, 1.0f);
    ReadV(r, &r0, 0.0f);
    ReadV(r, &r1, 0.0f);
    ReadV(r, &r2, 0.0f);
    Mtx_SetBasis(&m, &r0, &r1, &r2);
    Mtx_SetTranslation(&m, &pos);
    obj->id = lo | (hi << 16);
    n = Read(r);
    for (i = 0; i < n; i++) {
        ReadInt(r, &regions[i]);
        ReadInt(r, &ids[i]);
    }
    obj->type = type;
    obj->b1F2 = *(unsigned char*)r->cur;
    r->cur++;
    Align(r);
    ver = 0;
    if (r->version > 0x34) ver = Read(r);
    SoundAction_CtorVoice(&obj->snd, ver, name, obj, 0);
    func_003CDF20(obj);
    obj->SetMatrix(&m, 0);
    obj->Enable(1);
    for (i = 0; i < n; i++) {
        if (regions[i] != -1 && ids[i] != -1) {
            int c = IdMgr_FindCollision(regions[i], ids[i]);
            if (c) ZoneMgr_Associate(c, obj, 1, c);
        }
    }
    obj->b1F0 = 0;
    return obj;
}
#pragma pop


