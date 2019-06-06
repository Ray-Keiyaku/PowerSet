#include<iostream>
#include<string>
#include <cmath>

using namespace std;
int m = 0;
void bol(int n,string resu[],string a[],int now,string aa[])
{
	
	if(now>=n)
	{
		for(int i=0;i<n;i++)
		{
			if(aa[i]!="")
			{
				if(resu[m]!="")
					resu[m] += ",";
				resu[m]+=aa[i];
			}
		}
		m++;
		return;
	}
	aa[now] = "";
	bol(n,resu,a,now+1,aa);
	aa[now] = a[now];
	bol(n,resu,a,now+1,aa);

}

void output(string out[],int num)
{
	cout << "{";
	for (int i = 0; i < num;i++)
	{
		cout << "{" << out[i] << "}";
		if(i!=num-1)
			cout << ",";
	}
	cout << "}" << endl;
	cout << "The total is " << num << "." << endl;

}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		m = 0;
		string a[n];
		string aa[n];
		for (int i = 0; i < n;i++)
			cin >> a[i];
		int num = pow(2, n);
		string *resu=NULL;
		resu = new string[num];
		bol(n, resu, a,0,aa);
		output(resu,num);
		delete [] resu;
	}

	return 0;
}