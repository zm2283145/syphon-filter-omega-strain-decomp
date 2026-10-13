#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
struct Vec_288510 { int m0; int size; char** data; unsigned char owns; int Size() const { return size; } };
struct Mc_288510 { char pad[0x59D]; unsigned char a; unsigned char b; unsigned char c; };
struct Wrap_288510 { Mc_288510* p; };
extern "C" {
extern Wrap_288510 D_0055A830;
extern char D_00499C70[];
Vec_288510* func_002888C0(Vec_288510* v);
void func_002887C0(Vec_288510* v, short del);
void MemCardWrap_Enumerate(Wrap_288510* o, Vec_288510* v);
char** func_002888B0(Vec_288510* v, int i);
char* strchr(const char* s, int c);
int AgentFile_DecodeName(const unsigned char* in, char* out, int* digit, int max);
}
extern "C" unsigned char func_00288510(void)
{
    Wrap_288510* w = &D_0055A830;
    unsigned char ok = (w->p->a && w->p->b) && w->p->c;
    if (ok) {
        Vec_288510 v;
        char name[16];
        int digit;
        int i;
        ok = 0;
        func_002888C0(&v);
        v.owns = 1;
        MemCardWrap_Enumerate(w, &v);
        for (i = 0; i < v.Size(); i++) {
            if (!strchr(v.data[i], '.') && ((D_00499C70 + 1)[**func_002888B0(&v, i)] & 4) &&
                AgentFile_DecodeName((unsigned char*)v.data[i], name, &digit, 0x10)) {
                ok = 1;
                break;
            }
        }
        func_002887C0(&v, -1);
    }
    return ok;
}







