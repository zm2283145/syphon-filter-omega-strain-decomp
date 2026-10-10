#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct LevelReq {
    char b[0x18];
} LevelReq;

typedef struct LevelKey {
    char b[8];
} LevelKey;

extern int D_004926E0;
extern int D_00532AF0;
extern int D_00532B90;
extern void* ObjectiveRow_Construct(LevelReq*, int, int, int);
extern void func_00147600(void*, void*);
extern void* func_0032EEC0(LevelKey*, int, int);
extern void func_0032EEA0(void*, void*);

/* Script: cAgentData::RegisterLevel(a, b, c, d) - registers a level and its key. */
int Script_cAgentData__RegisterLevel_2(ScriptArg* args) {
    LevelReq req;
    LevelKey key;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    int index;
    int bv;
    int cv;
    d[0] = args[3].i;
    index = D_004926E0;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    D_004926E0 = index + 1;
    cv = *(int*)c;
    bv = *(int*)b;
    func_00147600(&D_00532AF0, ObjectiveRow_Construct(&req, *(int*)a, *(int*)d, index));
    func_0032EEA0(&D_00532B90, func_0032EEC0(&key, bv, cv));
    return 0;
}
