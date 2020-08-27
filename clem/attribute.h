// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台字体属性

#ifndef CLEM_ATTRIBUTE_H_
#define CLEM_ATTRIBUTE_H_

#include <clem/common.hpp>
#include <string>

class Attribute
{
public:
	Attribute(ushort attr);

	void putchar(char ch);

	void open();
	void close();

private:
	void complie();

	ushort attr;
};

enum class Fore
{
	black  = 0x0000,
	blue   = 0x0001,
	green  = 0x0002,
	cyan   = 0x0003,
	aqua   = 0x0003,
	red    = 0x0004,
	purple = 0x0005,
	yellow = 0x0006,
	white  = 0x0007,
	size
};

enum class Back
{
	black  = 0x0000,
	blue   = 0x0010,
	green  = 0x0020,
	cyan   = 0x0030,
	aqua   = 0x0030,
	red    = 0x0040,
	purple = 0x0050,
	yellow = 0x0060,
	white  = 0x0070,
	size
};

enum Common
{
	bold      = 0x0008,
	underline = 0x8000,
	reverse   = 0x4000,
	size
};

#endif // CLEM_ATTRIBUTE_H_
