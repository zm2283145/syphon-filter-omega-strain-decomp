/* cCollisionFace::SetWithoutCalculatingNormal (game.cc). GetVertex forwards
 * cCollisionModel -> cCollisionModelMaster -> cCollisionModel_Data; the full
 * three-level inline chain is needed for the retail register choice. */
#pragma cplusplus on
#pragma inline_depth(8)

struct cVector {
    float x, y, z, w;
    cVector() {}
    // 16-byte lq/sq copy idiom
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    float* W() { return &w; }
};
struct cMatrix { float m[4][4]; };

// VU0 macro-mode matrix * vector (COP2), not expressible in C
static inline void Apply(cVector* o, const cMatrix* m, const cVector* v)
{
    __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}

struct cXform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0xC];
    cMatrix localToWorldMatrix;
    unsigned char needsUpdate;
    cMatrix& GetMatrix() { if (needsUpdate) Update(); return localToWorldMatrix; }
};

struct cCollisionModelMaster;
struct cGOBJ { char pad[0x50]; cXform* xform; };

struct cCollisionModelMaster; struct cCollisionModel_Data;
struct cCollisionModelAddress { int off; cCollisionModelAddress(const cCollisionModelAddress& o) { off = o.off; } };
extern "C" cVector* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(cCollisionModel_Data* m, cCollisionModelAddress it);
struct cCollisionModel_Data { char pad[0x20]; cCollisionModelAddress mVertices;
    cVector& GetVertex(int index) { return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(this, mVertices)[index]; }
};

struct cCollisionModel {
    cGOBJ* parentGobj;
    cCollisionModelMaster* mMaster;
    cVector& GetVertex(int index) const;
    cXform* GetXform() const { return parentGobj->xform; }
};

struct cCollisionModelMaster { cCollisionModel_Data* mData; cVector& GetVertex(int index) const { return mData->GetVertex(index); } };
inline cVector& cCollisionModel::GetVertex(int index) const { return mMaster->GetVertex(index); }
struct cCollisionModel_Face {
    float mNormalScale;
    unsigned short vertices[3];
    unsigned char faceFlags[4];
    static bool Bit(int v) { return (v & 0x80) != 0; }
    bool IsCamPassThru() const { return Bit(0); }
    bool IsReceiveShadow() const { return Bit(faceFlags[1]); }
    bool IsReceiveReflection() const { return Bit(faceFlags[2]); }
};

struct cCollisionModel_FaceProperties {
    int properties[4];
    cCollisionModel_FaceProperties& operator=(const cCollisionModel_FaceProperties& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
};

struct cCollisionModel_FaceLocator {
    unsigned int index;
    const cCollisionModel* model;
    int pad[2];
    void Set(unsigned int i, const cCollisionModel& m) { index = i; model = &m; }
};

struct cCollisionFace {
    cVector vertices[3];
    cVector unitNormal;
    cCollisionModel_FaceProperties faceProperties;
    unsigned char isCamPassThru;
    unsigned char isReceiveShadow;
    unsigned char isReceiveReflection;
    char pad53[0xD];
    cCollisionModel_FaceLocator faceLocator;
};

extern "C" void cCollisionFace_SetWithoutCalculatingNormal(cCollisionFace* self, const cCollisionModel_Face& face, unsigned int iFaceIndex, const cCollisionModel_FaceProperties& iFaceProperties, const cCollisionModel& parentModel)
{
    self->vertices[0] = parentModel.GetVertex(face.vertices[0]);
    self->vertices[1] = parentModel.GetVertex(face.vertices[1]);
    self->vertices[2] = parentModel.GetVertex(face.vertices[2]);
    *self->unitNormal.W() = face.mNormalScale;
    cXform* xform = parentModel.GetXform();
    if (xform) {
        cMatrix& matrix = xform->GetMatrix();
        Apply(&self->vertices[0], &matrix, &self->vertices[0]);
        Apply(&self->vertices[1], &matrix, &self->vertices[1]);
        Apply(&self->vertices[2], &matrix, &self->vertices[2]);
    }
    self->faceProperties = iFaceProperties;
    self->isCamPassThru = face.IsCamPassThru();
    self->isReceiveShadow = face.IsReceiveShadow();
    self->isReceiveReflection = face.IsReceiveReflection();
    self->faceLocator.Set(iFaceIndex, parentModel);
}







