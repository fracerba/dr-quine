#include <stdio.h>

char *get_quine(void) {
	return "#include <stdio.h>%1$c%1$cchar *get_quine(void) {%1$c%2$creturn %3$c%4$s%3$c;%1$c}%1$c%1$c/*%1$c%2$cthis comment is outside a function%1$c*/%1$c%1$cint main (void) {%1$c%2$cprintf(get_quine(), 10, 9, 34, get_quine());%1$c%2$c/*%1$c%2$c%2$cthis comment is inside main%1$c%2$c*/%1$c%2$creturn 0;%1$c}";
}

/*
	this comment is outside a function
*/

int main (void) {
	printf(get_quine(), 10, 9, 34, get_quine());
	/*
		this comment is inside main
	*/
	return 0;
}