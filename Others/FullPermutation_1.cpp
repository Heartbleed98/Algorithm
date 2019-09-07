#include<iostream> 
#include<cstdio> 
#include<string>
#include<algorithm> 
using namespace std; 

const int MAXN = 11;
int n, P[MAXN], hashTable[MAXN] = {false};

// index是位置，x是填入某一位置的数字
void generateP(int index)
{
	if(index == n + 1)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1; x <= n; x++)
	{
		if(hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}
 
int main()  
{ 
	n = 3;
	generateP(1);
	return 0;
} 
