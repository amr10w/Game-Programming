#include <iostream>
#include <vector>

void pp(int & i)
{
    std::cout<<&i<<" "<<i<<" "<<sizeof(i)<<"\n";
}
void pp1(int  i)
{
    std::cout<<&i<<" "<<i<<" "<<sizeof(i)<<"\n";
}

int main(int argc,char * arcv[])
{

// int a=10;
//  int b=25;
// std::cout<<a<<"\n";
// std::cout<<&a<<" "<<a<<" "<<sizeof(a)<<"\n";
// std::cout<<b<<"\n";
// std::cout<<&b<<" "<<b<<" "<<sizeof(b)<<"\n";

// pp(a);
// pp(b);
// pp1(a);
// pp1(b);
// int arr[10]={};          //make all values =0
// // int * harr=new int[10];
// for(int i=0 ;i<10;i++){
// pp(arr[i]);
// }
// for(int i=0 ;i<10;i++){
// pp(harr[i]);
// }

// int a=10;
// int b=25;
// int * pa =&a;
// int *pb=&b;
// *(&a)=17; /*==*/ *pa=17;
// pp(a);
// pp(b);


return 0;
}