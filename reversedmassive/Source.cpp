#include "Header.h"

using namespace std;

int main()
{
	//для нормальной работы rand, которая генерирует случайные числа
	srand(time(NULL));

	while (true)
	{
		cout << "Enter massive capacity:\n";

		//переменные, хранящие размеры массива
		int rows, columns;

		//ввод числа строк
		while (true)
		{
			cout << "Enter number of rows: ";

			cin >> rows;

			//если число будет меньше или равно 0, то массив не получится создать 
			if (rows <= 0) cout << "Number of rows must be greater than 0\n";

			else break;
		}

		//ввод числа столбцов
		while (true)
		{
			cout << "Enter number of columns: ";

			cin >> columns;

			//если число будет меньше или равно 0, то массив не получится создать 
			if (columns <= 0) cout << "Number of columns must be greater than 0\n";

			else break;
		}

		//динамический массив а с заданными размерами  
		int** a = new int* [rows];

		for (int i = 0; i < rows; i++) a[i] = new int[columns];

		while (true)
		{
			cout << "Press 1 to enter massive values\nPress 2 to generate random numbers\n";

			//переменная для ввода ответа через _getch
			char ans = _getch();

			switch (ans)
			{
			case '1':
				//цикл, в котором юзер вводит значения в каждую ячейку массива а
				for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++)
				{
					cout << "a[" << i << "][" << j << "] = ";

					cin >> a[i][j];
				}

				break;

			case '2':
				//переменная, хранящая диапазон чисел, генерируемых в динамический массив а
				int range;

				//ввод диапазона чисел, генерируемых в динамический массив а
				while (true)
				{
					cout << "Enter range of generated numbers: ";

					cin >> range;

					//если диапазон чисел будет меньше или равен нулю, то будут проблемы...
					if (range <= 0) cout << "Range must be greater than zero\n";

					else break;
				}

				//цикл, генерирующий случайные числа в заданном диапазоне
				for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) a[i][j] = rand() % range;

				break;

			default:
				cout << "Something went wrong, try again, please...\n";

				break;
			}

			if (ans == '1' or ans == '2') break;
		}
		
		cout << "Your massive:\n";

		//цикл, выводящий ячейки массива а на экран в виде двумерной матрицы
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++) cout << a[i][j] << "\t";

			cout << "\n";
		}

		cout << "Reversed massive:\n";
		
		//цикл, выводящий ячейки перевёрнутого массива а на экран в виде двумерной матрицы
		for (int i = rows-1; i >= 0; i--)
		{
			for (int j = columns-1; j >= 0; j--) cout << a[i][j] << "\t";
			
			//очистка динамической памяти от строк массива а
			delete[] a[i];

			cout << "\n";
		}

		//очистка динамической памяти от массива а
		delete[] a;

		cout << "Press 1 to make another one massive\nPress anything else to quit\n";

		char ans = _getch();

		if (ans != '1') break;
	}
	
	return 0;
}