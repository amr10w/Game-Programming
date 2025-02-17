#include <iostream>
#include <vector>
#include <memory>
void pp(int & i)
{
    std::cout<<&i<<" "<<i<<" "<<sizeof(i)<<"\n";
}

template<typename T>
class DynamicArray
{
    T * m_arr;
    size_t m_size;
public:
    DynamicArray(size_t size):m_size(size),m_arr(new T[size])
    {    
        std::cout <<"Array constructor\n";
    }
    ~DynamicArray()
    {
        delete[]m_arr;
          std::cout <<"Array destructor\n";
    }
    T get(size_t index) const
    {
        return m_arr[index];
    }
    void set(size_t index , T val)
    {
        m_arr[index]=val;
    }
    void print() const{
        for (size_t i=0 ;i<m_size ; i++)
        {
            std::cout <<i << " "<< m_arr[i]<<"\n";
        }
        
    }
    //operator overloding

    T& operator [] (size_t index)
        {
            return m_arr[index];
        }

    const T& operator [] (size_t index) const 
        {
            return m_arr[index];
        }


};

int main(int argc,char * arcv[])
{
    
DynamicArray<float> myArray(10);
myArray.set(4,7.14);
myArray.set(2,134);
myArray.set(9,154);

myArray[3]=3.143563;
myArray.print();


std::cout<< myArray[2]<<"\n";
return 0;
}