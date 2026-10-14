/*
 * lib/lgaud: 2 files, 003261B0-003261F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003261B0 */
extern int func_003260F0(void);
extern void func_0010D210(unsigned int *cfg);
#define SCF_CFG_GET(name, override, expr) extern unsigned char override; int name(void) { unsigned int cfg; if (func_003260F0() == 0) { func_0010D210(&cfg); return expr; } return override; }

SCF_CFG_GET(func_003261B0, D_004914A2, (cfg >> 1) & 3)
/* merge_units: end func_003261B0 */

/* merge_units: begin func_003261F0 */
SCF_CFG_GET(func_003261F0, D_004914A5, cfg & 1)
/* merge_units: end func_003261F0 */
