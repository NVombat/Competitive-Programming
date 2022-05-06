'''
You are given:
An integer N denoting the number of chocolates
An array A where Ai represents the cost of the ith chocolate in the array

The chocolates have to be put into bags with the condition that no two chocolates of the same price can be in the same bag

What is the minimum number of bags needs to be able to solve this?
'''

#CODE
n = 16
a = [1,1,2,4,1,1,2,3,4,5,6,6,6,1,1,1]

max_cnt = 0
cnt = 0

a.sort()
print(a)

i = 0
j = 1
while (i < n and j < n):
    print("J:", j)

    if a[i] == a[j]:
        cnt = cnt + 1
        print("CNT:", cnt)
        i = i+1
        print("I:", i)
        if cnt > max_cnt:
            max_cnt = cnt
    else:
        cnt = cnt + 1
        if cnt > max_cnt:
            max_cnt = cnt
            cnt = 0
            i = i+1
        else:
            cnt = 0
            i = i+1
    j = i+1

print("The minimum number of bags needed is:", max_cnt)