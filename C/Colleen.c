#include <stdio.h>

char *get_quine(void) {
	return "#include <stdio.h>%c%cchar *get_quine(void) {%c%creturn %c%s%c;%c}%c%c/*%c%cthis comment is outside a function%c*/%c%cint main (void) {%c%cprintf(get_quine(), 10, 10, 10, 9, 34, get_quine(), 34, 10, 10, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10);%c%c/*%c%c%cthis comment is inside main%c%c*/%c%creturn 0;%c}";
}

/*
	this comment is outside a function
*/

int main (void) {
	printf(get_quine(), 10, 10, 10, 9, 34, get_quine(), 34, 10, 10, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10);
	/*
		this comment is inside main
	*/
	return 0;
}