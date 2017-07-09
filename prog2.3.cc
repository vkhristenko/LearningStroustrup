//
// Learning Stroustrup part 2.3
//
#include <iostream>
using namespace std;

// sizes of different data types(2.3.1) 

void sizesTable ()
{
	cout << "size of char is " << sizeof(char) << endl;
	cout << "size of short is " << sizeof(short) << endl;
	cout << "size of int is " << sizeof(int) << endl;
	cout << "size of long is " << sizeof(long) << endl;
	cout << "size of float is " << sizeof(float) << endl;
	cout << "size of double is " << sizeof(double) << endl;	
}

// указатели (2.3.5)

void f2()
{
	char c1 = 'a';
	char* p = &c1;
	char c2 = *p;
	cout << c2 << endl;
}

// длина строки в двух примерах (2.3.7)
char vic[] = "helloFromTheOtherSide"; //задается адрес для массива
char* p = vic;
int strlen0(char* p)
{
	int i = 0;
		while (*p++) i++;
		return i;
}

int strlen1(char* p)
{
	char* q = p;
	while(*p++);
	return q-p-1;
}

//значение прописных букв

//extern "C" int strlen(constant char*);
char alpha[] = "abcdefghijklmnopqrstuvwxyz";

void f3()
{
	int sz = strlen(alpha);	
	for (int i=0; i<sz; i++)
	{
	char ch = alpha[i];
	cout << '\''<< ch << '\''
	     << " = " << int(ch) << '\n';
//	     << " = " << oct(ch)
//	     << " = " << hex(ch) << '\n';
	}
}

//массив с двумя элементами 
char v[2][5] = 
	{
	{ 'a', 'b', 'c', 'd', 'e'},
	{ '0', '1', '2', '3', '4'}
	};
void f4()
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << "v[" << i << "][" << j
			     << "]=" << v[i][j] << "  ";
			cout << '\n';
	}
}

//massiv cherez ykazatel' (2.3.7)

/*void f5()
{
char* p = alpha;
	cout << *p << endl;
	char ch;
	while (ch = *p++)
		cout << ch << " = " << int(ch) << '\n';
}*/


void f6()
{
	int v1[] = { 1, 2, 3, 4, 5};
	int v2[] = {'a', 'b', 'c', 'd', 'e'};
	int v3[10];
	int i = &v1[4]-&v1[1];
	int s = &v2[4]-&v2[1];
	cout << "Pri vuchitanii ykazateley poluchaetsya:"
	<< '\n' << i << '\n' << s << endl;
	int* p = v3+3;
	int l = *p;
	cout << l << endl;
	int* z = &v3[2];
	cout << "Znachenie ykazatela v3 + 2 " 
	<< '\n' << p << '\n' << z << endl;
	int* x = v2 - 2;
	cout << x << endl;

}

//пример структуры (2.3.8)

struct address //определение структуры "адрес"
{
    // the need for the const is because otherwise you will be getting:
    //
    // prog2.3.cc:130:21: warning: conversion from string literal to 'char *' is deprecated
    //       [-Wc++11-compat-deprecated-writable-strings]
    //               "New Providence", {"N", "J"}, 
    //                         
    // the idea here is that "something" is of type char const * and you can not assign
    // that to something of type char*
    // In other words, given something that is a const, you can not assign it to be a 
    // non-const - varying basically...
    //
	char const * name;
	long number;
	char const * street;
	char const * town;
	char const * state[2];
	int zip;
};

//инициализация переменных

address jd = {
	"Jim Dandy",
	61, "South Street", // you forgot a comma in here!
	"New Providence", {"N", "J"}, 
    7974
};

address vk = {
	"Victor Khristenko",
	1220, "1st Ave NE", // you forgot a comma in here!
	"Cedar Rapids", {"I", "A"}, 
    52402
};

address* pointerAddress = &jd;

//вывод данных на экран

void print_address(address* p)
{
	cout << "Name: " << p -> name << '\n'
	<< "Number: " << p -> number << '\n'
	<< "Street: " << p -> street << '\n'
	<< "Town: " << p -> town << '\n'
	<< "State: " << p -> state[0] << p -> state[1] << '\n'
	<< "ZIP Code: " << p -> zip << endl;
} 

//присваивание адресу нового значения

address current;
address set_current(address next)
{
	address prev = current;
	current = next;
	return prev;
}

struct link{
	link* previous;
	link* successor;
};

//два структурных типа с одними и теми же
//членами - различны (2.3.9)

struct s1 { int a; };
struct s2 { int a; };

//использование typedef

typedef char* Pchar;
Pchar p1, p2;
char* p3 = p1;	

//ссылка как параметр функции(2.3.10)

void incr(int& aa) { aa++; }
void f7(){
	int x = 1;
	incr(x);
	cout << x << endl;
}

//указатель и переменная как параметры функции(2.3.10)

int next(int p) { return p+1; }
void inc(int* p) { (*p)++; }
void g()
{
	int x = 1;
	x = next(x);
	cout << x << endl;
	inc(&x);
	cout << x << endl;
}
//ссылка, представленная как указатель(2.3.10)

void f8()
{
	double* cdrp;
	double temp;
	temp = double(1);
	cdrp = &temp;
	cout << cdrp << endl;
}

int main()
{
	f8();
}
