#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string main , string sub)
{
	if(main[0] == '\0' && sub[0] == '\0')
		return true;
	if(main[0] == '\0')
		return false;
	if(sub[0] == '\0')
		return true;
	if(main.length() < sub.length())
		return false;
		
	bool found = true;
	for(int i = 0; main[i] != '\0'; i++)
	{
		found = true;
		for(int j = 0; sub[j] != '\0'; j++)
		{
			if(main[i+j] != sub[j])
			{
				found = false;
				break;
			}
		}
		if(found == true)
			return true;
	}
	return false;
}

int main() {
	// your code goes here
	string mtest1 = "gooooogle";
	string stest1 = "oog";
	string stest2 = "afd";
	cout << isSubstring(mtest1,stest1)<<endl;
	cout << isSubstring(mtest1,stest2)<<endl;
	return 0;
}
