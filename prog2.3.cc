//
// Learning Stroustrup part 2.3
//
#include <iostream>

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
	char* name;
	long number;
	char* street;
	char* town;
	char* state[2];
	int zip;
};

//инициализация переменных

address jd = {
	"Jim Dandy",
	61, "South Street"
	"New Providence", {'N', 'J'}, 7974
};


int main()
{
	printf("Hello World");
}

