#include <iostream>
#include <algorithm>

using namespace std;

/*
	this comment is outside a function
*/

string get_quine(string s){
	replace(s.begin(), s.end(), 64, 9);
	replace(s.begin(), s.end(), 36, 10);
	replace(s.begin(), s.end(), 96, 34);
	return s;
}

int main (void) {
	string str = "#include <iostream>$#include <algorithm>$$using namespace std;$$/*$@this comment is outside a function$*/$$string get_quine(string s){$@replace(s.begin(), s.end(), 64, 9);$@replace(s.begin(), s.end(), 36, 10);$@replace(s.begin(), s.end(), 96, 34);$@return s;$}$$int main (void) {$@string str = ``;$@/*$@@this comment is inside main$@*/$@cout << get_quine(str).insert(295, str);$@return 0;$}";
	/*
		this comment is inside main
	*/
	cout << get_quine(str).insert(295, str);
	return 0;
}