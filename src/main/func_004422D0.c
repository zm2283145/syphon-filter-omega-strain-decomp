#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
struct Vec_4422D0 { int m0; int size; char** data; unsigned char owns; int Size() const { return size; } };
struct Mc_4422D0 { char pad[0x59D]; unsigned char a; unsigned char b; unsigned char c; };
struct Wrap_4422D0 { Mc_4422D0* p; };
extern "C" {
extern Wrap_4422D0 g_MemCard;
extern char D_00499C70[];
Vec_4422D0* std_vector_charPtr_ctor_void_2(Vec_4422D0* v);
void std_vector_charPtr_dtor_void_2(Vec_4422D0* v, short del);
void MemCardWrap_Enumerate(Wrap_4422D0* o, Vec_4422D0* v);
char** std_vector_charPtr_opIndex_uint_2(Vec_4422D0* v, int i);
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
    std_vector_charPtr_ctor_void_2(&v);
    v.owns = 1;
    MemCardWrap_Enumerate(&g_MemCard, &v);
    for (i = 0; i < v.Size(); i++) {
        if (!strchr(v.data[i], '.') && ((D_00499C70 + 1)[**std_vector_charPtr_opIndex_uint_2(&v, i)] & 4) &&
            AgentFile_DecodeName((unsigned char*)v.data[i], name, &digit, 0x10)) {
            if ((!want || strcmp(name, want)) && slot == digit) {
                if (out) String_Copy(out, v.data[i]);
                std_vector_charPtr_dtor_void_2(&v, -1);
                return 1;
            }
        }
    }
    std_vector_charPtr_dtor_void_2(&v, -1);
    return 0;
}
