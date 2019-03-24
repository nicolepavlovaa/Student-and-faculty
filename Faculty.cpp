#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

Faculty::Faculty()
{
	size = 1;
	students = new Student[size];
}
Faculty::Faculty(const Faculty& other)
{
	delete[] students;
	students = new Student[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->students[i] = other.students[i];
	}
}
Faculty& Faculty::operator=(Faculty& other)
{
	if (this != &other)
	{
		delete[] students;
		Student * students = new Student[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->students[i] = other.students[i];
		}
	}
	return *this;
}
Faculty& Faculty::operator+=(Student& other)
{
	if (this->size == 1 && strcmp(this->students[0].getName(), "Anonymous")==0)
	{
		students[0] = other;
	}
	else
	{
		int newSize = this->size + 1;
		Student * temp = new Student[newSize];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = students[i];
		}
		temp[newSize - 1] = other;
		delete[] students;
		students = temp;
	}
	return *this;
}
Faculty& Faculty::operator-=(Student& other)
{
	bool found = false;
	int removedIndex;
	for (int i = 0; i < this->size; i++)
	{
		if (students[i] == other)
		{
			found = true;
			removedIndex = i;
		}
	}
	if (found == true)
	{
		int newSize = this->size - 1;
		Student * temp = new Student[newSize];
		for (int i = 0; i < removedIndex; i++)
		{
			temp[i] = students[i];
		}
		for (int i = removedIndex+1; i < newSize; i++)
		{
			temp[i-1] = students[i];
		}
		delete[] students;
		students = temp;
	}
	return *this;
}
Student& Faculty::getStudent(int index)
{
		return students[index];
}

Faculty::~Faculty()
{
	delete[] students;
}
