'''
You are given:
An integer N representing the length of an array of non-zero integers
An Array A which contains non-zero integers

Your aim is to output the array A where alternate elements are positive and negative.

If any elements are in excess, they need to be appended to the end of the final array
'''

#CODE
n = 6
a = [-1, -3, -2, 1, 1, 7]

neg = []
pos = []
for ele in a:
    if ele > 0:
        pos.append(ele)
    elif ele < 0:
        neg.append(ele)
    else:
        print("0")

neg_len = len(neg)
pos_len = len(pos)

fa = []

if neg_len>pos_len:
    for i in range(0, pos_len):
        fa.append(pos[i])
        fa.append(neg[i])

    for j in range(pos_len, neg_len):
        fa.append(neg[j])

    print("Magic Array:", fa)

elif pos_len>neg_len:
    for i in range(0, neg_len):
        fa.append(neg[i])
        fa.append(pos[i])

    for j in range(neg_len, pos_len):
        fa.append(pos[j])

    print("Magic Array:", fa)

else:
    for i in range(0, neg_len):
        fa.append(neg[i])
        fa.append(pos[i])

    print("Magic Array:", fa)
