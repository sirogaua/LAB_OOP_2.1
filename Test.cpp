/************************************************************************
*file: Test.cpp
*purpose : test list functions
*author : Sergii Shagan
* written :	20 / 03 / 2019
* last modified : 24 / 03 / 2019
* ************************************************************************/
#include "Student.h"

using namespace std;

int main()
{
	CStudent V;

	list <CStudent> LST;
	SetList(LST, "1.cvs");
	ListAll(LST);
	cout << endl << "///////////////////////////////////////////////////////////" << endl;
	SortByGrades(LST);
	ListAll(LST);
	cout << endl << "///////////////////////////////////////////////////////////" << endl;
	DeleteById(LST, 2);
	ListAll(LST);
	cout << endl << "///////////////////////////////////////////////////////////" << endl;
	V = BestAverage(LST);
	cout << endl << "BEST AVERAGE: ";
	V.Printessentials();
	cout << endl << "///////////////////////////////////////////////////////////" << endl;
	DeleteAll(LST);
	ListAll(LST);


	system("pause");

}
