
#include <stack.hpp>
#include <catch.hpp>

SCENARIO("init") 
{
    forward_list<int> s;
    REQUIRE(s.count() == 0);
    REQUIRE(s.empty());
}

SCENARIO("pop") 
{
    forward_list<int> v={1, 2, 4};
    int s = v.pop_back();
    int z = v.pop_front();                     
    REQUIRE(s== 4);
    REQUIRE(v.count() == 1);                
    REQUIRE(z==1);
}
SCENARIO("init list") 
{
    forward_list<int> v={1, 2, 3, 4, 5, 6};
    int s = v.pop_back();
    REQUIRE(v.count() == 5);
    REQUIRE(s == 6);
    s = v.pop_back();
    REQUIRE(s == 5);
    REQUIRE(v.count() == 4);
    s = v.pop_back();
    REQUIRE(s == 4);
    REQUIRE(v.count() == 3);
    s = v.pop_back();
    REQUIRE(s == 3);
    REQUIRE(v.count() == 2);
    s = v.pop_back();
    REQUIRE(s == 2);
    REQUIRE(v.count() == 1);
}

SCENARIO("push") 
{
   forward_list<int> s;
    s.push_back(5);
    s.push_front(7);
    REQUIRE(s.count() == 2);
}
SCENARIO("clear") 
{
   forward_list<int> s;
   s.push_back(5);
   s.push_front(7);
   s.clear();
   REQUIRE(s.count() == 0);
}
 SCENARIO("move") 
{
   forward_list<int> s = {1, 2};
   forward_list<int> m =std:: move(s);
   REQUIRE(m.count()==2);
}
SCENARIO("copy") 
{
   forward_list<int> s = {1, 2, 5, 9};
   forward_list<int> m = s;
   REQUIRE((m == s));
}
SCENARIO("back") 
{
   forward_list<int> s = {1, 2, 4};
   forward_list<int> m;
   forward_list<int> m2;
   m.push_back(1);
   m.push_back(2);
   m.push_back(4);
   m2.emplace_back(1);
   m2.emplace_back(2);
   m2.emplace_back(4);
   REQUIRE((m == s));
   REQUIRE((m2 == s));
}
SCENARIO("front") 
{
   forward_list<int> s = {4, 2, 1};
   forward_list<int> m;
   forward_list<int> m2;
   m.push_front(1);
   m.push_front(2);
   m.push_front(4);
   m2.emplace_front(1);
   m2.emplace_front(2);
   m2.emplace_front(4);
   REQUIRE((m == s));
   REQUIRE((m2 == s));
}
SCENARIO("init") 
{
   	queue <int> m ;
    REQUIRE(m.count()==0);

}

SCENARIO("init list") 
{
    queue <int> m={3, 4};
    REQUIRE(m.count()==2);
    int s = m.dequeue();
    REQUIRE(m.count() == 1);
    REQUIRE(s == 3);
    s = m.dequeue();
    REQUIRE(s == 4);
    REQUIRE(v.count() == 0);
}
SCENARIO("pop") 
{
    queue <int> m={3, 4};
    REQUIRE(m.count()==2);
    int s = m.dequeue();
    REQUIRE(m.count() == 1);
    REQUIRE(s == 3);
}

SCENARIO("push") 
{
    queue <int> m={3, 4};
    REQUIRE(m.count()==2);
    m.enqueue(5);
    REQUIRE(m.count() == 3);
    m.dequeue();
    m.dequeue();
    int s = m.dequeue();
    REQUIRE(s == 5);
}
 SCENARIO("move") 
{
   queue <int> l={3, 4};
   queue <int> m =std:: move(l);
   REQUIRE(m.count()==2);
   int s = m.dequeue();
   REQUIRE(m.count() == 1);
   REQUIRE(s == 3);
   s = m.dequeue();
   REQUIRE(s == 4);
   REQUIRE(v.count() == 0);
 }
SCENARIO("copy") 
{
    queue <int> l={3, 4};
   queue <int> m =l;
   REQUIRE(m.count()==2);
   int s = m.dequeue();
   REQUIRE(m.count() == 1);
   REQUIRE(s == 3);
   s = m.dequeue();
   REQUIRE(s == 4);
   REQUIRE(v.count() == 0);
   
}

