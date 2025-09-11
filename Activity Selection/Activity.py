
def main(S=[], E=[]):

    while True: 
        tmp = str(input(""))

        if tmp == "":
            print(activity_selection(S, E))
            break

        else:
            tmp = tmp.split(",")

        s = tmp[0].strip()
        e = tmp[1].strip()

        if not s.isdigit() or not e.isdigit():
            raise main(S, E)

        elif len(tmp) != 2:
            raise main(S, E)

        S.append(int(s))
        E.append(int(e))

def activity_selection(S, E):

    result = []

    end = E.copy()
    end.sort(reverse=False)

    result.append(end[0])
    
    for i in range(1, len(end)):
        if S[E.index(end[i])] >= result[len(result) - 1]:
            result.append(end[i])

    res = []
    for i in range(len(result)):
        res.append(E.index(result[i]))

    return res

if __name__ == "__main__":

    print("\nEnter the starting time and ending time in order seperated by comma")
    print("Press Enter when you're finished: ")
    main()