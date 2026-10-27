typedef struct { int pad[4]; int level; } E301E0;
typedef struct { int a; int count; } T301E0;
extern int D_00532B34;
extern E301E0* D_00532B38;
extern void std_vector_charPtr_push_back_charPR_2(T301E0* self, E301E0** e);
#pragma opt_strength_reduction off
void cAgentData_GetLockedParts_cArrayP_int(T301E0* self, int level)
{
    int i;
    self->count = 0;
    for (i = 0; i < D_00532B34; i++) {
        E301E0* e[1];
        E301E0* p = &D_00532B38[i];
        e[0] = p;
        if (level < p->level)
            std_vector_charPtr_push_back_charPR_2(self, e);
    }
}
#pragma opt_strength_reduction reset
