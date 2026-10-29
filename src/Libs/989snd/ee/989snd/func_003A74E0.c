#include "types.h"
#include "989snd.h"

typedef struct SndCommandBuffer {
    int num_commands;
    char buffer[4092];
} SndCommandBuffer;

typedef struct SndCommandReturnDef {
    void (*done)(unsigned int, unsigned long);
    unsigned long u_data;
} SndCommandReturnDef;

extern void SyncDCache(void*, void*);
extern void printf(char* fmt, ...);
extern int sceSifCheckStatRpc(void* cd);
extern void FlushCache(int);
extern int sceSifCallRpc(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
extern void snd_FlushSoundCommands(void);
extern void* memcpy(void*, void*, int);

extern char D_0053DBC0[];
extern int* D_0053DBE8;
extern int D_0053DBF0;
extern int D_0053DC40;
extern int D_0053DC48;
extern int D_00542840;
extern int D_00542848;
extern SndCommandBuffer* D_004934E0[2];
extern int D_004934E8[2];
extern SndCommandReturnDef* D_004934F0[2];
extern char D_004BCA50[];
extern char D_004BCA80[];
extern char D_004BCAE0[];

void snd_SendIOPCommandNoWait(int command, int data_size, char* data, void (*done)(unsigned int, unsigned long), unsigned long long u_data)
{
    int x;
    int was_caching = 0;
    int y;
    char* msg;
    int msg_size;
    unsigned int* data_hold;

    if (!D_00542848 && !D_0053DBE8 && !data_size && !done) {
        D_0053DC48 = 0;
        D_0053DBF0 = 1;
        D_0053DBE8 = &D_0053DC40;
        D_0053DC40 = 0;
        SyncDCache(&D_0053DC40, (char*)&D_0053DC40 + 3);
        SyncDCache(&D_0053DC48, (char*)&D_0053DC48 + 3);
        while (sceSifCheckStatRpc(D_0053DBC0)) {
            if (!snd_quiet) printf(snd_rpcCollisionMsg);
            snd_FlushSoundCommands();
            FlushCache(0);
        }
        sceSifCallRpc(D_0053DBC0, command, 1, 0, 0, &D_0053DC40, 12, 0, 0);
        return;
    }

    msg_size = data_size + 4;
    y = 0;
    if (msg_size % 4) msg_size += 4 - msg_size % 4;
    if (msg_size > 512) {
        printf(D_004BCA50);
        while (1) {}
    }
    while (D_004934E0[D_00542840]->num_commands == 256 || D_004934E8[D_00542840] < msg_size) {
        if (D_00542848) {
            was_caching = 1;
            D_00542848 = 0;
        }
        snd_FlushSoundCommands();
        if (y == 1 && !snd_quiet)
            printf(D_004BCA80, D_00542840, D_004934E0[D_00542840]->num_commands);
        y++;
    }
    if (y && !snd_quiet) printf(D_004BCAE0, y);
    if (was_caching) D_00542848 = 1;

    msg = &D_004934E0[D_00542840]->buffer[0xFFC - D_004934E8[D_00542840]];
    ((short*)msg)[0] = command;
    ((short*)msg)[1] = data_size;
    msg += 4;
    if (command != 0x68) {
        for (x = 0; x < data_size; x++) msg[x] = data[x];
    } else {
        for (x = 0; x < 12; x++) msg[x] = data[x];
        data_hold = ((unsigned int**)data)[3];
        memcpy(msg + 12, data_hold, ((int*)data)[2]);
    }
    D_004934E8[D_00542840] -= msg_size;
    D_004934F0[D_00542840][D_004934E0[D_00542840]->num_commands].done = done;
    D_004934F0[D_00542840][D_004934E0[D_00542840]->num_commands].u_data = u_data;
    D_004934E0[D_00542840]->num_commands++;
    snd_FlushSoundCommands();
}