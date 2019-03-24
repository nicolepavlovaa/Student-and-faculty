#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;
#include <cstring>

int main()
{
	Student maya;
	Student nicole;
	Student anna;
	Faculty FMI;

	maya.setName("Maya");
	maya.setFn(10101);
	maya.setCourse(2);
	nicole.setName("Nicole");
	nicole.setCourse(1);
	nicole.setFn(20202);
	cout << maya << endl;
	cout << nicole << endl;
	FMI += nicole;
	FMI += maya;
	cout << FMI.getStudent(0) << endl;
	if (maya == nicole)
	{
		cout << "yes" << endl;
	}

	system("pause");
	return 0;
}
