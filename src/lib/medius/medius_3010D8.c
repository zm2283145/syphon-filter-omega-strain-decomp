/*
 * lib/medius: 2 files, 003010D8-00301190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003010D8 */
int func_003010D8(int *out, unsigned char v)
{
    if (out == 0) return 2;
    switch (v) {
    case 0: *out = 2; break;
    case 1: *out = 4; break;
    case 2: *out = 5; break;
    case 3: *out = 6; break;
    case 4: *out = 7; break;
    case 5: *out = 8; break;
    case 6: *out = 9; break;
    default: return 1;
    }
    return 0;
}
/* merge_units: end func_003010D8 */

/* merge_units: begin func_00301190 */
int func_00301190(int *out, unsigned char v)
{
    if (out == 0) return 2;
    switch (v) {
    case 0: *out = 0; break;
    case 1: *out = 1; break;
    case 2: *out = 2; break;
    case 3: *out = 3; break;
    case 4: *out = 4; break;
    default: return 1;
    }
    return 0;
}
/* merge_units: end func_00301190 */
