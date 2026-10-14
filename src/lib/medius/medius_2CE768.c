/*
 * lib/medius: 2 files, 002CE768-002CE840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CE768 */
/* Stores a 48-byte block passed by value into a global. */
typedef struct { unsigned char b[48]; } Blk2CE768;
extern Blk2CE768 D_0051EFA8;
void func_002CE768(Blk2CE768 s)
{
    D_0051EFA8 = s;
}
/* merge_units: end func_002CE768 */

/* merge_units: begin func_002CE840 */
typedef struct { unsigned char b[48]; } B2CE840;
#if 0 /* merge_units */
extern B2CE840 D_0051EFA8;
#endif /* merge_units */
#define D_0051EFA8 (*(B2CE840*)&D_0051EFA8) /* merge_units */

void func_002CE840(B2CE840* p) { *p = D_0051EFA8; }
#undef D_0051EFA8 /* merge_units */
/* merge_units: end func_002CE840 */
