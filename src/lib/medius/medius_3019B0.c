/*
 * lib/medius: 5 files, 003019B0-00301AB8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003019B0 */
#define SCF_GET16(name) int name(unsigned char *p, unsigned short *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = p[0]; *out |= p[1] << 8; return 0; }
SCF_GET16(rt_msg_get_u2byte)
/* merge_units: end func_003019B0 */

/* merge_units: begin func_003019E8 */
int rt_msg_set_4byte(unsigned char *p, int v)
{
    int ret = 2;
    if (p == 0) return ret;
    *p++ = v;
    *p++ = v >> 8;
    *p++ = v >> 16;
    *p = v >> 24;
    return 0;
}
/* merge_units: end func_003019E8 */

/* merge_units: begin func_00301A20 */
int rt_msg_get_4byte(unsigned char *p, unsigned int *out)
{
    int ret = 2;
    if (p == 0) return ret;
    if (out == 0) return ret;
    *out = *p++;
    *out |= *p++ << 8;
    *out |= *p++ << 16;
    *out |= *p << 24;
    return 0;
}
/* merge_units: end func_00301A20 */

/* merge_units: begin func_00301A80 */
#define SCF_PUT32LE(name, T) int name(unsigned char *p, T v) { int ret = 2; if (p == 0) return ret; *p++ = v; *p++ = v >> 8; *p++ = v >> 16; *p = v >> 24; return 0; }
#define SCF_PUT32BE(name, T) int name(unsigned char *p, T v) { int ret = 2; if (p == 0) return ret; *p++ = v >> 24; *p++ = v >> 16; *p++ = v >> 8; *p = v; return 0; }
#define SCF_GET32LE(name) int name(unsigned char *p, unsigned int *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = *p++; *out |= *p++ << 8; *out |= *p++ << 16; *out |= *p << 24; return 0; }
#define SCF_GET32BE(name) int name(unsigned char *p, unsigned int *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = *p++ << 24; *out |= *p++ << 16; *out |= *p++ << 8; *out |= *p; return 0; }
SCF_PUT32LE(rt_msg_set_u4byte, unsigned int)
/* merge_units: end func_00301A80 */

/* merge_units: begin func_00301AB8 */
SCF_GET32LE(rt_msg_get_u4byte)
/* merge_units: end func_00301AB8 */
