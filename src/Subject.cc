#include "Subject.h"
#include "Observer.h"

Subject::~Subject() {}

void Subject::attach(Observer *o)
{
	observers.push_back(o);
}

void Subject::notifyObservers()
{
	for (auto &o : observers)
	{
		o->notify();
	}
}
