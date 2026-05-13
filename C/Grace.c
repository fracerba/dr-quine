#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
	this program is a quine, it self-replicates its own source code when executed.
*/

#define PATH "Grace_kid.c"
#define STR "#include <stdio.h>%c#include <sys/stat.h>%c#include <fcntl.h>%c#include <unistd.h>%c%c/*%c%cthis program is a quine, it self-replicates its own source code when executed.%c*/%c%c#define PATH %c%s%c%c#define STR %c%s%c%c#define FT() int main(void) { int fd = open(PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd == -1) { perror(%cError opening file%c); return 1; } dprintf (fd, STR, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 34, PATH, 34, 10, 34, STR, 34, 10, 34, 34, 10, 10); close (fd); return 0;}%c%cFT()"
#define FT() int main(void) { int fd = open(PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd == -1) { perror("Error opening file"); return 1; } dprintf (fd, STR, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 34, PATH, 34, 10, 34, STR, 34, 10, 34, 34, 10, 10); close (fd); return 0;}

FT()