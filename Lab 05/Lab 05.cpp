#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    char X='A', x = 'a';
    cout << (int)X << endl;
    cout << (int)x << endl;
    cout << "Разница занчений кодов: " << x - X;

    return 0;
}