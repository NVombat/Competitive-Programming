/*Edward is playing a simplified version of game called "Dorsplen". This game is played with gems of three different
colors: red, green and blue. Initially player has no gem and there are infinitely many gems of each color on the table.

On each turn a player can either acquire gems or buy an artifact. Artifact can be bought using gems. On acquiring gems
player can get three gems of distinct colors or two gems of the same color from the table.

Edward is planning to buy an artifact, it costs r red gems, g green gems and b blue gems. Compute, what is the minimum
number of turns Edward has to make to earn at least r red gems,
g green gems and b blue gems, so that he will be able to buy the artifact.

Input format

Input contains three integers in a single line r, g and b the number of red, green and blue gems, respectively,
required to buy the artifact.

Constraints

0 <= r,g,b <=10^18

Output format

Output single integer: the minimum number of turns Edward has to make to be able to buy the artifact.
TEST CASE 1

INPUT
4 5 8
OUTPUT
7
TEST CASE 2

INPUT
57 54 100
OUTPUT
79
*/

//CODE:

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  //Scan number of red, blue and green gems; cnt is the number of turns
  int r, g, b, cnt=0;
  cin >> r >> g >> b;
  //This array will store the 2 colours that are left once the colour with the least gems is gone
  int gems[] = {0, 0};
  
  //m = minimum
  int m = -1;
  //This if statement finds the smallest value in r, g, b
  //It also sets that value to zero after updating m
  //It also fills the array with the other 2 colours
  if(r<g and r<b)
  {
    m = r;
    gems[0]=(g-r);
    gems[1]=(b-r);
    r=0;
  }
  else if(g<r and g<b)
  {
    m = g;
    gems[0]=(r-g);
    gems[1]=(b-g);
    g=0;
  }
  else
  {
    m = b;
    gems[0]=(r-b);
    gems[1]=(g-b);
    b=0;
  }
  
  //The number of turns is first incremented by the min value
  cnt+=m;
  //Then it is again incremented by the minimum of the two colours in the array
  cnt = cnt + min(gems[0],gems[1]);
  //Finally the left over gems are calculated
  int left = max(gems[0],gems[1]) - min(gems[0],gems[1]); 
  
  //If the left over gems are even then choose second gem selection method
  if(left%2==0)
  {
    cnt+=left/2;
  }
  //If theyre odd then subtract by one and choose second gem selection method and then add 1 to make up for the -1 
  else
  {
    cnt+=((left-1)/2) + 1;
  }
  //Output the number of turns
  cout << cnt << endl;
  return 0;
}