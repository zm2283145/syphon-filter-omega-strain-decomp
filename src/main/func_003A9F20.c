#include "types.h"

typedef struct ModelSrc {
    int** model;  /* 0x00 */
    int unk04;    /* 0x04 */
} ModelSrc;

typedef struct ModelCtx {
    int** model;          /* 0x00 */
    char scales[0x10];    /* 0x04 */
    unsigned char hasSkel;/* 0x14 */
    char pad15[0x13];
    int unk28;            /* 0x28 */
} ModelCtx;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern void BoneScales_Init(void* scales, int* bones, Vec3f* scale);
extern void SkelNodes_Construct(ModelCtx* ctx);

/* Initializes a model context from src with unit bone scale. */
void ModelCtx_Init(ModelCtx* ctx, ModelSrc* src) {
    Vec3f scale;
    ctx->model = src->model;
    ctx->unk28 = src->unk04;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    BoneScales_Init(ctx->scales, *ctx->model, &scale);
    if (ctx->hasSkel) {
        SkelNodes_Construct(ctx);
    }
}
