#include "MovieSubtitles_types.h"

/* Return the final float field of the selected subtitle transform. */
float func_00412110(SubtitleTransformTable* table)
{
    return table->entries[table->current].unk134;
}
