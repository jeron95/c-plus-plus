#include <iostream>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;
const int SIZE = 150000;

	 set<string>load_set()
	{
		const int N  = 5;
		set<string> words;
		ifstream myfile;
		string line;
		int x = 0;
		myfile.open("wordslist.txt");
		while(!myfile.eof())
		{
			getline(myfile, line);
			words.insert(line);
			x++;
		}	
		myfile.close();
		return words;
	}

	map<string, set<string>> load_hashmap()
	{
		const int N  = 5;
		map<string, set<string>> words;
		ifstream myfile;
		string line;
		myfile.open("wordslist.txt");
		while(!myfile.eof())
		{
			getline(myfile, line);
			string original_line=line;
			sort(line.begin(), line.end());
			
			if (words.count(line)==0)
			{
				set<string> x;
				x.insert(original_line);
				words.insert(make_pair(line, x));
				
			}
			else
			{
				set<string> s = words[line];
				s.insert(original_line);
				words[line] =s;
			}
		}	
		myfile.close();
		return words;
	}

void make_it_all_random(string data[], size_t N)
{
	ifstream myfile;
	string words;
	
	myfile.open("wordslist.txt");
    for(size_t i=0; i<N; i++)
    {
		getline(myfile, data[i]);
    }
}


void approach1(string data[], size_t N, map<string, set<string>> table)
	{
		int n = 0;
		for(size_t i=0; i<N; i++)
		{
			string w =data[i];
			sort(w.begin(), w.end());
			if(table.find(w)!= table.end())
			{
				n++;
			}

		}
	}

void approach2(string data[], size_t N)
	{

	}

int main() 
{
	map<string, set<string>> table = load_hashmap();
	string *words;
	int size;
	cout << "What should the size be"<<endl;
	cin >> size;
	words = new string[size];
	make_it_all_random(words, size);
    
    clock_t start_time = clock();
	approach1(words, size, table);
	
    clock_t time_taken = clock()- start_time;
    float millisecs = ((float)time_taken)/CLOCKS_PER_SEC*1000;
    cout << "It took " << millisecs << " milliseconds to do unsorted";
    
    
    /*
    start_time = clock();
	approach2(word, size);
    time_taken = clock()- start_time;
    millisecs = ((float)time_taken)/CLOCKS_PER_SEC*1000;
    cout << "It took " << millisecs << " milliseconds to do sorted";
	*/
    
    return 0;
}


	

	


