#include "Header.h"

using namespace std;

int main()
{
	while (true)
	{
		//����������, �������� �������� �
		double x;

		while (true)
		{
			cout << "Enter x:\n";

			cin >> x;

			//���� � ������ 0, �� ��� ���� ����� ���������� � �������������. ���� � ����� ����� ����, �� ��������� ������� �� ���� (� � �����������)
			if (x <= 0) cout << "x must be > 0\n";
			
			else break;
		}
		
		//����������, �������� �������� ������� ����
		double needed_step;

		while (true)
		{
			cout << "Enter needed step:\n";
			
			cin >> needed_step;

			//���� ��� ����� ������ ��� ����� 0, �� ��������� ������� �� ����������
			if (needed_step <= 0) cout << "Needed step must be > 0\n";

			else break;
		}

		double a, i, F = (x + 2) / x, b = 0;

		for (i = 1; ; i++)
		{
			//���������� ��� �������� ���������� �������� ����
			a = fabs(b + F);

			//���������� ��� �������� �������� �������
			b = F;

			//���� �������
			F += pow(-1, i - 1) * (x + 2 + 2 * i) / (i * x);

			if (needed_step >= fabs(fabs(b + F) - a) or i > 100000) break;

		}
		
		//����� ���������� ���� �� ������ �����������
		if (i > 100000) cout << "Too big...\nPress 1 to quit\n";
		
		//����� ���������� ���� �� ������ ���������
		else cout << "\nResult: " << F << "\nNumber of steps: " << i << "\nPress 1 to quit\n";
		
		char ans = _getch();

		if (ans == '1') break;
	}

	return 0;
}