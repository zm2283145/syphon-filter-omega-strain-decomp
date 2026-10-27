#pragma cplusplus on
struct K_0013BD40 { int a; int b; int c; };
struct P_0013BD40 { int a; int b; int c; int d; int e; int f; };
struct Q_0013BD40 { int a; int b; int c; int d; };
struct R_0013BD40 { int it; unsigned char ok; };
extern "C" { void std_basic_string_char_char_traits_char_ctor_basicstringR(void* d, void* s); void std_make_pair_cString_cConsCommandP(P_0013BD40* d, K_0013BD40* k, int v);
void std_tree_pair_cString_value_compare_insert_one_pairR(R_0013BD40* r, void* m, Q_0013BD40* q); void String_Dtor(void* p, short f); }
extern "C" unsigned char cKeyedRegistry_cString_cConsCommand_Register(void* m, void* key, int v)
{
    R_0013BD40 r;
    K_0013BD40 k;
    P_0013BD40 p;
    Q_0013BD40 q;
    unsigned char ok;
    std_basic_string_char_char_traits_char_ctor_basicstringR(&k, key);
    std_make_pair_cString_cConsCommandP(&p, &k, v);
    std_basic_string_char_char_traits_char_ctor_basicstringR(&q, &p);
    q.d = p.d;
    std_tree_pair_cString_value_compare_insert_one_pairR(&r, m, &q);
    ok = r.ok;
    String_Dtor(&q, 0);
    String_Dtor(&p, 0);
    String_Dtor(&k, 0);
    return ok;
}
