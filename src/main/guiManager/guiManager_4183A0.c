/*
 * main/guiManager: 2 files, 004183A0-00418420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004183A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char d[0x18]; } g2E180;
typedef struct { int pad0; int size; g2E180* data; } g2Vec180;
extern void func_004172E0(g2E180* e, int flag);
void func_004183A0(g2Vec180* v) {
    g2E180* b = v->data;
    g2E180* e = b + v->size;
    while (b < e) {
        --e;
        func_004172E0(e, -1);
    }
    v->size = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004183A0 */

/* merge_units: begin func_00418420 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_418420;
typedef struct { char* p; } It_418420;
typedef struct { char pad[0x18]; int value; } Node_418420;
typedef struct { Node_418420* n; } MIt_418420;
typedef struct { char pad[0x10]; int def; } O_418420;
extern void String_CtorCStr_13B480(Str_418420* s, char* c);
extern void String_Dtor(Str_418420* s, int f);
extern void func_001BFF20(It_418420* out, Str_418420* s);
extern void func_001BFEE0(It_418420* out, Str_418420* s);
extern int func_001BFE90(It_418420* a, It_418420* b);
extern char* func_001BFED0(It_418420* a);
extern void func_001BFEB0(It_418420* a);
extern void func_00419740(MIt_418420* out, O_418420* o, Str_418420* key);
extern void func_00418590(MIt_418420* out, O_418420* o);
extern void func_00418580(MIt_418420* out, MIt_418420* src);

#pragma bool off
static inline int Ne_418420(Node_418420* a, Node_418420* b) { return (a == b) ^ 1; }

int func_00418420(O_418420* o, char* name)
{
    if (name == 0 || *name == 0) return o->def;
    {
        Str_418420 s;
        MIt_418420 e;
        MIt_418420 f;
        It_418420 it;
        It_418420 end;
        MIt_418420 tmp;
        Node_418420* n;
        String_CtorCStr_13B480(&s, name);
        func_001BFF20(&it, &s);
        func_001BFEE0(&end, &s);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
            func_001BFEB0(&it);
        }
        func_00419740(&f, o, &s);
        n = f.n;
        func_00418590(&tmp, o);
        func_00418580(&e, &tmp);
        if (Ne_418420(n, e.n)) {
            int r = n->value;
            String_Dtor(&s, 0);
            return r;
        } else {
            int r = o->def;
            String_Dtor(&s, 0);
            return r;
        }
    }
}
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_00418420 */
