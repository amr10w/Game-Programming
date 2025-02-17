#include <iostream>
#include <math.h>
#include "stack" 
#include <vector>
#include <fstream>
class student
{
   std::string m_first ="first";
   std::string m_last="last";
   int         m_id =0;
   float       m_avg=0;
   public:
   student()
   {
   }
   student(std::string first ,std::string last,int id,int avg)
   :m_first(first)
   ,m_last(last),m_id(id),m_avg(avg)
   {
   }
   int getAvg() const
   {
      return m_avg;
   }
   int getId() const
   {
      return m_id;
   }
   std::string getFirst() const
   {
      return m_first;
   }
   std::string getLast() const
   {
      return m_last;
   }
   void print  () const
   {
      std::cout<<m_first <<" "<<m_last<<" "<<m_id<<" "
      <<m_avg<<std::endl;
   }};
   class course 
   {
      std:: string m_name ="course ";
      std::vector<student> m_students ;
      public:
      course()
      {

      }
      course (const std::string & name):m_name (name)
      {}
      void addStudents(const student & s)
      {
         m_students.push_back(s);
      }
      const std::vector <student>& getStudents() const
      {
         return m_students;
      }
      void loadfromfile(const std::string & filename)
      {
         std::ifstream fin(filename);
         //std::string temp;
         std::string first,last;
         int id;
         float avg;
         //while(fin>>temp)
         //{
         // std::cout<<temp <<"\n";
         //}
while (fin>>first)
{
   fin>>last>>id>>avg;
  addStudents(student(first,last,id,avg));
}
         
      }
      void print() const 
      {
         for (const auto& s:m_students)
         {
            s.print();
         }
      }

   };


int main(int argc ,char * argv[]){
   /* std::vector<int> v;
    v.push_back(15);
    v.push_back(25);
    v.push_back(13);
    v.push_back(19);
    for(auto & a:v)
    {
      std::cout<< a <<"\n";
    }
    student s1;
    student s2("amr","ahmed",23,3.14);
    const student s3("ali","ahmed",11542,99.8);
    s3.print();*/
    course c("comp3200");
    c.loadfromfile("students.txt");
   //  c.addStudents(s1);
   //  c.addStudents(s2);
   //  c.addStudents(s3);
   //  c.addStudents(student("Mo","els",14522,55));
    c.print();
   return 0;
}                                