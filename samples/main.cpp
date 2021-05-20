
#include <iostream>
#include <string>
#include "roman.h"

void main()
{
	Roma r(12, "XXX");
	int num = r.ToNumber();
	std::cout << num<<'\n';
	std::string str = r.ToRoma();
	std::cout << str << '\n';
}

