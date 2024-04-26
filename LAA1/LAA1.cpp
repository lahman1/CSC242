#include <iostream>
#include <string>

using namespace std;

int main()
{
	string number;
	while (true) {
		cout << "Enter a 10 digit phone number please:" << endl;
		cout << "Example: 4155551212: ";
		cin >> number;
		if (number.length() == 10) {
			cout << "The phone number you entered is: ";
			cout << "(" << number.substr(0, 3) << ") " << number.substr(3, 3) << "-" << number.substr(6, 4);
			break;
		}
		else {
			cout << "Invalid phone number!" << endl;
		}
	}
	return 0;
}