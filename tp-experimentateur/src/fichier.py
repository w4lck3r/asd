def list_in_str(l):
    """
    """
    res = ""
    for i in l:
        res +=  str(i) + " "
    return res


def cree_fichier(nom_fichier, data):
    """
        :data: list[list]
    """
    with open(nom_fichier, "wt", encoding="utf8") as file:
        for line in data:
            file.write(list_in_str(line))
            file.write("\n")
