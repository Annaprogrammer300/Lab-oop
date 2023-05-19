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
		try {
			switch (choice)
			{

			case 49:
				f.add(create_function());
				f.print();
				break;

			case 50:
				cout << "������� ������, �� �������� ����� �������� ����� �������: ";
				cin >> index;
				f.insert(index, create_function());
				f.print();
				break;


			case 51:
				cout << "������� ������, �� �������� ����� ������� �������: ";
				cin >> index;
				f.remove(index);
				f.print();
				break;

			case 52:
				cout << "������� ������ �������, � ������� ����� ���������: ";
				cin >> index;
				cout << "������� �������� �������\n";
				cin >> x;
				cout << "�������� �������:  " << f[index]->compute_value(x) << endl;
				f.print();
				break;

			case 53:
				cout << "������� ������ �������, � ������� ����� ��������� �����������: ";
				cin >> index;
				cout << "�����������:  " << f[index]->compute_derivative() << endl;
				f.print();
				break;

			case 54:
				cout << "������� ������ �������, � ������� ����� ��������� �������������: ";
				cin >> index;
				cout << "�������������:  " << f[index]->compute_antiderivative() << endl;
				f.print();
				break;

			case 55:
				cout << "������� �������� ��� ���������� ����������� ����������� ����� �������� �������\n";
				cin >> x;
				cout << "������ ������� � ����������� �����������: " << f.last_min(x);
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
		}

	}
	return 0;
}