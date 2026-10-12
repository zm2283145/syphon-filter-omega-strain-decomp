#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Mgr_244B90 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void Refresh(); };
struct W_244B90 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void Draw(); };
extern "C" {
extern unsigned char D_004FFC29;
extern char D_005381F0[];
void func_00261130(char* o);
void func_0037A1E0(void* a);
Mgr_244B90* func_004147A0(void);
void func_0016E880(Word* w, void* l);
int* func_002440B0(int* dst, int value);
void func_00244080(Word* w, void* l);
Word* func_00244070(Word* dst, Word* src);
void func_003E7670(int a);
void func_002434F0(char* o);
}
#define Begin_244B90(l) (func_0016E880(&tmp, l), func_002440B0(&r, tmp.value), (char*)r)
#define End_244B90(l) (func_00244080(&e, l), func_00244070(&e2, &e), (char*)e2.value)

extern "C" void func_00244B90(char* o)
{
    char* n;
    char* v;
    W_244B90* a;
    Word e2; int r; Word tmp; Word e;
    func_00261130(o);
    if (!D_004FFC29) {
        func_0037A1E0(D_005381F0);
        if (F_(o, 0x6A0, int) && F_(o, 0x6A9, unsigned char)) {
            func_004147A0()->Refresh();
            for (n = Begin_244B90(o + 0x6E8); n != End_244B90(o + 0x6E8); n = F_(n, 4, char*)) {
                v = F_(n, 8, char*);
                a = F_(v, 0x10, W_244B90*);
                if (a && F_(v, 0xC, int) && F_(a, 0x64, unsigned char)) {
                    a->Draw();
                }
            }
            func_003E7670(F_(o, 0x54, int));
            func_0037A1E0(D_005381F0);
        } else {
            func_002434F0(o);
            func_003E7670(F_(o, 0x54, int));
            func_004147A0()->Refresh();
        }
    } else {
        func_004147A0()->Refresh();
    }
}

