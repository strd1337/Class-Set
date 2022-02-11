#include "var1_header_lab3_2.h"


//����������� �� ���������
Set::Set()
{
	p_size = 0;
	pointer = nullptr;
}


//����������� �����������
Set::Set(const Set& other)
{
	//����������� ���-�� ���������
	p_size = other.p_size;

	try {
		//��������� ������
		pointer = new int [p_size];

		//���������� ����������
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = other.pointer[i];

	}
	catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		exit(-1);
	}
}


//����������
Set::~Set()
{
	delete[] pointer;
}


//�������� ������������
Set& Set::operator=(const Set& other)
{
	//������������ ������ ����
	if (this == &other)
		return *this;

	//������� ������		
	delete[] pointer;

	//������ 
	p_size = other.p_size;

	try {
		//�������� ������
		pointer = new int [p_size];

		//��������� ����������
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = other.pointer[i];

		//����������
		return *this;

	}
	catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		exit(-1);
	}
}


//���������� ��������
Set& Set::operator+=(const int element)
{
	//������� ����� �������
	Set temp(*this);

	//������� ������ ������ 		
	delete[] pointer;

	try {
		//�������� ����� ������ ��� +1 ��������
		pointer = new int[p_size + 1];

		//��������� ���������� �� ������� � �����
		for (int_set i = 0; i < p_size; ++i)
			pointer[i] = temp.pointer[i];

		//������� ��������
		pointer[p_size++] = element;

		//����������
		return *this;
	}
	catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		exit(-1);
	}
}


//�������� ==
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


//�������� !=
bool Set::operator!=(const Set& other)
{
	return !(*this == other);
}


//�������������� �������� ���������
bool Set::belongSet(const int element) const
{
	for (int_set i = 0; i < p_size; ++i)
		if (pointer[i] == element)
			return true;

	return false;
}


//������ ���������
void Set::print(const char* name) const
{
	if (!p_size) {
		cout << "\n������. ��������� �� ����������.\n";
	}
	else {
		cout << "������ ������� " << name << ":" << endl;

		for (int_set i = 0; i < p_size; ++i)
			cout << pointer[i] << "\t";

		cout << "\n\n";
	}
}


//��������� ���������� ��������� ���������
int Set::getSize() const
{
	return p_size;
}


//��������� ����� ���������
void Set::setNumber(const int_set i, const int element)
{
	//�������� �� ����� �� �������
	if (i > -1 || i < p_size)
		pointer[i] = element;
	else {
		cout << endl << "������. ����� �� �������." << endl;
	}
}


//�����������
Set operator+(const Set& one, const Set& two)
{
	//������� ����� ������
	//�� ���������� 1 ��������
	Set temp(one);

	//��������� � ����� ������ ��� ��������
	//������� ��������
	for (int_set i = 0; i < two.p_size; ++i)
		temp += two.pointer[i];
	
	//����������
	return temp;
}


//���������
Set operator-(const Set& one, const Set& two)
{	
	//������� ����� ������
	Set temp;
	
	//��� �� ���� ��������� ������� �������
	for (int_set i = 0; i < one.p_size; ++i)
	{
		//���� �� ����� ������� �� 2 �������
		bool flag = true;

		//��� �� ���� ��������� ������� �������
		for (int_set j = 0; j < two.p_size; ++j)
		{
			//���� ������� 1-�� ������� �� ����� 
			//�������� 2-�� �������, ��������� � ����������
			//�������� 2-�� �������
			if (one.pointer[i] != two.pointer[j])
				continue;
			else { 
				//����� ��������� � ��������� 
				//� ���������� �������� 1-��� �������
				flag = false;
				break;
			}
		}
		
		//�� ��������� ��� � ����� ������
		if (flag)
			temp += one.pointer[i];
	}
		
	//����������
	return temp;
}


//�����������
Set operator*(const Set& one, const Set& two)
{
	//������� ����� ������
	Set temp;

	//��� �� ���� ��������� ������� �������
	for (int_set i = 0; i < one.p_size; ++i)
		//��� �� ���� ��������� ������� �������
		for (int_set j = 0; j < two.p_size; ++j)
			//���� ������� 1-�� ������� ����� 
			//�������� 2-�� �������, ��������� �������
			//� ����� ������ � ��������� � ���������� 
			//�������� 1-�� �������
			if (one.pointer[i] == two.pointer[j]) {
				temp += one.pointer[i];
				break;
			}

	//����������
	return temp;
}


//�������� ����
istream& operator>>(istream& ist, Set& other)
{
	cout << "\n������� ��������� ������ ��������?\n����: ";
	ist >> other.p_size;

	other.pointer = new int[other.p_size];

	for (int_set i = 0; i < other.p_size; ++i)
	{
		cout << "Set[" << i + 1 << "] = ";
		ist >> other.pointer[i];
	}

	return ist;
}


//�������� ������
ostream& operator<<(ostream& ost, const Set& other)
{
	for (int_set i = 0; i < other.p_size; ++i)
		ost << other.pointer[i] << "\t";

	ost << endl;

	return ost;
}