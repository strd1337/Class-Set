#include "var1_header_lab3_2.h"


//конструктор по умолчанию
Set::Set()
{
	p_size = 0;
	pointer = nullptr;
}


//конструктор копирования
Set::Set(const Set& other)
{
	//копирование кол-ва элементов
	p_size = other.p_size;

	try {
		//выделение памяти
		pointer = new int [p_size];

		//заполнение значениями
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = other.pointer[i];

	}
	catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		exit(-1);
	}
}


//деструктор
Set::~Set()
{
	delete[] pointer;
}


//оператор присваивания
Set& Set::operator=(const Set& other)
{
	//присваивание самому себе
	if (this == &other)
		return *this;

	//очищаем память		
	delete[] pointer;

	//размер 
	p_size = other.p_size;

	try {
		//выделяем память
		pointer = new int [p_size];

		//заполняем значениями
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = other.pointer[i];

		//возвращаем
		return *this;

	}
	catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		exit(-1);
	}
}


//добавление элемента
Set& Set::operator+=(const int element)
{
	//создаем новый элемент
	Set temp(*this);

	//очищаем старую память 		
	delete[] pointer;

	try {
		//выделяем новую память для +1 элемента
		pointer = new int[p_size + 1];

		//заполняем значениями из старого в новый
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = temp.pointer[i];

		//вставка элемента
		pointer[p_size++] = element;

		//возвращаем
		return *this;
	}
	catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		exit(-1);
	}
}


//оператор ==
bool Set::operator==(const Set& other)
{
	int_set k = 0;
	for (int_set i = 0; i < p_size; ++i)
	{
		for (int_set j = 0; j < p_size; ++j)
		{
			if (pointer[i] == other.pointer[j]) {
				++k;
				break;
			}
		}
	}
	if (k == p_size)
		return true;
	else
		return false;
}


//оператор !=
bool Set::operator!=(const Set& other)
{
	return !(*this == other);
}


//принадлежность элемента множеству
bool Set::belongSet(const int element) const
{
	for (int_set i = 0; i < p_size; ++i)
		if (pointer[i] == element)
			return true;

	return false;
}


//печать множества
void Set::print(const char* name) const
{
	if (!p_size) {
		cout << "\nОшибка. Множества не существует.\n";
	}
	else {
		cout << "Печать объекта " << name << ":" << endl;

		for (int_set i = 0; i < p_size; ++i)
			cout << pointer[i] << "\t";

		cout << "\n\n";
	}
}


//получение количества элементов множества
int Set::getSize() const
{
	return p_size;
}


//изменение числа множества
void Set::setNumber(const int_set i, const int element)
{
	//проверка на выход за границы
	if (i > -1 || i < p_size)
		pointer[i] = element;
	else {
		cout << endl << "Ошибка. Выход за пределы." << endl;
	}
}


//объединение
Set operator+(const Set& one, const Set& two)
{
	//создаем новый объект
	//со значениями 1 элемента
	Set temp(one);

	//добавляем в новый объект все значения
	//второго элемента
	for (int_set i = 0; i < two.p_size; ++i)
		temp += two.pointer[i];
	
	//возвращаем
	return temp;
}


//вычитание
Set operator-(const Set& one, const Set& two)
{	
	//создаем новый объект
	Set temp;
	
	//идём по всем элементам первого объекта
	for (int_set i = 0; i < one.p_size; ++i)
	{
		//если не нашли элемент во 2 объекте
		bool flag = true;

		//идём по всем элементам второго объекта
		for (int_set j = 0; j < two.p_size; ++j)
		{
			//если элемент 1-го объекта не равен 
			//элементу 2-го объекта, переходим к следующему
			//элементу 2-го объекта
			if (one.pointer[i] != two.pointer[j])
				continue;
			else { 
				//иначе завершаем и переходим 
				//к следующему элементу 1-ого объекта
				flag = false;
				break;
			}
		}
		
		//то добавляем его в новый объект
		if (flag)
			temp += one.pointer[i];
	}
		
	//возвращаем
	return temp;
}


//пересечение
Set operator*(const Set& one, const Set& two)
{
	//создаем новый объект
	Set temp;

	//идём по всем элементам первого объекта
	for (int_set i = 0; i < one.p_size; ++i)
		//идём по всем элементам второго объекта
		for (int_set j = 0; j < two.p_size; ++j)
			//если элемент 1-го объекта равен 
			//элементу 2-го объекта, добавляем элемент
			//в новый объект и переходим к следующему 
			//элементу 1-го объекта
			if (one.pointer[i] == two.pointer[j]) {
				temp += one.pointer[i];
				break;
			}

	//возвращаем
	return temp;
}


//оператор ввод
istream& operator>>(istream& ist, Set& other)
{
	cout << "\nСколько элементов хотите добавить?\nВвод: ";
	ist >> other.p_size;

	other.pointer = new int[other.p_size];

	for (int_set i = 0; i < other.p_size; ++i)
	{
		cout << "Set[" << i + 1 << "] = ";
		ist >> other.pointer[i];
	}

	return ist;
}


//оператор вывода
ostream& operator<<(ostream& ost, const Set& other)
{
	for (int_set i = 0; i < other.p_size; ++i)
		ost << other.pointer[i] << "\t";

	ost << endl;

	return ost;
}