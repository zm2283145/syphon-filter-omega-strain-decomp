typedef struct { int a, b, need; int pad[6]; } E32BB0;
extern int D_00532B74;
extern E32BB0* D_00532B78;
extern int AgentData_TotalPoints(void* self);
int func_00332BB0(void* self, int i)
{
    if (i >= 0 && i < D_00532B74) {
        E32BB0* e = D_00532B78 + i;
        int need = e->need;
        if (need <= AgentData_TotalPoints(self))
            return 1;
    }
    return 0;
}