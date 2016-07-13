#include <iostream>

using namespace std;

class Fraction
{
private:
	int sign; // знак дроби (+ или -)
	int intPart; // целая часть дроби
	int numerator; // числитель дроби
	int denominator; // знаменатель дроби
	void Cancellation(); //сокращение дроби
	void GetIntPart(); //выделение целой части дроби
	void GetMixedView(); //преобразование в смешанный вид
public:
	Fraction(int = 1, int = 0, int = 0, int = 1); //конструктор инициализации
	Fraction (const Fraction&); // конструктор копирования
	Fraction (const double&); // конструктор преобразования типа
	~Fraction(); //деструктор
	// метод преобразования в тип double
	operator double();
	// методы сравнения двух дробей
	const bool operator > (const Fraction);
	const bool operator < (const Fraction);
	const bool operator >= (const Fraction);
	const bool operator <= (const Fraction);
	const bool operator != (const Fraction);
	const bool operator == (const Fraction);
	// метод сложения двух дробей
	Fraction operator + (const Fraction);
	// метод вычитания двух дробей
	Fraction operator - (const Fraction);
	// метод умножения двух дробей
	Fraction operator * (const Fraction);
	// метод деления двух дробей
	Fraction operator / (const Fraction);
	// метод умножения на (-1)
	Fraction operator - ();
	// функция сложения целого числа и дроби
	friend Fraction operator + (const Fraction c, const double a)
	{
		Fraction b(c);
		double d = double(b);
		Fraction *res = new Fraction(d+a);
		return *res;
	}
	// функция вычитания дроби из целого числа
	friend Fraction operator - (const Fraction c, const double a)
	{
		return c+(-a);
	}
	// функция умножения целого числа и дроби
	friend Fraction operator * (const Fraction c, const double a)
	{
		Fraction b(c);
		double d = double(b);
		Fraction *res = new Fraction(d*a);
		return *res;
	}
	// функция деления целого числа на дробь
	friend Fraction operator / (const Fraction c, const double a)
	{
		if (a==0) throw "Деление на 0!";
		return c*(1/a);
	}
	//функция ввода дроби
	friend istream& operator >> (istream& in, Fraction& a)
	{
		setlocale(LC_ALL, "Rus");
		cout << "Введите целую часть:\n";
		in >> a.intPart;
		cout << "Введите числитель:\n";
		in >> a.numerator;
		cout << "Введите знаменатель:\n";
		in >> a.denominator;
		if (a.denominator == 0) throw "знаменатель = 0!\n";
		a.GetMixedView();
		return in;
	}
	//функция вывода дроби
	friend ostream& operator << (ostream& fout, Fraction& a)
	{
		setlocale(LC_ALL, "Rus");
		// знак числа печатается только, если число отрицательно
		if (a.sign < 0) fout << "-";
		// если целая часть не равна 0, выводим ее
		if (a.intPart != 0) fout << a.intPart << " ";
		// дробная часть печатается, если числитель не равен 0
		if (a.numerator != 0) fout << a.numerator << "/" << a.denominator;
		// если и целая часть и дробная часть равны 0, то число равно 0
		if (a.intPart == 0 && a.numerator == 0) fout << "0";
		// если вывод осуществляется в файл, используется символ '\t'
		if(typeid(ofstream) == typeid(fout)) fout << "\t";
		else fout << " ";
		return fout;
	}
};
