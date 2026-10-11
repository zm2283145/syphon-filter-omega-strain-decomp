#pragma cplusplus on
struct K_0013BD40 { int a; int b; int c; };
struct P_0013BD40 { int a; int b; int c; int d; int e; int f; };
struct Q_0013BD40 { int a; int b; int c; int d; };
struct R_0013BD40 { int it; unsigned char ok; };
extern "C" { void func_0013BCB0(void* d, void* s); void func_0013BDE0(P_0013BD40* d, K_0013BD40* k, int v);
void func_0013C130(R_0013BD40* r, void* m, Q_0013BD40* q); void func_00138B70(void* p, short f); }
extern "C" unsigned char func_0013BD40(void* m, void* key, int v)
{
    R_0013BD40 r;
    K_0013BD40 k;
    P_0013BD40 p;
    Q_0013BD40 q;
    unsigned char ok;
    func_0013BCB0(&k, key);
    func_0013BDE0(&p, &k, v);
    func_0013BCB0(&q, &p);
    q.d = p.d;
    func_0013C130(&r, m, &q);
    ok = r.ok;
    func_00138B70(&q, 0);
    func_00138B70(&p, 0);
    func_00138B70(&k, 0);
    return ok;
}
