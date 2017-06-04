#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define SWAP(A, B) { String T = A; A = B; B = T; };

void list_create(List list, int len)
{
	list->len = len;
	list->cur_len = 0;
	list->str = (String *)malloc(sizeof(String) * (len + 1));
}

int add_elem(List list, int k, String *str)
{
	if (k > list->cur_len + 1)
		return LIST_ERROR;

	if (list_is_full(list)) {
		printf("Список полон");
		return LIST_ERROR;
	}

	list->cur_len++;
	memcpy(&list->str[k], &list->str[k - 1], sizeof(String) * (list->cur_len - k));
	string_copy(&list->str[k - 1], str);

	return LIST_SUCCESS;
}

int delete_elem(List list, int k)
{
	if (list_is_empty(list) || k > list->cur_len)
		return LIST_ERROR;

	if (k == 1)
		string_copy(&list->str[k - 1], &list->str[list->cur_len - 1]);
	else
		memcpy(&list->str[k - 1], &list->str[k], sizeof(String) * (list->cur_len - k));
	list->cur_len--;

	return LIST_SUCCESS;
}

int list_is_empty(List list)
{
	return !list->cur_len;
}

int list_is_full(List list)
{
	return list->len == list->cur_len;
}

void print_list(List list)
{
	if (list_is_empty(list)) {
		printf("\nСписок пуст.\n\n");
		return;
	}

	for (int i = 0; i < list->cur_len; ++i)
		printf("%s ", list->str[i].cstring);
	printf("\n\n");
}

int swap_elems(List list, int k)
{
	if (k < 2 || list->cur_len < k)
		return LIST_ERROR;
	SWAP(list->str[k - 2], list->str[k]);
	return LIST_SUCCESS;
}

void list_destroy(List *list)
{
	free((*list)->str);
	free(*list);
}