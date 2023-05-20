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
				cout << "������� ������, �� �������� ����� �������� ����� �������: ";
				cin >> index;
				f.insert(index, create_function());
				cout << "\n" << endl;
				f.print();
				break;


			case 51:
				cout << "������� ������, �� �������� ����� ������� �������: ";
				cin >> index;
				f.remove(index);
				cout << "\n" << endl;
				f.print();
				break;

			case 52:
				cout << "������� ������ �������, ������� ����� ���������: ";
				cin >> index;
				cout << "������� �������� �������\n" << "x= ";
				cin >> x;
				cout << "�������� �������:  " << f[index]->compute_value(x) << endl;
				f.print();
				break;

			case 53:
				cout << "������� ������ �������, � ������� ����� ����� �����������: ";
				cin >> index;
				cout << "�����������:  " << endl; f[index]->compute_derivative()->print();
				cout << "\n" << endl;
				f.print();
				break;

			case 54:
				cout << "������� ������ �������, � ������� ����� ����� �������������: ";
				cin >> index;
				cout << "�������������:  " << endl; f[index]->compute_antiderivative()->print();
				cout << "\n" << endl;
				f.print();
				break;

			case 55:
				cout << "������� �������� ��� ���������� ����������� ����������� ����� �������� �������\n"<<"x= ";
				cin >> x;
				cout << "������ ������� � ����������� �����������: " << f.last_min(x) << "\n" << endl;
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
		}//���� ������!
		getch();
	}
	return 0;
}