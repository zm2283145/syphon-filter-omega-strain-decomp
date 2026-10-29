#pragma cplusplus on
#include "types.h"

typedef __int128 u_long128;

struct manAttribs {
    u_long128 partName;
    u_long128 texName;
};

struct SKL {
    u_long128 hdr[4];
    manAttribs manAttribsTable[32];
};

struct cMan {
    char bbox[0x20];
    char SKLName[0x20];
    SKL skl;
};

struct cSKM_GOBJ {
    char gobj[0x60];
    cMan mModel;
};

typedef struct {
    signed char menu;
    unsigned char part;
    short count;
} tSelInfo;

struct GuiAgentCreate {
    char widget[0x70];
    cSKM_GOBJ* man;
    char pad74[0xC4 - 0x74];
    int selectionCount;
    int selectionItem;
    char padCC[0xD8 - 0xCC];
    int sex;
    int race;
    char padE0[0xED - 0xE0];
    char bodyPart;
    char partTexMode;
    char menuOption;
};

struct Monster;

extern "C" {
extern Monster g_AgentPartCache;
extern u_long128 D_0055DE00;
extern int D_00571300;
extern tSelInfo D_0048B500[][11];
int SKL_FindSex(SKL*);
char SKL_FindRace(SKL*);
int Monster_CountPartsByName(Monster*, u_long128, int*, int, int);
int Monster_CountTexByName(Monster*, u_long128, int*, int, int, int);
int cMan_CountFaceShapes(int);
}

/* MMI select: (part & mask) | (tex & ~mask); MW has no 128-bit C bitwise operators */
static inline u_long128 Blend(u_long128 p, u_long128 x, u_long128 mask)
{
    u_long128 r, t;
    asm {
        pnor t, mask, mask
        pand r, p, mask
        pand t, x, t
        por t, t, r
    }
    return t;
}

static inline u_long128 GetTexName(cMan* m, int i)
{
    u_long128 x, p, k;
    p = m->skl.manAttribsTable[i].partName;
    x = m->skl.manAttribsTable[i].texName;
    k = D_0055DE00;
    return Blend(p, x, k);
}

#pragma push
#pragma opt_propagation off
extern "C" void GuiAgentCreate_CountSelections(GuiAgentCreate* self)
{
    int command;
    int selection = -1;
    if (self->menuOption >= 11) {
        self->selectionItem = 0;
        return;
    }
    self->sex = SKL_FindSex(&self->man->mModel.skl);
    self->race = SKL_FindRace(&self->man->mModel.skl);
    self->bodyPart = D_0048B500[self->sex][self->menuOption].part;
    command = (unsigned char)D_0048B500[self->sex][self->menuOption].menu;
    if (command == 0) {
        self->selectionCount = Monster_CountPartsByName(&g_AgentPartCache, self->man->mModel.skl.manAttribsTable[self->bodyPart].partName, &selection, self->sex, 0);
    }
    if (command == 7) {
        self->selectionCount = Monster_CountPartsByName(&g_AgentPartCache, self->man->mModel.skl.manAttribsTable[self->bodyPart].partName, &selection, self->sex, 1);
    }
    if (command == 1) {
        self->selectionCount = Monster_CountTexByName(&g_AgentPartCache, GetTexName(&self->man->mModel, self->bodyPart), &selection, self->sex, self->race, 2);
    }
    if (command == 2) {
        self->selectionCount = Monster_CountTexByName(&g_AgentPartCache, self->man->mModel.skl.manAttribsTable[self->bodyPart].texName, &selection, self->sex, self->race, 0);
    }
    if (command == 3) {
        self->selectionCount = 100;
    }
    if (command == 4) {
        self->selectionCount = 2;
    }
    if (command == 5) {
        self->selectionCount = D_00571300;
    }
    if (command == 6) {
        self->selectionCount = cMan_CountFaceShapes(self->sex);
    }
    if (command == 8) {
        self->selectionCount = Monster_CountTexByName(&g_AgentPartCache, self->man->mModel.skl.manAttribsTable[self->bodyPart].texName, &selection, self->sex, self->race, 1);
    }
    if (selection != -1) {
        D_0048B500[self->sex][self->menuOption].count = selection;
    }
    self->selectionItem = D_0048B500[self->sex][self->menuOption].count;
}
#pragma pop
