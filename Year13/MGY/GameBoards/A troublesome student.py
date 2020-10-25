def format_name(name):
    split = name.find(" ")
    first = name[0:split]
    print(first)
    last = name[split+1 : len(name)]

    return last + ", " + first

print(format_name("John SMITH"))
print(format_name("John SMITH"))
print(format_name("Neil Patrick HARRIS"))