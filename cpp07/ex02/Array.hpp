#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template <typename T>
class Array {
	private:
		size_t	size;
		T*		arr;

	public:
		Array<T>(void) {
			this->size = 0;
			this->arr = NULL;
		}

		Array<T>(unsigned int n)
		{
			this->size = n;
			if (size > 0)
				this->arr = new T[n];
			else
				this->arr = NULL;
		}

		Array<T>(const Array<T>& old) {
			this->size = old.getSize();
			this->arr = new T[this->size];
			for (size_t i = 0; i < this->size; i++)
				this->arr[i] =  old.arr[i];
		}

		Array<T>& operator=(const Array<T>& old) {
			if (this->arr != NULL) delete[] this->arr;
			this->size = old.getSize();
			if (this->size > 0)
				this->arr = new T[this->size];
			else
				this->arr = NULL;
			for (size_t i = 0; i < this->size; i++)
				this->arr[i] =  old.arr[i];
			return (*this);
		}

		~Array<T>(void) {
			if (this->size <= 0)
				return ;
			delete[] this->arr;
		}

		T& operator[](size_t i) {
			if (!this->arr || i >= this->size) {
				throw (std::out_of_range("Array index out of range"));
			}
			return (this->arr[i]);
		}

		size_t getSize(void) const {
			return (this->size);
		}
};

#endif