#include "types.h"

typedef struct ModelDef {
    int unk00;
    char roots[0x50];   /* 0x04 */
    int channelCount;   /* 0x54 */
    int pairCount;      /* 0x58 */
} ModelDef;

typedef struct ModelInst {
    char pad00[0x24];
    ModelDef* def;      /* 0x24 */
    char pad28[0x50];
    char channels[0x10];/* 0x78 */
    char pairs[0x18];   /* 0x88 */
    char roots[4];      /* 0xA0 */
} ModelInst;

typedef struct AnimChannel {
    char data[0x48];
} AnimChannel;

typedef struct IntPair2 {
    int a, b;
} IntPair2;

extern void RootCollection_InitFromModel(void* roots, void* src);
extern void AnimChannel_Construct(AnimChannel* ch);
extern void AnimChannels_ClearCount(AnimChannel* ch, float t);
extern void ChannelVector_Resize(void* vec, int count, AnimChannel* fill);
extern void func_001AEFE0(AnimChannel* ch, int flags);
extern void func_001BE020(void* vec, int count, IntPair2* fill);

/* Attaches a model definition: roots, animation channels and pair table. */
void Model_Attach(ModelInst* inst, ModelDef* def) {
    AnimChannel ch;
    IntPair2 pair;
    inst->def = def;
    RootCollection_InitFromModel(inst->roots, def->roots);
    AnimChannel_Construct(&ch);
    AnimChannels_ClearCount(&ch, 0.0f);
    ChannelVector_Resize(inst->channels, def->channelCount, &ch);
    func_001AEFE0(&ch, -1);
    pair.a = 0;
    pair.b = 0;
    func_001BE020(inst->pairs, def->pairCount, &pair);
}
