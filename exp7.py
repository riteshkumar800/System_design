s = "i+i*i$"
i = 0

def E():
    T(); E_()

def E_():
    global i
    if s[i] == '+':
        i += 1
        T(); E_()

def T():
    F(); T_()

def T_():
    global i
    if s[i] == '*':
        i += 1
        F(); T_()

def F():
    global i
    if s[i] == 'i':
        i += 1
    elif s[i] == '(':
        i += 1
        E()
        if s[i] == ')':
            i += 1
        else:
            error()
    else:
        error()

def error():
    print("Rejected")
    exit()

E()
print("Accepted" if s[i] == '$' else "Rejected")