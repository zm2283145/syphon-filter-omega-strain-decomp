#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
struct Vec_4422D0 { int m0; int size; char** data; unsigned char owns; int Size() const { return size; } };
struct Mc_4422D0 { char pad[0x59D]; unsigned char a; unsigned char b; unsigned char c; };
struct Wrap_4422D0 { Mc_4422D0* p; };
extern "C" {
extern Wrap_4422D0 D_0055A830;
extern char D_00499C70[];
Vec_4422D0* func_002888C0(Vec_4422D0* v);
void func_002887C0(Vec_4422D0* v, short del);
void MemCardWrap_Enumerate(Wrap_4422D0* o, Vec_4422D0* v);
char** func_002888B0(Vec_4422D0* v, int i);
char* strchr(const char* s, int c);
int AgentFile_DecodeName(const unsigned char* in, char* out, int* digit, int max);
int strcmp(const char* a, const char* b);
void String_Copy(char* d, const char* s);
}
extern "C" int SaveAgentWidget_FindSlotFile(int slot, const char* want, char* out)
{
    Vec_4422D0 v;
    char name[16];
    int digit;
    int i;
    func_002888C0(&v);
    v.owns = 1;
    MemCardWrap_Enumerate(&D_0055A830, &v);
    for (i = 0; i < v.Size(); i++) {
        if (!strchr(v.data[i], '.') && ((D_00499C70 + 1)[**func_002888B0(&v, i)] & 4) &&
            AgentFile_DecodeName((unsigned char*)v.data[i], name, &digit, 0x10)) {
            if ((!want || strcmp(name, want)) && slot == digit) {
                if (out) String_Copy(out, v.data[i]);
                func_002887C0(&v, -1);
                return 1;
            }
        }
    }
    func_002887C0(&v, -1);
    return 0;
}
