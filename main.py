import random

zods   = []

first  = ['A', 'B', 'C', 'D']
second = ['a', 'b', 'c', 'd']
thrid  = ['E', 'F', 'G', 'H']

def getPrediciton():
    return f'{random.choice(first)}, {random.choice(second)}, {random.choice(third)}'

print("Hellow, World!")