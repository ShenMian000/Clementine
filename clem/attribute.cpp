// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台字体属性

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


void Attribute::on() const
{

}

void Attribute::off() const
{

}

void Attribute::complie(ushort attr)
{
	
}
