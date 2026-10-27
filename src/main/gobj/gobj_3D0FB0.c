#include "types.h"

typedef struct { int unk0; int list1; int head1; int first1; int list2; int head2; int first2; } Obj;
extern void std_list_deleter_cText_erase(void* result, void* list, int* first, int* last);
extern void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(void* result, void* list, int* first, int* last);

/* Clears both object lists (erase whole range). */
void cTextSystem_Clear(Obj* self)
{
    int last2;
    int first2;
    int r2;
    int last1;
    int first1;
    int r1;
    last1 = (int)&self->head1;
    first1 = self->first1;
    std_list_deleter_cText_erase(&r1, &self->list1, &first1, &last1);
    last2 = (int)&self->head2;
    first2 = self->first2;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r2, &self->list2, &first2, &last2);
}
