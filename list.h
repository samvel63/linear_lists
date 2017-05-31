#ifndef _LIST_H_
#define _LIST_H_

#include "mystring.h"

#define DELETE_SUCCESS 0
#define DELETE_ERROR -1

typedef struct _list *List;

struct _list {
	int len;
	int cur_len;
	String *str;
};

void list_create(List list, int len);
void add_elem(List list, String *str);
int delete_elem(List list, String *str);
void list_destroy(List *list);

#endif // _LIST_H_