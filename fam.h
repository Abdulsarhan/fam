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

#define IM_API extern

vec3 fam_vec3_cross(vec3 a, vec3 b);

float fam_vec2_dot(vec2 a, vec2 b);
float fam_vec3_dot(vec3 a, vec3 b);
float fam_vec4_dot(vec4 a, vec4 b);

vec2 fam_vec2_add(vec2 a, vec2 b);
vec3 fam_vec3_add(vec3 a, vec3 b);
vec4 fam_vec4_add(vec4 a, vec4 b);

vec2 fam_vec2_sub(vec2 a, vec2 b);
vec3 fam_vec3_sub(vec3 a, vec3 b);
vec4 fam_vec4_sub(vec4 a, vec4 b);

float fam_lerp(float a, float b, float t);

#ifdef __cplusplus
}
#endif
#endif /* FAM_H */

#ifdef FAM_IMPLEMENTATION
vec3 fam_vec3_cross(vec3 a, vec3 b) {
	vec3 ret = {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
	return ret;	
}

float fam_vec2_dot(vec2 a, vec2 b) {
	return a.x * b.x + a.y * b.y;
}

float fam_vec3_dot(vec3 a, vec3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float fam_vec4_dot(vec4 a, vec4 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

vec2 fam_vec2_add(vec2 a, vec2 b) {
	vec2 ret = { a.x + b.x, a.y + b.y };
	return ret;
}

vec3 fam_vec3_add(vec3 a, vec3 b) {
	vec3 ret = { a.x + b.x, a.y + b.y, a.z + b.z };
	return ret;
}

vec4 fam_vec4_add(vec4 a, vec4 b) {
	vec4 ret = { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	return ret;
}

vec2 fam_vec2_sub(vec2 a, vec2 b) {
	vec2 ret = { a.x - b.x, a.y - b.y };
	return ret;
}

vec3 fam_vec3_sub(vec3 a, vec3 b) {
	vec3 ret = { a.x - b.x, a.y - b.y, a.z - b.z };
	return ret;

}

vec4 fam_vec4_sub(vec4 a, vec4 b) {
	vec4 ret = { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	return ret;
}

mat4 fam_rotate(mat4 mat, vec3 vec, vec3 axis) {

}

mat4 fam_scale(mat4 mat, vec3 vec) {

}

mat4 fam_translate(mat4 mat, vec3 vec) {

0, 0, 0, tx
0, 0, 0, ty
0, 0, 0, tz
0, 0, 0,  1
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