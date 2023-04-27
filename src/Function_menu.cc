#include <Function1/Function1.h>
#include <Function1/Function_menu.h>
#include <string.h>



using namespace std;
using namespace menu;
using namespace function;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �-------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ������� � �����                                      |" << endl;
	cout << " | 2 - �������� ������� �� �������                                   |" << endl;
	cout << " | 3 - ������� ������� �� �������                                    |" << endl;
	cout << " | 4 - ��������� �������� ������� �� ��������� ���������             |" << endl;
	cout << " | 5 - �������� ����������� �������                                  |" << endl;
	cout << " | 6 - �������� �������������  �������                               |" << endl;
	cout << " | 7 - ����� � ������ ������� � ����������� ��������� �����������    |" << endl;
	cout << " | 8 - ������� ������ �������                                        |" << endl;
	cout << " | 9 - ����� �� �������                                              |" << endl;
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


	cout << "������� ��� ������� (1-����������� �������� 2-���������� � �������): ";
	cin >> type;
	if (type != 1 && type != 2)
		throw runtime_error("Invalid type");
	if (type == 1) {
		cout << " ������� ����������� ����� �������� \n " << "c=";
		cin >> c;
		return Function (Type::log, c);
	}
	if (type == 2) {
		cout << " ������� ����������� ����� �������� \n " << "a=";
		cin >> a;
		cout << " ������� ������� ������� \n " << "b=";
		cin >> b;
		return Function(Type::power, a, b);
	}
	
}

