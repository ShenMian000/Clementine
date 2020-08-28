// Copyright 2020 SMS
// License(Apache-2.0)
// ����̨��������

#include "attribute.h"
#include <stdio.h>

using std::string;

Attribute::Attribute(ushort attr)
{
	complie(attr);
}

void Attribute::puts(const string& str) const
{
	puts(str.c_str());
}

void Attribute::puts(const char* str) const
{
	on();
	::puts(str);
	off();
}

void Attribute::putc(char ch) const
{
	on();
	putchar(ch);
	off();
}

#ifdef OS_LINUX

void Attribute::on() const
{
	printf(attribute.c_str());
}

void Attribute::off() const
{
	printf("\33[0m");
}

void Attribute::complie(ushort attr)
{
	ushort fore = attr & 0x000f;
	ushort back = attr & 0x00f0;
	ushort mode = attr & 0x0f00;

	attribute = "\e[";

	switch(fore)
	{
	case fore::black:
		attribute += "30;";
		break;

	case fore::blue:
		attribute += "34;";
		break;

	case fore::green:
		attribute += "32;";
		break;

	case fore::cyan:
		attribute += "36;";
		break;

	case fore::red:
		attribute += "31;";
		break;

	case fore::purple:
		attribute += "35;";
		break;

	case fore::yellow:
		attribute += "33;";
		break;

	case fore::white:
		attribute += "37;";
		break;
	}

	switch(back)
	{
	case back::black:
		attribute += "40;";
		break;

	case back::blue:
		attribute += "44;";
		break;

	case back::green:
		attribute += "42;";
		break;

	case back::cyan:
		attribute += "46;";
		break;

	case back::red:
		attribute += "41;";
		break;

	case back::purple:
		attribute += "45;";
		break;

	case back::yellow:
		attribute += "43;";
		break;

	case back::white:
		attribute += "47;";
		break;
	}

	switch(mode)
	{
	case mode::bold:
		attribute += "1;";
		break;

	case mode::underline:
		attribute += "4;";
		break;

	case mode::reverse:
		attribute += "7;";
		break;
	}

	if(attribute.back() == ';')
		attribute.pop_back();

	attribute += 'm';
}

#endif // OS_LINUX
