#include "Fraction.h"

// конструктор класса "Рациональная дробь"
Fraction::Fraction(int s, int i, int n, int d)
	: sign(s), intPart(i), numerator(n), denominator(d)
{
	//if (s != 1 && s!= -1) throw "error with sign";
	if (d==0) throw "знаменатель = 0\n";
	GetMixedView();
}

Fraction::Fraction (const Fraction& f)
	: sign(f.sign), intPart(f.intPart), 
	numerator(f.numerator), denominator(f.denominator) {}

Fraction::Fraction (const double& d)
{
	// до 5 знаков после запятой
	double tmp = d;
	if (tmp == 0.0) { *this = Fraction(); return; }
	intPart = int(tmp);
	if (tmp > 0) sign = 1;
	else sign = -1;
	numerator = int((tmp - double(intPart))*100000);
	denominator = 100000;
	GetMixedView();
}

// деструктор дроби
Fraction::~Fraction()
{
	/*cout << "Дробь " << (*this)
	<< " уничтожена" << endl;*/
}

// метод сокращения рациональной дроби
void Fraction::Cancellation()
{
	if(numerator != 0)
	{
		int m = denominator, n = numerator, ostatok = m%n;
		// вычисление НОД(числитель, знаменатель) алгоритмом Евклида
		while(ostatok != 0)
		{
			m = n; n = ostatok; ostatok = m % n;
		}
		int nod = n;
		if(nod != 1)
		{
			numerator /= nod; denominator /= nod;
		}
	}
}

// метод выделения целой части рационального числа
void Fraction::GetIntPart()
{
	if(numerator >= denominator)
	{
		intPart += (numerator / denominator);
		numerator %= denominator;
	}
}

// метод преобразования дроби в смешанный вид
void Fraction::GetMixedView()
{
	GetIntPart(); //выделение целой части числа
	Cancellation(); //сокращение дроби
}

// операция преобразования дроби в тип double
Fraction::operator double()
{
	Fraction res(*this);
	double r = (double)res.sign * 
		(res.intPart * res.denominator + res.numerator) / res.denominator;
	return r;
}

// операции сравнения двух дробей
const bool Fraction::operator ==(const Fraction a)
{
	if (sign != a.sign || intPart != a.intPart ||
		numerator * a.denominator !=
		denominator * a.numerator)
		return false;
	return true;
}
const bool Fraction::operator !=(const Fraction a)
{
	return !(*this==a);
}
const bool Fraction::operator > (const Fraction a)
{
	Fraction b(a);
	if (double(*this) > double(b))
		return false;
	return true;
}
const bool Fraction::operator < (const Fraction a)
{
	Fraction b(a);
	if (double(*this) < double(b))
		return false;
	return true;
}
const bool Fraction::operator >= (const Fraction a)
{
	Fraction b(a);
	if (double(*this) >= double(b))
		return false;
	return true;
}
const bool Fraction::operator <= (const Fraction a)
{
	Fraction b(a);
	if (double(*this) <= double(b))
		return false;
	return true;
}

Fraction Fraction::operator + (const Fraction a)
{
	Fraction res(*this);
	return a+res;
}

Fraction Fraction::operator - (const Fraction a)
{
	Fraction b(a);
	return -b+(*this);
}

Fraction Fraction::operator * (const Fraction a)
{
	Fraction tmp1(*this), tmp2(a);
	double d1(tmp1), d2(tmp2);
	Fraction *res = new Fraction (d1*d2);
	return *res;
}

Fraction Fraction::operator / (const Fraction a)
{
	Fraction tmp1(*this), tmp2(a);
	double d1(tmp1), d2(tmp2);
	Fraction *res = new Fraction (d1/d2);
	return *res;
}

Fraction Fraction:: operator-()
{
	Fraction res(*this);
	res.sign *= -1;
	return res;
}