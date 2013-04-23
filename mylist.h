#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>
#include <stdexcept>


const int MAX_SIZE = 100;

template <typename T>
class MyList{
public:
MyList();
~MyList();
void push_back(T newVal);
int size();
void setSizeZero();
T& at(int position);
bool remove(T val);
T pop(int loc);
T& operator[](int position);
bool empty();

private:
T* data_;
int size_;
int totalsize_;

};

template<typename T>
MyList<T>::MyList()
	{
	size_=0;
	totalsize_=MAX_SIZE;
	data_= new T[MAX_SIZE];
	}

template<typename T>
MyList<T>::~MyList()
	{
	delete [] data_;
	
	}

template<typename T>
int MyList<T>::size()
	{
	return size_;
	}

template<typename T>
void MyList<T>::setSizeZero()
	{
	size_=0;
	}
	
template<typename T>
T& MyList<T>::at(int position)
	{
	
	if(position>size_)
	{
		//throw conditional;
		throw std::invalid_argument("Invalid argument, user entered");
	}
	
	return data_[position];
	}
	
template<typename T>
T& MyList<T>::operator[](int position)
	{
	
	return data_[position];
	
	}

template<typename T>
T MyList<T>::pop(int loc)
{
	//Throw conditional
	if(loc>size_)
	{
		throw std::invalid_argument("Invalid argument, user entered");
	}
	
	
	T tempvalue=data_[loc];
	
	if(loc<size_-1)
	{
		for(int j=loc;j<size_-1;j++)
		{	data_[j]=data_[j+1];
		}
		size_--;
		return tempvalue;
	}
			
	else if(loc==size_-1)
	{
		size_--;
		return tempvalue;
	}
			
	
	
}



template<typename T>
bool MyList<T>::remove(T val)
{
	for(int i=0;i<size_;i++)
	{
		
		
		if(data_[i]==val)
		{
			
			if(i<size_-1)
			{
				for(int j=i;j<size_-1;j++)
				{	data_[i]=data_[i+1];
				}
			}
			
			else if(i==size_-1)
			{
				size_--;
				return true;
			}
			
			size_--;
			return true;
		}
		
		
	}
	
	return false;

}

template<typename T>
void MyList<T>::push_back(T newVal)
{
	if(size_+1<=totalsize_)
	{data_[size_]=newVal;
	size_++;}

	else if(size_+1>totalsize_)			
	{
		totalsize_*=2;
	
		T* newdata_= new T[totalsize_];
		for(int i=0;i<size_;i++)
			{
			newdata_[i]=data_[i];
			}
		newdata_[size_]=newVal;
		size_++;
	
		data_=newdata_; 
	}


}

template<typename T>
bool MyList<T>::empty()
{
  if(size_==0)
  {return true;}
  
  else {return false;}
}


#endif
