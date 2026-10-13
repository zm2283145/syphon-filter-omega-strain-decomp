#include "types.h"
#pragma opt_strength_reduction off

typedef struct DosDef {
    const char* name;
    int unk04;
    int index;
    char pad0C[0x18];
} DosDef;

typedef struct DosDefVec {
    int unk00;
    int count;
    DosDef* data;
} DosDefVec;

typedef struct DosEntry {
    int agent;
    int num;
    int dossier;
    int unk0C;
    unsigned char flag;
    char pad11[0xF];
    int key;
} DosEntry;

typedef struct DosEntryVec {
    int unk00;
    int count;
    DosEntry* data;
} DosEntryVec;

extern DosDefVec D_00532B50;
extern DosEntryVec D_00532B70;
extern char D_004B99A8[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Loc_FindKeyThunk(const char* key);
extern int func_00338B60(DosEntryVec* v, DosEntry* pos, int count, DosEntry* value);

static inline DosDef* At(DosDefVec* v, int i) { return &v->data[i]; }
void Global_cAgentData__RegisterDossier(int agent, const char* name)
{
    int found = 0;
    int i;
    DosEntry e;
    char buf[16];
    for (i = 0; i < D_00532B50.count; i++) {
        if (strcmp(At(&D_00532B50, i)->name, name) == 0) {
            found = At(&D_00532B50, i)->index;
            break;
        }
    }
    e.agent = agent;
    e.dossier = found;
    e.unk0C = -1;
    e.num = 0;
    e.flag = 0;
    sprintf(buf, D_004B99A8, e.num + 1);
    e.key = Loc_FindKeyThunk(buf);
    func_00338B60(&D_00532B70, &D_00532B70.data[D_00532B70.count], 1, &e);
}
