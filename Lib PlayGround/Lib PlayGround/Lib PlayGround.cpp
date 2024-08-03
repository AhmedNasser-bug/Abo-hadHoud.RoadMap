// Lib PlayGround.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "D:\WEB\Abo-hadHoud.RoadMap\datelib.h"
using namespace DateLib;
int main()
{
	sDate date = CreateDate();
	string strDate = dateToString(date);
	cout << FormatDate(date, "D:dd , M:mm , Y:yyyy");

}




