# -*- coding: utf-8 -*-

"""
:mod:`test` module : test module for experiences assignment

:author: `FIL - IEEA - Univ. Lille1.fr <http://portail.fil.univ-lille1.fr>`_

:date: 2018, january
"""
from fichier import*
import sys
import experience
import marker
import sorting
from sorting import merge_sort
from functools import cmp_to_key





def compare (m1,m2):
    '''
    Compares two markers

    :param m1: A marker 
    :type m1: Marker
    :param m2: Another marker
    :type m2: Marker
    :return: -1 if *m1 < m2*, 0 if *m1* = *m2* or 1 when *m1* > *m2*
    :rtype: int
    '''
    
  
    return m1.cmp(m2)

# STRATEGY 1
def negative_markers1(markers,positive):
    """
    Computes the list of negative markers from the list of markers and
    the list of positive markers.

    :param markers: The list of markers 
    :type markers: list of str
    :param positive: The list of positive markers
    :type positive: list of str
    :return: The list of negative markers
    :rtype: list of str
    """
    cpt = 0
    negative = []
    for marker in markers :
        found = False
        i=0
        while found == False and i < len(positive):
            if compare(marker, positive[i]) ==0 :
                found = True
            i+=1
            cpt+=1
            
        if found == False :
            negative.append(marker)
    return (negative,cpt)

# STRATEGY 2
def negative_markers2(markers,positive):
    cpt =0
    negative = []
    positive = sorting.merge_sort(positive,compare)

    for marker in markers :
        found = False
        min_pos = 0
        max_pos = len(positive)-1

        while min_pos <= max_pos and not found:
            middle_pos = (min_pos + max_pos) // 2
            element = positive[middle_pos]
            comp = compare(element, marker)

            if comp < 0 : 
                min_pos = middle_pos + 1
            elif comp > 0 :
                max_pos = middle_pos - 1
            else :
                found = True
            cpt+=1
    
        if found == False :
            negative.append(marker)
    
    return (negative,cpt)


# STRATEGY 3
def negative_markers3(markers,positive):
    cpt=0
    negative = []
    markers_trie=merge_sort(markers,compare)
    positive_trie=merge_sort(positive,compare)
    i=0
    trouve=False 
    while i<len(markers):
        j=len(positive_trie)-1
        while j>=0 and not trouve:
            if (compare(markers_trie[i],positive_trie[j])!=-1):
                positive_trie = positive_trie[j+1:]
                trouve =True
            j-=1
            cpt+=1
        if not trouve:
            negative.append(markers_trie[i])
        i+=1
        trouve = False
    return (negative,cpt)
    
#question 3
def teste(m):
    res=[]
    for i in range(1,m+1):
        exp = experience.Experience(i,i)
        markers = exp.get_markers()
        positive = exp.get_positive_markers()
        res.append([i,i,negative_markers1(markers,positive)[1],negative_markers2(markers,positive)[1],negative_markers3(markers,positive)[1]])
    return res
    
    
   
if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: {} <p> <m>\n\n<p>: nombre de marqueurs positifs\n<m>: nombre de marqueurs".format(sys.argv[0]))
        sys.exit(1)
    p = int(sys.argv[1])
    m = int(sys.argv[2])

    assert (m > 0), "The number of markers must be greater than 0"
    assert (p <= m), "The number of positive markers must be less or equal to the number of markers"
    
    exp = experience.Experience(p,m)
    markers = exp.get_markers()
    positive = exp.get_positive_markers()

    print("Markers: {}".format(markers))
    print("Positive markers: {}".format(positive))
    
    # test stategy 1
    cpt = negative_markers1(markers,positive)[1]
    print("Negative markers: {}".format(negative_markers1(markers,positive)[0]))
    print("Nb. comparisons: {}".format(cpt))

    # test stategy 2
    cpt = negative_markers2(markers,positive)[1]
    print("Negative markers: {}".format(negative_markers2(markers,positive)[0]))
    print("Nb. comparisons: {}".format(cpt))

    # test stategy 3
    cpt = negative_markers3(markers,positive)[1]
    print("Negative markers: {}".format(negative_markers3(markers,positive)[0]))
    print("Nb. comparisons: {}".format(cpt))
    #crèation des fichiers
    for i in range(10,101,10):
    
    	cree_fichier("tp1-"+str(i)+".dat", teste(i))
     
     
    
