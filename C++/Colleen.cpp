#include <iostream>

using namespace std;

/*
	this comment is outside a function
*/

string get_quine(string s){
	for (char& c : s)
		c = (c == 64) ? 9 : (c == 36) ? 10 : (c == 96) ? 34 : c;
	return s;
}

int main (void) {
	string str = "#include <iostream>$$using namespace std;$$/*$@this comment is outside a function$*/$$string get_quine(string s){$@for (char& c : s)$@@c = (c == 64) ? 9 : (c == 36) ? 10 : (c == 96) ? 34 : c;$@return s;$}$$int main (void) {$@string str = ``;$@/*$@@this comment is inside main$@*/$@cout << get_quine(str).insert(239, str);$@return 0;$}";
	/*
		this comment is inside main
	*/
	cout << get_quine(str).insert(239, str);
	return 0;
}