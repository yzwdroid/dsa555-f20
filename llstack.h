
#include "lab4.h"
template <typename T>
class Stack{
	DList<T> theStack_;

public:
	Stack(){	
	}
	void push(const T& data){
		theStack_.push_front(data);
	}
	void pop(){
		theStack_.pop_front();
	}
	T top() const{
		return *(theStack_.cbegin());
	}
	bool isEmpty() const{
		return (theStack_.cbegin() == theStack_.cend());
	}
};

/*
class Stack{
	DList<T> theStack_;

public:
	Stack(){	
	}
	void push(const T& data){
		theStack_.push_back(data);
	}
	void pop(){
		theStack_.pop_back();
	}
	T top() const{
		const_iterator it = theStack_.cend();
		return *(--it);
	}
	bool isEmpty(){
		return (theStack_.cbegin() == theStack_.cend());
	}
};

*/