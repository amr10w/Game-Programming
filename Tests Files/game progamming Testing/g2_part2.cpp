#include <iostream>
#include <vector>
void pp(int & i)
{
    std::cout<<&i<<" "<<i<<" "<<sizeof(i)<<"\n";
}


class IntArray
{
    int * m_arr;
    size_t m_size;
public:
    IntArray(size_t size):m_size(size),m_arr(new int[size])
    {    
        std::cout <<"Array constructor\n";
    }
    ~IntArray()
    {
        delete[]m_arr;
          std::cout <<"Array destructor\n";
    }
    int get(size_t index) const
    {
        return m_arr[index];
    }
    void set(size_t index , int val)
    {
        m_arr[index]=val;
    }
    void print() const{
        for (size_t i=0 ;i<m_size ; i++)
        {
            std::cout <<i << " "<< m_arr[i]<<"\n";
        }
    }
};

int main(int argc,char * arcv[])
{
IntArray myArray(10);
myArray.set(4,7);
myArray.set(2,134);
myArray.set(9,154);
myArray.print();
return 0;
}