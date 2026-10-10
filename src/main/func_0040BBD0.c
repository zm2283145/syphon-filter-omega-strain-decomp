#include "types.h"

typedef struct HolderWord {
    char pad00[8];
    int value;
} HolderWord;

/* Copy the holder's word through the two value-object temporaries. */
void func_0040BBD0(Word* result, const HolderWord* source)
{
    Word first;
    Word second;
    first.value = source->value;
    second = first;
    result->value = second.value;
}
