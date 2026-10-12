#include "types.h"

/* compiler: Metrowerks (default check.py) */

char D_004988B8[] __attribute__((aligned(8))) = "_pictureTemporalScalableExtension is not supported"; /* 8-aligned in the original data */
extern int func_0010BD90(void* ctx, void* table);

/* Parses the picture temporal scalable extension using its field table. */
int _pictureTemporalScalableExtension(void* ctx)
{
    return func_0010BD90(ctx, D_004988B8);
}
