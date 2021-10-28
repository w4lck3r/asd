# -*- coding: utf-8 -*-

from math import log
import random
from hash_functions import HashFunctions
from bloomfilter import BloomFilter

def random_word ():
    """
    Returns a word with random letters whose length is between 4 and 7.

    :rtype: string
    """
    letters = [ chr(i) for i in range(ord('a'),ord('z')+1) ] + [ chr(i) for i in range(ord('A'),ord('Z')+1) ]
    length = 4 + random.randint(0,4)
    str = ""
    for i in range(length):
        str = str + random.choice(letters)
    return str

if __name__ == "__main__":
    hashes = HashFunctions(8)
    bf = BloomFilter(16, hashes)
    w = random_word()
    bf.add("timoleon")
    if bf.contains("timoleon"):
        print("%s est present" % ("timoleon"))
    if bf.contains(w):
        print("%s est present" % (w))

    """
    i = [random_word() for i in range(8)]
    hashes = HashFunctions(8)
    bf = BloomFilter(3, hashes)
    for elt in i :
        print(elt)
        bf.add(elt)
        print(bf.filtre.values())
    
    
    hashes = HashFunctions(1)
    print(hashes.random_tab[0][127])
    
    """
    i = [random_word() for i in range((2**10)+1)]
    with open("res.txt", "w") as file:
        for n in range(1,9) :
            for t in range(10,21) :
                hashes = HashFunctions(n)
                bf = BloomFilter(t, hashes)
                for w in i :
                    bf.add(w)
                wordTest = 0
                FPTest = 0
                for k in range(1,(2**14)+1) :
                    u = random_word()
                    if u not in i :
                        wordTest +=1
                        if bf.contains(u) :
                            FPTest +=1
                file.write("{:d} {:d} {:d} {:d} {:f}\n".format(t, n, wordTest, 
                FPTest, (FPTest/wordTest)))
            file.write("\n\n")
            print(n)
    
    
                

                
