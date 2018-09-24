n = int(input())
l = [int(x) for x in input().split()]

if sum(l) > 0:
  print('HARD')
else:
  print('EASY')
