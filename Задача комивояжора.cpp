#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	int	uz [50][50], vich[50][50],
			msh[50][50], mshstr[50][50], mshsto[50][50],
			d[50][2], g[50][2], k[50][2], m[50][2],
			mstr[50], msto[50], kp[50], c[50],
			a, b, e, f, h, n, r, i, j, sp=0; 
	
	setlocale(LC_ALL, "Russian");

	 /*Ввод и инициализация*/

	cout<<"Введите размер матрицы:"<<endl;
	cin>>r;

	for(i=0;i<r;i++)
		 uz[i][i]=-999;

	cout<<"Введите матрицу смежности без значений на главной диагонали:"<<endl;
	for(i=0;i<r;i++)
	{
		cout<<"Введите "<<i+1<<" строку:"<<endl;
		for(j=0;j<r;j++)
			if(uz[i][j]!=-999)
				cin>>uz[i][j];
	}

	for(i=0;i<r;i++)
	{
		cout<<endl;
		for(j=0;j<=(r-1);j++)
			cout<<uz[i][j]<<" ";
    }

	for(j=0;j<r;j++)
	{
		g[j][0]=j+1;
		g[j][1]=j+1;
	}

	for(i=0;i<=r;i++)
		for(j=0;j<=r;j++)
			vich[i][j]=uz[i][j];

	for(j=0;j<=(r-2);j++)
	{
		m[j][0]=0;
		m[j][1]=0;
	}

	/*Начало цикла решения задачи*/
	
	for(h=1;h<=5;h++)
	{
	
		/*Вычисление и вычитание минимальных элементов строк*/

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				if(vich[i][j]!=-999)
					{
						mstr[i]=vich[i][j];
						break;
					}

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				if(vich[i][j]!=-999)
					if(mstr[i]>vich[i][j])
						mstr[i]=vich[i][j];

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
			if(vich[i][j]!=-999)
				vich[i][j]=vich[i][j]-mstr[i];

		/*Вычисление и вычитание минимальных элементов столбцов*/

		for(j=0;j<=(r-h);j++)
			for(i=0;i<=(r-h);i++)
				if(vich[i][j]!=-999)
				{
					msto[j]=vich[i][j];
					break;
				}

		for(j=0;j<=(r-h);j++)
			for(i=0;i<=(r-h);i++)
				if(vich[i][j]!=-999)
					if(msto[j]>vich[i][j])
						msto[j]=vich[i][j];

		for(j=0;j<=(r-h);j++)
			for(i=0;i<=(r-h);i++)
				if(vich[i][j]!=-999)
					vich[i][j]=vich[i][j]-msto[j];

		/*Сумма констант приведения на данном шаге*/

		for(i=0;i<=(r-h);i++)
			kp[h-1]=kp[h-1]+mstr[i]+msto[i];

		if(h==r-1)goto e;

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				msh[i][j]=-111;

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				if(vich[i][j]==0)
				{
					for(a=0;a<=(r-h);a++)
						if(vich[i][a]!=-999)
							if(a!=j)
							{
								mshstr[i][j]=vich[i][a];
								goto A;
							}
     
A:
					for(a=0;a<=(r-h);a++)
						if(vich[i][a]!=-999)
							if(a!=j)
								if(mshstr[i][j]>vich[i][a])
									mshstr[i][j]=vich[i][a];

					for(b=0;b<=(r-h);b++)
						if(vich[b][j]!=-999)
							if(b!=i)
							{
								mshsto[i][j]=vich[b][j];
								goto B;
							}

B:
					for(b=0;b<=(r-h);b++)
						if(vich[b][j]!=-999)
							if(b!=i)
								if(mshsto[i][j]>vich[b][j])
									mshsto[i][j]=vich[b][j];
     
					/*Вычисление штрафа*/
      
					msh[i][j]=mshstr[i][j]+mshsto[i][j];	
				} 

		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				if(msh[i][j]!=-111)
				{
					c[h-1]=msh[i][j];
					d[h-1][0]=i;
					d[h-1][1]=j;
					goto C;
				}

C:
		for(i=0;i<=(r-h);i++)
			for(j=0;j<=(r-h);j++)
				if(msh[i][j]!=111)
					if(msh[i][j]>c[h-1])
					{
						c[h-1]=msh[i][j];
						d[h-1][0]=i;
						d[h-1][1]=j;
					}

		k[h-1][0]=g[d[h-1][0]][0];
		k[h-1][1]=g[d[h-1][1]][1];

		/*Урезание строки матрицы*/

		for(i=0;i<=(r-h-1);i++)
			if(i==d[h-1][0])
				for(e=i;e<=(r-h-1);e++)
					for(f=0;f<=(r-h);f++)
						vich[e][f]=vich[e+1][f]; 

		/*Урезание столбца матрицы*/
		
		for(j=0;j<=(r-h-1);j++)
			if(j==d[h-1][1])
				for(e=j;e<=(r-h-1);e++)
					for(f=0;f<=(r-h-1);f++)
						vich[f][e]=vich[f][e+1];

		for(i=d[h-1][0];i<=(r-h-1);i++)
			g[i][0]=g[i+1][0];
		for(i=d[h-1][1];i<=(r-h-1);i++)
			g[i][1]=g[i+1][1];

		for(i=0;i<=(r-h-1);i++)
			for(j=0;j<=(r-h-1);j++)
				if (k[h-1][0]==g[j][1]&&k[h-1][1]==g[i][0])
					vich[i][j]=-999;

		for(i=0;i<(h-1);i++)
			if(k[h-1][0]==k[i][1])
			{
				m[h-1][0]=k[i][0];
				m[h-1][1]=k[h-1][1];
			}

		for(i=0;i<(h-1);i++)
			if(k[h-1][1]==k[i][0])
				if(m[h-1][0]==0)
				{
					m[h-1][0]=k[h-1][0];
					m[h-1][1]=k[i][1];
				}
				else 
					m[h-1][1]=k[i][1];

		for(i=0;i<h-1;i++)
			if(m[i][0]!=0)
				if(k[h-1][0]==m[i][1])
					m[h-1][0]=m[i][0];

		for(i=0;i<h-1;i++)
			if(m[i][0]!=0)
				if(k[h-1][1]==m[i][0])
					m[h-1][1]=m[i][1];

		for(i=0;i<=(r-h-1);i++)
			for(j=0;j<=(r-h-1);j++)
				if (m[h-1][0]==g[j][1]&&m[h-1][1]==g[i][0])
					vich[i][j]=-999;
	}

	/*Конец основного цикла*/

e:
	int l=2;
	for(i=0;i<=1;i++)
		for(j=0;j<=1;j++)
			if(vich[i][j]==0)
			{
				k[r-l][0]=g[i][0]; 
				k[r-l][1]=g[j][1];
				l=l-1;
			}
 
	for(i=0;i<=r-1;i++)
		sp=sp+uz[k[i][0]-1][k[i][1]-1];
 
	cout<<endl<<endl;
	cout<<"Минимальная стоимость проезда:"<<sp<<endl<<endl;
	cout<<"Оптимальный тур:"<<endl;
	
	for(i=0;i<=(r-1);i++)
	{ 
		if (i==0)
			cout<<k[i][0]<<" => ";
		if(i==(r-1))
			cout<<k[i][1]<<endl;
		else
			cout<<k[i][1]<<" => ";
    }
	return 0;
}