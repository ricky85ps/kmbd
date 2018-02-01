/*! \file

 */

#include "kmbdQueues.h"

#include <array>
#include "catch.hpp"


using namespace kmbd;

class MyElement : public Queue<MyElement>::Element{
public:
	int number;
};


TEST_CASE( "enqueueTwiceFirst", "[Queues]" )
{
	Queue<MyElement> myQueue;
	bool succeed;

	MyElement testElement;

	//! this must succeed, because list is empty
	REQUIRE(myQueue.enqueue(&testElement));

	//! this must fail per definition DEF01 in kEmbeddedQueues.h
	REQUIRE( not myQueue.enqueue(&testElement) );

}


TEST_CASE( "enqueueAndDequeue257", "[Queues]" )
{
	Queue<MyElement> myQueue;
	bool succeed = true;

	int i = 0;

	std::array<MyElement, 257> MyArray;
	for(auto& myElement : MyArray)
	{
		myElement.number = i;
		myQueue.enqueue(&myElement);
		++i;
	}

	int j = 0;
	while(i-- and succeed == true)
	{
		MyElement* myElement = myQueue.dequeue();
		if( (myElement == nullptr) or (j != myElement->number) ){
			succeed = false;
		}
		j++;
	}
	REQUIRE(succeed);
}

TEST_CASE( "enqueueTwiceAfter257", "[Queues]" )
{
	Queue<MyElement> myQueue;
	bool succeed;

	MyElement testElement;
	std::array<MyElement, 257> MyArray;

	//! this must succeed, because list is empty
	REQUIRE(myQueue.enqueue(&testElement));

	for(auto& myElement : MyArray)
	{
		myQueue.enqueue(&myElement);
	}
	//! this must fail per definition DEF01 in kEmbeddedQueues.h
	REQUIRE(not myQueue.enqueue(&testElement));
}
