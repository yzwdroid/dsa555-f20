template <typename T>
class ArrayList{
	
public:
	ArrayList(unsigned int cap=10);
	void push_front(const T& data);
	void push_back(const T& data);
	void insert(const T& data, int loc);
	void pop_front();
	void pop_back();
	void remove(int loc);
	~ArrayList();
};