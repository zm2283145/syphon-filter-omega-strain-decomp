#include "types.h"
typedef struct { void** p; } It_EF50;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x53]; int lA4[3]; } S_EF50;
extern void** func_001CF0C0(void* v);
extern void** func_001CF090(void* v);
extern void func_001CF0B0(It_EF50* out, void* v, void*** p);
extern void func_001CF100(It_EF50* it, void* c);
extern void func_001CF0E0(It_EF50* it, void* c);
extern int func_001CEF10(It_EF50* a, It_EF50* b);
extern void** func_001CF0D0(It_EF50* it);
extern void func_001CEF30(It_EF50* it);
void func_001CEF50(S_EF50* o);
static inline int NotEq_EF50(void** a, It_EF50* b) { return !(a == b->p); }
static inline void Mark_EF50(S_EF50* o)
{
    It_EF50 b;
    It_EF50 e;
    if (!o->a50) {
        It_EF50* pe;
        o->a50 = 1;
        func_001CF100(&b, o->lA4);
        func_001CF0E0(&e, o->lA4);
        pe = &e;
        while (func_001CEF10(&b, pe)) {
            func_001CEF50(*func_001CF0D0(&b));
            func_001CEF30(&b);
        }
    }
}
void func_001CEF50(S_EF50* o)
{
    It_EF50 e;
    It_EF50 tb;
    It_EF50 te;
    void** pb;
    void** pe;
    It_EF50* ep;
    void** it;
    if (!o->a50) {
        o->a50 = 1;
        pb = func_001CF0C0(o->lA4);
        func_001CF0B0(&tb, o->lA4, &pb);
        it = tb.p;
        pe = func_001CF090(o->lA4);
        func_001CF0B0(&te, o->lA4, &pe);
        e.p = te.p;
        ep = &e;
        for (; NotEq_EF50(it, ep); it++) {
            Mark_EF50((S_EF50*)*it);
        }
    }
}



