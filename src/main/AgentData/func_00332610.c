#include "types.h"
#pragma opt_strength_reduction off

typedef struct PartDef {
    char name[20];
} PartDef;

typedef struct PartDefVec {
    int unk00;
    int count;
    PartDef* data;
} PartDefVec;

typedef struct PartVec {
    int unk00;
    int count;
    PartDef** data;
} PartVec;

typedef struct PartIt {
    PartDef** p;
} PartIt;

typedef struct Agent332610 {
    char pad[0xB58];
    PartVec parts;
} Agent332610;

extern PartDefVec D_00532B30;
extern char D_004B9290[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_00332840(PartIt* out, PartVec* v);
extern PartIt* func_00332830(PartIt* dst, PartIt* src);
extern void func_00332820(PartIt* out, PartVec* v);
extern void func_00332800(PartIt* out, PartVec* v);
extern int func_003327A0(PartIt* a, PartIt* b);
extern PartDef** func_003327F0(PartIt* it);
extern PartIt* func_003327C0(PartIt* it);
extern PartIt* func_003327E0(PartIt* dst, PartIt* src);
extern void func_00330280(PartVec* v, PartDef** value);

void cAgentData_UnlockPart(Agent332610* self, const char* name)
{
    PartDef* found;
    PartIt res;
    PartIt end;
    PartIt endTmp;
    PartIt first;
    PartIt last;
    char buf[0x88];
    int i;
    PartIt* rp;
    found = 0;
    for (i = 0; found == 0 && i < D_00532B30.count; i++) {
        if (strcmp(name, D_00532B30.data[i].name) == 0) {
            found = &D_00532B30.data[i];
        }
    }
    if (found == 0) {
        sprintf(buf, D_004B9290, name);
        return;
    }
    func_00332840(&endTmp, &self->parts);
    func_00332830(&end, &endTmp);
    func_00332820(&first, &self->parts);
    func_00332800(&last, &self->parts);
    while (func_003327A0(&first, &last)) {
        if (*func_003327F0(&first) == found) {
            func_003327E0(&res, &first);
            rp = &res;
            goto done;
        }
        func_003327C0(&first);
    }
    func_003327E0(&res, &last);
    rp = &res;
done:
    if (rp->p == end.p) {
        func_00330280(&self->parts, &found);
    }
}
