#include <Function1/Function1.h>
#include <Function1/Function_menu.h>

#include <Windows.h>

using namespace function;
using namespace menu;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	FunctionList f;
	Function fun;

	menu::text_menu();

	while (true)
	{
		int choice = menu::get_key();
		int index = 0;
		float x;

		system("cls");
		menu::text_menu();


		if (choice == 57) {
			f.clear();
			break;
		}

		switch (choice)
		{

		case 49:
			f.add(create_function());
			break;

		case 50:
			cout << "Введите индекс, по которому нужно вставить новую функцию: ";
			cin >> index;
			f.insert(index, create_function());
			break;


		case 51:
			cout << "Введите индекс, по которому нужно удалить функцию: ";
			cin >> index;
			f.remove(index);
			break;

		case 52:
			cout << "Введите индекс функции, у которую нужно вычислить: ";
			cin >> index;
			cout << "Введите аргумент функции\n";
			cin >> x;
			cout << "Значение функции:  " << f[index].compute_value(x) << endl;
			break;

		case 53:
			cout << "Введите индекс функции, у которую нужно вычислить производную: ";
			cin >> index;
			cout << "Введите аргумент функции\n";
			cin >> x;
			cout << "Производная:  " << f[index].compute_derivative().compute_value(x) << endl;
			break;

		case 54:
			cout << "Введите индекс функции, у которой нужно вычислить первообразную: ";
			cin >> index;
			cout << "Введите аргумент функции\n";
			cin >> x;
			cout << "Первообразная:  " << f[index].compute_antiderivative().compute_value(x) << endl;
			break;

		case 55:
			cout << "Введите аргумент для вычисления минамальной производной среди заданных функций\n";
			cin >> x;
			cout << "Индекс функции с минимальной производной: " << f.last_min(x);
			break;

		case 56:
			cout << f;
			break;
		}

	}
	return 0;
}