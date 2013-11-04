#include <iostream>
#include <unordered_set>
#include <array>
using namespace std;

int main() {
	const int N = 5;
	// create an array
	array<int,N> oddManOut;
	for (int i = 0; i < N/2 ; i++)
	{
	oddManOut[i] = i;
	oddManOut[N/2 + i] = i; 
	}
	oddManOut[N-1] = 20;
	//print the array
	for(int i = 0; i < N ; i++)
	{
		cout << "Elemen " << i + 1 << " is " << oddManOut[i] << endl;
	}
	//get the odd man out
	unordered_set<int> s;
	unordered_set<int>::iterator it;
	int sum = 0;
	for(int i = 0; i < N; i++)
	{
		it = s.find(oddManOut[i]);
		if(it != s.end())
			sum = sum - *it;
		else
		{
			sum = sum + *it;
			s.insert(oddManOut[i]);
		}
	}
	cout << "The odd man out is: " << sum << endl;
	
	return 0;
}
