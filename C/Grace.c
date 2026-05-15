#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
	this program is a quine, it self-replicates its own source code when executed.
*/

#define PATH "Grace_kid.c"
#define STR "#include <stdio.h>%1$c#include <sys/stat.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c%1$c/*%1$c%2$cthis program is a quine, it self-replicates its own source code when executed.%1$c*/%1$c%1$c#define PATH %3$c%4$s%3$c%1$c#define STR %3$c%5$s%3$c%1$c#define FT() int main(void) { int fd = open(PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd == -1) { perror(%3$cError opening file%3$c); return 1; } dprintf (fd, STR, 10, 9, 34, PATH, STR); close (fd); return 0;}%1$c%1$cFT()"
#define FT() int main(void) { int fd = open(PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd == -1) { perror("Error opening file"); return 1; } dprintf (fd, STR, 10, 9, 34, PATH, STR); close (fd); return 0;}

FT()