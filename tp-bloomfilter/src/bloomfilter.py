# -*- coding: utf-8 -*-

""":mod:`bloomfilter` module : Implements a bloomfilter.

:author: `tarmelit lydia  AND salmi badreddine`_

:date:  april 2021

"""
import hash_functions

class BloomFilter:
    
    def __init__ (self, n, hashes):
        """
        Creates a new empty Bloom filter of size :math:`2^n`
        
        :param n: the log of the size of the filter (the filter will be of size :math:`2^n`)
        :type n: int
        :param hashes: the hash functions
        :type hashes: HashFunctions
        """
        f = {}
        for i in range(2**n) :
            f[i] = False
        self.filtre = f
        self.hashes = hashes


    def add (self, e):
        """
        Adds *e* to the Bloom filter.

        :param e: The element to be added
        :type e: Any
        :rtype: None
        """
        res = False
        for k in self.filtre.values() :
            if k == False :
                res = True
        if res == False :
            return False

        i = 0
        cle = self.hashes.hash(i,e) % len(self.filtre)
        while (self.filtre[cle] != False) :
            i+=1
            if i >= self.hashes.nb_functions() :
                return False
            cle = self.hashes.hash(i,e) % len(self.filtre)
        self.filtre[cle] = True
        return True

    def contains (self, e):
        """
        Returns True if *e* is stored in the Bloom filter

        :param e: The element to be tested
        :type e: Any
        :rtype: bool
        """
        i = 0
        cle = self.hashes.hash(i,e) % len(self.filtre)
        if self.filtre[cle] == True :
            return True
        return False
    
    def __contains__(self, e):
        return self.contains(e)
