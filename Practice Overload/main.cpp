#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class String {
private:
	static const int sz = 80;
	char str[sz];
public:
	String() {
		strcpy_s(str, " ");
	}
	String(char s[]) {
		strcpy_s(str, s);
	}
	void display() {
		cout << str << endl;
	}

	String operator ++ ();
	String operator+=(String s);
};

int main() {
	String s1 = const_cast<char*>("11111");
	++s1;
	s1.display();
	String s2 = const_cast<char*>("22222");
	String s3;
	s3 = s1 += s2;
	s3.display();
	return 0;
}

//string concatenation
String String::operator+=(String s) {
	int len = strlen(str);
	if (strlen(str) + strlen(s.str) < sz) {
		strcat_s(str, s.str);
		return String(str);
	}
	else return String(str);
}

//increase the letters case
String String::operator ++ () {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		str[i] = toupper(str[i]);
	}
	return String(str);
}