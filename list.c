#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		string_copy(&list->str[list->cur_len++], str);
	}
}

int delete_elem(List list, String *str)
{
	for (int i = 0; i < list->cur_len; ++i) {
		if (string_cmp(&list->str[i], str)) {
			memcpy(&list->str[i], &list->str[i + 1], sizeof(String) * (list->cur_len - (i + 1)));
			list->cur_len--;
			return DELETE_SUCCESS;
		}
	}
	return DELETE_ERROR;
}

void list_destroy(List *list)
{
	free((*list)->str);
	free(*list);
}