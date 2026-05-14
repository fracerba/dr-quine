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
	char *str = "#include <stdio.h>%c#include <sys/stat.h>%c#include <fcntl.h>%c#include <unistd.h>%c#include <stdlib.h>%c%cint print_error(char *err) {%c%cperror(err);%c%creturn 1;%c}%c%c";
	char *str2 = "int main(void) {%c%cint n = %d;%c%cif (n <= 0)%c%c%creturn 0;%c%cif (!access(%cSully_5.c%c, F_OK))%c%c%cn--;%c%cchar file[10];%c%csnprintf(file, 10, %cSully_%%d.c%c, n);%c%cint fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c%cif (fd < 0)%c%c%creturn(print_error(%cError opening file%c));%c";
	char *str3 = "%cchar *str = %c%s%c;%c%cchar *str2 = %c%s%c;%c%cchar *str3 = %c%s%c;%c%cchar *str4 = %c%s%c;%c%cchar *str5 = %c%s%c;%c";
	char *str4 = "%cdprintf (fd, str, 10, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10, 10);%c%cdprintf (fd, str2, 10, 9, n, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10);%c%cdprintf (fd, str3, 9, 34, str, 34, 10, 9, 34, str2, 34, 10, 9, 34, str3, 34, 10, 9, 34, str4, 34, 10, 9, 34, str5, 34, 10);%c%cdprintf (fd, str4, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10);%c%cdprintf (fd, str5, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10);%c%cclose (fd);%c";
	char *str5 = "%cchar command[50];%c%csnprintf(command, 50, %cclang -Wall -Wextra -Werror -o Sully_%%d %%s%c, n, file);%c%cif (system(command) < 0)%c%c%creturn print_error(%cError compiling file%c);%c%csnprintf(command, 50, %c./Sully_%%d%c, n);%c%cif (system(command) < 0)%c%c%creturn print_error(%cError running file%c);%c%creturn 0;%c}";
	dprintf (fd, str, 10, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10, 10);
	dprintf (fd, str2, 10, 9, n, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10);
	dprintf (fd, str3, 9, 34, str, 34, 10, 9, 34, str2, 34, 10, 9, 34, str3, 34, 10, 9, 34, str4, 34, 10, 9, 34, str5, 34, 10);
	dprintf (fd, str4, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10);
	dprintf (fd, str5, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10);
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