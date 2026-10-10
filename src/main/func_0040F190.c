#include "types.h"

typedef struct MemCard {
    int iconSys;
    char pad[0x10];
    int unk14;
    char pad2[0x400 - 0x18];
    int iconParams[3];
    char pad3[0x440 - 0x40C];
    char iconData[0x100];
    int unk540, unk544, unk548, unk54C, unk550;
    int pad554;
    int unk558;
    int pad55C;
    int unk560, unk564, unk568, unk56C;
    char pad4[0x2C];
    unsigned char flag59C, flag59D, flag59E, flag59F, flag5A0;
    char pad5[3];
    int unk5A4;
} MemCard;

extern int func_002B4F10(int* params, char* data);
extern void String_Copy(char* dst, const char* src); /* String_Copy */
extern void strncpy(void* dst, const void* src, int size); /* strncpy-style copy */
extern void func_0040F290(void* dst, const void* src, int size);
extern char* D_00494008;
extern char D_00493D84[], D_00493D44[], D_00493DC4[], D_00493C40[], D_004BEDA8[], D_00493D00[], D_004BEDB0[];

/* Resets the memory card state and builds the icon.sys header strings. */
MemCard* MemCard_SetupIconSys(MemCard* self) {
    self->iconParams[0] = 2;
    self->iconParams[1] = 2;
    self->iconParams[2] = 0;
    self->iconSys = func_002B4F10(self->iconParams, self->iconData);
    self->unk540 = 0;
    self->unk544 = 0;
    self->unk548 = 0;
    self->unk54C = 0;
    self->unk550 = 0;
    self->unk560 = 0;
    self->unk564 = 0;
    self->unk568 = 0;
    self->unk14 = 0x10;
    self->unk558 = 0;
    self->unk56C = 0;
    self->flag59D = 0;
    self->flag59E = 0;
    self->flag59F = 0;
    self->flag5A0 = 0;
    self->flag59C = 0;
    self->unk5A4 = 0;
    String_Copy(D_00493D84, D_00494008);
    String_Copy(D_00493D44, D_00494008);
    String_Copy(D_00493DC4, D_00494008);
    strncpy(D_00493C40, D_004BEDA8, 4);
    func_0040F290(D_00493D00, D_004BEDB0, 0x20);
    return self;
}
