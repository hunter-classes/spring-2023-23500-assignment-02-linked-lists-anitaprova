#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "OList.h"
#include <string>

TEST_CASE("insert")
{
	OList *m = new OList();
	m->insert("0");
	m->insert("1");
	m->insert("2");
	m->insert("3");

	CHECK(m->toString() == "0-->1-->2-->3-->nullptr");

	OList *a = new OList();
	a->insert("6");
	a->insert("45");
	a->insert("999");
	CHECK(a->toString() == "6-->45-->999-->nullptr");
}

TEST_CASE("get")
{
	OList *m = new OList();
	m->insert("66");
	m->insert("12");
	m->insert("89");

	CHECK(m->get(0) == "12");
	CHECK(m->get(1) == "66");
	CHECK(m->get(2) == "89");
}

TEST_CASE("contains")
{
	OList *m = new OList();
	m->insert("66");
	m->insert("12");
	m->insert("52");
	m->insert("89");

	CHECK(m->contains("66") == 1);
	CHECK(m->contains("89") == 1);
	CHECK(m->contains("52") == 1);
	CHECK(m->contains("200") == 0);
}

TEST_CASE("remove")
{
	OList *m = new OList();
	m->insert("66");
	m->insert("12");
	m->insert("52");
	m->insert("89");

	m->remove(0);
	CHECK(m->toString() == "52-->66-->89-->nullptr");

	m->remove(2);
	CHECK(m->toString() == "52-->66-->nullptr");
}

TEST_CASE("reverse")
{
	OList *reverse = new OList();
	reverse->insert("66");
	reverse->insert("12");
	reverse->insert("52");
	reverse->insert("89");

	reverse->reverse();
	CHECK(reverse->toString() == "89-->66-->52-->12-->nullptr");
}