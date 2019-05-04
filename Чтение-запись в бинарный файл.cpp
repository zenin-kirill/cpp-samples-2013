#include <iostream>
#include <fstream>

using namespace std;

class mat_t
{
		double x,y,Vx,Vy,m;

public:
	mat_t()
	{
		x=0;
		y=0;
		Vx=0;
		Vy=0;
		m=1;
		cout<<"Создан объект: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	mat_t(double inx,double iny, double invx, double invy, double inm)
	{
		x=inx;
		y=iny;
		Vx=invx;
		Vy=invy;
		m=inm;
		cout<<"Создан объект: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	mat_t(const mat_t &a)
	{
		x=a.x;
		y=a.y;
		Vx=a.Vx;
		Vy=a.Vy;
		m=a.m;
		cout<<"Создан объект: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	bool enter_d()
	{
		cout<<"Введите данные: x,y,vx,vy,m."<<endl;
		if ((cin>>x)&&
			(cin>>y)&&
			(cin>>Vx)&&
			(cin>>Vy)&&
			(cin>>m)&&
			(m>0)) 
			{
				cout<<"Данные успешно введены: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
				return 1;
			}
		else
		{
			cin.clear();
			cin.sync();
			cout<<"Ошибка! Введенные данные не верны!"<<endl<<endl;	
			return 0;
		}	
	}

	void enter_d(double inx,double iny, double invx, double invy, double inm)
	{
		x=inx;
		y=iny;
		Vx=invx;
		Vy=invy;
		m=inm;
		cout<<"Данные успешно введены: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	void enter_d(const mat_t &a)
	{
		x=a.x;
		y=a.y;
		Vx=a.Vx;
		Vy=a.Vy;
		m=a.m;
		cout<<"Данные успешно введены: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	void print_d()
	{
		cout<<endl<<"Полный вывод:"<<endl;
		cout<<"x="<<x<<";"<<endl;
		cout<<"y="<<y<<";"<<endl;
		cout<<"Vx="<<Vx<<";"<<endl;
		cout<<"Vy="<<Vy<<";"<<endl;
		cout<<"m="<<m<<"."<<endl<<endl;
	}

	bool edit_d()
	{
		double Fx,Fy,t;

		cout<<"Что изменить данные, введите Fx,Fy,t."<<endl;
		if ((cin>>Fx)&&
			(cin>>Fy)&&
			(cin>>t)&&
			(t>0))
					cout<<"Данные успешно изменены:";
			else
			{
				cin.clear();
				cin.sync();
				cout<<"Ошибка! Введенные данные не верны!"<<endl<<endl;
				return 0;
			}
		
		double x0=x;
		double y0=y;

		double vx0=Vx;
		double vy0=Vy;

		Vx=vx0+(Fx*t)/m;
		Vy=vy0+(Fy*t)/m;

		x=x0+vx0*t+(Fx/m*t*t)/2;
		y=y0+vy0*t+(Fy/m*t*t)/2;
		cout<<" x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
		return 1;
	}

	void edit_d(double fx,double fy, double t)
	{
		double x0=x;
		double y0=y;
		double vx0=Vx;
		double vy0=Vy;
		Vx=vx0+(fx*t)/m;
		Vy=vy0+(fy*t)/m;
		x=x0+vx0*t+(fx/m*t*t)/2;
		y=y0+vy0*t+(fy/m*t*t)/2;
		cout<<"Данные успешно изменены: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<"!"<<endl;
	}

	bool sravm(const mat_t &a)
	{
		if ((x==a.x)&&
			(y==a.y)&&
			(Vx=a.Vx)&&
			(Vy==a.Vy)&&
			(m=a.m))
				return 1;
		else 
			return 0;
	}
		
	~mat_t()
	{ 
		cout<<"Объект: x="<<x<<", у="<<y<<", Vx="<<Vx<<", Vy="<<Vy<<", m="<<m<<", успешно удален!"<<endl;
	}

	double _m()
	{
		return m;
	}

	double _Vx()
	{
		return Vx;
	}

	double _Vy()
	{
		return Vy;
	}

	double _x()
	{
		return x;
	}
	
	double _y()
	{
		return y;
	}

};

int main()
{
	int n;
	double M=0, Smx=0, Smy=0, SmVx=0,SmVy=0;
	setlocale(LC_ALL,"Russian");
	mat_t SYS;
	mat_t P[6];
	ifstream fin("C:\\1.bin",ios::binary|ios::in);	
	if (!fin) cout<<"Ошибка ввода в файл.";
	fin.read((char*)&n,sizeof n);
	for (int i=0;i<n;i++)
	{
		fin.read((char*)&P[i], sizeof(P[i]));
	}
	fin.close(); 
	for (int i=0;i<n;i++)
	{
		M=M+P[i]._m();
		Smx=Smx+P[i]._m()*P[i]._x();
		Smy=Smy+P[i]._m()*P[i]._y();
		SmVx=P[i]._m()*P[i]._Vx();
		SmVy=P[i]._m()*P[i]._Vy();
	}
	Smx=Smx/M;
	Smy=Smy/M;
	SmVx=SmVx/M;
	SmVy=SmVy/M;
	SYS.enter_d(Smx,Smy,SmVx,SmVy,M);
	 ofstream fout("C:\\2.bin",ios::binary|ios::out); 
	 if (!fout) cout<<"Ошибка вывода в файл.";
     fout.write((char*)&SYS, sizeof(SYS));
	 for (int i=(n-1);i>=0;i--)
		 fout.write((char*)&P[i], sizeof(P[i]));
     fout.close(); 

	return 0;
}