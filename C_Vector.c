#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Vector_Implement(type) \
	typedef struct{ \
		type * data;\
		size_t size;\
		size_t capacity;\
		\
	}Vector_##type;\
	Vector_##type	Vector_New_##type(size_t elements){\
		Vector_##type out;\
		out.data = malloc(sizeof(type) * elements);\
		out.size = 0;\
		out.capacity = elements;\
		memset(out.data,0,sizeof(type) * elements);\
		return out;\
	}\
	void Vector_Delete_##type(Vector_##type * vec){\
		free(vec->data);\
		vec->data = NULL;\
		vec->size = 0;\
		vec->capacity = 0;\
	}\
	void	Vector_Resize_##type(Vector_##type *vec, size_t elements){\
		vec->data = realloc(vec->data,elements * sizeof(type));\
		vec->capacity = elements;\
	}\
	void Vector_Push_##type(Vector_##type* vec, type val){\
		vec->size++;\
		if(vec->size == vec->capacity){\
			vec->data = realloc(vec->data,(vec->size * 2) * sizeof(type));\
			vec->capacity = vec->size * 2;\
			printf("NEW ALLOCATION\n");\
		}\
		vec->data[vec->size -1] = val;\
	}\
	type Vector_Get_##type(Vector_##type *vec, int index){\
		if(index >= vec->size) return 0;\
		return vec->data[index];\
	}\
	void Vector_Set_##type(Vector_##type *vec, int index, type value){\
		if(index >= vec->capacity) return;\
		vec->data[index] = value;\
		if(index >= vec->size)		vec->size = index + 1;\
	}


