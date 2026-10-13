#pragma opt_strength_reduction off
#include "types.h"
typedef struct { char pad[0x1C]; unsigned char used; char pad1D[3]; int cat; int idx; int sub; } Item6DE0;
typedef struct { char pad[0x14]; Item6DE0* items; char pad18[4]; int sel; char pad20[0]; } Grp6DE0;
typedef struct { char pad[0x48]; char list[8]; Grp6DE0* groups; char pad54[4]; int sel; } Menu6DE0;
typedef struct { char pad[0x25C]; int db; } G6DE0;
extern G6DE0* D_004FFC04;
extern char D_004FFB50[];
extern char D_004B8748[];
extern char D_004B8758[];
extern char D_004B8768[];
extern char D_004B8778[];
int Agent_GetSelected(void*, int);
int Loc_LookupText(char*);
void String_Copy(char*, char*);
int func_00328140(Menu6DE0*, int, char*, int, char*);
void func_00328310(Menu6DE0*, int);
void func_0032A280(void*);
int func_003329B0(int, int, int, int);
int Hog_FindFileNoCase(int, char*, int);
int sprintf(char*, const char*, ...);
static inline Grp6DE0* G(Menu6DE0* m, int i) { return &m->groups[i]; }
void func_00326DE0(Menu6DE0* self, int cat, int selIdx, int selVal, int flag)
{
    int i;
    int j;
    unsigned char ok;
    int agent;
    int db;
    int r;
    char buf[32];
    char buf2[16];
    func_0032A280(self->list);
    self->sel = -1;
    if (cat <= 0 || cat > 18) return;
    db = D_004FFC04->db;
    if (db == 0) return;
    agent = Agent_GetSelected(D_004FFB50, -1);
    for (i = 0; i < 5; i++) {
        sprintf(buf, D_004B8748, i);
        func_00328310(self, Loc_LookupText(buf));
        for (j = 1; ; j++) {
            sprintf(buf, D_004B8758, cat, i + 1, j);
            if (Hog_FindFileNoCase(db, buf, 1) == -1) break;
            ok = 1;
            if (!func_003329B0(agent, cat, i, j - 1)) {
                if (flag) continue;
                String_Copy(buf, D_004B8768);
                ok = 0;
            }
            if (ok) {
                sprintf(buf2, D_004B8778, cat, i + 1, j);
                r = func_00328140(self, i, buf, db, buf2);
                if (r != -1) {
                    Item6DE0* it = &G(self, i)->items[r];
                    it->used = 1;
                    it->cat = cat;
                    it->idx = i;
                    it->sub = j - 1;
                }
            } else {
                func_00328140(self, i, buf, db, 0);
            }
        }
    }
    self->sel = selIdx;
    G(self, selIdx)->sel = selVal;
}



