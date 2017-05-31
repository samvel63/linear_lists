#ifndef _LIST_H_
#define _LIST_H_

#include "mystring.h"

#define LIST_SUCCESS 0
#define LIST_ERROR -1

typedef struct _list *List;

struct _list {
	int len;
	int cur_len;
	String *str;
};

void list_create(List list, int len);
void add_elem(List list, String *str);
int delete_elem(List list, String *str);
int swap_elems(List list, int k);
void print_list(List list);
void list_destroy(List *list);

#endif // _LIST_H_