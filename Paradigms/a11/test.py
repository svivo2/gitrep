import operator
import string
file = "assignment11-account-info.txt"
info = []
with open(file) as data:
    for line in data:
        info = line.split(';')
        if 'buser' in info:
            print("Correct username")
            if 'pass2' in info:
                print("Correct password")
            else:
                print("incorrect password")
        else:
            print("Incorrect username")
