#include <Function1/Function1.h>
#include <Function1/Function_menu.h>
#include <string.h>



using namespace std;
using namespace menu;
using namespace function;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                Меню                               |" << endl;
	cout << " —-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить функцию в конец                                      |" << endl;
	cout << " | 2 - добавить функцию по индексу                                   |" << endl;
	cout << " | 3 - удалить функцию по индексу                                    |" << endl;
	cout << " | 4 - вычислить значение функции от заданного аргумента             |" << endl;
	cout << " | 5 - получить производную функции                                  |" << endl;
	cout << " | 6 - получить первообразную  функции                               |" << endl;
	cout << " | 7 - поиск в наборе функции с минимальным значением производной    |" << endl;
	cout << " | 8 - вывести список функций                                        |" << endl;
	cout << " | 9 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57))
		return key;
}

Function menu::create_function() {
	Function f;
	int type;
	float a, b, c;


	cout << "Введите тип функции (1-Натуральный логарифм 2-Возведение в степень): ";
	cin >> type;
	if (type != 1 && type != 2)
		throw runtime_error("Invalid type");
	if (type == 1) {
		cout << " Введите коэффициент перед функцией \n " << "c=";
		cin >> c;
		return Function (Type::log, c);
	}
	if (type == 2) {
		cout << " Введите коэффициент перед функцией \n " << "a=";
		cin >> a;
		cout << " Введите степень функции \n " << "b=";
		cin >> b;
		return Function(Type::power, a, b);
	}
	
}

