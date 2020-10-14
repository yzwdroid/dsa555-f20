template <typename T>
class Queue{
	DList<T> theQueue_;

public:
	Queue(){}
	void enqueue(const T& data){
		theQueue_.push_back();
	}
	void dequeue(){
		theQueue_.pop_front();
	}
	T front() const{
		return *(theQueue_.cbegin());
	}
	bool isEmpty() const{
		return (theQueue_.cbegin()==theQueue_.cend());
	}
};