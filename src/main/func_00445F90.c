#pragma cplusplus on
typedef struct { char pad0[4]; unsigned char type; char pad5[3]; int f8; int fC; short pad10; unsigned short len; char* data; } LMsg;
typedef struct { int type; int f4; int f8; char data[0x200]; int len; int code; } LBig;
typedef struct { int type; char pad4[8]; char s0[0x20]; char s1[0x80]; } LSmall;

extern "C" void* memset(void*, int, int);
extern "C" void* memcpy(void*, const void*, int);
extern "C" char* strncpy(char*, const char*, int);
extern "C" int String_CompareNoCase(const char*, const char*);
extern "C" int func_00446340(char*, int);
extern "C" void LobbyArray_Append(void*, void*);
extern "C" int D_00584540;
extern "C" char* D_00584530;
extern "C" char* D_00584534;
extern "C" char* D_00584538;
extern "C" char* D_00585E60;

extern "C" void func_00445F90(LMsg* m) {
    char buf[0x200];
    LBig big;
    LSmall sm;
    unsigned char code;
    int r;
    bool send;

    if (m == 0) return;
    if (m->len >= 0x200) return;
    memset(buf, 0, 0x200);
    memcpy(buf, m->data, m->len);
    r = func_00446340(buf, m->len);
    code = r;
    if ((code == 0 || code == 9) && (code != 0 || m->type == 100)) {
        memset(&big, 0, sizeof(big));
        big.code = (unsigned char)r;
        big.type = m->type;
        big.f4 = m->f8;
        big.f8 = m->fC;
        big.len = m->len;
        if (code == 9) {
            if (D_00584540 == 1)
                strncpy(big.data, D_00584530, 0x200);
            else
                big.data[0] = 0;
        } else {
            memcpy(big.data, m->data, big.len);
        }
        LobbyArray_Append(D_00585E60 + 0x38, &big);
        return;
    }
    if (m->len >= 0x80) return;
    send = false;
    memset(&sm, 0, sizeof(sm));
    switch (code) {
    case 0:
        if (D_00584540 > 0) {
            sm.type = 10;
            strncpy(sm.s1, D_00584530, 0x80);
            send = true;
        }
        break;
    case 1:
        if (D_00584540 == 2) {
            sm.type = 2;
            strncpy(sm.s1, D_00584530, 0x20);
            strncpy(sm.s0, D_00584534, 0x20);
            send = true;
        }
        break;
    case 2:
        if (D_00584540 == 2) {
            sm.type = 6;
            strncpy(sm.s1, D_00584530, 0x20);
            strncpy(sm.s0, D_00584534, 0x20);
            send = true;
        }
        break;
    case 3:
        if (D_00584540 == 2) {
            sm.type = 11;
            strncpy(sm.s1, D_00584530, 0x20);
            strncpy(sm.s0, D_00584534, 0x20);
            send = true;
        }
        break;
    case 4:
    case 5:
        if (D_00584540 == 3) {
            bool acc = !String_CompareNoCase(D_00584538, "ACCEPT");
            sm.type = acc ? 4 : 5;
            strncpy(sm.s1, D_00584530, 0x20);
            strncpy(sm.s0, D_00584534, 0x20);
            send = true;
        }
        break;
    case 6:
    case 7:
        if (D_00584540 == 2) {
            bool acc = !String_CompareNoCase(D_00584534, "ACCEPT");
            sm.type = acc ? 7 : 8;
            strncpy(sm.s0, D_00584530, 0x20);
            send = true;
        }
        break;
    case 8:
        if (D_00584540 == 1) {
            sm.type = 3;
            strncpy(sm.s0, D_00584530, 0x20);
            send = true;
        }
        break;
    }
    if (send)
        LobbyArray_Append(D_00585E60 + 0x1C, &sm);
}
