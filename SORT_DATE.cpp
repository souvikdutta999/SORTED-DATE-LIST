#include <algorithm>
#include <iostream>
#include <string>
#include<fstream>
#include<unordered_map>
using namespace std;
unordered_map<string, int> monthsMap;
class MyDate 
{
	public:
    int day; 
    int month; 
    int year; 
}; 

bool compare(const MyDate &d1, const MyDate &d2) 
{ 
    if (d1.year < d2.year) 
        return true; 
    if (d1.year == d2.year && d1.month < d2.month) 
        return true; 
    if (d1.year == d2.year && d1.month == d2.month && 
                              d1.day < d2.day) 
        return true; 
    return false; 
} 

void sortDates(MyDate arr[], int n) 
{ 

    sort(arr, arr+n, compare); 
} 

	

int main()
{   monthsMap["JAN"] = 1; monthsMap["FEB"] = 2; monthsMap["MAR"] = 3; monthsMap["APR"] = 4; monthsMap["MAY"] = 5;  monthsMap["JUNE"] = 6; 
    monthsMap["JULY"] = 7; monthsMap["AUG"] = 8; monthsMap["SEP"] = 9; monthsMap["OCT"] = 10; monthsMap["NOV"] = 11; monthsMap["DEC"] = 12; 
    monthsMap["January"] = 1; monthsMap["February"] = 2; monthsMap["March"] = 3; monthsMap["April"] = 4; monthsMap["May"] = 5; monthsMap["June"] = 6; 
    monthsMap["July"] = 7; monthsMap["August"] = 8; monthsMap["September"] = 9; monthsMap["October"] = 10; monthsMap["November"] = 11; monthsMap["December"] = 12;
    monthsMap["01"] = 1; monthsMap["02"] = 2; monthsMap["03"] = 3; monthsMap["04"] = 4; monthsMap["05"] = 5;  monthsMap["06"] = 6; 
    monthsMap["07"] = 7; monthsMap["08"] = 8; monthsMap["09"] = 9; monthsMap["10"] = 10; monthsMap["11"] = 11; monthsMap["12"] = 12; 
    int i=0,count=0,j=0,k=0,c1=0;
    string word= "";
    ifstream file("test.txt");
  	string str;
  	MyDate input[100];
  	while (getline(file, str))
	{
    	//cout << str << "\n";
    	c1+=1;
    	for (auto x : str) 
    	{
    		if(x =='/' || x==' ' || x ==',')
    		{
           		//cout << word << endl; 
           		if(word.length()<=2 && count==0)
           		{
           			input[i].day=std::stoi(word);
           			i+=1;
           			count+=1;
           		}
           		else if(word.length()==4)
           		{
           			input[j].year=std::stoi(word);
           			j+=1;
           		}
           		else
           		{
           			
           			input[k].month =monthsMap[word];
           			k+=1;
				}
           		word = ""; 
			} 
       		else
       		{ 
           		word = word + x; 
      		} 
   		}  
   		count=0;
   		//cout << word << endl; 
  	}
    file.close();
    for(int i=0; i<c1; i++) 
    { 
        cout<<input[i].day<<" "<<input[i].month<<" "<<input[i].year; 
        cout<<endl; 
    } 
    cout<<"\n";
    sortDates(input,c1);
    int m;
    
    cout<<"AFTER SORTING THE DATES ARE: "<<"\n";
    for(int i=0; i<c1; i++) 
    {
    		//cout<<input[m].year<<"\n";
	    	if((input[i].year)%4!=0)
	    	{
	    		if(input[i].month==2)
	    		{
	    			if(input[i].day==29)
	    			cout<<"THIS IS NOT A LEAP YEAR SO INVALID DATE"<<"\n";
				}
			}
			else if((input[i].year)%4==0)
	    	{
	    		if(input[i].month==2)
	    		{
	    			if(input[i].day==29)
	    			cout<<"THIS IS A LEAP YEAR"<<"\n";
				}
			}
			else
			{
				if(input[i].month!=2)
				{
					if(input[i].day>=32)
					cout<<"INVALID DATE"<<"\n";
				}
			}
        cout<<input[i].day<<" "<<input[i].month<<" "<<input[i].year; 
        cout<<endl; 
    } 
    return 0;
}



