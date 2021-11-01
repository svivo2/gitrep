""" [20 pts]
Define a Python function named "Evens" that takes one
argument, which is assumed to be a list of integers,
and returns a list containing all of the integers from
the input list which are even numbers, in the same order.
"""

def Evens():
    nums = input("Input integer list: ")
    list = []
    for i in nums:
        if i.isdigit() and int(i) % 2 == 0:
            list.append(int(i))
    print(list)
Evens()
