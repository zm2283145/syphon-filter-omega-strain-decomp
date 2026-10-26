/*
 * lib/medius: 7 files, 002F4EE0-002F4FB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F4EE0 */
#include "types.h"

extern int CreateAudio(void);
extern int InitializeAudio(int, int);

int rt_audio_initialize(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = CreateAudio();
    tmp2 = InitializeAudio(tmp0, a1);
    *(int*)((char*)a0) = tmp0;
    return tmp2;
}
/* merge_units: end func_002F4EE0 */

/* merge_units: begin func_002F4F30 */
extern int ResolveAddress(int, int, int, int);

int rt_audio_resolve_address(int a0, int a1, int a2, int a3) {
    return ResolveAddress(a0, a1, a2, a3);
}
/* merge_units: end func_002F4F30 */

/* merge_units: begin func_002F4F48 */
extern int CreateChannel(int, int, int, int);

int rt_audio_create_channel(int a0, int a1, int a2, int a3) {
    return CreateChannel(a0, a1, a2, a3);
}
/* merge_units: end func_002F4F48 */

/* merge_units: begin func_002F4F60 */
extern int Quit(int);

int rt_audio_quit(int a0) {
    return Quit(a0);
}
/* merge_units: end func_002F4F60 */

/* merge_units: begin func_002F4F78 */
extern int SetLocalID(int, int);

int rt_audio_set_local_id(int a0, int a1) {
    return SetLocalID(a0, a1);
}
/* merge_units: end func_002F4F78 */

/* merge_units: begin func_002F4F90 */
extern int GetLocalID(int, int);

int rt_audio_get_local_id(int a0, int a1) {
    *(int*)((char*)a1) = (0 | 65535);
    return GetLocalID(a0, a1);
}
/* merge_units: end func_002F4F90 */

/* merge_units: begin func_002F4FB0 */
extern int GetClientInfo(int, int, int);

int rt_audio_get_client_info(int a0, int a1, int a2) {
    return GetClientInfo(a0, a1, a2);
}
/* merge_units: end func_002F4FB0 */
