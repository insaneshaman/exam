#include "Header.h"

using namespace std;

int main()
{
	while (true)
	{
		//переменная, хранящая значение х
		double x;

		while (true)
		{
			cout << "Enter x:\n";

			cin >> x;

			//если х меньше 0, то шаг ряда будет стремиться к бесконечности. Если х будет равен нулю, то произойдёт деление на ноль (х в знаменателе)
			if (x <= 0) cout << "x must be > 0\n";
			
			else break;
		}
		
		//переменная, хранящая значение нужного шага
		double needed_step;

		while (true)
		{
			cout << "Enter needed step:\n";
			
			cin >> needed_step;

			//если шаг будет меньше или равен 0, то программа никогда не завершится
			if (needed_step <= 0) cout << "Needed step must be > 0\n";

			else break;
		}

		double a, i, F = (x + 2) / x, b = 0;

		for (i = 1; ; i++)
		{
			//переменная для хранения результата прошлого шага
			a = fabs(b + F);

			//переменная для хранения значения функции
			b = F;

			//сама функция
			F += pow(-1, i - 1) * (x + 2 + 2 * i) / (i * x);

			if (needed_step >= fabs(fabs(b + F) - a) or i > 100000) break;

		}
		
		//вывод результата если всё прошло ненормально
		if (i > 100000) cout << "Too big...\nPress 1 to quit\n";
		
		//вывод результата если всё прошло нормально
		else cout << "\nResult: " << F << "\nNumber of steps: " << i << "\nPress 1 to quit\n";
		
		char ans = _getch();

		if (ans == '1') break;
	}

	return 0;
}