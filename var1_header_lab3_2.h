#include <Windows.h>	
#include <math.h>   					
#include <iomanip> 
#include <iostream>	 
#include <new>


typedef unsigned int int_set;
using namespace std;


class Set
{
public:
	//������������
	Set();													//����������� �� ���������
	Set(const Set&); 										//����������� �����������
	~Set();													//����������
	
	//������
	Set & operator = (const Set&);							//�������� ������������
	Set	& operator += (const int);							//���������� ��������
	bool operator == (const Set&);							//�������� ==
	bool operator != (const Set&);							//�������� !=
	bool belongSet(const int) const;						//�������������� �������� ���������
	void print(const char *) const;							//������ ���������

	//������ � ������ 
	int getSize() const;									//��������� ���������� ��������� ���������
	void setNumber(const int_set, const int);				//��������� ����� ���������

	//������������� �������
	friend Set operator + (const Set&, const Set&);			//�����������
	friend Set operator - (const Set&, const Set&);			//���������
	friend Set operator * (const Set&, const Set&);			//�����������
	friend istream& operator >> (istream&, Set&);			//�������� ����
	friend ostream& operator << (ostream&, const Set&);		//�������� ������

private:
	int* pointer;											//��������� �� ���������
	int_set p_size;											//���������� ��������� ���������
};