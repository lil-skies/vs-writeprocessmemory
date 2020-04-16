#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//integer
	int procID = 0;

	//enter process ID for locating
	cout << "Enter A Valid Process ID: " << "\n";
	cin >> procID;
	cout << endl;

	//opens process based off typed in process ID + check
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
	if (hProcess == NULL) {
		cout << "Process Could Not Be Opened" << "\n";
		system("pause");
		cout << endl;
		return EXIT_FAILURE;
	}

	//uses entered memory address to find value that is going to be overwritten
	int memoryAddress;
	cout << "Enter A Valid Memory Address: " << "\n";
	cin >> hex >> memoryAddress;
	cout << endl;

	//the value that is overwriting the current value
	int writeTo;
	cout << "Enter A Value: " << "\n";
	cin >> dec >> writeTo;
	cout << endl;

	//writes to memory + check
	BOOL wpmReturn = WriteProcessMemory(hProcess, (LPVOID)memoryAddress, &writeTo, sizeof(int), NULL);
	if (wpmReturn == FALSE) {
		cout << "Could Not Overwrite Current Value" << "\n";
		system("pause");
		cout << endl;
		return EXIT_FAILURE;
	}
	cout << "Overwritten Successfully, Please Close Tab";
}