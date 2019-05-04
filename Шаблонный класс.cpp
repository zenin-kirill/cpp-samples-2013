#include <iostream>
#include <math.h>
#include <clocale>
#include <time.h>

using namespace std;
const int SIZE=10;

template <class T> class arr
{
	T a[SIZE];
public:
	arr();
	arr(T b);
	arr(arr & b);
	~arr();
	T getn(int n);
	void putn(T b, int n);
	double G();
	void print();
	arr operator=(const arr &d)
	{
		A[0][0]=d.A[0][0];	
		A[0][1]=d.A[0][1];
		A[1][0]=d.A[1][0];
		A[1][1]=d.A[1][1];
		return this;
	}
};

template <class T> arr<T>::arr()
{
	srand(time(NULL));
	for (int i=0;i<SIZE;i++)
	{
		a[i]=(T(rand()%100)/10)+20;
	}
	cout << "Объект создан.\n";
}

template <class T> arr<T>::arr(T b)
{
	for (int i=0;i<SIZE;i++)
	{
		a[i]=b;
	}
	cout << "Объект создан.\n";
}

template <class T> arr<T>::arr(arr & b)
{
	for (int i=0;i<SIZE;i++)
	{
		a[i]=b.a[i];
	}
	cout << "Объект создан.\n";
}

template <class T> T arr<T>::getn(int n)
{
	if (n<=SIZE)
	{
		return a[n];
	}
	else cout<<"Неверное значение аргумента.";
}

template <class T> void arr<T>::putn(T b,int n)
{
	if(n<=SIZE)
		a[n]=b;
	else
		cout<<"Неверное значение аргумента.";
}

template <class T> double arr<T>::G()
{
	double p=1;
	for (int i=0;i<SIZE;i++)
	{
		p=p*a[i];
	}
	return pow(p,(1.0/10.0));
}

template <class T> void arr<T>::print()
{
	cout <<endl<< "Вывод:\n";
	for (int i=0;i<SIZE;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
}

template <class T> arr<T>::~arr()
{
	cout << "Объект уничтожен."<<endl;
}


int main()
{
	setlocale(LC_ALL,"Russian");
	arr<int> A;
	arr<double> B;
	arr<long> C(3);
	arr<char> CH;
	
	A.print();
	B.print();
	C.print();
	CH.print();

	cout<<"Третий член массива А:"<<A.getn(3-1)<<endl;
	C.putn(9999,4);
	C.print();
	cout<<"Среднее геометрическое:"<<B.G()<<endl;
	
	return 0;
}