#ifndef __FACULTY_H
#define __FACULTY_H
#include <iostream>
#include "Student.h"

class Faculty
{
	Student * students;

public:
	Faculty();
	Faculty(const Faculty& other);
	Faculty& operator=(Faculty& other);
	Faculty& operator+=(Student& other);
	Faculty& operator-=(Student& other);
	~Faculty();
};

#endif 
