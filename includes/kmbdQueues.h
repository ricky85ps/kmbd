/*! \file
	implementation of intrinsic queue is done here
	-	DEF01 The client is allowed to queue one queue element only once into a single
		queue. Twice time will let queue reject second time!
		-->	Client must queue copy of element if he really want to queue twice
	-	Queueing one element in more than one queue is not allowed, otherwise
		if in second queue a new element will be inserted, next pointer of element
		will be overwritten, which means, that after this element, further elements
		of the first queue are discarded and instead elements of the second queue
		are attached
		-->	Client must queue copy of element if he really want to queue into a
			second queue

 */

#ifndef KMBDQUEUES_H_
#define KMBDQUEUES_H_

namespace kmbd{

//! ID calculated by git version control
static constexpr char QueuesId[] = "$Id$";

class GenericQueue{

private:
	class Element{
	public:
		Element* pNext;
	};

protected:
	GenericQueue() : pFirstMessage(nullptr)
	{}

	Element* pFirstMessage;

	bool enqueue(void* vreq)
	{
		Element* req = static_cast<Element*>(vreq);
		bool enqeue = true;
		if(pFirstMessage == nullptr)
		{
			req->pNext = nullptr;
			pFirstMessage = req;
		}else
		{
			Element* pCurr = pFirstMessage;
			if(pCurr==req){
				enqeue = false;
			}

			while( (pCurr->pNext != nullptr) and enqeue){
				pCurr = pCurr->pNext;
				if(pCurr==req){
					enqeue = false;
				}
			}
			if(enqeue)
			{// since here pCurr->pNext == nullptr
				req->pNext = nullptr;
				pCurr->pNext = req;
			}
		}
		return enqeue;
	}

	void* dequeue(void)// returns nullptr if queue is empty
	{
		Element* pCurr = pFirstMessage;
		if(pCurr != nullptr){
			pFirstMessage = pCurr->pNext;
		}
		return pCurr;
	}

};//class queue

template<typename T> class Queue: private GenericQueue{
public:
	class Element{
	public:
		Element* pNext;
	};

	//! returns true if succesfully enqueued
	bool enqueue(Element* req)
		{ return GenericQueue::enqueue(req); }

	T* dequeue(void)
		{ return static_cast<T*>(GenericQueue::dequeue()); }
};

};//namespace kEmbedded
#endif /* KMBDQUEUES_H_ */

