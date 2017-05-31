#ifndef _LIST_H_
#define _LIST_H_

#include "mystring.h"

typedef struct _list *List;

struct _list {
	int len;
	int cur_len;
	String *str;
};

void list_create(List list, int len);
void add_elem(List list, String *str);
void list_destroy(List *list);

#endif // _LIST_H_