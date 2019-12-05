#include "Header.h"

using namespace std;

int main()
{
	while (true)
	{
		//������ ����������
		int r;
		
		while (true)
		{
			cout << "Enter radius:\n";
			
			//���� ������� ����������
			cin >> r;

			if (r < 0) cout << "Radius cant be less than 0!\n";

			else break;
		}

		//�������� � �� ��������� �������� y=x*x+a
		int a;
		
		while (true)
		{
			cout << "Enter a from y=x*x+a:\n";

			//���� �
			cin >> a;

			//�������� ������ ���� ������ ����������
			if (a > r)	cout << "Parabola is out of round. Enter a again\n";

			else break;
		}

		//�������� b �� ��������� ������ y=b
		int b;
		
		while (true)
		{
			cout << "Enter b from y=b:\n";

			//���� b
			cin >> b;

			//������ ������ ��������� ����� ���������� ��� �������� �
			if (fabs(b) > r) cout << "Line is out of round. Enter b again\n";

			//������ ������ �������� �������� ��� ��������� ����� ��
			else if (b < a) cout << "Line is out of parabola. Enter b again\n";

			else break;
		}

		//���������� � �����
		int x;
		
		while (true)
		{
			cout << "Enter x:\n";
			
			//���� �
			cin >> x;

			//����� ������ ���� ������ ����������
			if (x > r) cout << "Point is out of round\n";

			//����� ������ ���� ������ ��������
			else if (x * x + a > b) cout << "Point is out of parabola\n";

			else break;
		}
		
		//���������� � �����
		int y;
	
		cout << "Enter y:\n";
		//���� �
		cin >> y;

		//����� ������ ���� ������ ����������
		if (y > r) cout << "Point is out of round\n";

		//����� ������ ���� ��� ������ �=b
		else if (y > b) cout << "Point is out of line\n";

		//����� ������ ���� ������ ��������
		else if (y < a) cout << "Point is out of parabola\n";

		else cout << "Point is in range!\n";

		cout << "Press 1 to solve another one task\nPress anything else to quit\n";

		char ans = _getch();

		if (ans != '1') break;
	}

	return 0;
}