#include <container.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
	int length;
	char *str;
} String;

String *string_from(char *str) {
	int strlen = 0;
	String *st = (String *)malloc(sizeof(String));
	while (str[strlen] != '\0') {
		strlen++;
	}
	char *new_str = (char *)malloc(strlen + 1); // +1 for null terminator
	memcpy(new_str, str, strlen);
	st->str = new_str;
	st->length = strlen;

	return st;
}

String *string_concat(String *str1, String *str2) {
	String *st = (String *)malloc(sizeof(String));
	char *new_str = (char *)malloc(str1->length + str2->length +
								   1); // +1 for null terminator

	memcpy(new_str, str1->str, str1->length);
	memcpy(new_str + str1->length, str2->str, str2->length);
	new_str[str1->length + str2->length] = '\0';

	st->str = new_str;
	st->length = str1->length + str2->length;
	return st;
}

int string_len(String *str) { return str->length; }

char *string(String *st) { return st->str; }

void string_free(String *str) {
	free(str->str);
	free(str);
}
