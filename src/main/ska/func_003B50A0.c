#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_50A0;
typedef struct { char* p; } It_50A0;
typedef struct { char pad[0x148]; struct { int a; int n; }* p148; } Obj_50A0;
extern int Hog_GetMemberInPlace(Obj_50A0* o, int i);
extern char* Archive_GetMemberName(Obj_50A0* o, int i);
extern void String_CtorCStr_13B480(Str_50A0* s, char* c);
extern void String_Dtor(Str_50A0* s, int f);
extern void func_001BFF20(It_50A0* out, Str_50A0* s);
extern void func_001BFEE0(It_50A0* out, Str_50A0* s);
extern int func_001BFE90(It_50A0* a, It_50A0* b);
extern char* func_001BFED0(It_50A0* a);
extern void func_001BFEB0(It_50A0* a);
extern int func_003B7100(Str_50A0* s, Str_50A0* t, int n);
extern void func_003B52B0(Str_50A0* out, Str_50A0* s, int a, int b);
extern int String_Length(Str_50A0* s);
extern char* String_CStr_Thunk(Str_50A0* s);
extern void Skas_RegisterClip(int* out, void* self, char* name, int clip);
extern char D_004BCD78[];

void func_003B50A0(void* self, Obj_50A0* o)
{
    int r;
    It_50A0 it;
    It_50A0 end;
    Str_50A0 s;
    Str_50A0 t;
    Str_50A0 u;
    char name[0x30];
    int n = o->p148->n;
    int i;
    for (i = 0; i < n; i++) {
        int clip = Hog_GetMemberInPlace(o, i);
        if (clip) {
            int idx;
            String_CtorCStr_13B480(&s, Archive_GetMemberName(o, i));
            func_001BFF20(&it, &s);
            func_001BFEE0(&end, &s);
            while (func_001BFE90(&it, &end)) {
                if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
                func_001BFEB0(&it);
            }
            String_CtorCStr_13B480(&t, D_004BCD78);
            idx = func_003B7100(&s, &t, -1);
            String_Dtor(&t, 0);
            if (idx != -1) {
                int j;
                func_003B52B0(&u, &s, 0, idx);
                for (j = 0; j < 47; j++) {
                    name[j] = (j < String_Length(&u)) ? String_CStr_Thunk(&u)[j] : 0;
                }
                name[j] = 0;
                String_Dtor(&u, 0);
                Skas_RegisterClip(&r, self, name, clip);
            }
            String_Dtor(&s, 0);
        }
    }
}
