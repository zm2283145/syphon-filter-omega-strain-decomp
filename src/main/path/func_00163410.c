#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V operator-(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Dist(const V* a, const V* b)
{
    V r;
    V d;
    float ret;
    {
        V* pr = &r; const V* pa = a; const V* pb = b;
        asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    }
    {
    V* dd; const V* ss; int t; __int128 x; V* pv;
    ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
    asm {
        lqc2 vf1, 0(pv)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, ret
    }
    }
    return ret;
}
struct ROpen { char pad[0xC]; float f; int parent; int node; float g; unsigned char open; char pad1D[3]; };
struct Search { char pad[0x20]; V goal; V start; char pad40[0x18]; char openList[4]; };
struct PNode;
extern "C" {
extern int D_004EA798;
extern ROpen D_004EA7B0[];
PNode* NpcPath_GetNode(int);
void Node_GetTranslation(V* out, PNode* n);
void NpcRoute_InsertSorted(void* list, ROpen* n);
}
static inline ROpen* AllocOpen()
{
    ROpen* n;
    int c;
    n = 0;
    c = D_004EA798;
    if (c < 400) { n = &D_004EA7B0[c]; D_004EA798 = c + 1; }
    return n;
}
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" bool NpcRoute_OpenNode(Search* self, int node)
{
    bool r = false;
    V t; V d1; V d2; V r1; V r2;
    ROpen* n = AllocOpen();
    if (n) {
        float g; float h;
        Node_GetTranslation(&t, NpcPath_GetNode(node));
        {
            V* pr = &r1; const V* pa = &self->start; const V* pb = &t;
            __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
        }
        {
        V* dd; const V* ss; int tt; __int128 x; V* pv;
        ss = &r1; pv = &d1; asm { mtc1 $zero, g } dd = &d1; x = *(__int128*)ss; *(__int128*)dd = x;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(g), "=&r"(tt) : "r"(pv) : "memory");
        }
        n->node = node;
        n->g = g;
        {
            V* pr = &r2; const V* pa = &self->goal; const V* pb = &t;
            __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
        }
        {
        V* dd; const V* ss; int tt; __int128 x; V* pv;
        ss = &r2; pv = &d2; asm { mtc1 $zero, h } dd = &d2; x = *(__int128*)ss; *(__int128*)dd = x;
        asm {
            lqc2 vf1, 0(pv)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni tt, vf4
            mtc1 tt, h
        }
        }
        n->f = g + h;
        n->parent = 0;
        n->open = 1;
        NpcRoute_InsertSorted(self->openList, n);
        r = true;
    }
    return r;
}

