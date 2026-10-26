/*
 * lib/medius: 17 files, 002F7B48-002F7CD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7B48 */
#include "types.h"

extern int rt_comm_platform2_startup(void);

int rt_comm_platform_startup(void) {
    return rt_comm_platform2_startup();
}
/* merge_units: end func_002F7B48 */

/* merge_units: begin func_002F7B60 */
extern int rt_comm_platform2_shutdown(void);

int rt_comm_platform_shutdown(void) {
    return rt_comm_platform2_shutdown();
}
/* merge_units: end func_002F7B60 */

/* merge_units: begin func_002F7B78 */
extern int Socket_Construct(float);

int rt_comm_platform_create(float f12) {
    return Socket_Construct(f12);
}
/* merge_units: end func_002F7B78 */

/* merge_units: begin func_002F7B90 */
extern int rt_comm_platform2_destroy(int);

int rt_comm_platform_destroy(int a0) {
    return rt_comm_platform2_destroy(a0);
}
/* merge_units: end func_002F7B90 */

/* merge_units: begin func_002F7BA8 */
extern int rt_comm_platform2_send(int, int, int, int);

int rt_comm_platform_send(int a0, int a1, int a2, int a3) {
    return rt_comm_platform2_send(a0, a1, (a2 & 65535), a3);
}
/* merge_units: end func_002F7BA8 */

/* merge_units: begin func_002F7BC0 */
extern int rt_comm_platform2_send_to(int, int, int, int, int, int);

int rt_comm_platform_send_to(int a0, int a1, int a2, int a3, int t0, int t1) {
    return rt_comm_platform2_send_to(a0, a1, (a2 & 65535), a3, (t0 & 65535), t1);
}
/* merge_units: end func_002F7BC0 */

/* merge_units: begin func_002F7BE0 */
extern int rt_comm_platform2_send_echo(int, int, int, int);

int rt_comm_platform_send_echo(int a0, int a1, int a2, int a3) {
    return rt_comm_platform2_send_echo(a0, a1, a2, (a3 & 65535));
}
/* merge_units: end func_002F7BE0 */

/* merge_units: begin func_002F7BF8 */
extern int rt_comm_platform2_receive(int, int, int, int);

int rt_comm_platform_receive(int a0, int a1, int a2, int a3) {
    return rt_comm_platform2_receive(a0, a1, (a2 & 65535), a3);
}
/* merge_units: end func_002F7BF8 */

/* merge_units: begin func_002F7C10 */
extern int rt_comm_platform2_receive_from(int, int, int, int, int, int);

int rt_comm_platform_receive_from(int a0, int a1, int a2, int a3, int t0, int t1) {
    return rt_comm_platform2_receive_from(a0, a1, a2, a3, (t0 & 65535), t1);
}
/* merge_units: end func_002F7C10 */

/* merge_units: begin func_002F7C28 */
extern int rt_comm_platform2_receive_echo(int, int, int, int);

int rt_comm_platform_receive_echo(int a0, int a1, int a2, int a3) {
    return rt_comm_platform2_receive_echo(a0, a1, a2, a3);
}
/* merge_units: end func_002F7C28 */

/* merge_units: begin func_002F7C40 */
extern int rt_comm_platform2_get_avail_bytes_to_read(int, int);

int rt_comm_platform_get_avail_bytes_to_read(int a0, int a1) {
    return rt_comm_platform2_get_avail_bytes_to_read(a0, a1);
}
/* merge_units: end func_002F7C40 */

/* merge_units: begin func_002F7C58 */
extern int rt_comm_platform2_get_local_ip(int);

int rt_comm_platform_get_local_ip(int a0) {
    return rt_comm_platform2_get_local_ip(a0);
}
/* merge_units: end func_002F7C58 */

/* merge_units: begin func_002F7C70 */
extern int rt_comm_platform2_get_broadcast_ip(int);

int rt_comm_platform_get_broadcast_ip(int a0) {
    return rt_comm_platform2_get_broadcast_ip(a0);
}
/* merge_units: end func_002F7C70 */

/* merge_units: begin func_002F7C88 */
extern int rt_comm_platform2_get_host_by_name(int, int);

int rt_comm_platform_get_host_by_name(int a0, int a1) {
    return rt_comm_platform2_get_host_by_name(a0, a1);
}
/* merge_units: end func_002F7C88 */

/* merge_units: begin func_002F7CA0 */
extern int rt_comm_platform2_get_remote_ip(int, int);

int rt_comm_platform_get_remote_ip(int a0, int a1) {
    return rt_comm_platform2_get_remote_ip(a0, a1);
}
/* merge_units: end func_002F7CA0 */

/* merge_units: begin func_002F7CB8 */
extern int rt_comm_platform2_display_state(void);

int rt_comm_platform_display_state(void) {
    return rt_comm_platform2_display_state();
}
/* merge_units: end func_002F7CB8 */

/* merge_units: begin func_002F7CD0 */
extern int rt_comm_platform2_is_connected(int, int);

int rt_comm_platform_is_connected(int a0, int a1) {
    return rt_comm_platform2_is_connected(a0, a1);
}
/* merge_units: end func_002F7CD0 */
