/*
 * lib/medius: 2 files, 00467DF0-00467EC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00467DF0 */
typedef struct { unsigned char b[48]; } Blk7DF0;
extern Blk7DF0 D_00587DD8;
void func_00467DF0(Blk7DF0 s)
{
    D_00587DD8 = s;
}
/* merge_units: end func_00467DF0 */

/* merge_units: begin func_00467EC8 */
typedef struct { unsigned char b[48]; } B467EC8;
#if 0 /* merge_units */
extern B467EC8 D_00587DD8;
#endif /* merge_units */
#define D_00587DD8 (*(B467EC8*)&D_00587DD8) /* merge_units */

void func_00467EC8(B467EC8* p) { *p = D_00587DD8; }
#undef D_00587DD8 /* merge_units */
/* merge_units: end func_00467EC8 */
