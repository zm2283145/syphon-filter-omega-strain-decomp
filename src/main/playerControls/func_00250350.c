#include "types.h"

typedef struct { int unk0; int words[1]; } PrioritySet;

/* Returns 1 if bit n is set in the priority set. */
int PrioritySet_Test(PrioritySet* set, int n)
{
    return ((set->words[n / 32] >> (n & 31)) & 1) != 0;
}
