//
//Пример из 2.3.10
//


#include <iostream>
using namespace std;


struct pair {        
	char* name;
	int val;
};

const int large = 1024;
static pair vec[large+1];

pair*find(const char* p)
/*
	//работает со множеством пар "pair",
	//ишет p, если находит, возвращает его "pair"
	//в противном случае возвращает неиспользованную "pair"
*/
{
	for (int i=0; vec[i].name; i++)
		if (strcmp(p,vec[i].name == 0) return &vec[i];
	if (i == large) return &vec[large-1];
	return &vec[i];
}



int main()
{
cout << "Hello World" << endl;
}
