#include "types.h"

typedef struct Tmp16 {
    int a, b, c, d;
} Tmp16;

extern void String_Copy(Tmp16*);
extern void LobbyArray_Append(void*, Tmp16*);

/* Builds a temporary with String_Copy and passes it to LobbyArray_Append(self + 0x54). */
void func_00442670(char* self) {
    Tmp16 tmp;
    String_Copy(&tmp);
    LobbyArray_Append(self + 0x54, &tmp);
}
