
#include <stack.hpp>
#include <catch.hpp>
SCENARIO("ini")
{
	stack<int> Stack;
	REQUIRE(Stack.size() == 0);
	REQUIRE(Stack.empty());
}
	
SCENARIO("push")
{
	stack<int> s;
	s.push(4);
	s.push(5);
	s.push(12);
	s.push(78);
	auto sp =s.pop();
	REQUIRE(s.size() == 3);
	REQUIRE(*sp==78);
}
SCENARIO("null")
{
	stack<int> s;
	auto sp =s.pop();
	REQUIRE(sp==nullptr);
}
SCENARIO("count and size")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	REQUIRE(Stack.size() == 2);
}

SCENARIO("pop")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	REQUIRE(Stack.size() == 2);
}

