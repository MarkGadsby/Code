def CSV_Divider(line):
    i_end = line.find(',')
    i_start = 0

    values = []

    while (i_end != -1):
        values.append(line[i_start : i_end])
        i_start = i_end + 1
        i_end = line.find(',', i_start)

    return values


returned_list = CSV_Divider("Neptune,102,258,60182,16.1,4495.1,-200")

print(returned_list)

for value in returned_list:
    print('\n\t' + value)