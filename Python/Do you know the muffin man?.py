def csv_output(whole_string, delimiter):
    location = whole_string.find(delimiter)

    word = whole_string[0:location]
    rest = whole_string[location + 1 : len(whole_string)]

    if location >= 0:  
        print(word)
        csv_output(rest, delimiter)
    else:
        print(rest)

csv_output("do,you,know,the,muffin,man", ",")

