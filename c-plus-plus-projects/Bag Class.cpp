/* 
 * File:   main.cpp
 * Author: Jasi Davidson
 *
 * Created on September 27, 2016, 1:27 PM
 */

#include<iostream>

#include<string>

#include<cassert>

using namespace std;

class bag

    {

    public:

       // TYPEDEFS and MEMBER CONSTANTS



        typedef int value_type;

        typedef size_t size_type;

        static const size_type CAPACITY = 1000;        
        // CONSTRUCTOR

        bag( ) { used = 0; }

        // MODIFICATION MEMBER FUNCTIONS

        size_type erase(const value_type& target);

        bool erase_one(const value_type& target);

        void insert(const value_type& entry);

        // CONSTANT MEMBER FUNCTIONS

        size_type size( ) const{ return used; }

        size_type count(const value_type& target) const;

    private:

        value_type data[CAPACITY];  // The array to store items

        size_type used;             // How much of array is used

    };



    bag::size_type bag::erase(const value_type& target)

    {

     size_type index = 0;

     size_type many_removed = 0;

 

     while(index < used)

     {

         if(data[index] == target)

         {

           --used;

           data[index] = data[used];

           ++many_removed;

         }

         else

           ++index;

     }

     return many_removed;

    }

    bool bag::erase_one(const value_type& target)

    {

     size_type index; // The location of target in the data array  

 

     // First, set index to the location of target in the data array,

     // which could be as small as 0 or as large as used-1. If target is not

     // in the array, then index will be set equal to used.

     index = 0;

     while((index < used) && (data[index] != target))
     {
         ++index;
     }


     if(index == used)
     {
         return false; // target isn’t in the bag, so no work to do.
     
     }

     // When execution reaches here, target is in the bag at data[index].

     // So, reduce used by 1 and copy the last item onto data[index].

     --used;

     data[index] = data[used]; 
     

     return true;

    }

 

    void bag::insert(const value_type& entry)

    { 

        assert(size( ) < CAPACITY);

 

        data[used] = entry;

                   ++used;

    }

 

    bag::size_type bag::count(const value_type& target) const

    {

        size_type answer;

        size_type i;

 

        answer = 0;

        for(i = 0; i < used; ++i)

            if(target == data[i])

                ++answer;

        return answer;

    }
    
    int main()
    {
        bag mynumbers;
        mynumbers.insert(129);
        mynumbers.insert(128);
        mynumbers.insert(127);
        mynumbers.insert(126);
        mynumbers.insert(125);
        bag randomnumbers;
        randomnumbers.insert(1);
        randomnumbers.insert(2);
        randomnumbers.insert(3);
        randomnumbers.insert(4);
        randomnumbers.insert(5);
        bag yournumbers;
        int x;
        for(int i=0; i<5; i++)
        {
            cin >> x;
            yournumbers.insert(x);
        }
        cout << mynumbers.size()<<endl;
        cout << randomnumbers.size()<<endl;
        cout << yournumbers.size()<<endl;
		cout << yournumbers.count(15)<<endl;
        return 0;
    }
    


