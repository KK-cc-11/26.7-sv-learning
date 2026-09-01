#include<bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
};

int direction(point p1,point p2,point p3){
    return (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
}

bool onSeg(point p1,point p2,point p3){
    if(min(p1.x,p2.x)<p3.x&&p3.x<=max(p1.x,p2.x)){
        if(min(p1.y,p2.y)<=p3.y&&p3.y<=max(p1.y,p2.y))
            return true;
    }
    return false;
}

bool segIntersect(point p1, point p2,point p3,point p4){
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if ( ((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)) )
        return true;
    else if ( d1 == 0 && onSeg(p3,p4,p1) ) return true;
    else if ( d2 == 0 && onSeg(p3,p4,p2) ) return true;
    else if ( d3 == 0 && onSeg(p1,p2,p3) ) return true;
    else if ( d4 == 0 && onSeg(p1,p2,p4) ) return true;
    else return false;
}