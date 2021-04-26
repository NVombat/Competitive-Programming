'''
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while
123 is not.

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
'''

#CODE:
#Function to check if the number is a palindrome -> returns a bool value
def isPalindrome(x: int) -> bool:
    #If the number is negative (-123) 
    if(x<0):
        #Not a palindrome as -123 = 321- thus return false
        return False
    #If number is non negative
    else:
        #Convert the number to a string
        x = str(x)
        #Store the reverse of the string in another variable
        y = x[::-1]
        #If the string and its reverse match then they are palindromes thus return true
        if(x==y):
            return True
        #If string and reverse dont match -> return false
        else:
            return False

#Take input number from user and check for palindrome
x = int(input("Enter Number: "))
if(isPalindrome(x)):
    print("IS A PALINDROME")
else:
    print("NOT A PALINDROME")