#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation on
#pragma opt_dead_assignments off
/* GuiAgentCreate::UpdateClones: refresh sex/race from the preview man, then clone the preview man into the
   neighbouring people slots (GuiAgentCreate::CloneMan inlined) and re-randomise the far one. */
#include "types.h"
typedef struct {
    char pad[0x40];
    char app[0x30];
    __int128 save70;
    char pad2[0x2C04 - 0x80];
    int keep;
    char pad3[0x2C10 - 0x2C08];
    signed char preset;
    char pad4[0x2DF0 - 0x2C11];
} __attribute__((aligned(16))) Man_CB20;
typedef struct { char pad[0x60]; Man_CB20 man; } Obj_CB20;
typedef struct {
    char pad0[0x60]; Obj_CB20* people01[2];
    Obj_CB20* people2;
    Obj_CB20* people3;
    Obj_CB20* man;
    void CloneMan(Man_CB20* s, Man_CB20* src);
    char pad74[0xD8 - 0x74];
    int sex;
    int race;
} GAC_CB20;
extern "C" {
void cMan_SetBoneSet(Man_CB20* s, int preset);
int SKL_FindSex(void* app);
signed char SKL_FindRace(void* app);
void GuiAgentCreate_Randomize_2(GAC_CB20* self, Man_CB20* skel, int dir);
void GuiAgentCreate_UpdateClones(GAC_CB20* self, int dir, int newClones);
}
static inline char* App_CB20(Man_CB20* m) { return m->app; }

static inline void QCopy_CB20(void* d0, void* s0, int nn) { int n = nn; void* s = s0; void* d = d0;
    asm {
        .set noreorder
            lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
inline void GAC_CB20::CloneMan(Man_CB20* s, Man_CB20* src)
{
    __int128 q = s->save70;
    int k = s->keep;
    QCopy_CB20(s, src, 0x2DF0 / 16);
    s->keep = k;
    cMan_SetBoneSet(s, s->preset);
    s->save70 = q;
}
void GuiAgentCreate_UpdateClones(GAC_CB20* self, int dir, int newClones)
{
    self->sex = SKL_FindSex(App_CB20(&self->man->man));
    self->race = SKL_FindRace(App_CB20(&self->man->man));
    if (newClones) {
        if (dir == 1) {
            self->CloneMan(&self->people2->man, &self->man->man);
            { Man_CB20* src = &self->people3->man; self->CloneMan(&self->man->man, src); }
            GuiAgentCreate_Randomize_2(self, &self->people3->man, dir);
        } else {
            self->CloneMan(&self->people3->man, &self->man->man);
            { Man_CB20* m = &self->man->man; self->CloneMan(m, &self->people2->man); }
            GuiAgentCreate_Randomize_2(self, &self->people2->man, dir);
        }
    } else {
        GuiAgentCreate_Randomize_2(self, &self->people2->man, -1);
        GuiAgentCreate_Randomize_2(self, &self->people3->man, 1);
    }
    self->sex = SKL_FindSex(App_CB20(&self->man->man));
    self->race = SKL_FindRace(App_CB20(&self->man->man));
}
