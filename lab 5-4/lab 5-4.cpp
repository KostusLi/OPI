#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Открыть VS" << endl;
	cout << "Нажать создание проекта" << endl;
	cout << "Выбрать пустой проект" << endl;
	int title;
	cout << "Введите название проекта" << endl;
	cin >> title;
	cout << "Нажать создать проект" << endl;

	return 0;
}