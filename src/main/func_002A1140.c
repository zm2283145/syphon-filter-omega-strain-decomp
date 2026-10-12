typedef struct { char pad[0x32]; unsigned char unk32; } G_2A1140;
typedef struct { int unk0; char name[4]; } Ctl_2A1140;
typedef struct { char pad[0xDC]; Ctl_2A1140* unkDC; Ctl_2A1140* unkE0; } Obj_2A1140;

extern int String_AssignCStr_1C43A0(void*, const char*);
extern void func_0033C320(Obj_2A1140*, int);
extern void func_002A0F60(Obj_2A1140*);
extern void func_002A1590(Obj_2A1140*, int);
extern void func_002A1600(Obj_2A1140*, int);
extern int func_0033CF90(Obj_2A1140*, Ctl_2A1140*, unsigned int, int, int);
extern const char* D_0048BA40;
extern const char* D_0048BA48;
extern const char* D_0048BA60;
extern G_2A1140* D_004FFC04;
extern unsigned char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;

int func_002A1140(Obj_2A1140* self, Ctl_2A1140* ctl, unsigned int msg, int code, int param)
{
    unsigned short m = msg;

    if ((m == 27 || m == 26) && code == 11) {
        func_0033C320(self, 1);
        return 1;
    }
    if (m == 2) {
        if (String_AssignCStr_1C43A0(ctl->name, D_0048BA60) == 0) {
            func_002A0F60(self);
            return 1;
        }
        if (String_AssignCStr_1C43A0(ctl->name, D_0048BA40) == 0) {
            func_002A1590(self, 1);
            return 1;
        }
        if (String_AssignCStr_1C43A0(ctl->name, D_0048BA48) == 0) {
            func_002A1600(self, 1);
            return 1;
        }
    }
    if (m == 16 && code == 1 && (ctl == self->unkE0 || ctl == self->unkDC)) {
        return 1;
    }
    if (m == 30 && D_004FFC04->unk32 == 0) {
        D_005064B0 = code;
        D_005064B8 = param;
        D_005064A8 = 1;
        return 1;
    }
    return func_0033CF90(self, ctl, msg, code, param);
}
