#include "LinkedList.h"

int main()
{
#pragma region Print&PushBackTest

	std::cout << "Print & PushBack Test:" << std::endl;
	LinkedList<int> PrintandPushBackTest;

	// Should return and empty line
	PrintandPushBackTest.PrintList();

	PrintandPushBackTest.PushBack(1);

	PrintandPushBackTest.PrintList();

	PrintandPushBackTest.PushBack(2);

	PrintandPushBackTest.PrintList();

	PrintandPushBackTest.PushBack(3);

	PrintandPushBackTest.PrintList();

	PrintandPushBackTest.~LinkedList();

	std::cout << std::endl;

#pragma endregion

#pragma region RemoveAtTest

	std::cout << "Remove Test:" << std::endl;
	LinkedList<std::string> RemoveTest;

	RemoveTest.PushBack("1");
	RemoveTest.PushBack("2");
	RemoveTest.PushBack("3");
	RemoveTest.PrintList();

	// Test for our of range
	std::cout << "Should print error message:" << std::endl;
	RemoveTest.RemoveAt(5);

	// Test for removing first element
	RemoveTest.RemoveAt(0);
	std::cout << "(1) should be removed from 1,2,3:" << std::endl;
	RemoveTest.PrintList();

	RemoveTest.PushBack("4");

	// Test for removing last element
	RemoveTest.RemoveAt(2);
	std::cout << "(4) should be removed from 2,3,4:" << std::endl;
	RemoveTest.PrintList();

	RemoveTest.PushBack("4");

	// Test for removing middle element
	RemoveTest.RemoveAt(1);
	std::cout << "(3) should be removed from 2,3,4:" << std::endl;
	RemoveTest.PrintList();

	RemoveTest.~LinkedList();

	std::cout << std::endl;

#pragma endregion

#pragma region Get&SetDataTest

	std::cout << "Get & Set Data Test:" << std::endl;
	LinkedList<float> GetandSetDataTest;

	GetandSetDataTest.PushBack(0.1);
	GetandSetDataTest.PushBack(1.2);
	GetandSetDataTest.PushBack(0.3);

	GetandSetDataTest.PrintList();

	int idx = 1;

	GetandSetDataTest.SetData(0.2, idx);

	float data = GetandSetDataTest.GetData(idx);

	std::cout << data << std::endl;

	//Test for Get out of range
	GetandSetDataTest.SetData(1.234, 5);

	data = GetandSetDataTest.GetData(5);

	std::cout << "Should be default value or empty" << std::endl;
	std::cout << data << std::endl;

	GetandSetDataTest.~LinkedList();

	std::cout << std::endl;
#pragma endregion

#pragma region IteratorTest

	std::cout << "Iterator Test:" << std::endl;
	LinkedList<bool> IteratorTest;

	IteratorTest.PushBack(true); 
	IteratorTest.PushBack(false); 
	IteratorTest.PushBack(true); 
	
	for (LinkedList<bool>::Iterator it = IteratorTest.begin(); it != IteratorTest.end(); ++it)  
		std::cout << *it << " "; 

	std::cout << std::endl;

	IteratorTest.PushBack(false); 

	for (LinkedList<bool>::Iterator it = IteratorTest.begin(); it != IteratorTest.end(); ++it)
		std::cout << *it << " ";

	IteratorTest.~LinkedList();

	std::cout << std::endl;

#pragma endregion

	return 0;
}