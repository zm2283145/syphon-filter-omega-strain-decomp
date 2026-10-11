#include "types.h"
extern char* D_005061D0;
static inline short R16_00281E90(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline char R8_00281E90(void) { return *D_005061D0++; }
void func_00281E90(char* str) {
    int n = R16_00281E90();
    int i;
    for (i = 0; i < n; i++) str[i] = R8_00281E90();
}