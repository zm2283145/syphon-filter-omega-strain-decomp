/*
 * SFOGame/Source/NIEvent: 1 file, 0023EB70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023EB70 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Node;
struct Vec { int cap; int n; Node** p; };
class Node {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46();
    virtual Node* Find();
    char pad04[0x90];
    Node* parent;
    int pad98;
    Vec kids;
};
extern "C" {
int std_vector_cNIEventBasePtr_size(Vec*);
int cArray_cNIEventBasePtr_Size(Vec*);
Node** cArray_cNIEventBasePtr_opIndex(Vec*, int);
Node** std_vector_imp_cNIEventBasePtr_1_opIndex(Vec*, int);
Node* cNIEventBase_GetFirstVUM(Node*);
Node* cNIEventBase_GetVUMInTree(Node*);
}
static inline Node* G(Node* x)
{
    if (x->Find()) return x->Find();
    for (int k = 0; k < cArray_cNIEventBasePtr_Size(&x->kids); k++) {
        if (!!cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&x->kids, k)))
            return cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&x->kids, k));
    }
    return 0;
}
static inline Node* L1(Node* pp)
{
    if (pp->parent) return cNIEventBase_GetVUMInTree(pp->parent);
    return cNIEventBase_GetFirstVUM(pp);
}
static inline Node* L2(Node* p)
{
    if (p->parent) return L1(p->parent);
    if (p->Find()) return p->Find();
    for (int k = 0; k < cArray_cNIEventBasePtr_Size(&p->kids); k++) {
        if (!!cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&p->kids, k)))
            return cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&p->kids, k));
    }
    return 0;
}
extern "C" Node* cNIEventBase_GetVUMInTree(Node* o)
{
    Node* p = o->parent;
    if (p) return L2(p);
    if (o->Find()) return o->Find();
    for (int j = 0; j < std_vector_cNIEventBasePtr_size(&o->kids); j++) {
        if (G(*std_vector_imp_cNIEventBasePtr_1_opIndex(&o->kids, j)))
            return G(*std_vector_imp_cNIEventBasePtr_1_opIndex(&o->kids, j));
    }
    return 0;
}
static inline void merge_flush_func_0023EB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023EB70 */
