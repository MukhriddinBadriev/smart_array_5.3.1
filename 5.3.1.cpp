#include <iostream>
#include <exception>
class smart_array {
public:
	smart_array(int size) {
		size_ = size;
		s_m = new int(size_);	
	}
	int add_element(int element) {
		if (capacity == size_) {
			size_ *= 2;
			int* tmp = new int[size_];
			for (int i = 0; i < capacity; ++i) {
				tmp[i] = s_m[i];
			}
			delete[]s_m;
			s_m = tmp;
		}
		if (i < size_)s_m[i] = element;
		i++;
		return element;
	}
	int get_element(int id) {
		if (id >= size_) {
			throw std::exception();
		}
		return s_m[id];
	}
	~smart_array() {
		delete[] s_m;
	}
private:
	int* s_m=nullptr;
	int size_ = 0;
	int capacity = 0;
	int i = 0;
};
int main(){
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
    return 0;
}