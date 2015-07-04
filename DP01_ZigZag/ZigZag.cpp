#include <stdlib.h>
#include <iostream>
using namespace std;

#define ARRAY_SIZE(array) ( sizeof((array))/sizeof(array[0]) )

class ZigZag {    
	
public:
    template <typename T, int N>
	int longestZigZag(T (&sequence) [N]) {
		int seqLength=ARRAY_SIZE(sequence);

        //base case
        if(seqLength == 1) return 1;

        //make an array of differences between # pairs
        int arrayDiff[seqLength-1];
        for(int i=0;i<(seqLength-1);++i) {
            arrayDiff[i]=sequence[i+1]-sequence[i];
        }

        //find 'Lowest Common Substring' variant
        int diffLength=ARRAY_SIZE(arrayDiff);

        //check for zeroes  
        int i=0;
        while((i<diffLength)&&(arrayDiff[i]==0)) ++i;
        if(i == diffLength) return 1;

        int dir = arrayDiff[i];
        int len = 2;
        for(int j=(i+1);j<(diffLength-1);++j) {
        //    cout << (arrayDiff[i]*dir) << endl;
            if((arrayDiff[i]*dir)<0) {
                dir *= -1;
                ++len;
            }
        }
        return len;    
    }
};

int main(int argc, char *argv[]) {
    ZigZag zz;

    int case0[]={1,7,4,9,2,5};
    int case1[]={1,17,5,10,13,15,10,5,16,8};
    int case2[]={44};
    int case3[]={1,2,3,4,5,6,7,8,9};
    int case4[]={70,55,13,2,99,2,80,80,80,80,100,19,7,5,5,5,1000,32,32};
    int case5[]={374,40,854,203,203,156,362,279,812,955,600,947,978,46,
    100, 953,670,862,568,188,67,669,810,704,52,861,49,640,370,908,477,
    245,413,109,659,401,483,308,609,120,249,22,176,279,23,22,617,462,
    459,244};
    
    cout << zz.longestZigZag(case0) << endl;
    cout << zz.longestZigZag(case1) << endl;
    cout << zz.longestZigZag(case2) << endl;
    cout << zz.longestZigZag(case3) << endl;
    cout << zz.longestZigZag(case4) << endl;
    cout << zz.longestZigZag(case5) << endl;

	return 0;
}
