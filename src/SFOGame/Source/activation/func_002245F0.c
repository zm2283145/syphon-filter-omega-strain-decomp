#pragma cplusplus on
#pragma opt_propagation off
#pragma always_inline on
#pragma inline_depth(8)
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Box { V mn; V mx; };
static inline int InBox(const V* p, const Box* b) {
    const V* hi = &b->mx;
    int r;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(b)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
extern "C" void std_vector_cGOBJPtr_ctor_void(void*);
extern "C" void cArray_cGOBJPtr_dtor(void*);
struct cArray { int a, b, c; unsigned char mCanExpand; };
static inline void cArray_Construct(cArray* t) { std_vector_cGOBJPtr_ctor_void(t); t->mCanExpand = 1; }
struct cHandle { int v; cHandle(int x) : v(x) {} };
struct cTerrain {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box* GetBounds();
    char pad04[8];
    cHandle mHandle;
    char pad10[0x1E4];
    cArray mActivationList;
};
struct cSafePtr {
    cTerrain* volatile mPtr;
    cHandle mHandle;
    bool IsNull() const { return !mPtr; }
    bool Matches() const { return mPtr->mHandle.v == mHandle.v; }
    bool Matches(cTerrain* p) const { return p->mHandle.v == mHandle.v; }
    bool IsValid() const { cTerrain* p = mPtr; return !p || Matches(p); }
    cTerrain* Raw() const { return mPtr; }
    cTerrain* Get() const { bool v = IsValid(); if (v) return Raw(); return 0; }
    void Set(cTerrain* p) { mPtr = p; mHandle = p ? p->mHandle : cHandle(-1); }
};
struct cActivationTracker { V position; cSafePtr terrainPiece; };
static inline bool InTerrain(cActivationTracker* t) { return t->terrainPiece.Get() ? (unsigned char)InBox(&t->position, t->terrainPiece.Get()->GetBounds()) : 0; }
extern "C" {
extern signed char D_004F7518;
extern cArray D_004A5B00;
extern char D_004F7520[];
void std_vector_cGOBJPtr_ctor_void(void*);
void __register_global_object(void* obj, void* dtor, void* link);
cTerrain* nActivation_FindBestSectorInActivation(const V* p, cTerrain* t);
cTerrain* nActivation_GetClosestTerrainPiece(const V* p);
cArray* nActivation_GetActivationFor(cActivationTracker* t);
}
cArray* nActivation_GetActivationFor(cActivationTracker* t)
{
    cTerrain* terrainPiece;
    if (!D_004F7518) {
        cArray* o = &D_004A5B00;
        cArray_Construct(o);
        __register_global_object(o, (void*)cArray_cGOBJPtr_dtor, D_004F7520);
        D_004F7518 = 1;
    }
    if (InTerrain(t)) {
        terrainPiece = t->terrainPiece.Get();
    } else {
        terrainPiece = nActivation_FindBestSectorInActivation(&t->position, t->terrainPiece.Get());
        if (!terrainPiece)
            terrainPiece = nActivation_GetClosestTerrainPiece(&t->position);
        t->terrainPiece.Set(terrainPiece);
    }
    return terrainPiece ? &terrainPiece->mActivationList : &D_004A5B00;
}