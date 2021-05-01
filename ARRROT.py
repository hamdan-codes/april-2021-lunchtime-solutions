# cook your dish here
# Author: Chaudhary Hamdan

n = int(input())
arr = [int(x) for x in input().split()]
s = sum(arr)
q = int(input())
_ = input()
for i in range(q):
    s = s * 2
    print(s % 1000000007)
