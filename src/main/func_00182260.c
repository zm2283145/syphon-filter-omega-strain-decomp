/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

int func_00182260(void* self, char* p) {
    return *(int*)(p + 0);
}

int func_00182270(char* self) {
    return *(int*)(self + 0);
}

void func_00182280(char* self, int value) {
    *(int*)(self + 4) = value;
}
