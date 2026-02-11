#include "LinkedList.h"

int main()
{
	LinkedList<std::string> TheFiles("Hello");

	TheFiles.PushBack("World");

	std::cout << TheFiles.GetData(0) << ", " << TheFiles.GetData(1) << std::endl;

	TheFiles.RemoveAt(1);

	TheFiles.PushBack("Loser");

	std::cout << TheFiles.GetData(0) << ", " << TheFiles.GetData(1) << std::endl;

	TheFiles.SetData("Ron Weasley", 1);

	std::cout << TheFiles.GetData(0) << ", " << TheFiles.GetData(1) << std::endl;

	return 0;
}