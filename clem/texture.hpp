// Copyright 2020 SMS
// License(Apache-2.0)
// ²ÄÖÊ

#ifndef CLEM_TEXTURE_HPP_
#define CLEM_TEXTURE_HPP_

#include "attribute.h"

struct Texture
{
	Texture(char ch, const Attribute& attr)
			: ch(ch), attr(attr)
	{
	}

	char      ch;
	Attribute attr;
};

#endif // CLEM_TEXTURE_HPP_
