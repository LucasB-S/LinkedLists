#include "LinkedList.h"

int main()
{
#pragma region Print,PushBack,PopBack & GetLength Test

	std::cout << "Print,PushBack,PopBack & GetLength Test:" << std::endl;
	LinkedList<int> IntList;

	// Should return and empty line
	IntList.PrintList();

	IntList.PushBack(1);

	IntList.PrintList();

	IntList.PushBack(2);

	IntList.PrintList();

	IntList.PushBack(3);

	IntList.PrintList();

	IntList.PopBack();

	IntList.PrintList();

	std::cout << "List Length: " << IntList.GetLength() << std::endl;

	IntList.~LinkedList();

	std::cout << std::endl;

#pragma endregion

#pragma region RemoveAt Test

	std::cout << "Remove Test:" << std::endl;
	LinkedList<std::string> StringList;

	StringList.PushBack("1");
	StringList.PushBack("2");
	StringList.PushBack("3");
	StringList.PrintList();

	// Test for our of range
	std::cout << "Should print error message:" << std::endl;
	StringList.RemoveAt(5);

	// Test for removing first element
	StringList.RemoveAt(0);
	std::cout << "(1) should be removed from 1,2,3:" << std::endl;
	StringList.PrintList();

	StringList.PushBack("4");

	// Test for removing last element
	StringList.RemoveAt(2);
	std::cout << "(4) should be removed from 2,3,4:" << std::endl;
	StringList.PrintList();

	StringList.PushBack("4");

	// Test for removing middle element
	StringList.RemoveAt(1);
	std::cout << "(3) should be removed from 2,3,4:" << std::endl;
	StringList.PrintList();

	StringList.~LinkedList();

	std::cout << std::endl;

#pragma endregion

#pragma region Get & SetData Test

	std::cout << "Get & Set Data Test:" << std::endl;
	LinkedList<float> FloatList;

	FloatList.PushBack(0.1);
	FloatList.PushBack(1.2);
	FloatList.PushBack(0.3);

	FloatList.PrintList();

	int idx = 1;

	FloatList.SetData(0.2, idx);

	float data = FloatList.GetData(idx);

	std::cout << data << std::endl;

	//Test for Get out of range
	FloatList.SetData(1.234, 5);

	data = FloatList.GetData(5);

	std::cout << "Should be default value or empty" << std::endl;
	std::cout << data << std::endl;

	FloatList.~LinkedList();

	std::cout << std::endl;
#pragma endregion

#pragma region Iterator Test

	std::cout << "Iterator Test:" << std::endl;
	LinkedList<bool> BoolList;

	BoolList.PushBack(true); 
	BoolList.PushBack(false); 
	BoolList.PushBack(true); 
	
	for (LinkedList<bool>::Iterator it = BoolList.begin(); it != BoolList.end(); ++it)  
		std::cout << *it << " "; 

	std::cout << std::endl;

	BoolList.PushBack(false); 

	for (LinkedList<bool>::Iterator it = BoolList.begin(); it != BoolList.end(); ++it)
		std::cout << *it << " ";

	BoolList.~LinkedList();

	std::cout << std::endl;

#pragma endregion

	return 0;
}