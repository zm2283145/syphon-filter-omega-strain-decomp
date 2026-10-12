#include "types.h"
void Stats_Add(int* stats, unsigned char idx, int n)
{
    if (idx < 31 && n > 0) {
        stats[idx + 2] += n;
        if (idx < 13) {
            stats[idx + 20] += n;
        }
    }
}