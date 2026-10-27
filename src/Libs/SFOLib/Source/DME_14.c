/*
 * Libs/SFOLib/Source/DME: 1 file, 0042B5D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin DME_42B5D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
long long SoftFloat_FloatToDouble(float f);
int SoftFloat_DoubleSub(int a, long long b);
long long SoftFloat_DoubleMultiply(long long a, long long b);
int SoftFloat_IntToDouble(int v);
unsigned int SoftFloat_DoubleToInt(int v);
void NetGetValidClientCount(int* out, int a);
extern int D_00494180;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005723F8;
extern unsigned char D_00572400;
extern unsigned int D_00572428;
extern unsigned int D_0057242C;
extern unsigned int D_00572430;
extern int D_00572538;
}

static inline int HostCount_42B5D0(void)
{
    if (g_IsMultiplayer) {
        int n;
        NetGetValidClientCount(&n, D_005721A8);
        return n;
    }
    return 1;
}

static inline unsigned int Now_42B5D0(void)
{
    int v = D_00572538;
    int n = SoftFloat_IntToDouble(v);
    return SoftFloat_DoubleToInt(SoftFloat_DoubleSub(n, SoftFloat_DoubleMultiply((long long)0x3FB00000 << 0x20, SoftFloat_FloatToDouble((float)v))));
}

static inline bool HasRoom_42B5D0(void)
{
    int max = D_00494180;
    return HostCount_42B5D0() < max;
}

extern "C" bool func_0042B5D0(void)
{
    bool ok = !D_00572400 && !D_005723F8 && HasRoom_42B5D0();
    if (ok) {
        unsigned int t = Now_42B5D0();
        if (D_00572428 < 0xFFFFFFE && D_00572428 < t)
            D_00572428 = t + 45000;
        else if (D_0057242C < 0xFFFFFFE && D_0057242C < t)
            D_0057242C = t + 45000;
        else if (D_00572430 < 0xFFFFFFE && D_00572430 < t)
            D_00572430 = t + 45000;
        else
            ok = 0;
    }
    return ok;
}
static inline void merge_flush_DME_42B5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end DME_42B5D0 */
