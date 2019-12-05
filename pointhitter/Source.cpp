#include "Header.h"

using namespace std;

int main()
{
	while (true)
	{
		//радиус окружности
		int r;
		
		while (true)
		{
			cout << "Enter radius:\n";
			
			//ввод радиуса окружности
			cin >> r;

			if (r < 0) cout << "Radius cant be less than 0!\n";

			else break;
		}

		//параметр а из уравнения параболы y=x*x+a
		int a;
		
		while (true)
		{
			cout << "Enter a from y=x*x+a:\n";

			//ввод а
			cin >> a;

			//парабола должна быть внутри окружности
			if (a > r)	cout << "Parabola is out of round. Enter a again\n";

			else break;
		}

		//параметр b из уравнения прямой y=b
		int b;
		
		while (true)
		{
			cout << "Enter b from y=b:\n";

			//ввод b
			cin >> b;

			//прямая должна проходить через окружность или касаться её
			if (fabs(b) > r) cout << "Line is out of round. Enter b again\n";

			//прямая должна касаться параболы или проходить через неё
			else if (b < a) cout << "Line is out of parabola. Enter b again\n";

			else break;
		}

		//координата х точки
		int x;
		
		while (true)
		{
			cout << "Enter x:\n";
			
			//ввод х
			cin >> x;

			//точка должна быть внутри окружности
			if (x > r) cout << "Point is out of round\n";

			//точка должна быть внутри параболы
			else if (x * x + a > b) cout << "Point is out of parabola\n";

			else break;
		}
		
		//координата у точки
		int y;
	
		cout << "Enter y:\n";
		//ввод у
		cin >> y;

		//точка должна быть внутри окружности
		if (y > r) cout << "Point is out of round\n";

		//точка должна быть под прямой у=b
		else if (y > b) cout << "Point is out of line\n";

		//точка должна быть внутри параболы
		else if (y < a) cout << "Point is out of parabola\n";

		else cout << "Point is in range!\n";

		cout << "Press 1 to solve another one task\nPress anything else to quit\n";

		char ans = _getch();

		if (ans != '1') break;
	}

	return 0;
}