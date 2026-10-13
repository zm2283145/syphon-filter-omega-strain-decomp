#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_NoInstance();
extern SFOLobby * D_00585E60;

typedef struct { char c[21]; } SCc21;
typedef struct { int c[39]; } SCi39;
/* Reply callback: flags gotReply210 and copies the 0xBC-byte reply into reply1C30. */
void func_0044E280(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    int *var_a2_2;
    int *var_a1_2;
    signed char *var_a1;
    signed char *var_a2;
    int var_a0;
    int var_a0_2;

    if (SFOLobby_NoInstance() == 0) {
        var_a0 = 0x15;
        var_a2 = arg3;
        D_00585E60->gotReply210 = 1;
        temp_a3 = (signed char *)D_00585E60->reply1C30;
        var_a1 = temp_a3;
        *(SCc21 *)(temp_a3) = *(SCc21 *)(arg3);
        var_a2_2 = arg3 + 0x20;
        var_a1_2 = temp_a3 + 0x20;
        var_a0_2 = 0x27;
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
        F_(temp_a3, 0x1C, int) = F_(arg3, 0x1C, int);
        *(SCi39 *)(temp_a3 + 0x20) = *(SCi39 *)(arg3 + 0x20);
    }
}
