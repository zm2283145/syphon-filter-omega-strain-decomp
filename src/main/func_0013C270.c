#pragma cplusplus on
#pragma bool off
struct It_0013C270 { void* n; };
static inline int ItEq(void* a, It_0013C270* b) { return a == b->n; }
extern "C" { void func_0013C4A0(It_0013C270* r, void* t, int k); void func_0013C300(It_0013C270* r, void* t);
void func_0013C2F0(It_0013C270* r, It_0013C270* s); void func_0013C6F0(void* t, It_0013C270* it); }
extern "C" void func_0013C270(void* t, int k)
{
    It_0013C270 c;
    It_0013C270 a;
    It_0013C270 x;
    It_0013C270 e;
    void* n;
    func_0013C4A0(&a, t, k);
    n = a.n;
    func_0013C300(&e, t);
    func_0013C2F0(&c, &e);
    if (ItEq(n, &c) ^ 1) {
        x.n = n;
        func_0013C6F0(t, &x);
    }
}
#pragma bool reset


