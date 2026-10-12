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
int func_0023DA80(Vec*);
int func_0023DA90(Vec*);
Node** func_0023DAA0(Vec*, int);
Node** func_0023DAB0(Vec*, int);
Node* func_0023EEA0(Node*);
Node* func_0023EB70(Node*);
}
static inline Node* G(Node* x)
{
    if (x->Find()) return x->Find();
    for (int k = 0; k < func_0023DA90(&x->kids); k++) {
        if (!!func_0023EEA0(*func_0023DAA0(&x->kids, k)))
            return func_0023EEA0(*func_0023DAA0(&x->kids, k));
    }
    return 0;
}
static inline Node* L1(Node* pp)
{
    if (pp->parent) return func_0023EB70(pp->parent);
    return func_0023EEA0(pp);
}
static inline Node* L2(Node* p)
{
    if (p->parent) return L1(p->parent);
    if (p->Find()) return p->Find();
    for (int k = 0; k < func_0023DA90(&p->kids); k++) {
        if (!!func_0023EEA0(*func_0023DAA0(&p->kids, k)))
            return func_0023EEA0(*func_0023DAA0(&p->kids, k));
    }
    return 0;
}
extern "C" Node* func_0023EB70(Node* o)
{
    Node* p = o->parent;
    if (p) return L2(p);
    if (o->Find()) return o->Find();
    for (int j = 0; j < func_0023DA80(&o->kids); j++) {
        if (G(*func_0023DAB0(&o->kids, j)))
            return G(*func_0023DAB0(&o->kids, j));
    }
    return 0;
}
