#pragma cplusplus on
#include "types.h"
struct V456 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(char*); };
extern "C" {
extern void func_0041F150(void*);
extern V456* GuiWidget_FindChildByName(void*, char*);
extern char D_004A7520[];
extern char D_004C1A38[];
extern char D_004FFB50[];
extern int Agent_GetSelected(char*, int);
extern char* func_00336170(int);
extern void func_0041BEB0(V456*, char*, int);
}
extern "C" void func_00456F90(void* w) {
    V456* p;
    func_0041F150(w);
    p = GuiWidget_FindChildByName(w, "value_agentname");
    p = (p && p->v20(D_004A7520)) ? p : 0;
    if (p) {
        char* s = func_00336170(Agent_GetSelected(D_004FFB50, -1));
        func_0041BEB0(p, s ? s : D_004C1A38, 0);
    }
}
