// в с++ каждый символ хранится как число (имеет свой код в таблице ASCII), 
// поэтому мы сначала проверяем, что первый символ – заглавная буква, используя коды,
// проверяем, что следующие три символа – цифры, 
// а последние два символа – заглавные буквы. 
#include <iostream>
#include <string>
int main() {
	std::string n;
	std::cin >> n;
	if (n[0] < 'A' || n[0] > 'Z') {
		std::cout << "No" << std::endl;
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		if (n[i] < '0' || n[i] > '9') {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	for (int i = 4; i <= 5; i++) {
		if (n[i] < 'A' || n[i] > 'Z') {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;
	return 0;
}