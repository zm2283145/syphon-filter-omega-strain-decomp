extern int *std_list_deleter_TextAtom_generic_iterator_ctor(int *self, int value);
extern int std_list_deleter_TextAtom_tail(char *self);
extern char *details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(char *self);
extern void std_vector_float_push_back(void *v, float *value);

static inline char *At(char *self, int i) { return (*(char ***)(self + 0x60))[i]; }
#pragma opt_strength_reduction off
void GuiSubTitleDisplay_CalcLineTimes(char *self)
{
    float sum;
    int end;
    int i;
    char *list;
    char *n;

    *(int *)(self + 0x6C) = 0;
    sum = 0.0f;
    for (i = 0; i < *(int *)(self + 0x5C); i++) {
        list = At(self, i);
        for (n = *(char **)(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(list + 4) + 4); std_list_deleter_TextAtom_generic_iterator_ctor(&end, std_list_deleter_TextAtom_tail(list)), n != (char *)end; n = *(char **)(n + 4)) {
            sum += *(float *)(n + 0x10);
            sum += *(int *)(n + 0x3C) / 20.0f;
        }
        std_vector_float_push_back(self + 0x68, &sum);
    }
}
#pragma opt_strength_reduction reset

