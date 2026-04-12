stack = []

rules = {
    "E+E": "E",
    "E*E": "E",
    "(E)": "E",
    "id": "E"
}

def reduce():
    s = "".join(stack)
    for rhs in rules:
        if rhs in s:
            i = s.find(rhs)
            for _ in range(len(rhs)):
                stack.pop(i)
            stack.insert(i, "E")
            print("Reduce:", rhs, "-> E")
            return True
    return False

while True:
    inp = input("Enter string (use id, +, *, (), or exit): ")
    if inp == "exit":
        break

    inp += "$"
    stack.clear()
    i = 0

    print("\nStack\tInput\tAction")

    while i < len(inp):
        stack.append(inp[i])
        i += 1
        print("".join(stack), "\t", inp[i:], "\tShift")

        while reduce():
            pass

    if stack == ['E'] and inp[-1] == '$':
        print("\nAccepted\n")
    else:
        print("\nRejected\n")