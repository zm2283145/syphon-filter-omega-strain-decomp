#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Str_1C01D0 { unsigned int word; unsigned int length; char* data; };
struct It_1C01D0 { char* p; };
struct Pair_1C01D0 { Str_1C01D0 key; void* val; };
struct Ins_1C01D0 { void* node; unsigned char inserted; };
struct Tbl_1C01D0 { int f0; int count; };
struct Arc_1C01D0 { char pad0[0x148]; Tbl_1C01D0* f148; };
struct Ska_1C01D0 {
    int f0;
    char v4[0x10];
    char v14[0x10];
    char v24[0x10];
    char v34[0x10];
    char v44[0x10];
    int f54;
    int f58;
};
extern "C" {
extern char D_0048B2F8[];
extern char D_004FFBC0[];
int sprintf(char* buf, const char* fmt, ...);
Arc_1C01D0* Archive_Open(void* a, char* name, int b, int c);
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_001C0810(void*);
void func_001C07C0(void*);
void func_001C0720(void*);
void func_001C05E0(void*);
void func_001C0540(void*);
int func_0036D4E0(Arc_1C01D0* a, int i);
int func_0036D380(Arc_1C01D0* a, int i);
char* Archive_GetMemberName(Arc_1C01D0* a, int i);
void func_003B6270(Ska_1C01D0* p, int a, int b, Arc_1C01D0* c);
void String_CtorCStr_13B480(Str_1C01D0* s, char* c);
void func_001BFF20(It_1C01D0* out, Str_1C01D0* s);
void func_001BFEE0(It_1C01D0* out, Str_1C01D0* s);
int func_001BFE90(It_1C01D0* a, It_1C01D0* b);
char* func_001BFED0(It_1C01D0* a);
void func_001BFEB0(It_1C01D0* a);
int String_AssignCStr_1C43A0(Str_1C01D0* a, char* b);
void func_001EFB60(Ska_1C01D0* p);
void func_0013BCB0(Str_1C01D0* d, Str_1C01D0* s);
void func_001C0500(Pair_1C01D0* out, Str_1C01D0* k, Ska_1C01D0* v);
void func_001C4770(Ins_1C01D0* out, void* t, Pair_1C01D0* k);
void String_Dtor(void* s, int f);
}
extern "C" void func_001C01D0(void* self, void* fs)
{
    char buf[0x80];
    Arc_1C01D0* tex;
    Arc_1C01D0* a;
    int n;
    int i;
    sprintf(buf, "%s\\COMMON\\SKA.HOG", D_0048B2F8);
    tex = Archive_Open(fs, buf, 0, 0);
    sprintf(buf, "%s\\COMMON\\SKAS.HOG", D_0048B2F8);
    a = Archive_Open(fs, buf, 0, 0);
    n = a->f148->count;
    for (i = 0; i < n; i++) {
        Ska_1C01D0* p;
        {
            AllocGuard g;
            p = (Ska_1C01D0*)Mem_Alloc(0, 0x5C, "Loader.cc", 0x637);
        }
        if (p) {
            p->f0 = 0;
            func_001C0810(p->v4);
            func_001C07C0(p->v14);
            func_001C0720(p->v24);
            func_001C05E0(p->v34);
            func_001C0540(p->v44);
            p->f54 = 0;
            p->f58 = 0;
        }
        {
            int x = func_0036D4E0(a, i);
            func_003B6270(p, x, func_0036D380(a, i), tex);
        }
        {
            Str_1C01D0 s;
            It_1C01D0 it;
            It_1C01D0 end;
            String_CtorCStr_13B480(&s, Archive_GetMemberName(a, i));
            func_001BFF20(&it, &s);
            func_001BFEE0(&end, &s);
            while (func_001BFE90(&it, &end)) {
                if (*func_001BFED0(&it) >= 'a' && *func_001BFED0(&it) <= 'z') *func_001BFED0(&it) -= 0x20;
                func_001BFEB0(&it);
            }
            if (!String_AssignCStr_1C43A0(&s, "FEMALE.SKAS") || !String_AssignCStr_1C43A0(&s, "MALE.SKAS"))
                func_001EFB60(p);
            {
                Ins_1C01D0 r;
                Str_1C01D0 t;
                Pair_1C01D0 pa;
                Pair_1C01D0 pb;
                func_0013BCB0(&t, &s);
                func_001C0500(&pa, &t, p);
                func_0013BCB0(&pb.key, &pa.key);
                pb.val = pa.val;
                func_001C4770(&r, D_004FFBC0, &pb);
                String_Dtor(&pb, 0);
                String_Dtor(&pa, 0);
                String_Dtor(&t, 0);
            }
            String_Dtor(&s, 0);
        }
    }
}
