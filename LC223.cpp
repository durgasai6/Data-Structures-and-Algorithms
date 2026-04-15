#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
    cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;
    int area1=(ax2-ax1)*(ay2-ay1);
    int area2=(bx2-bx1)*(by2-by1);
    int width=max(0,min(bx2,ax2)-max(bx1,ax1));
    int height=max(0,min(by2,ay2)-max(ay1,by1));
    int result=area1+area2-(width*height);
    cout<<result<<endl;
    return 0;
}









/*Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 

Example 1:

Rectangle Area
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45
Example 2:

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
 

Constraints:

-104 <= ax1 <= ax2 <= 104
-104 <= ay1 <= ay2 <= 104
-104 <= bx1 <= bx2 <= 104
-104 <= by1 <= by2 <= 104*/