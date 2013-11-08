#include <iostream>
using namespace std;

/*data structure for a node*/
template <class T>
struct node {
	int data;
	node<T>* next;
};

/* function to create a newNode*/
template <class T>
node<T>* newNode(T data)
{
	node<T>* node = new struct node<T>;
	node->data = data;
	node->next = nullptr;
	return node;
}

/* detect circularity in linked list*/
template <class T>
bool isCircular(node<T> *root)
{
	/*base case*/
	if( root == nullptr)
		return false;
	node<T> *pFast;
	node<T> *pSlow;
	pFast = pSlow = root;
	bool circular =  false;
	while(pFast != nullptr)
	{
		pFast = pFast->next;
		if(pFast != nullptr) /*increment the pointer by twice*/
			pFast = pFast->next;
		else
			return false; /*reached end*/
		pSlow = pSlow->next;
		if(pSlow == pFast)
		{
			return true; /*found circular*/
		}
	}
	return false; /*reached end*/
}
int main() {
	// your code goes here
	node<int> *circularList = newNode(5);
	circularList->next = newNode(6);
	circularList->next->next = circularList;
	node<int> *noncircularList = newNode(6);
	noncircularList->next = newNode(7);
	cout << "Case 1 " << isCircular(circularList) <<endl;
	cout << "Case 2 " << isCircular(noncircularList)<<endl;
	return 0;
}
