#include <iostream>
#include <string.h>
using namespace std;
void mistake(char str[],int done)
{
	cout<<"\n  Mistake : ";
	for (int i=0;i<=done;i++)
		cout<<str[i];
	cout<<endl;
}
int main()
{
	char str[25];
	cout<<"\n  String : ";
	flushall();
	cin.getline(str,25);
	int n=0,done=-1;
	char *next=(char*)malloc(n*sizeof(char));
	for (int i=0;i<strlen(str);i++)
	{
		if (str[i]=='('||str[i]=='['||str[i]=='{')
		{
			n++;
			next=(char*)realloc(next,n*sizeof(char));
			next[n-1]=str[i];
			done++;
			continue;
		}
		if (str[i]==')')
		{
			if (next[n-1]=='(')
			{
				n--;
				next=(char*)realloc(next,n*sizeof(char));
				done++;
				continue;
			}
		}
		if (str[i]==']')
		{
			if (next[n-1]=='[')
			{
				n--;
				next=(char*)realloc(next,n*sizeof(char));
				done++;
				continue;
			}
		}
		if (str[i]=='}')
		{
			if (next[n-1]=='{')
			{
				n--;
				next=(char*)realloc(next,n*sizeof(char));
				done++;
				continue;
			}
		}
		if (str[i]!='('&&str[i]!='['&&str[i]!='{'&&str[i]!=')'&&str[i]!=']'&&str[i]!='}')
		{
			done++;
			continue;
		}
		if (done<i)
		{
			mistake(str,done);
			break;
		}
	}
	if (done+1==strlen(str))
		cout<<"\n  Congratulations!"<<endl;
	return 0;
}