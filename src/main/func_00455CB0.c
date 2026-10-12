#pragma cplusplus on
#include "types.h"
struct V455 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(char*); };
typedef struct { char pad[0x48]; void* f48; } W455;
extern "C" {
extern void func_0041EFA0(W455*);
extern char* Loc_LookupText(char*);
extern void func_0043DB80(void*);
extern void func_0043DCE0(void*, char*);
extern V455* func_0041DB80(W455*, char*);
extern char D_004A7520[];
extern char D_004C1A38[];
extern char D_004FFC90[];
extern void func_0041BEB0(V455*, char*, int);
}
extern "C" void func_00455CB0(W455* w) {
    V455* p;
    func_0041EFA0(w);
    if (w->f48) {
        char* t = Loc_LookupText("level_briefing");
        void* x = w->f48;
        func_0043DB80(x);
        func_0043DCE0(x, t ? t : D_004C1A38);
    }
    p = func_0041DB80(w, "label_briefingheader");
    p = (p && p->v20(D_004A7520)) ? p : 0;
    if (p) {
        char* t = Loc_LookupText(D_004FFC90);
        func_0041BEB0(p, t ? t : D_004FFC90, 0);
    }
}
