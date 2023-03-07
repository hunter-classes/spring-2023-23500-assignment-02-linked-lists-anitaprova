#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "OList.h"
#include <string>

TEST_CASE("insert"){
	OList *m = new OList();
	m->insert("0");
	m->insert("1");
	m->insert("2");
	m->insert("3");

	CHECK(m->toString() == "0-->1-->2-->3-->nullptr");
}

TEST_CASE("get"){
	OList *m = new OList();
}

TEST_CASE("contains")
{
	OList *m = new OList();
}

TEST_CASE("remove")
{
	OList *m = new OList();
}

TEST_CASE("reverse")
{
	OList *m = new OList();
}