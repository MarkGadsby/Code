import time

# node class
class node:
    def __init__ (self, word):
        self.left = None
        self.right = None
        self.word = word
        self.instances = 1

# utility function to add a word to the tree
def insert(root, node):
    if root is None:
        root = node
    else:
        if root.word < node.word:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        elif root.word > node.word:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)
        else:
            root.instances += 1

# utility function to read the tree from left to right
def traverseInOrder(root, write_file):
    if root:
        traverseInOrder(root.left, write_file)
        write_file.write(str(root.instances) + "\t" + root.word + "\n")
        traverseInOrder(root.right, write_file)


start = time.time()

readFile = open("../TestData/Shakespeare.txt")

root = node("root")
totalWords = 0

for line in readFile:
    for word in line.split():
        insert(root, node(word))
        totalWords += 1

sortedFile = open("Sorted.txt", 'a')
traverseInOrder(root, sortedFile)

readFile.close()
sortedFile.close()

end = time.time()

print()
print("PYTHON: Total Words = " + str(totalWords) + " Total time = " + str(end - start))
print()
