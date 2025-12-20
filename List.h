#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define List_Implement(type) \
	typedef struct{ \
		type * data;\
		size_t size;\
		size_t capacity;\
		\
	}List_##type;\
	List_##type	List_New_##type(size_t elements){\
		List_##type out;\
		out.data = malloc(sizeof(type) * elements);\
		out.size = 0;\
		out.capacity = elements;\
		memset(out.data,0,sizeof(type) * elements);\
		return out;\
	}\
	void List_Delete_##type(List_##type * vec){\
		free(vec->data);\
		vec->data = NULL;\
		vec->size = 0;\
		vec->capacity = 0;\
	}\
	void	List_Resize_##type(List_##type *vec, size_t elements){\
		vec->data = realloc(vec->data,elements * sizeof(type));\
		vec->capacity = elements;\
	}\
	void List_Push_##type(List_##type* vec, type val){\
		vec->size++;\
		if(vec->size == vec->capacity){\
			vec->data = realloc(vec->data,(vec->size * 2) * sizeof(type));\
			vec->capacity = vec->size * 2;\
			printf("NEW ALLOCATION\n");\
		}\
		vec->data[vec->size -1] = val;\
	}\
		type List_Get_##type(List_##type *vec, int index){\
		if(index < vec->size)return vec->data[index];\
			}\
	void List_Set_##type(List_##type *vec, int index, type value){\
		if(index >= vec->capacity) return;\
		vec->data[index] = value;\
		if(index >= vec->size)		vec->size = index + 1;\
	}


