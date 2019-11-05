#pragma once
#include <cassert>
namespace Lept
{
	enum TYPE
	{
		LEPT_NULL,
		LEPT_FALSE,
		LEPT_TRUE,
		LEPT_NUMBER,
		LEPT_STRING,
		LEPT_ARRAY,
		LEPT_OBJECT
	};

	enum
	{
		PARSE_OK = 0,
		PARSE_EXPECT_VALUE,
		PARSE_INVAILD_VALUE,
		PARSE_ROOT_NOT_SINGULAR
	};

	struct Value
	{
		TYPE type;
	};

	struct Context
	{
		const char* json;
	};

	static void parseWhitespace(Context* c)
	{
		const char* p = c->json;
		while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
			p++;
		c->json = p;
	}

	static int parseNull(Context* c, Value* v)
	{
		if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l')
			return PARSE_INVAILD_VALUE;
		c->json += 3;
		v->type = LEPT_NULL;
		return PARSE_OK;
	}

	static int parseValue(Context* c, Value* v)
	{
		switch (*c->json)
		{
		case 'n': return parseNull(c, v);
		case '\0': return PARSE_EXPECT_VALUE;
		default: return PARSE_INVAILD_VALUE;
		}
	}

	int parse(Value* v, const char* json)
	{
		Context c;
		assert(v != nullptr);
		c.json = json;
		v->type = LEPT_NULL;
		parseWhitespace(&c);
		return parseValue(&c, v);
	}
	TYPE geType(const Value* v);

	int addSome(int a, int b)
	{
		return a + b;
	}
}
