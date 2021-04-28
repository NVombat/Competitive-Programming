'''LEETCODE
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
'''

#CODE:
#Function to reverse integer - returns an integer
def reverse(x: int) -> int:
    #If integer is 0 return 0
    if x==0:
        return 0
    #If integer is greater than 0
    elif x>0:
        #Convert to string
        x = str(x)
        #Reverse string
        x = x[::-1]
        #Convert back to integer
        x = int(x)
        #Check if the integer is in range
        if(x>((2**31)-1)):
            #Return 0 if out of range
            return 0
        #Return reversed integer
        return x
    #If integer is smaller than 0
    else:
        #Convert it to a positive integer
        x = x*(-1)
        #Convert to string
        x = str(x)
        #Reverse string
        x = x[::-1]
        #Convert back to negative integer
        x = (int(x))*-1
        #Check if the integer is in range
        if(x<(-2**31)):
            return 0
        #Return reversed integer
        return x

#Code to run function:
#Take input integer from user and reverse integer
x = int(input("Enter Integer Here: "))
rev_x = reverse(x)
print("Reversed Integer:", rev_x)