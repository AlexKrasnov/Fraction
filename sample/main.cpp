#include "Fraction.h"

void menu()
{
	setlocale (LC_ALL, "rus");
	cout <<"\t\t***Класс Рациональное число***\n\n";
	cout << "1) Сложение двух дробей\n";
	cout << "2) Сложение дроби и целого числа\n";
	cout << "3) Сложение дроби и вещественного числа\n";
	cout << "4) Вычитание одной дроби из другой\n";
	cout << "5) Вычитание из дроби целого числа\n";
	cout << "6) Вычитание из дроби вещественного числа\n";
	cout << "7) Умножение двух дробей\n";
	cout << "8) Умножение дроби и целого числа\n";
	cout << "9) Умножение дроби и вещественного числа\n";
	cout << "10) Деление двух дробей\n";
	cout << "11) Деление дроби на целое число\n";
	cout << "12) Деление дроби на вещественное число\n";
	cout << "13) Перевод дроби в вещественное число\n";
	cout << "14) Перевод вещественного числа в дробь\n";
	cout << "15) Выход\n";
	Fraction a,b;
	int ival;
	double dval;
	int count(0);
	while(count != 15)
	{
		cout << "Выберите нужную операцию: \n";
		cin >> count;
		switch(count)
		{
		case 1: 
			{
				cout << "1) Сложение двух дробей\n";
				cout << "Введите 2 дроби\n";
				cin >> a; cin >> b; 
                Fraction c = a + b;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 2: 
			{
				cout << "2) Сложение дроби и целого числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите целое число\n"; 
				cin >> ival; 
				Fraction c = a + double(ival);
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 3: 
			{
				cout << "3) Сложение дроби и вещественного числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите вещественное число\n"; 
				cin >> dval; 
				Fraction c = a + dval;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 4: 
			{
				cout << "4) Вычитание одной дроби из другой\n";
				cout << "Введите 2 дроби\n";
				cin >> a; cin >> b; 
                Fraction c = a - b;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 5: 
			{
				cout << "5) Вычитание из дроби целого числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите целое число\n"; 
				cin >> ival; 
				Fraction c = a - double(ival);
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 6: 
			{
				cout << "6) Вычитание из дроби вещественного числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите вещественное число\n"; 
				cin >> dval; 
				Fraction c = a - dval;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 7: 
			{
				cout << "7) Умножение двух дробей\n";
				cout << "Введите 2 дроби\n";
				cin >> a; cin >> b; 
                Fraction c = a * b;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 8: 
			{
				cout << "8) Умножение дроби и целого числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите целое число\n"; 
				cin >> ival; 
				Fraction c = a * double(ival);
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 9: 
			{
				cout << "9) Умножение дроби и вещественного числа\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите вещественное число\n"; 
				cin >> dval; 
				Fraction c = a * dval;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 10: 
			{
				cout << "10) Деление двух дробей\n";
				cout << "Введите 2 дроби\n";
				cin >> a; cin >> b; 
                Fraction c = a / b;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 11: 
			{
				cout << "11) Деление дроби на целое число\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите целое число\n"; 
				cin >> ival; 
				Fraction c = a / double(ival);
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 12: 
			{
				cout << "12) Деление дроби на вещественное число\n";
				cout << "Введите дробь\n"; 
				cin >> a; 
				cout << "Введите вещественное число\n"; 
				cin >> dval; 
				Fraction c = a / dval;
				cout << "Результат: \n" << c << endl; 
				break;
			}
		case 13:
			{
				cout << "13) Перевод дроби в вещественное число\n";
				cout << "Введите дробь:\n";
				cin >> a;
				cout << "Результат: \n"  << double(a) << endl;
				break;
			}
		case 14:
			{
				cout << "14) Перевод вещественного числа в дробь\n";
				cout << "Введите вещественное число:\n";
				cin >> dval;
				Fraction *res = new Fraction (dval);
				cout << "Результат: \n"  << *res << endl;
				break;
			}
		case 15: break;
		default: cout<< "Неправильный ввод\n"; 
		}
	}
}


void main()
{
	try
	{
		menu();
	}
	catch(const char* error)
	{
		cout << error;
	}
}