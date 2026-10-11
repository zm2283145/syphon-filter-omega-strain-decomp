#include "types.h"
extern char* D_005061D0;
extern int strlen(const char* s);
static inline void W16_00281C80(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
void func_00281C80(char* str) {
    int n = strlen(str) + 1;
    int i;
    W16_00281C80(n);
    for (i = 0; i < n; i++) *D_005061D0++ = str[i];
}