import math
twoValues = input().split(" ")

n = int(twoValues[0])
m = int(twoValues[1])
for i in range(m):
  cache = input()
print(int(math.factorial(n)//pow(2,m)) % int((pow(10,9)+7)))