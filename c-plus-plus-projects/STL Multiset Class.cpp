/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jas
 *
 * Created on November 11, 2016, 1:01 PM
 */

#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <cassert>
#include <set>
#include <iostream>                  
#include <fstream>                   
#include <string>
using namespace std;


int main()
{   
   srand(time(0)); 
   multiset<string> choresch;
   multiset<string> ::iterator choresIT;
   
   string line;

   ifstream fin;                  

   fin.open("chores.txt");       

   if(fin.is_open())
   {     
			while (fin.good()) 

            {

                  getline(fin, line);   //read a line from file

                  choresch.insert(line);
                  
                  
			}

            fin.close();               

	}

   else
   {

            cout << "Error trying to open the file or file does not exist";
            exit(1);
	}

  
	bool exit_menu=false;
	int user_option=0;
		
		
		do
		{
			cout<<"What do you want to do?"<<endl;
			
			cout<<"1) Add an item to the list"<<endl;

			cout<<"2) Ask how many chores are in the list"<<endl;

			cout<<"3) Display the list of chores"<<endl;

			cout<<"4) Delete an item from the list"<<endl;

                        cout<<"5) Exit the program" <<endl;
            
            cin>>user_option;
            string newChore;
            string delChore;
            			
			switch(user_option)
			{
				case 1:
					cout<<"Adding the chore to file"<<endl;
					cin.ignore();					
					getline(cin, newChore);
					choresch.insert(newChore);
					break; 
				case 2:
					cout<<"How many chores are in the list:"<<endl;
					cout<<choresch.size()-1;
					cout<<""<<endl;
					break;
				case 3:
					cout<<"Here's the list of chores!"<<endl;
					for(choresIT=choresch.begin();choresIT!=choresch.end();choresIT++)
					{
						cout<<*choresIT<<endl;
						}
					cout<<endl;	
					break;
				case 4:
					cout << "Which chore would you like to delete?"<<endl;
					cin.ignore();
					getline(cin, delChore);
					for(choresIT=choresch.begin();choresIT!=choresch.end();choresIT++)
					{
						if(delChore==*choresIT)
						{
						choresch.erase(choresIT);
						}
					}
					
					break;
				case 5:
				    cout <<"Goodbye!" <<endl;
				    exit_menu=true;
				    break;	
				default:
					cout <<"Did you read my message correctly?"<<endl;
					break;
			}
		}while(!exit_menu);
	
		
		ofstream in;
		in.open("chores.txt");
		
		if(in.is_open())
   {     
			for(choresIT=choresch.begin();choresIT!=choresch.end();choresIT++)
    
            {
                  in<<*choresIT<<endl;
             
            }

            in.close();               

	}

   else

            cout << "Error opening the file or file does not exist";


		return 0;
    }
    
   


   
       






