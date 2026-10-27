#include "types.h"

typedef struct Tmp16 {
    int a, b, c, d;
} Tmp16;

extern void Libc_Strcpy(Tmp16*);
extern void SFOLobbyList_Append(void*, Tmp16*);

/* Builds a temporary with Libc_Strcpy and passes it to SFOLobbyList_Append(self + 0x54). */
void func_00442670(char* self) {
    Tmp16 tmp;
    Libc_Strcpy(&tmp);
    SFOLobbyList_Append(self + 0x54, &tmp);
}
