/*
 * lib/medius: 14 files, 002F4FF0-002F5138
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F4FF0 */
#include "types.h"

extern int RemovePlayer(int);

int rt_audio_remove_player(int a0) {
    return RemovePlayer(a0);
}
/* merge_units: end func_002F4FF0 */

/* merge_units: begin func_002F5008 */
extern int SetIgnoreFlag(int, int, int);

int rt_audio_set_ignore(int a0, int a1, int a2) {
    return SetIgnoreFlag(a0, a1, a2);
}
/* merge_units: end func_002F5008 */

/* merge_units: begin func_002F5020 */
extern int JoinChannel(int, int);

int rt_audio_join_channel(int a0, int a1) {
    return JoinChannel(a0, a1);
}
/* merge_units: end func_002F5020 */

/* merge_units: begin func_002F5038 */
extern int QuitChannel(int, int);

int rt_audio_quit_channel(int a0, int a1) {
    return QuitChannel(a0, a1);
}
/* merge_units: end func_002F5038 */

/* merge_units: begin func_002F5050 */
extern int func_002DACB0(int);

int rt_audio_get_state(int a0) {
    return func_002DACB0(a0);
}
/* merge_units: end func_002F5050 */

/* merge_units: begin func_002F5068 */
extern int UpdateAudio(int);

int rt_audio_update(int a0) {
    return UpdateAudio(a0);
}
/* merge_units: end func_002F5068 */

/* merge_units: begin func_002F5080 */
extern int StreamInput(int, int, int, int);

int rt_audio_write(int a0, int a1, int a2, int a3) {
    return StreamInput(a0, a1, a2, a3);
}
/* merge_units: end func_002F5080 */

/* merge_units: begin func_002F5098 */
extern int DestroyAudio(int);

void rt_audio_destroy(int a0) {
    int v0;
    int cond;

    cond = a0 == 0;
    if (cond) goto L002F50B0;
    v0 = DestroyAudio(a0);
    goto ret;
L002F50B0:;
    goto ret;
ret:;
}
/* merge_units: end func_002F5098 */

/* merge_units: begin func_002F50C0 */
extern int EnumChannel(int, int, int);

int rt_audio_enum_channel(int a0, int a1, int a2) {
    return EnumChannel(a0, a1, a2);
}
/* merge_units: end func_002F50C0 */

/* merge_units: begin func_002F50D8 */
extern int EnumPlayer(int, int, int);

int rt_audio_enum_players(int a0, int a1, int a2) {
    return EnumPlayer(a0, a1, a2);
}
/* merge_units: end func_002F50D8 */

/* merge_units: begin func_002F50F0 */
extern int EnumChannelPlayer(int, int, int, int);

int rt_audio_enum_channel_players(int a0, int a1, int a2, int a3) {
    return EnumChannelPlayer(a0, a1, a2, a3);
}
/* merge_units: end func_002F50F0 */

/* merge_units: begin func_002F5108 */
extern int EnumConnectedPlayer(int, int, int, int);

int rt_audio_enum_connected_players(int a0, int a1, int a2, int a3) {
    return EnumConnectedPlayer(a0, a1, a2, a3);
}
/* merge_units: end func_002F5108 */

/* merge_units: begin func_002F5120 */
extern int SetRedundancyOff(int, int);

int rt_audio_set_redundancy_off(int a0, int a1) {
    return SetRedundancyOff(a0, a1);
}
/* merge_units: end func_002F5120 */

/* merge_units: begin func_002F5138 */
extern int GetCPULoad(int, int, int, int, int);

int rt_audio_get_cpu_load(int a0, int a1, int a2, int a3, int t0) {
    return GetCPULoad(a0, a1, a2, a3, t0);
}
/* merge_units: end func_002F5138 */
