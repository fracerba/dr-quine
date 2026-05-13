#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

/*
	this program is a quine, it self-replicates its own source code when executed.
*/

#define PATH "Grace_kid.cpp"
#define STR "#include <iostream>$#include <algorithm>$#include <fstream>$$using namespace std;$$/*$@this program is a quine, it self-replicates its own source code when executed.$*/$$#define PATH ``$#define STR ``$#define FT() int main (void) { string str = STR; replace(str.begin(), str.end(), 64, 9); replace(str.begin(), str.end(), 36, 10); replace(str.begin(), str.end(), 96, 34); ofstream file(PATH); str.insert(199, STR); str.insert(184, PATH); file << str; file.close();}$$FT()"
#define FT() int main (void) { string str = STR; replace(str.begin(), str.end(), 64, 9); replace(str.begin(), str.end(), 36, 10); replace(str.begin(), str.end(), 96, 34); ofstream file(PATH); str.insert(199, STR); str.insert(184, PATH); file << str; file.close();}

FT()