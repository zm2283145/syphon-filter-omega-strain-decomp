/*
 * SFOGame/Source/targetManager: 1 file, 0022AB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022AB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_dead_assignments off
union V {
    struct { float x, y, z, w; } f;
    __int128 q;
    V& operator=(const V& o) {
        V* d = this; const V* s = &o; __int128 t;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s));
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory");
        return *this;
    }
};
struct Obj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual V GetPos(int);
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual V GetDir();
};
extern "C" int GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(const V& a, const V& b, int c);
static inline V Pos_(Obj* o) { return o->GetPos(-1); }
static inline V Dir_(Obj* o) { return o->GetDir(); }
static inline int Hit_(const V& dir, Obj* a, Obj* b, int c, V& pa) { pa = a->GetPos(-1); return GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(dir, b->GetPos(-1), c); }
extern "C" int GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(Obj* a, Obj* b, int c)
{
    V pa; V t1; V t2;
    V* q0 = &pa; V* q1 = &t1; V* q2 = &t2;
    return Hit_(a->GetDir(), a, b, c, pa);
}
static inline void merge_flush_func_0022AB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022AB20 */
