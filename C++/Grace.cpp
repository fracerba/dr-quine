#include <iostream>
#include <fstream>

using namespace std;

/*
	this program is a quine, it self-replicates its own source code when executed.
*/

#define PATH "Grace_kid.cpp"
#define STR "#include <iostream>$#include <fstream>$$using namespace std;$$/*$@this program is a quine, it self-replicates its own source code when executed.$*/$$#define PATH ``$#define STR ``$#define FT() int main (void) { string str = STR; for (char& c : str) c = (c == 64) ? 9 : (c == 36) ? 10 : (c == 96) ? 34 : c; str.insert(178, STR); str.insert(163, PATH); ofstream file(PATH); file << str; file.close();}$$FT()"
#define FT() int main (void) { string str = STR; for (char& c : str) c = (c == 64) ? 9 : (c == 36) ? 10 : (c == 96) ? 34 : c; str.insert(178, STR); str.insert(163, PATH); ofstream file(PATH); file << str; file.close();}

FT()