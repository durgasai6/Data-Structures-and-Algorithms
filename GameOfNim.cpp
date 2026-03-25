#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%4==0){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    return 0;
}




/*🧩 Problem: Game of Nim

You are playing the following game with your friend:

There is a heap of n stones on the table.
You and your friend will take turns removing stones, and you go first.
🎮 Rules:
On each turn, a player can remove 1, 2, or 3 stones from the heap.
The player who removes the last stone wins the game.
❓ Task

Given an integer n, return:

true if you can guarantee a win assuming both players play optimally
false otherwise
📥 Input
An integer n representing the number of stones
📤 Output
A boolean:
true → you can win
false → you will lose
🔒 Constraints
1 <= n <= 2³¹ - 1*/