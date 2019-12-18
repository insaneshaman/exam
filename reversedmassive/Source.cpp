#include "Header.h"

using namespace std;

int main()
{
	//��� ���������� ������ rand, ������� ���������� ��������� �����
	srand(time(NULL));

	while (true)
	{
		cout << "Enter massive capacity:\n";

		//����������, �������� ������� �������
		int rows, columns;

		//���� ����� �����
		while (true)
		{
			cout << "Enter number of rows: ";

			cin >> rows;

			//���� ����� ����� ������ ��� ����� 0, �� ������ �� ��������� ������� 
			if (rows <= 0) cout << "Number of rows must be greater than 0\n";

			else break;
		}

		//���� ����� ��������
		while (true)
		{
			cout << "Enter number of columns: ";

			cin >> columns;

			//���� ����� ����� ������ ��� ����� 0, �� ������ �� ��������� ������� 
			if (columns <= 0) cout << "Number of columns must be greater than 0\n";

			else break;
		}

		//������������ ������ � � ��������� ���������  
		int** a = new int* [rows];

		for (int i = 0; i < rows; i++) a[i] = new int[columns];

		while (true)
		{
			cout << "Press 1 to enter massive values\nPress 2 to generate random numbers\n";

			//���������� ��� ����� ������ ����� _getch
			char ans = _getch();

			switch (ans)
			{
			case '1':
				//����, � ������� ���� ������ �������� � ������ ������ ������� �
				for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++)
				{
					cout << "a[" << i << "][" << j << "] = ";

					cin >> a[i][j];
				}

				break;

			case '2':
				//����������, �������� �������� �����, ������������ � ������������ ������ �
				int range;

				//���� ��������� �����, ������������ � ������������ ������ �
				while (true)
				{
					cout << "Enter range of generated numbers: ";

					cin >> range;

					//���� �������� ����� ����� ������ ��� ����� ����, �� ����� ��������...
					if (range <= 0) cout << "Range must be greater than zero\n";

					else break;
				}

				//����, ������������ ��������� ����� � �������� ���������
				for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) a[i][j] = rand() % range;

				break;

			default:
				cout << "Something went wrong, try again, please...\n";

				break;
			}

			if (ans == '1' or ans == '2') break;
		}
		
		cout << "Your massive:\n";

		//����, ��������� ������ ������� � �� ����� � ���� ��������� �������
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++) cout << a[i][j] << "\t";

			cout << "\n";
		}

		cout << "Reversed massive:\n";
		
		//����, ��������� ������ ������������ ������� � �� ����� � ���� ��������� �������
		for (int i = rows-1; i >= 0; i--)
		{
			for (int j = columns-1; j >= 0; j--) cout << a[i][j] << "\t";
			
			//������� ������������ ������ �� ����� ������� �
			delete[] a[i];

			cout << "\n";
		}

		//������� ������������ ������ �� ������� �
		delete[] a;

		cout << "Press 1 to make another one massive\nPress anything else to quit\n";

		char ans = _getch();

		if (ans != '1') break;
	}
	
	return 0;
}