#include <stdlib.h>
#include <string.h>

#include "mystring.h"

uint32_t string_copy(String *to, String *from)
{
    strncpy(to->cstring, from->cstring, strlen(from->cstring) + 1);
    return STRING_SUCCESS;
}

uint32_t string_cmp(String  *one, String *two)
{
	if (strlen(one->cstring) != strlen(two->cstring))
		return 0;
	else
		return !strcmp(one->cstring, two->cstring);
}