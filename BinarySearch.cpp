#include<isotream>
#include<vector>
using namespace std;
int binSearch(vector<int> v, int l,int r,int key)
{
    while (r-l>1){
        int mid = l+(r-l)/2;
        if(v[m]>key) r=mid;
        else l=mid;
    }
    return r;
}
// the prequisiton of this method is to sort the array