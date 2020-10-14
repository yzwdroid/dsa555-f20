template <typename T>
class Stack{
	T* data_;
	unsigned int capacity_;
	unsigned int used_;
	void grow(){
		T* newArray=new T[capacity_*2];
		for(int i=0;i<used_;i++){
			newArray[i]=data_[i];
		}
		capacity_=capcity_*2;
		delete [] data_;
		data_=newArray;
	}
public:
	Stack(int capacity=4){
		data_=new T[capacity];
		used_=0;
		capacity_=capacity;
	}
	void push(const T& data){
		if(used_==capacity_){
			grow();
		}
		data_[used_++]=data;
	}
	void pop(){
		used_--;
	}
	T top() const{
		return data_[used_-1];
	}
	bool isEmpty() const{
		return used_==0;
	}
};