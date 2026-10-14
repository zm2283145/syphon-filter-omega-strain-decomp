typedef struct {
    int x0;
    char pad4[0x140 - 4];
} Blk;

typedef struct {
    char pad0[0x138];
    int Second_Field;
    char pad13C[0x168 - 0x13C];
    int picture_coding_type;
    char pad16C[0x18C - 0x16C];
    int picture_structure;
    char pad190[0x1D0 - 0x190];
    unsigned char *forward_reference_frame;
    unsigned char *backward_reference_frame;
    char pad1D8[0x1E0 - 0x1D8];
    unsigned char *field[2][4];
    char pad200[0x6D4 - 0x200];
    Blk blk[(0x828 - 0x6D4) / 0x140];
    char pad[0x828 - 0x6D4 - ((0x828 - 0x6D4) / 0x140) * 0x140];
    int cur;
} Ctx;

extern char D_004983A0[];
extern char D_004983C0[];
extern char D_004983E0[];

extern void func_00105088(Ctx *ctx, unsigned char *src, int sfield, int dfield, int yoff, int h,
                          int bx, int by, int dx, int dy, int field, int avg);
extern void func_00106758(Ctx *ctx, int DMV[][2], int *dmvector, int mvx, int mvy);
extern int func_0010BD58(void *, const char *, int);

void func_00104980(Ctx *ctx, int bx, int by, int macroblock_type, int motion_type,
                   int PMV[2][2][2], int motion_vertical_field_select[2][2], int *dmvector)
{
    int currentfield;
    int DMV[2][2];
    int avg;
    int sel;

    avg = 0;
    sel = 1;
    ctx->blk[ctx->cur].x0 = 0;

    if ((macroblock_type & 8) || ctx->picture_coding_type == 2) {
        if (ctx->picture_structure == 3) {
            if (motion_type == 2 || !(macroblock_type & 8)) {
                func_00105088(ctx, ctx->forward_reference_frame, 0, 0, 0, 16, bx, by,
                              PMV[0][0][0], PMV[0][0][1], 0, 0);
            } else if (motion_type == 1) {
                func_00105088(ctx, ctx->forward_reference_frame, motion_vertical_field_select[0][0], 0, 0, 8, bx, by,
                              PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                func_00105088(ctx, ctx->forward_reference_frame, motion_vertical_field_select[1][0], 1, 0, 8, bx, by,
                              PMV[1][0][0], PMV[1][0][1] >> 1, 1, 0);
            } else if (motion_type == 3) {
                func_00106758(ctx, DMV, dmvector, PMV[0][0][0], PMV[0][0][1] >> 1);
                func_00105088(ctx, ctx->forward_reference_frame, 0, 0, 0, 8, bx, by,
                              PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                func_00105088(ctx, ctx->forward_reference_frame, 1, 0, 0, 8, bx, by,
                              DMV[0][0], DMV[0][1], 1, 1);
                func_00105088(ctx, ctx->forward_reference_frame, 1, 1, 0, 8, bx, by,
                              PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                func_00105088(ctx, ctx->forward_reference_frame, 0, 1, 0, 8, bx, by,
                              DMV[1][0], DMV[1][1], 1, 1);
            } else {
                func_0010BD58(ctx, D_004983A0, motion_type);
            }
        } else {
            unsigned char *predframe[2][2];

            currentfield = (ctx->picture_structure == 2);
            predframe[0][0] = ctx->field[0][0];
            predframe[0][1] = ctx->field[1][0];
            predframe[1][0] = ctx->field[0][1];
            predframe[1][1] = ctx->field[1][1];
            if (ctx->picture_coding_type == 2 && ctx->Second_Field && currentfield != motion_vertical_field_select[0][0])
                sel = 1;
            else
                sel = 0;

            if (motion_type == 1 || !(macroblock_type & 8)) {
                func_00105088(ctx, predframe[sel][motion_vertical_field_select[0][0]], 0, 0, 0, 16, bx, by,
                              PMV[0][0][0], PMV[0][0][1], 0, 0);
            } else if (motion_type == 2) {
                func_00105088(ctx, predframe[sel][motion_vertical_field_select[0][0]], 0, 0, 0, 8, bx, by,
                              PMV[0][0][0], PMV[0][0][1], 0, 0);
                sel = 0;
                if (ctx->picture_coding_type == 2 && ctx->Second_Field && currentfield != motion_vertical_field_select[1][0])
                    sel = 1;
                func_00105088(ctx, predframe[sel][motion_vertical_field_select[1][0]], 0, 0, 8, 8, bx, by,
                              PMV[1][0][0], PMV[1][0][1], 0, 0);
            } else if (motion_type == 3) {
                sel = 1;
                if (!ctx->Second_Field)
                    sel = 0;
                func_00106758(ctx, DMV, dmvector, PMV[0][0][0], PMV[0][0][1]);
                func_00105088(ctx, predframe[0][currentfield], 0, 0, 0, 16, bx, by,
                              PMV[0][0][0], PMV[0][0][1], 0, 0);
                func_00105088(ctx, predframe[sel][!currentfield], 0, 0, 0, 16, bx, by,
                              DMV[0][0], DMV[0][1], 0, 1);
            } else {
                func_0010BD58(ctx, D_004983C0, motion_type);
            }
        }
        avg = 1;
    }

    if (macroblock_type & 4) {
        if (ctx->picture_structure == 3) {
            int one = 1;
            if (motion_type == 2) {
                func_00105088(ctx, ctx->backward_reference_frame, 0, 0, 0, 16, bx, by,
                              PMV[0][1][0], PMV[0][1][1], 0, avg);
            } else {
                func_00105088(ctx, ctx->backward_reference_frame, motion_vertical_field_select[0][1], 0, 0, 8, bx, by,
                              PMV[0][1][0], PMV[0][1][1] >> 1, one, avg);
                func_00105088(ctx, ctx->backward_reference_frame, motion_vertical_field_select[1][1], 1, 0, 8, bx, by,
                              PMV[1][1][0], PMV[1][1][1] >> 1, one, avg);
            }
        } else {
            if (motion_type == 1) {
                func_00105088(ctx, motion_vertical_field_select[0][1] ? ctx->field[1][1] : ctx->field[0][1],
                              0, 0, 0, 16, bx, by, PMV[0][1][0], PMV[0][1][1], 0, avg);
            } else if (motion_type == 2) {
                func_00105088(ctx, motion_vertical_field_select[0][1] ? ctx->field[1][1] : ctx->field[0][1],
                              0, 0, 0, 8, bx, by, PMV[0][1][0], PMV[0][1][1], 0, avg);
                func_00105088(ctx, motion_vertical_field_select[1][1] ? ctx->field[1][1] : ctx->field[0][1],
                              0, 0, 8, 8, bx, by, PMV[1][1][0], PMV[1][1][1], 0, avg);
            } else {
                func_0010BD58(ctx, D_004983E0, motion_type);
            }
        }
    }
}
