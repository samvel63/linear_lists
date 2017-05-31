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

	while (scanf("%6s", s) == 1) {
		if (!strcmp(s, "print") || !strcmp(s, "p")) {
			if (list->cur_len == 0)
				printf("\nСписок пуст.\n\n");
			else
				print_list(list);
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
		} else if (!strcmp(s, "swap")) {
			int k = 0;
			scanf("%d", &k);
			if (!swap_elems(list, k))
				printf("\nЭлементы изменены\n\n");
			else
				printf("\nНе удалось изменить элементы\n\n");
		} else if (!strcmp(s, "quit") || !strcmp(s, "q")) {
			break;
		}
		memset(s, '\0', 7);
	}
	
	list_destroy(&list);
	printf("\n\n");
	return 0;
}