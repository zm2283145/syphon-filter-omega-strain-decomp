#include "types.h"

typedef struct {
    char voice[8];
    int duration;
} Line_463390;

typedef struct {
    char pad0[0xB70];
    unsigned char bB70;
    char padB71[3];
    unsigned char bB74;
} Agent_463390;

typedef struct {
    int unk0;
    int count;
    int* data;
    unsigned char owned;
} IntVec_463390;

typedef struct {
    char pad0[0x254];
    unsigned char b254;
    unsigned char b255;
    char pad256[0x260 - 0x256];
    char lines[0xC];        /* 0x260 */
} Self_463390;

extern char D_004FFB50[];
extern unsigned char D_005721C8;
extern char D_004C27A0[];
extern char D_004C27A8[];
extern char D_004C2610[];
extern char D_004C2608[];
extern char D_004C25F8[];
extern int D_00497BD8[];
extern Agent_463390* Agent_GetSelected(void* mgr, int idx);
extern int cAgentData_GetStat(Agent_463390* agent, int stat);
extern int sprintf(char* buf, const char* fmt, ...);
extern Line_463390* func_00462650(Line_463390* line, char* voice, int duration);
extern void func_00462620(void* vec, Line_463390* line);
extern void func_001C10A0(IntVec_463390* v);
extern void PtrVec_PushBack_1C1080(IntVec_463390* v, int* value);
extern int func_00460B50(IntVec_463390* v);
extern int* func_00460B40(IntVec_463390* v, int i);
extern void VoiceQueue_Push(void* vec, char* name, float seconds);
extern void func_0013A040(IntVec_463390* v, int flags);

static inline int Pct_463390(Agent_463390* ag, int total, int part)
{
    int r = 0;
    int d = cAgentData_GetStat(ag, total);
    int v = cAgentData_GetStat(ag, part);
    if (d) r = v * 100 / d;
    return r;
}

void GuiEndGameStatistics_QueueVoices(Self_463390* self)
{
    char buf[32];
    IntVec_463390 list;
    char name[32];
    int n;

    if (D_005721C8) {
        int bestA = 0;
        int bestB = 0;
        int idxA = -1;
        int idxB = -1;
        int i;
        for (i = 0; i < 4; i++) {
            Agent_463390* a = Agent_GetSelected(D_004FFB50, i);
            if (a->bB70 && a->bB74) {
                int pa = Pct_463390(Agent_GetSelected(D_004FFB50, i), 0x1D, 0x1E);
                int pb = Pct_463390(Agent_GetSelected(D_004FFB50, i), 0x1B, 0x1C);
                if (bestA < pa) {
                    bestA = pa;
                    idxA = i;
                }
                if (bestB < pb) {
                    bestB = pb;
                    idxB = i;
                }
            }
        }
        if (!self->b254) {
            self->b254 = 1;
            if (-1 < idxA) {
                Line_463390 line;
                sprintf(buf, D_004C27A0, idxA + 1);
                func_00462650(&line, buf, 0x1E);
                func_00462620(self->lines, &line);
            }
        }
        if (!self->b255) {
            self->b255 = 1;
            if (-1 < idxB) {
                Line_463390 line;
                sprintf(buf, D_004C27A8, idxB + 1);
                func_00462650(&line, buf, 0x1E);
                func_00462620(self->lines, &line);
            }
        }
    }
    func_001C10A0(&list);
    list.owned = 1;
    if (D_005721C8) {
        int i;
        for (i = 0; i < 4; i++) {
            Agent_463390* a = Agent_GetSelected(D_004FFB50, i);
            if (a->bB70 && a->bB74 && !cAgentData_GetStat(Agent_GetSelected(D_004FFB50, i), 0x1A))
                PtrVec_PushBack_1C1080(&list, &i);
        }
    } else {
        if (Agent_GetSelected(D_004FFB50, -1)->bB74 && !cAgentData_GetStat(Agent_GetSelected(D_004FFB50, -1), 0x1A))
            PtrVec_PushBack_1C1080(&list, D_00497BD8);
    }
    n = func_00460B50(&list);
    if (n) {
        if (n > 1) {
            int j;
            for (j = 0; j < func_00460B50(&list); j++) {
                sprintf(name, D_004C2610, *func_00460B40(&list, j) + 1);
                VoiceQueue_Push(self->lines, name, 0.0f);
            }
            sprintf(name, D_004C2608, 5);
            VoiceQueue_Push(self->lines, name, 1.0f);
        } else {
            sprintf(name, D_004C25F8, 5, *func_00460B40(&list, 0) + 1);
            VoiceQueue_Push(self->lines, name, 1.0f);
        }
    }
    func_0013A040(&list, -1);
}





