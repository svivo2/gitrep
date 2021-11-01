import operator
import string
skip = []
erasures = ['\n','\t','.','?','!',',',';',':','\'','\"','(',')']
list = []
StoryFile = input("Story Filename: ")
SkipFile = input("Skip Word Filename: ")
pair = {}
with open(SkipFile) as words:
    skip = words.read().lower().split(',')
with open(StoryFile) as story:
    word = story.read().lower()
    for s in erasures:
        if s in word:
            word = word.replace(s,' ')
    word = word.split()
skip.append('s')
for t in skip:
    for s in word:
        if s == t:
            word.remove(t)
            # print(t)
for x in range(len(word) - 1):
    if (word[x] + " " + word[x + 1]) in pair:
        pair[word[x] + " " + word[x + 1]] = pair[word[x] + " " + word[x + 1]] + 1
    else:
        pair[word[x] + " " + word[x + 1]] = 1
pair = sorted(pair.items(), key=operator.itemgetter(1))
print("Skip Words: ")
print(skip)
print("Erasures: ")
print(erasures)
# print("\nWords: ")
# print(word)
print("The five most frequently occurring word pairs are:")
for x in range(5):
    print(pair.pop())
