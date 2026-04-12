def parse(s):
    s += '$'
    i = 0

    def E():
        nonlocal i
        T(); E_()

    def E_():
        nonlocal i
        if s[i] == '+':
            i += 1
            T(); E_()

    def T():
        nonlocal i
        F(); T_()

    def T_():
        nonlocal i
        if s[i] == '*':
            i += 1
            F(); T_()

    def F():
        nonlocal i
        if s[i] == 'i':
            i += 1
        elif s[i] == '(':
            i += 1
            E()
            if s[i] == ')':
                i += 1
            else:
                return False
        else:
            return False
        return True

    try:
        E()
        return s[i] == '$'
    except:
        return False


while True:
    inp = input("Enter expression (use i, +, *, (), or exit): ")
    if inp == "exit":
        break

    if parse(inp):
        print("Accepted\n")
    else:
        print("Rejected\n")