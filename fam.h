#ifndef FAM_H
#define FAM_H

typedef struct {
	float x, y;
}vec2;

typedef struct {
	float x, y, z;
}vec3;

typedef struct {
	float x, y, z, w;
}vec4;

typedef struct {
	int x, y;
}ivec2;

typedef struct {
	int x, y, z;
}ivec3;

typedef struct {
	int x, y, z, w;
}ivec4;

typedef struct {
	float a, b,
	   	  c, d;
}mat2;

typedef struct {
	float a, b, c,
		  d, e, f,
		  g, h, i;
}mat3;

typedef struct {
	float a, b, c, d,
		  e, f, g, h, 
		  i, j, k, l;
}mat4;

#ifdef __cplusplus
extern "C" {
#endif

#define FAMAPI extern

FAMAPI vec3 fam_vec3_cross(vec3 a, vec3 b);

FAMAPI float fam_vec2_dot(vec2 a, vec2 b);
FAMAPI float fam_vec3_dot(vec3 a, vec3 b);
FAMAPI float fam_vec4_dot(vec4 a, vec4 b);

FAMAPI vec2 fam_vec2_add(vec2 a, vec2 b);
FAMAPI vec3 fam_vec3_add(vec3 a, vec3 b);
FAMAPI vec4 fam_vec4_add(vec4 a, vec4 b);

FAMAPI vec2 fam_vec2_sub(vec2 a, vec2 b);
FAMAPI vec3 fam_vec3_sub(vec3 a, vec3 b);
FAMAPI vec4 fam_vec4_sub(vec4 a, vec4 b);

FAMAPI float fam_lerp(float a, float b, float t);
FAMAPI void fam_srand(uint64_t *state, uint64_t seed);
FAMAPI uint32_t fam_rand(uint64_t *state)
#ifdef __cplusplus
}
#endif
#endif /* FAM_H */

#ifdef FAM_IMPLEMENTATION

FAMAPI void fam_srand(uint64_t *state, uint64_t seed) {
    if (seed == 0) {
        seed = 1;
    }
    *state = seed;
}

FAMAPI uint32_t fam_rand(uint64_t *state) {
    *state = *state * 0xff1cd035ul + 0x05;
    return (uint32_t)(*state >> 32);
}

FAMAPI vec3 fam_vec3_cross(vec3 a, vec3 b) {
	vec3 ret = {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
	return ret;	
}

FAMAPI float fam_vec2_dot(vec2 a, vec2 b) {
	return a.x * b.x + a.y * b.y;
}

FAMAPI float fam_vec3_dot(vec3 a, vec3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

FAMAPI float fam_vec4_dot(vec4 a, vec4 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

FAMAPI vec2 fam_vec2_add(vec2 a, vec2 b) {
	vec2 ret = { a.x + b.x, a.y + b.y };
	return ret;
}

FAMAPI vec3 fam_vec3_add(vec3 a, vec3 b) {
	vec3 ret = { a.x + b.x, a.y + b.y, a.z + b.z };
	return ret;
}

FAMAPI vec4 fam_vec4_add(vec4 a, vec4 b) {
	vec4 ret = { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	return ret;
}

FAMAPI vec2 fam_vec2_sub(vec2 a, vec2 b) {
	vec2 ret = { a.x - b.x, a.y - b.y };
	return ret;
}

FAMAPI vec3 fam_vec3_sub(vec3 a, vec3 b) {
	vec3 ret = { a.x - b.x, a.y - b.y, a.z - b.z };
	return ret;

}

FAMAPI vec4 fam_vec4_sub(vec4 a, vec4 b) {
	vec4 ret = { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	return ret;
}

FAMAPI mat4 fam_rotate(mat4 mat, vec3 vec, vec3 axis) {

}

FAMAPI mat4 fam_scale(mat4 mat, vec3 vec) {

}

FAMAPI mat4 fam_translate(mat4 mat, vec3 vec) {

}

float fam_lerp(float a, float b, float t) {
    return a * (1 - t) + b * t;
}


/* NOTE: OPENGL IS FUCKING COLUMN MAJOR. */

/* translation matrix*/
/*

0, 0, 0, tx
0, 0, 0, ty
0, 0, 0, tz
0, 0, 0,  1

*/

/* scale matrix*/
/*
sx, 0, 0, 0
0, sy, 0, 0
0, 0, sz, 0
0, 0, 0,  1
*/

/* rotation matrix*/
/*
sx, 0, 0, 0
0, sy, 0, 0
0, 0, sz, 0
0, 0, 0,  1
*/
#endif /* FAM_IMPLEMENTATION */