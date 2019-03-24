/* ************************************************************************ /
 * file: Student.h
 * declarations for CStudent class and contaner list functions
*author : Sergii Shagan
* written :	20 / 03 / 2019
* last modified : 24 / 03 / 2019
* ************************************************************************/
#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <list>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iterator>

using namespace std;

class CStudent
{
public:
	//default constructor
	CStudent();

	//copy constructor
	CStudent(const CStudent  &);
	//destructor
	~CStudent();

	void SetInfo(const char *_fname, const char *_lname, const int _id);
	void Printessentials()const;
	void SetGrades(int *grds, int n);
	float AverageGrade()const;

	//overloaded assignment
	CStudent  & operator=(const CStudent  &);
	bool operator<(const CStudent  &)const;
	bool operator==(int id)const;

private:
	int id;//student’s id
	char *fname;//first name
	char *lname;//last name	
	int *grades;//grades
	unsigned int grades_nmb;//number of grades
};

struct  AverageG
{
	bool operator()(CStudent lhs, CStudent rhs) { return lhs.AverageGrade() < rhs.AverageGrade(); } // realizations operator compare AverageGrades
};


void SetList(list <CStudent >&, const char *csv); //function Set List
void ListAll(list <CStudent >);//function Print List
void SortByGrades(list <CStudent > &);//function sort List
void DeleteById(list <CStudent > &, int id);//function Delete by ID List
CStudent  BestAverage(list <CStudent >);//function searching Best Average List
void DeleteAll(list <CStudent > &);//function Delete All List