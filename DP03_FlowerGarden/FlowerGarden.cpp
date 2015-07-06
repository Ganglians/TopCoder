#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template< typename T, size_t N >
vector<T> makeVector(const T (&data)[N]) 
{
	
	return std::vector<T>(data, data+N);
} 

class FlowerGarden 
{

public:

    vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) 
    {

        int h = height.size();
        vector<bool> filledIn = vector<bool>(h);
        vector<int> order;
   
        int maxH = 0, pos = -1;
        bool blocking = false, found = true;
        
        for(int i = 0; i < h; ++i)
        {

		    maxH = 0;	

			for(int j = 0; j < h; ++j) 
			{
				
				if(filledIn[j])
					continue;
				found = true;

				for(int k = 0; k < h; ++k) 
				{

					if(filledIn[k])
						continue;
					blocking = !(wilt[j] < bloom[k] || bloom[j] > wilt[k]);

					if((height[j] > height[k]) && blocking) 
					{

						found = false;
						break;
					}     
				}

				if(found && (maxH < height[j])) 
                {
		
					maxH = height[j];
					pos = j;
				}
			}

            order.push_back(height[pos]);
            filledIn[pos] = true;
		}
    return order;
	}
};

int main(int argc, char* argv[]) 
{
    
    int h[] = {5, 4, 3, 2, 1};
    int b[] = {1, 5, 10, 15, 20};
    int w[] = {5, 10, 14, 20, 25};

    vector<int>height = makeVector(h);
    vector<int>bloom = makeVector(b);
    vector<int>wilt = makeVector(w);

    FlowerGarden fg;
    vector<int>ans = fg.getOrdering(height, bloom, wilt);

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
return 0;
}
