#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int print_error(char *err) {
	perror(err);
	return 1;
}

int main(void) {
	int n = 5;
	if (n <= 0)
		return 0;
	if (!access("Sully_5.c", F_OK))
		n--;
	char file[10];
	snprintf(file, 10, "Sully_%d.c", n);
	int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return(print_error("Error opening file"));
	char *str = "#include <stdio.h>%1$c#include <sys/stat.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c#include <stdlib.h>%1$c%1$cint print_error(char *err) {%1$c%2$cperror(err);%1$c%2$creturn 1;%1$c}%1$c%1$c";
	char *str2 = "int main(void) {%1$c%2$cint n = %4$d;%1$c%2$cif (n <= 0)%1$c%2$c%2$creturn 0;%1$c%2$cif (!access(%3$cSully_5.c%3$c, F_OK))%1$c%2$c%2$cn--;%1$c%2$cchar file[10];%1$c%2$csnprintf(file, 10, %3$cSully_%%d.c%3$c, n);%1$c%2$cint fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);%1$c%2$cif (fd < 0)%1$c%2$c%2$creturn(print_error(%3$cError opening file%3$c));%1$c";
	char *str3 = "%2$cchar *str = %3$c%4$s%3$c;%1$c%2$cchar *str2 = %3$c%5$s%3$c;%1$c%2$cchar *str3 = %3$c%6$s%3$c;%1$c%2$cchar *str4 = %3$c%7$s%3$c;%1$c%2$cdprintf (fd, str, 10, 9);%1$c%2$cdprintf (fd, str2, 10, 9, 34, n);%1$c%2$cdprintf (fd, str3, 10, 9, 34, str, str2, str3, str4);%1$c%2$cdprintf (fd, str4, 10, 9, 34);%1$c%2$cclose (fd);%1$c";
	char *str4 = "%2$cchar command[50];%1$c%2$csnprintf(command, 50, %3$cclang -Wall -Wextra -Werror -o Sully_%%d %%s%3$c, n, file);%1$c%2$cif (system(command) < 0)%1$c%2$c%2$creturn print_error(%3$cError compiling file%3$c);%1$c%2$csnprintf(command, 50, %3$c./Sully_%%d%3$c, n);%1$c%2$cif (system(command) < 0)%1$c%2$c%2$creturn print_error(%3$cError running file%3$c);%1$c%2$creturn 0;%1$c}";
	dprintf (fd, str, 10, 9);
	dprintf (fd, str2, 10, 9, 34, n);
	dprintf (fd, str3, 10, 9, 34, str, str2, str3, str4);
	dprintf (fd, str4, 10, 9, 34);
	close (fd);
	char command[50];
	snprintf(command, 50, "clang -Wall -Wextra -Werror -o Sully_%d %s", n, file);
	if (system(command) < 0)
		return print_error("Error compiling file");
	snprintf(command, 50, "./Sully_%d", n);
	if (system(command) < 0)
		return print_error("Error running file");
	return 0;
}