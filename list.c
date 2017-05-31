#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void list_create(List list, int len)
{
	list->len = len;
	list->cur_len = 0;
	list->str = (String *)malloc(sizeof(String) * (len + 1));
}

void add_elem(List list, String *str)
{
	if (list->cur_len == list->len - 1) {
		printf("Список полон\n");
	} else {
		string_copy(&list->str[list->cur_len], str);
		list->cur_len++;
	}
}

void list_destroy(List *list)
{
	free((*list)->str);
	free(*list);
}