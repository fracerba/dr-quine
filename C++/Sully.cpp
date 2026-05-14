#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int print_error(string s) {
	cerr << s << endl;
	return 1;
}

int main(void) {
	int n = 5;
	if (n <= 0)
		return 0;
	n--;
	string exe = "Sully_" + to_string(n);
	string name = exe + ".cpp";
	string str = "#include <iostream>$#include <algorithm>$#include <fstream>$$using namespace std;$$int print_error(string s) {$@cerr << s << endl;$@return 1;$}$$int main(void) {$@int n = ;$@if (n <= 0)$@@return 0;$@n--;$@string exe = `Sully_` + to_string(n);$@string name = exe + `.cpp`;$@string str = ``;$@string str2(str);$@replace(str.begin(), str.end(), 64, 9);$@replace(str.begin(), str.end(), 36, 10);$@replace(str.begin(), str.end(), 96, 34);$@str.insert(287, str2);$@str.insert(171, to_string(n));$@ofstream file(name);$@file << str;$@file.close();$@string command = `c++ -Wall -Wextra -Werror -std=c++17 -o ` + exe + ` ` + name;$@if (system(command.c_str()) < 0)$@@return print_error(`Error compiling file`);$@command = `./` + exe;$@if (system(command.c_str()) < 0)$@@return print_error(`Error running file`);$@return 0;$}";
	string str2(str);
	replace(str.begin(), str.end(), 64, 9);
	replace(str.begin(), str.end(), 36, 10);
	replace(str.begin(), str.end(), 96, 34);
	str.insert(287, str2);
	str.insert(171, to_string(n));
	ofstream file(name);
	file << str;
	file.close();
	string command = "c++ -Wall -Wextra -Werror -std=c++17 -o " + exe + " " + name;
	if (system(command.c_str()) < 0)
		return print_error("Error compiling file");
	command = "./" + exe;
	if (system(command.c_str()) < 0)
		return print_error("Error running file");
	return 0;
}