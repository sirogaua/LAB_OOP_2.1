/************************************************************************
*file: Student.cpp
*purpose : realizations for CStudent class functions and contaner list functions
*author : Sergii Shagan
* written :	20 / 03 / 2019
* last modified : 24 / 03 / 2019
* ************************************************************************/

#include "Student.h"
#include <fstream>
#include <string>

CStudent::CStudent()
{
	fname = new char[50];
	lname = new char[50];
	grades = new int[20];
}

CStudent::CStudent(const CStudent  &klass)
{
	if (klass == NULL)
	{
			cout << "Incorect Data.\n";
			system("pause");
			exit(1);
	}
	fname = new char[50];
	lname = new char[50];
	grades = new int[20];
	strcpy(fname, klass.fname);
	strcpy(lname, klass.lname);
	id = klass.id;
	grades_nmb = klass.grades_nmb;
	for (int i = 0; i < grades_nmb; i++)
	{
		grades[i] = klass.grades[i];
	}
}

CStudent::~CStudent()
{
	delete fname;
	delete lname;
	delete grades;
}

void CStudent::SetInfo(const char *_fname, const char *_lname, int _id)
{
	if (!_fname || !_lname || !_id)
	{
		cout << "Incorect Data.\n";
		system("pause");
		exit(1);
	}

	strcpy(fname, _fname);
	strcpy(lname, _lname);
	id = _id;
}

void CStudent::Printessentials()const
{
	cout << endl << "fname: " << fname << endl << "lname: " << lname << endl << "ID: " << id << endl;
	cout << "grades: ";
	for (int i = 0; i < grades_nmb; i++)
	{
		cout << grades[i] << " ";
	}
	cout << endl;
	float Arf = this->AverageGrade();
	cout << "AverageGrade: " << Arf << endl;
}

void CStudent::SetGrades(int *grds, int n)
{
	if (!grds || !n)
	{
		cout << "Incorect Data.\n";
		system("pause");
		exit(1);
	}
	grades_nmb = n;
	for (int i = 0; i < n; i++)
	{
		grades[i] = grds[i];
	}
}

float CStudent::AverageGrade()const
{
	float sum = 0;
	for (int i = 0; i < grades_nmb; i++)
	{
		sum = sum + grades[i];
	}
	return sum / grades_nmb;
}

bool CStudent::operator==(int id)const
{
	return this->id == id;
}

bool CStudent::operator<(const CStudent  &klass)const
{
	if (klass == NULL)
	{
		cout << "Incorect Data.\n";
		system("pause");
		exit(1);
	}
	return this->id < klass.id;
}

CStudent & CStudent::operator=(const CStudent  &klass)
{
	if (this != &klass)
	{
		this->id = klass.id;
		strcpy(this->fname, klass.fname);
		strcpy(this->lname, klass.lname);
		this->grades = (int *)malloc(sizeof(int) * klass.grades_nmb);
		this->grades_nmb = klass.grades_nmb;
		for (int i = 0; i < this->grades_nmb; i++)
		{
			this->grades[i] = klass.grades[i];
		}
	}
	return *this;
}

void SetList(list <CStudent> &CP, const char *csv)
{
	if (!csv)
	{
		cout << "Incorect Data.\n";
		system("pause");
		exit(1);
	}
	CStudent buffer;

	int _id;
	char *_fname = new char[50];
	char *_iname = new char[50];
	int *_grds = new int[20];
	int n;

	string X;

	int buff;
	ifstream fin(csv);
	while (getline(fin, X))
	{
		buff = X.find(";");
		if (buff == -1)
		{
			cout << "Incorect format of csv file.\n";
			system("pause");
			exit(1);
		}
		_id = stoi(X.substr(0, buff));

		X = X.substr(buff + 1);
		buff = X.find(";");
		if (buff == -1)
		{
			cout << "Incorect format of csv file.\n";
			system("pause");
			exit(1);
		}
		memcpy(_fname, X.substr(0, buff).c_str(), X.substr(0, buff).size() + 1);

		X = X.substr(buff + 1);
		buff = X.find(";");
		if (buff == -1)
		{
			cout << "Incorect format of csv file.\n";
			system("pause");
			exit(1);
		}
		memcpy(_iname, X.substr(0, buff).c_str(), X.substr(0, buff).size() + 1);

		X = X.substr(buff + 1);
		buff = X.find(";");
		if (buff == -1)
		{
			cout << "Incorect format of csv file.\n";
			system("pause");
			exit(1);
		}
		n = stoi(X.substr(0, buff));


		for (int i = 0; i < n - 1; i++)
		{
			X = X.substr(buff + 1);
			buff = X.find(";");
			if (buff == -1)
			{
				cout << "1Incorect format of csv file.\n";
				system("pause");
				exit(1);
			}
			_grds[i] = stoi(X.substr(0, buff));
		}
		X = X.substr(buff + 1);
		_grds[n - 1] = stoi(X);
		
		buffer.SetGrades(_grds, n);
		buffer.SetInfo(_fname, _iname, _id);
		CP.push_back(CStudent(buffer));
	}
	fin.close();
	delete(_fname);
	delete(_iname);
	delete(_grds);
}

void ListAll(list <CStudent> CP)
{
	list <CStudent>::iterator CP_Iter;
	CP_Iter = CP.begin();
	while (CP_Iter != CP.end())
	{
		CP_Iter->Printessentials();
		CP_Iter++;
	}
	if (CP.begin() == CP.end())
	{
		cout << endl << "LIST EMPTY" << endl;
	}
}


void SortByGrades(list <CStudent > &CP)
{
	if (CP.empty())
	{
		cout << "List Empty.\n";
		system("pause");
		exit(1);
	}
	CP.sort(AverageG());
}

void DeleteById(list <CStudent > &CP, int id)
{
	if (CP.empty() || !id)
	{
		cout << "Incorect Data.\n";
		system("pause");
		exit(1);
	}
	list <CStudent>::iterator CP_Iter;
	CP_Iter = CP.begin();
	while (CP_Iter != CP.end())
	{
		if (CP_Iter->operator==(id) == true)
		{
			CP.erase(CP_Iter);
			break;
		}
		CP_Iter++;
	}
}

CStudent BestAverage(list <CStudent >CP)
{
	if (CP.empty())
	{
		cout << "List Empty.\n";
		system("pause");
		exit(1);
	}
	CStudent best;
	SortByGrades(CP);
	list <CStudent>::iterator CP_Iter = CP.end();
	CP_Iter--;
	best.operator=(*CP_Iter);
	return best;
}

void DeleteAll(list <CStudent > &CP)
{
	list <CStudent>::iterator CP_Iter;
	CP_Iter = CP.begin();
	while (!CP.empty())
	{
		CP.erase(CP_Iter);
		CP_Iter = CP.begin();
	}
}