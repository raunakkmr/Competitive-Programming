from math import gcd

t = int(input())
for tc in range(t):
    s = input()
    terms = s.split(' ')
    nums, dens = [], []
    for term in terms:
        num, den = term.split('/')
        nums.append(int(num))
        dens.append(int(den))

    den1 = dens[0]*dens[1] // gcd(dens[0],dens[1])
    num1 = nums[0]*den1//dens[0] + nums[1]*den1//dens[1]

    den2 = den1*dens[2] // gcd(den1,dens[2]) 
    num2 = num1*den2//den1 + nums[2]*den2//dens[2]

    g = gcd(num2, den2)
    num2 = num2 // g
    den2 = den2 // g

    print(str(int(num2))+'/'+str(int(den2)))