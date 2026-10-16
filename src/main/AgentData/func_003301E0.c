typedef struct { int pad[4]; int level; } E301E0;
typedef struct { int a; int count; } T301E0;
extern int D_00532B34;
extern E301E0* D_00532B38;
extern void PtrVec_PushBack_330280(T301E0* self, E301E0** e);
#pragma opt_strength_reduction off
void AgentData_AppendLockedParts(T301E0* self, int level)
{
    int i;
    self->count = 0;
    for (i = 0; i < D_00532B34; i++) {
        E301E0* e[1];
        E301E0* p = &D_00532B38[i];
        e[0] = p;
        if (level < p->level)
            PtrVec_PushBack_330280(self, e);
    }
}
#pragma opt_strength_reduction reset
