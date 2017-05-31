#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystring.h"
#include "list.h"

int main(void)
{
	List list = (List)malloc(sizeof(*list));

	char s[7];
	int n = 0;
	String elem;
	printf("\n\nВведите размер списка:\n\n");
	scanf("%d", &n);
	list_create(list, n);

	while (1) {
		scanf("%6s", s);
		if (!strcmp(s, "print") || !strcmp(s, "p")) {
			if (list->cur_len == 0) {
				printf("\nСписок пуст.\n\n");
			} else {
				for (int i = 0; i < list->cur_len; ++i)
					printf("%s ", list->str[i].cstring);
				printf("\n\n");
			}
		} else if (!strcmp(s, "len")) {
			printf("\nРазмер списка: %d", list->len);
			printf("\nКоличество элементов в списке: %d", list->cur_len);
		} else if (!strcmp(s, "add")) {
			scanf("%63s", elem.cstring);
			add_elem(list, &elem);
		} else if (!strcmp(s, "delete") || !strcmp(s, "del")) {
			scanf("%63s", elem.cstring);
			if (!delete_elem(list, &elem))
				printf("\nЭлемент удален\n\n");
			else
				printf("\nНе удалось удалить элемент\n\n");
		} else if (!strcmp(s, "quit") || !strcmp(s, "q")) {
			break;
		}
	}
	
	list_destroy(&list);
	printf("\n\n");
	return 0;
}