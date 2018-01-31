/*! \file

 */

#include "catch.hpp"
#include "kmbdQueues.h"


#include <array>


using namespace kmbd;

class MyElement : public Queue<MyElement>::element{
public:
	int number;
};


static bool enqueueTwiceFirst(void)
{
	Queue<MyElement> myQueue;
	bool succeed;

	MyElement testElement;

	//! this must succeed, because list is empty
	succeed = myQueue.enqueue(&testElement);

	if(succeed){
		//! this must fail per definition DEF01 in kEmbeddedQueues.h
		succeed = myQueue.enqueue(&testElement);
		succeed = not succeed;
	}

	return succeed;
}


static bool enqueueAndDequeue257(void)
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


	return succeed;
}

static bool enqueueTwiceAfter257(void)
{
	Queue<MyElement> myQueue;
	bool succeed;

	MyElement testElement;
	std::array<MyElement, 257> MyArray;

	//! this must succeed, because list is empty
	succeed = myQueue.enqueue(&testElement);

	if(succeed){
		for(auto& myElement : MyArray)
		{
			myQueue.enqueue(&myElement);
		}
		//! this must fail per definition DEF01 in kEmbeddedQueues.h
		succeed = myQueue.enqueue(&testElement);
		succeed = not succeed;
	}

	return succeed;
}


TEST_CASE( "Queues Test", "[Queues]" )
{
    REQUIRE( enqueueTwiceFirst() );
    REQUIRE( enqueueAndDequeue257() );
    REQUIRE( enqueueTwiceAfter257() );
}
