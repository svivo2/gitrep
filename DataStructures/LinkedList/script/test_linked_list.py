import ctypes
import os

class LinkedList:
    def __init__(self):
        self.libpath = "lib/liblinked_list.so"
        if not os.path.exists(self.libpath):
            self.libpath = "../lib/liblinked_list.so"

        assert os.path.exists(self.libpath), "The library does not exist. Did you compile your source code?"

        self.libpath = os.path.realpath(self.libpath)

        self.c_lib = ctypes.CDLL(self.libpath)

        # Create Linked List Function
        self.c_lib.createLinkedList.restype = ctypes.c_void_p

        # Insert Node Function
        self.c_lib.insertNode.argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.c_lib.insertNode.restype  = ctypes.c_int

        # Delete Node Function
        self.c_lib.deleteNode.argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.c_lib.deleteNode.restype  = ctypes.c_int

        # Search Node Function
        self.c_lib.searchNode.argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.c_lib.searchNode.restype  = ctypes.c_int

        # Length of Linked List Function
        self.c_lib.length.argtypes = [ctypes.c_void_p]
        self.c_lib.length.restype = ctypes.c_int

        # Release Linked List Function
        self.c_lib.releaseLinkedList.argtypes = [ctypes.c_void_p]

        self.linkedList = self.c_lib.createLinkedList()

    def __del__(self):
        self.c_lib.releaseLinkedList(self.linkedList)


    def insert(self, value):
        return self.c_lib.insertNode(self.linkedList, value)

    def delete(self, value):
        return self.c_lib.deleteNode(self.linkedList, value)

    def search(self, value):
        return self.c_lib.searchNode(self.linkedList, value)

    def length(self):
        return self.c_lib.length(self.linkedList)

if __name__ == "__main__":
    linkedList = LinkedList()
    for value in range(1, 11):
        success = linkedList.insert(value)
        assert success == 1, "Insert %d to linked list unsuccessfully. Please check your implementation in C++!" % value
        print("Insert %d to linked list successfully" % value)

    assert linkedList.search(5) == 1, "Value = 5 should exist in your linked list but you return 0. Please check your implementation in C++!"
    print("Value = 5 exists in your linked list")

    assert linkedList.search(15) == 0, "Value = 15 should not exist in your linked list but you return 1. Please check your implementation in C++!"
    print("Value = 15 does not exist in your linked list")

    length = linkedList.length()
    assert length == 10, "The current number of values in the linked list should be 10 but you return %. Please check your implementation in C++!" % length
    print("The current number of values in the linked list: %d" % length)

    assert linkedList.delete(5) == 1, "Value = 5 in your linked list should be deleted. Please check your implementation in C++!"
    print("You delete value = 5 out of your linked list successfully!")

    length = linkedList.length()
    assert length == 9, "The current number of values in the linked list should be 9 but you return %d. Please check your implementation in C++!" % length
    print("The current number of values in the linked list: %d" % length)


    assert linkedList.search(5) == 0, "Value = 5 should not exist in your linked list since you just delte it but you return 1. Please check your implementation in C++!"
    print("Value = 5 does not exist in your linked list since you just delete it")
