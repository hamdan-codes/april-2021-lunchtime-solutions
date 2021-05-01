# cook your dish here
# Author: Chaudhary Hamdan

t = int(input())
for _ in range(t):
    zero = 0
    one = 0
    flag = 0
    l = int(input())
    s = input()
    for i in range(l):
        c = s[i]
        if c == '0':
            zero += 1
        else:
            one += 1
        
        if one * 2 >= i + 1:
            flag = 1
            print('YES')
            break
    
    if flag == 0:
        print('NO')
        
    