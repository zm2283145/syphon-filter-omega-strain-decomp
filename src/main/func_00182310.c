// cBox::Transform(const cMatrix&): transform the 8 box corners by m and rebuild the box.
// The 16-byte copies use the volatile lq/sq idiom (as in cBox_Empty); it also gives retail's
// unshared constant materialisation.
#pragma cplusplus on
#pragma inline_depth(8)

struct cMatrix {
    float m[4][4];
} __attribute__((aligned(16)));

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o)
    {
        cVector* d = this;
        const cVector* s = &o;
        __int128 q;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory");
    }
    cVector& operator=(const cVector& o)
    {
        cVector* d = this;
        const cVector* s = &o;
        __int128 q;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory");
        return *this;
    }
    void WSet1() { w = 1.0f; }
    cVector& Transform(const cMatrix& m)
    {
        cVector* p = this;
        const cMatrix* mp = &m;
        asm {
            lqc2 vf8, 0x0(p)
            lqc2 vf4, 0x0(mp)
            lqc2 vf5, 0x10(mp)
            lqc2 vf6, 0x20(mp)
            lqc2 vf7, 0x30(mp)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(p)
        }
        return *p;
    }
    cVector GetTransformed(const cMatrix& m) const
    {
        cVector v(*this);
        cVector& r = v.Transform(m);
        return r;
    }
} __attribute__((aligned(16)));

struct cBox {
    cVector min;
    cVector max;
    void Empty()
    {
        min = cVector(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        max = cVector(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
    void Include(const cVector& v)
    {
        cBox* b = this;
        cVector* pv0 = &max;
        const cVector* pv = &v;
        asm {
            lqc2 vf1, 0x0(b)
            lqc2 vf2, 0x0(pv0)
            lqc2 vf3, 0x0(pv)
            vmini.xyz vf1, vf1, vf3
            vmax.xyz vf2, vf2, vf3
            sqc2 vf1, 0x0(b)
            sqc2 vf2, 0x0(pv0)
        }
    }
};

extern "C" void cBox_Transform(cBox* self, const cMatrix& m)
{
    cVector oldMin(self->min);
    oldMin.WSet1();
    cVector oldMax(self->max);
    oldMax.WSet1();
    self->Empty();
    self->Include(oldMin.GetTransformed(m));
    self->Include(cVector(oldMin.x, oldMin.y, oldMax.z, 1.0f).Transform(m));
    self->Include(cVector(oldMin.x, oldMax.y, oldMin.z, 1.0f).Transform(m));
    self->Include(cVector(oldMin.x, oldMax.y, oldMax.z, 1.0f).Transform(m));
    self->Include(cVector(oldMax.x, oldMin.y, oldMin.z, 1.0f).Transform(m));
    self->Include(cVector(oldMax.x, oldMin.y, oldMax.z, 1.0f).Transform(m));
    self->Include(cVector(oldMax.x, oldMax.y, oldMin.z, 1.0f).Transform(m));
    self->Include(oldMax.GetTransformed(m));
}
