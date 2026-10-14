/* 00108440 (libmpeg, gcc29): 8 diffs with stock gcc29 build; 0 diffs (MATCH) when the gcc29 991111 cc1 output is assembled with the ee-gcc2.96 gas (asx.py). See NOTES.md 'gas finding'. */
typedef struct {
    char pad0[0xEC];
    int picStructure;
    char pad1[0x17C - 0xF0];
    int f_code[2][2];
    int picture_structure;
    int top_field_first;
    int frame_pred_frame_dct;
    int concealment_motion_vectors;
    int repeat_first_field;
    int progressive_frame;
} MpegCtx;

extern int func_00107ED8(void *, int);

#define IPU_CTRL ((volatile unsigned int *)0x10002010)

void func_00108440(MpegCtx *m)
{
    int x;

    m->f_code[0][0] = func_00107ED8(m, 4);
    m->f_code[0][1] = func_00107ED8(m, 4);
    m->f_code[1][0] = func_00107ED8(m, 4);
    m->f_code[1][1] = func_00107ED8(m, 4);
    x = func_00107ED8(m, 2);
    *IPU_CTRL = (*IPU_CTRL & 0xFFFCFFFF) | (x << 16);
    m->picture_structure = func_00107ED8(m, 2);
    if (m->picStructure == 0) {
        m->picStructure = m->picture_structure;
    }
    m->top_field_first = func_00107ED8(m, 1);
    m->frame_pred_frame_dct = func_00107ED8(m, 1);
    m->concealment_motion_vectors = func_00107ED8(m, 1);
    x = func_00107ED8(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFBFFFFF) | (x << 22);
    x = func_00107ED8(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFDFFFFF) | (x << 21);
    x = func_00107ED8(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFEFFFFF) | (x << 20);
    m->repeat_first_field = func_00107ED8(m, 1);
    func_00107ED8(m, 1);
    m->progressive_frame = func_00107ED8(m, 1);
    if (func_00107ED8(m, 1) != 0) {
        func_00107ED8(m, 1);
        func_00107ED8(m, 3);
        func_00107ED8(m, 1);
        func_00107ED8(m, 7);
        func_00107ED8(m, 8);
    }
}