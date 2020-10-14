template <typename T>
class Queue{
	T* data_;
	unsigned int capacity_;
	unsigned int used_;
	int front_;
	int back_;
	void grow(){
		T* newArray=new T[capacity_*2];
		int j=front_;
		for(int i=0;i<used_;i++,j=(j+1)%capacity_){
			newArray[i]=data_[j];
		}
		capacity_=capcity_*2;
		delete [] data_;
		data_=newArray;
		front_=0;
		back_=used_;
	}
public:
	Queue(int capacity=4){
		data_=new T[capacity];
		used_=0;
		capacity_=capacity;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}
		data_[back_]=data;
		back_=(back+1)%capacity_;
//		back_=(back_==capacity_-1)?0:back_+1;
		used_++;
	}
	void dequeue(){
		front_=(front+1)%capacity_;
		used_--;
	}
	T front() const{
		return data_[0];
	}
	bool isEmpty() const {
		return used_==0;
	}
};