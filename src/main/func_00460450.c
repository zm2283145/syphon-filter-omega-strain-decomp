#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"

typedef struct {
    int unk0;
    int count;
    int *data;
    unsigned char owns;
} VecI0450;

typedef struct {
    int text;
    int unk4;
    unsigned char type;
    char pad9[0xB];
} Item0450;

typedef struct {
    int unk0;
    int count;
    Item0450 *items;
    unsigned char flag;
} List0450;

typedef struct {
    char pad0[0xB50];
    void *cur;
    void *b54;
    char pad58[0xB70 - 0xB58];
    unsigned char b70;
} Agent0450;

typedef struct {
    char pad0[0x350];
    int vec350;
} Obj0450;

extern "C" {
extern char D_004C25F8[];
extern char D_004C2608[];
extern char D_004C2610[];
extern char D_004FFB50[];
extern unsigned char D_005721C8;
int sprintf(char *buf, const char *fmt, ...);
Agent0450 *Agent_GetSelected(void *a, int i);
void PtrVec_PushBack_1C1080(VecI0450 *v, int *p);
void func_0013A040(VecI0450 *v, int f);
void func_001C10A0(VecI0450 *v);
void func_00296FA0(List0450 *l);
void func_00299360(List0450 *l, short f);
void AgentData_GetAwardRows(Agent0450 *a, unsigned char type, List0450 *out);
void AgentData_GetRatings(Agent0450 *a, List0450 *out);
void VoiceQueue_Push(void *vec, char *name, float seconds);
int *func_00460B40(VecI0450 *v, int i);
int func_00460B50(VecI0450 *v);
void GuiEndGameAwards_QueueVoices(Obj0450 *o);
}

static inline bool HasCur(Agent0450 *a)
{
    bool ok = false;
    if (a->b54 != 0 && a->cur != a->b54)
        ok = true;
    return ok;
}

static inline void Report(Obj0450 *o, VecI0450 *v, int kind)
{
    char buf[32];
    int n = func_00460B50(v);
    if (n != 0) {
        if (n > 1) {
            int i;
            for (i = 0; i < func_00460B50(v); i++) {
                sprintf(buf, D_004C2610, *func_00460B40(v, i) + 1);
                VoiceQueue_Push(&o->vec350, buf, 0.0f);
            }
            sprintf(buf, D_004C2608, kind);
            VoiceQueue_Push(&o->vec350, buf, 1.0f);
        } else {
            sprintf(buf, D_004C25F8, kind, *func_00460B40(v, 0) + 1);
            VoiceQueue_Push(&o->vec350, buf, 1.0f);
        }
    }
}

void GuiEndGameAwards_QueueVoices(Obj0450 *o)
{
    VecI0450 v6;
    VecI0450 v9;
    VecI0450 v8;
    VecI0450 v7;
    int idx;
    int n;

    func_001C10A0(&v6);
    v6.owns = 1;
    func_001C10A0(&v9);
    v9.owns = 1;
    func_001C10A0(&v8);
    v8.owns = 1;
    func_001C10A0(&v7);
    v7.owns = 1;
    n = D_005721C8 ? 4 : 1;
    for (idx = 0; idx < n; idx++) {
        Agent0450 *agent = Agent_GetSelected(D_004FFB50, idx);
        List0450 list;
        func_00296FA0(&list);
        list.flag = 1;
        if (agent->b70) {
            if (HasCur(agent))
                PtrVec_PushBack_1C1080(&v6, &idx);
            AgentData_GetRatings(agent, &list);
                        { int j = 0; Item0450** pit = &list.items;
            if (j < list.count) do { if ((*pit)[j].type == 1) { PtrVec_PushBack_1C1080(&v7, &idx); break; } } while (++j < list.count); }


            AgentData_GetAwardRows(agent, 1, &list);
            {
                int j = 0;
                if (j < list.count) do {
                    if (list.items[j].type == 1) {
                        PtrVec_PushBack_1C1080(&v8, &idx);
                        break;
                    }
                } while (++j < list.count);
            }
            AgentData_GetAwardRows(agent, 2, &list);
            {
                int j = 0;
                if (j < list.count) do {
                    if (list.items[j].type == 1) {
                        PtrVec_PushBack_1C1080(&v9, &idx);
                        break;
                    }
                } while (++j < list.count);
            }
        }
        func_00299360(&list, 0);
    }
    Report(o, &v6, 6);
    Report(o, &v7, 7);
    Report(o, &v8, 8);
    Report(o, &v9, 9);
    func_0013A040(&v7, -1);
    func_0013A040(&v8, -1);
    func_0013A040(&v9, -1);
    func_0013A040(&v6, -1);
}
