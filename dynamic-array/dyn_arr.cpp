#include <iostream>
#include <cmath>

using namespace std;

template <typename T> class dynArr {
	private:
		T* arr_;
		int capacity_;
		int size_;

		void resize_(int newCapacity) {
			T* tempArr = new T[newCapacity];
			for (int i = 0; i < size_; i++) {
				tempArr[i] = arr_[i];
			}

			delete[] arr_;
			arr_ = tempArr;
			tempArr = NULL;
			delete tempArr;

			capacity_ = newCapacity;
		}
	public:
		dynArr() {
			arr_ = new T[16];
			capacity_ = 16;
			size_ = 0;
		}

		dynArr(int capacity) {
			if (capacity > 16) {
				capacity *= pow(2, capacity / 16);
			}

			arr_ = new T[capacity];
			capacity_ = capacity;
			size_ = 0;
		}

		int size() {
			return size_;
		}

		int capacity() {
			return capacity_;
		}

		bool is_empty() {
			if (size_ == 0) {
				return true;
			} else {
				return false;
			}
		}

		T at(int index) {
			return arr_[index];
		}

		void push(T item) {
			if (size_ == capacity_) {
				resize_(capacity_ * 2);
			}

			arr_[size_] = item;
			size_++;
		}

		void insert(int index, T item) {
			if (size_ == capacity_) {
				resize_(capacity_ * 2);
			}

			for (int i = size_; i > index; i--) {
				arr_[i] = arr_[i-1];
			}

			arr_[index] = item;
			size_++;
		}

		void prepend(T item) {
			insert(0, item);
		}

		T pop() {
			if ((capacity_ / size_) >= 4) {
				resize_(capacity_ / 2);
			}
			return arr_[--size_];
		}

		void deleteEl(int index) {
			for (int i = index; i < size_ - 1; i++) {
				arr_[i] = arr_[i+1];
			}
			size_--;
		}

		void remove(T item) {
			for (int i = 0; i < size_; i++) {
				if (arr_[i] == item) {
					deleteEl(i); // O(n^2), 0(n)??
				}
			}
		}

		int find(T item) {
			for (int i = 0; i < size_; i++) {
				if (arr_[i] == item) {
					return i;
				}
			}
			return -1;
		}
};

// Some tests
int main() {
	dynArr<int> arr;

	for (int i = 0; i < 20; i++) {
		arr.push((i + 1) * 2);
	}

	cout << arr.size() << endl;
	cout << arr.capacity() << endl;

	for (int i = 0; i < 13; i++) {
		arr.pop();
	}

	cout << arr.size() << endl;
	cout << arr.capacity() << endl;

	for (int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << " ";
	}

	cout << endl;
	return 0;
}
