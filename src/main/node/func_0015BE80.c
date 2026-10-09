/*
 * Matched functions (byte-identical with the retail executable).
 * cNode virtual slots: position getters and default (empty) handlers.
 */

#include "types.h"
#include "node_types.h"

extern int func_0015C170(void* a0, cNode* node);

int cNode_v34(void* a0, cNode* node) {
    return func_0015C170(a0, node);
}

/* v35..v37: write the node translation as a point (w = 1). */
void cNode_v35(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_v36(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_v37(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

int cNode_v38(void* a0, cNode* node) {
    return func_0015C170(a0, node);
}

int cNode_v39(void* a0, cNode* node) {
    return func_0015C170(a0, node);
}

int cNode_v3B(void* a0, cNode* node) {
    return func_0015C170(a0, node);
}

void cNode_v0E(void) {
}

void cNode_v0F(void) {
}

void Actor_VirtualNop(void) {
}

void Node_SetFlag2C(cNode* self) {
    self->flag2C = 1;
}

void Node_ClearFlag2C(cNode* self) {
    self->flag2C = 0;
}

unsigned char Node_GetFlag2C(cNode* self) {
    return self->flag2C;
}

int func_0015BFB0(void) {
    return 0;
}

void func_0015BFC0(void) {
}

int func_0015BFD0(void) {
    return 0;
}

int func_0015BFE0(void) {
    return 0;
}

int func_0015BFF0(void) {
    return 0;
}

void func_0015C000(void) {
}

int func_0015C010(void) {
    return 0;
}

int func_0015C020(void) {
    return 0;
}
