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

	//menu::text_menu();

	while (true)
	{
		system("cls");
		menu::text_menu();
		int choice = menu::get_key();
		int index = 0;
		float x;

		if (choice == 57) {
			f.clear();
			break;
		}
		try {
			switch (choice)
			{

			case 49:
				f.add(create_function());;
				cout << "\n" << endl;
				f.print();
				break;

			case 50:
				cout << "Введите индекс, по которому нужно вставить новую функцию: ";
				cin >> index;
				f.insert(index, create_function());
				cout << "\n" << endl;
				f.print();
				break;


			case 51:
				cout << "Введите индекс, по которому нужно удалить функцию: ";
				cin >> index;
				f.remove(index);
				cout << "\n" << endl;
				f.print();
				break;

			case 52:
				cout << "Введите индекс функции, которую нужно вычислить: ";
				cin >> index;
				cout << "Введите аргумент функции\n" << "x= ";
				cin >> x;
				cout << "Значение функции:  " << f[index]->compute_value(x) << endl;
				f.print();
				break;

			case 53:
				cout << "Введите индекс функции, у которой нужно найти производную: ";
				cin >> index;
				cout << "Производная:  " << endl; f[index]->compute_derivative()->print();
				cout << "\n" << endl;
				f.print();
				break;

			case 54:
				cout << "Введите индекс функции, у которой нужно найти первообразную: ";
				cin >> index;
				cout << "Первообразная:  " << endl; f[index]->compute_antiderivative()->print();
				cout << "\n" << endl;
				f.print();
				break;

			case 55:
				cout << "Введите аргумент для вычисления минамальной производной среди заданных функций\n"<<"x= ";
				cin >> x;
				cout << "Индекс функции с минимальной производной: " << f.last_min(x) << "\n" << endl;
				f.print();
				break;

			case 56:
				f.print();
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;

		}
		catch (...) {
			cout << "Unknown error" << endl;
		}//Амир лучший!
		getch();
	}
	return 0;
}