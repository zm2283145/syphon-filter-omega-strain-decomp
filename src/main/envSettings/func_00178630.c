#pragma cplusplus on
#include "types.h"
struct V4_178630 { float x, y, z, w; };
struct LightBase_178630 { int f0; };
struct Light_178630 : LightBase_178630 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void SetColor(V4_178630* c); virtual void Apply();
};
struct V3_178630 { float x, y, z; };
struct Actor_178630 { char pad0[0xC]; unsigned int id; char pad10[0x49 - 0x10]; unsigned char type; };
struct It_178630 { Actor_178630** p; };
struct Vec_178630;
struct Reader_178630 { int version; int a, b; char* cur; };
struct EnvSettings_178630 {
    void* vt; char pad4[8]; int id; char pad10[0x60 - 0x10];
    float f60, f64, f68, f6C, f70, f74, f78; unsigned char b7C; char pad7D[3]; float f80;
    V3_178630 color; int collision[4]; Light_178630* light; Actor_178630* actor;
};
extern "C" {
extern char D_004D9E00[];
extern char D_004D9F10[];
extern char D_00535D20[];
void cGOBJ_ctor(EnvSettings_178630* obj, int* id, int kind, int* out);
Light_178630* LightMgr_AllocPoint(void* pool, int n, int id);
V4_178630* Vec4_SetFromVec3W(V4_178630* out, V3_178630* in, float w);
void LevelLight_CreateDirectional(Light_178630* l, int a, V4_178630* c);
int IdMgr_FindCollision(int region, int id);
void* World_GetActorArray(void);
Vec_178630* func_001339A0(void* arr);
void PtrVec_Begin(It_178630* out, Vec_178630* v);
void PtrVec_End(It_178630* out, Vec_178630* v);
void func_00133980(It_178630* out, It_178630* in);
}
static inline int Read_178630(Reader_178630* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt_178630(Reader_178630* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void ReadFloat_178630(Reader_178630* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void Align_178630(Reader_178630* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline int Ne_178630(It_178630* a, It_178630* b) { return (a->p == b->p) ^ 1; }
/* Environment settings object: reads light/fog parameters and finds the zone actor. */
extern "C" EnvSettings_178630* cEnvSettings_ctor(EnvSettings_178630* obj, Reader_178630* r)
{
    It_178630 end;
    It_178630 it;
    int gid;
    int out;
    It_178630 te;
    It_178630 tb;
    int ids[4];
    V4_178630 zero;
    V4_178630 tmp;
    int hi, lo, i;
    int* p;
    unsigned char find;
    Light_178630* l;
    out = 0;
    gid = 0;
    cGOBJ_ctor(obj, &gid, 7, &out);
    obj->vt = D_004D9E00;
    hi = Read_178630(r);
    lo = Read_178630(r);
    obj->id = lo | (hi << 16);
    ReadFloat_178630(r, &obj->f70);
    ReadFloat_178630(r, &obj->f74);
    ReadFloat_178630(r, &obj->f78);
    ReadFloat_178630(r, &obj->f68);
    ReadFloat_178630(r, &obj->f6C);
    ReadFloat_178630(r, &obj->f60);
    ReadFloat_178630(r, &obj->f64);
    ReadFloat_178630(r, &obj->color.x);
    ReadFloat_178630(r, &obj->color.y);
    ReadFloat_178630(r, &obj->color.z);
    l = LightMgr_AllocPoint(D_00535D20, 1, lo);
    if (l) {
        LevelLight_CreateDirectional(l, 1, Vec4_SetFromVec3W(&tmp, &obj->color, 0.0f));
        *(void**)((char*)l + 4) = D_004D9F10;
    }
    obj->light = l;
    if (obj->light) {
        zero.x = 0; zero.y = 0; zero.z = 0; zero.w = 0;
        obj->light->SetColor(&zero);
        obj->light->Apply();
    }
    ReadInt_178630(r, &ids[0]);
    ReadInt_178630(r, &ids[1]);
    ReadInt_178630(r, &ids[2]);
    ReadInt_178630(r, &ids[3]);
    obj->b7C = *(unsigned char*)r->cur;
    r->cur++;
    p = ids;
    Align_178630(r);
    if (r->version >= 0x37)
        ReadFloat_178630(r, &obj->f80);
    else
        obj->f80 = 0.45f;
    { int off; char* base = (char*)obj; for (i = 0, off = 0; i < 4; i++, p++, off += 4)
        *(int*)(base + 0x90 + off) = IdMgr_FindCollision(hi, *p); }
    obj->actor = 0;
    if (r->version >= 0x3A) {
        find = *(unsigned char*)r->cur;
        r->cur++;
        Align_178630(r);
    } else {
        find = 1;
    }
    if (find) {
        void* arr = World_GetActorArray();
        PtrVec_End(&te, func_001339A0(arr));
        func_00133980(&end, &te);
        PtrVec_Begin(&tb, func_001339A0(arr));
        func_00133980(&it, &tb);
        while (Ne_178630(&it, &end)) {
            Actor_178630* a = *it.p;
            if (a->type == 5 && hi == (a->id & 0xFF0000) >> 16) {
                obj->actor = a;
                break;
            }
            it.p++;
        }
    }
    return obj;
}