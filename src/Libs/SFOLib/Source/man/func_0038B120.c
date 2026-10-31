// cMan::GetLocal2ScreenMatrix(cMatrix&, const cMatrix&) @ 0x0038B120 (lane k3)
// scaleNOffsetMatrix = cMatrix(cMatrix(16 floats), cVector) per prototype out-of-line ctors.
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct cMatrix {
    float m[4][4];
    cMatrix() {}
    cMatrix(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }
    cMatrix(const cMatrix& o, const cVector& t) {
        m[0][0] = o.m[0][0]; m[0][1] = o.m[0][1]; m[0][2] = o.m[0][2];
        m[1][0] = o.m[1][0]; m[1][1] = o.m[1][1]; m[1][2] = o.m[1][2];
        m[2][0] = o.m[2][0]; m[2][1] = o.m[2][1]; m[2][2] = o.m[2][2];
        m[0][3] = o.m[0][3]; m[1][3] = o.m[1][3]; m[2][3] = o.m[2][3];
        *(cVector*)m[3] = t;
    }
} __attribute__((aligned(16)));

struct cXViewport;
extern "C" void cXViewport_Validate(const cXViewport* vp);

struct cXViewport {
    char win[16];
    cMatrix orthoMat;
    cMatrix perspMat;
    cVector scale;
    cVector offset;
    char padB0[0x104 - 0xB0];
    unsigned char isOrtho;
    unsigned char isOnScreen;
    unsigned char isDirty;
    unsigned long scissorReg;
    void Validate() const { cXViewport_Validate(this); }
    const cVector& GetScale() const { Validate(); return scale; }
    const cVector& GetOffset() const { Validate(); return offset; }
    const cMatrix& GetProjMatrix() const { Validate(); if (isOrtho) return orthoMat; return perspMat; }
};

struct cXVideo {
    char pad[0x1F0];
    cXViewport viewports[1];
};

extern "C" {
extern cXVideo g_Video;
extern int D_00538C60;
extern float D_00538258[];
extern float D_00538268[];
extern int D_00538278;
extern cMatrix g_IdentityMatrix;
extern cMatrix D_00539070;
}

static inline cXViewport& GetViewport() { return g_Video.viewports[D_00538C60]; }
static inline const cMatrix& GetScreenMatrix() { if (GetViewport().isOrtho) return g_IdentityMatrix; return D_00539070; }

static inline void MatMul(cMatrix& d, const cMatrix& a, const cMatrix& b) { __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf7, 0x30(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(&d), "r"(&b), "r"(&a) : "memory"); }

static inline void MatMul2(cMatrix& d, const cMatrix& b, const cMatrix& a) { MatMul(d, a, b); }
extern "C" void cMan_GetLocal2ScreenMatrix(cMatrix& local2ScreenMatrix, const cMatrix& local2CameraMatrix)
{
    cMatrix camera2ScreenMatrix;
    cXViewport& viewPort = GetViewport();
    cVector scale = viewPort.GetScale();
    cVector offset = viewPort.GetOffset();
    float diagScaleX = 0.0625f / (float)D_00538258[D_00538278];
    float diagScaleY = 0.0625f / D_00538268[D_00538278];
    cMatrix scaleNOffsetMatrix(cMatrix(diagScaleX * scale.x, 0.0f, 0.0f, 0.0f,
                                       0.0f, diagScaleY * scale.y, 0.0f, 0.0f,
                                       0.0f, 0.0f, 0.0625f * scale.z, 0.0f,
                                       0.0f, 0.0f, 0.0f, 1.0f),
                               cVector(0.0625f * offset.x, 0.0625f * offset.y, 0.0625f * offset.z, 1.0f));
    MatMul2(camera2ScreenMatrix, GetScreenMatrix(), viewPort.GetProjMatrix());
    MatMul(camera2ScreenMatrix, scaleNOffsetMatrix, camera2ScreenMatrix);
    MatMul(local2ScreenMatrix, camera2ScreenMatrix, local2CameraMatrix);
}
