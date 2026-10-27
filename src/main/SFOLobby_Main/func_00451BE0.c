#include "types.h"
typedef struct {
    char p0[0x1B38]; int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80;
    char p1B84[0x1BE8 - 0x1B84]; char f1BE8[0x40];
    int f1C28; int f1C2C; char p1C30[0x1EB4 - 0x1C30]; int f1EB4; char f1EB8[0x40];
} S451BE0;
extern int D_00497770;
extern char D_004C0FA0[];
extern char D_004C0FA8[];
extern void Libc_Strcpy(char*, char*);
extern char* strrchr(const char*, int);
extern int sprintf(char*, const char*, ...);
extern int SFOLobby_ChannelInfoRequest(S451BE0*, int);
extern int SFOLobby_FindChannel(S451BE0*, char*);
extern int SFOLobby_CreateChannel(S451BE0*, char*, char*);
extern int SFOLobby_JoinChannel(S451BE0*, int, int);

int SFOLobby_HandleOverflowJoinChannel(S451BE0* s, int id)
{
    char buf[0x40];
    int i;
    char* p;

    for (i = 1; i < D_00497770; ) {
        if (!SFOLobby_ChannelInfoRequest(s, id))
            return 0;
        if (s->f1C2C - s->f1C28 > 0) {
            if (!SFOLobby_JoinChannel(s, id, 0))
                return 0;
            s->f1EB4 = id;
            Libc_Strcpy(s->f1EB8, s->f1BE8);
            return 1;
        }
        Libc_Strcpy(buf, s->f1BE8);
        p = strrchr(buf, '_');
        if (!p)
            return 0;
        sprintf(p, D_004C0FA0, i++);
        if (!SFOLobby_FindChannel(s, buf)) {
            if (!SFOLobby_CreateChannel(s, buf, D_004C0FA8))
                return 0;
            if (!SFOLobby_JoinChannel(s, s->f1B38, 0))
                return 0;
            s->f1EB4 = s->f1B38;
            Libc_Strcpy(s->f1EB8, buf);
            return 1;
        }
        id = s->f1B80;
    }
    return 0;
}
