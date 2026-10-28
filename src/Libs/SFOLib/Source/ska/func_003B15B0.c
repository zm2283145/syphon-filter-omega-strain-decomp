/* cSkaPlaybackItem::Accumulate: first contribution is copied; otherwise summed root rotations (weighted when still unweighted) and weights. Dead 'xx = this' locals keep retail's dead addius. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma peephole off
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    V operator*(float k) const;
    V operator+(const V& o) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { int r; const V* ss = s; asm {
        .set noreorder
        lqc2 vf1, 0x0(ss)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } }
static inline void AddTo(V* d, const V* a, const V* b) { asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
inline V V::operator+(const V& o) const { V t; AddTo(&t, this, &o); return t; }
struct cSkaPlaybackItem {
    void* mAnimation;
    float mSummedWeight;
    unsigned char mIsSummedOffsetRootRotationUnweightedAndNormalized;
    V mSummedOffsetRootRotation;
    V GetWeighted() const {
        if (mIsSummedOffsetRootRotationUnweightedAndNormalized)
            return mSummedOffsetRootRotation * mSummedWeight;
        return mSummedOffsetRootRotation;
    }
};
extern "C" void cSkaPlaybackItem_Accumulate(cSkaPlaybackItem* self, const cSkaPlaybackItem* contribution)
{
    if (self->mSummedWeight == 0.0f) {
        *self = *contribution;
    } else {
        self->mSummedOffsetRootRotation = self->GetWeighted() + contribution->GetWeighted();
        self->mSummedWeight += contribution->mSummedWeight;
        self->mIsSummedOffsetRootRotationUnweightedAndNormalized = 0;
    }
}
