#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template< typename T, size_t N >
std::vector<T> makeVector(const T (&data)[N]) 
{
	
	return std::vector<T>(data, data+N);
} 
 
class BadNeighbors 
{
	
public:
	
	map<int, int> answer;
	vector<int> blah;
  
	int getAnswer(int i1, int i2) 
	{
		
		int key = i1*500+i2; //Some sort of convention for making a key (?). Mapping in terms of i1 and i2 
		if ( answer.count(key) ) 
		{
			
			return answer[key]; //If area with key is nonempty then return the answer that's there. (counts elements with that key)
		}
		if (i1 > i2) 
		{
			
			return 0; // If the lower bound becomes larger than the upper bound
		}
		answer[key] = max(getAnswer(i1+1,i2), getAnswer(i1+2,i2)+blah[i1]); //The max of the recursive call

		return answer[key];
	}
  
	int maxDonations(vector <int> donations) 
	{
		blah = donations;
		int n = donations.size();
    
		return max( getAnswer(0, n-2), getAnswer(1, n-1) );
	}
};

int main(int argc, char *argv[]) {
	
	BadNeighbors bn;
	int c0[] = {10, 3, 2, 5, 7, 8};
	vector<int> case0 = makeVector(c0);
	
	cout << bn.maxDonations(case0) << endl;
	
	return 0;
} 
