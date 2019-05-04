#include <iostream>
#include <clocale>
#include <time.h>
#include <math.h>

using namespace std;
int const	k=6;
int const	m=872;
int const	b=103;

long randomchik(long x0)
{
	return abs(b*x0+k)%872;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	
	bool ok=0;
	int dD[100000], mash[10000], nal, zan, r, D, N, i, j, k, m, Nmash=0;
	long x1=3341;

	cout<<"Введите длину тротуара:"<<endl; 
		cin>>D;
	cout<<endl<<"Введите длину машины:"<<endl; 
		cin>>N;

	for ( i=0;i<D;i++)
	{
		dD[i]=0;
	}

	for ( i=D;i<(D+N+1);i++)
	{
		dD[i]=-1;
	}

	do
	{
		nal=0;
		for (i=0;i<D;i++)
		{
			if(dD[i]==0)
				nal++;
			if(dD[i]==1)
				nal=0;
			if(nal>=N)
				break;
		}

		if(nal<N)
			ok=1;
		else
		{
			for(j=0;j<10;j++)
			{
				x1=randomchik((long)time(NULL));
				r=x1%D;
				zan=0;
				for (k=r;k<=(r+(N-1));k++)
				{

					if(dD[k]==0)
						zan++;
					if((dD[k]==1)||(dD[k]==-1))
						zan=0;
					if (zan>=N)
					{
						mash[Nmash]=r;
						Nmash++;
						for(m=r;m<=(r+(N-1));m++)
						{
							dD[m]=1;
						}
						break;
					}
				}
			}
			
		}
		if(ok==true)
		break;
	}
	
	while (ok==false);

	cout<<endl;
	cout<<"Места на парковке занятые/свободные:"<<endl;
	for(i=0;i<D;i++)
	{
		cout<<dD[i]<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	cout<<"А вот так машины заполняли пространство:"<<endl;

	for(i=0;i<Nmash;i++)
	{
		for(j=0;j<N;j++)
			cout<<(mash[i]+j+1)<<" ";
	cout<<endl;
	}
	cout<<endl;
	cout<<"Количество машин:"<<Nmash<<endl;
}