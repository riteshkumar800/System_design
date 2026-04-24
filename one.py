# def f(a):
#     l = b = w = c = 0

#     for i in open(a):
#         l += 1
#         if i.strip() == "":
#             b += 1
#         w += len(i.split())
#         c += len(i.replace(" ", "").replace("\n", ""))

#     print("Lines:", l)
#     print("Blank:", b)
#     print("Words:", w)
#     print("Chars:", c)

# f("input.txt")




##########################

# def student_data():
#     n = int(input("Enter number of students: "))
#     records = []

#     for _ in range(n):
#         roll = input("Roll No: ")
#         name = input("Name: ")
#         marks = float(input("Marks: "))
#         records.append((roll, name, marks))

#     # Write to file
#     with open("students.txt", "w") as f:

#         for r in records:
#             f.write(f"{r[0]} {r[1]} {r[2]}\n")

#     # Compute statistics
#     marks_list = [r[2] for r in records]

#     print("Average Marks:", sum(marks_list) / n)
#     print("Highest Marks:", max(marks_list))
#     print("Lowest Marks:", min(marks_list))


# # Function call
# student_data()

##########################

# def f(a, r):
#     l = open(a).readlines()
#     x = open(a, "w")

#     for i in range(len(l)):
#         if (i+1) not in r:
#             x.write(l[i])

#     x.close()

# f("input.txt", [3])


##########################

# def f(a, b):
#     x = open(a)
#     y = open(b, "w")

#     for i in x:
#         if i.strip()[:1] != "#":
#             y.write(i)

#     x.close()
#     y.close()

# f("s.txt", "d.txt")


##########################

# import keyword, re

# def f(a):
#     c = open(a).read()
#     t = re.findall(r'\w+|[^\s\w]', c)

#     for i in t:
#         if keyword.iskeyword(i):
#             print(i, "K")
#         elif i.isdigit():
#             print(i, "N")
#         elif i.isidentifier():
#             print(i, "ID")

#         elif i in "+-*/%=<>":
             
#              print(i, "-> Operator")
#         else:
#             print(i, "S")

# f("p.py")


##########################

# def f(a, b, c):
#     d = open(b).read().split()
#     w = open(a).read().split()

#     x = open(a, "w")
#     y = open(c, "w")

#     for i in w:
#         if i not in d:
#             x.write(i+" ")

#     for i in d:
#         y.write(i+" : "+str(w.count(i))+"\n")

#     x.close()
#     y.close()

# f("s.txt", "d.txt", "r.txt")

##########################

def check_ops(file_name):
    valid_ops = ['+', '-', '*', '/', '%', '=', '==', '!=', '<', '>', '<=', '>=']
    
    code = open(file_name).read().split()

    for token in code:
        if token in valid_ops:
            print(token, "-> Valid")
        elif any(ch in "+-*/%=<>" for ch in token):
            print(token, "-> Invalid")

check_ops("input.txt")


##########################


# import re

# def check_string(s):
#     if re.fullmatch("a*", s):
#         print("Matches a*")

#     if re.fullmatch("a*b+", s):
#         print("Matches a*b+")

#     if re.fullmatch("abb", s):
#         print("Matches abb")

# s = input("Enter string: ")
# check_string(s)

##########################



# import ply.lex as lex

# # tokens
# tokens = ('ID','NUM','OP','ASSIGN','KEY')

# keywords = ['if','else','while','for']

# # files
# kf = open("keywords.txt","w")
# idf = open("identifiers.txt","w")
# opf = open("operators.txt","w")
# nf = open("numbers.txt","w")

# # rules
# t_OP = r'\+|\-|\*|/'
# t_ASSIGN = r'='
# t_ignore = ' \t'

# def t_NUM(t):
#     r'\d+(\.\d+)?'
#     nf.write(t.value+"\n")
#     return t

# def t_ID(t):
#     r'[a-zA-Z_][a-zA-Z0-9_]*'
    
#     if len(t.value) > 10:
#         print("Long ID:", t.value)

#     if t.value in keywords:
#         kf.write(t.value+"\n")
#     else:
#         idf.write(t.value+"\n")
    
#     return t

# def t_newline(t):
#     r'\n+'
#     t.lexer.lineno += len(t.value)

# def t_comment1(t):
#     r'//.*'
#     pass

# def t_comment2(t):
#     r'/\*[\s\S]*?\*/'
#     pass

# def t_error(t):
#     print("Illegal:", t.value[0], "Line:", t.lineno)
#     t.lexer.skip(1)

# lexer = lex.lex()

# # input
# data = open("input.txt").read()
# lexer.input(data)

# for tok in lexer:
#     if tok.type == 'OP':
#         opf.write(tok.value+"\n")

##########################





# import ply.lex as lex

# tokens = ('ID',)

# t_ignore = ' \t'

# def t_ID(t):
#     r'[a-zA-Z_]+'
#     print(t.value)
#     return t

# def t_comment1(t):
#     r'//.*'
#     pass

# def t_comment2(t):
#     r'/\*[\s\S]*?\*/'
#     pass

# def t_error(t):
#     t.lexer.skip(1)

# lexer = lex.lex()
# lexer.input(open("input.txt").read())

# for tok in lexer:
#     pass

##########################
#8.1

# import ply.lex as lex
# import ply.yacc as yacc


# tokens = ('NUM', 'PLUS', 'MUL')

# t_PLUS = r'\+'
# t_MUL  = r'\*'
# t_ignore = ' \t'

# def t_NUM(t):
#     r'\d+'
#     t.value = int(t.value)
#     return t

# def t_error(t):
#     t.lexer.skip(1)

# lex.lex()


# def p_expr_plus(p):
#     'expr : expr PLUS term'
#     p[0] = p[1] + p[3]

# def p_expr_term(p):
#     'expr : term'
#     p[0] = p[1]

# def p_term_mul(p):
#     'term : term MUL NUM'
#     p[0] = p[1] * p[3]

# def p_term_num(p):
#     'term : NUM'
#     p[0] = p[1]

# def p_error(p):
#     print("Error")

# parser = yacc.yacc()


# # print(parser.parse("3+5*2"))
# s = input("Enter expression: ")

# try:
#     print("Result:", eval(s))
# except:
#     print("Invalid Expression")


#8.2

# def parse(s):
#     stack = ['$', 'E']
#     s = list(s) + ['$']
#     i = 0

#     table = {
#         ('E','i'): ['T','E\''],
#         ('E\'','+'): ['+','T','E\''],
#         ('E\'','$'): ['ε'],
#         ('T','i'): ['F','T\''],
#         ('T\'','+'): ['ε'],
#         ('T\'','*'): ['*','F','T\''],
#         ('T\'','$'): ['ε'],
#         ('F','i'): ['i']
#     }

#     while stack:
#         top = stack.pop()
#         if top == s[i]:
#             i += 1
#         elif (top, s[i]) in table:
#             rule = table[(top, s[i])]
#             if rule != ['ε']:
#                 stack += rule[::-1]
#         else:
#             print("Error")
#             return

#     print("Accepted")

# parse("i+i*i")


##########################

#9
# stack = []
# inp = "id+id*id$"

# rules = {"id":"E", "E+E":"E", "E*E":"E", "(E)":"E"}

# def reduce():
#     s = "".join(stack)
#     for r in rules:
#         if r in s:
#             i = s.find(r)
#             for _ in r:
#                 stack.pop(i)
#             stack.insert(i, rules[r])
#             print("Reduce:", r, "-> E")
#             return True
#     return False

# i = 0
# print("Stack\tInput\tAction")

# while i < len(inp):
#     stack.append(inp[i])
#     i += 1
#     print("".join(stack), "\t", inp[i:], "\tShift")

#     while reduce():
#         print("Stack:", stack)

# if stack == ['E']:
#     print("Accepted")
# else:
#     print("Rejected")



##########################

#10

# s = "i+*i"
# i = 0

# def E():
#     T()
#     if i < len(s) and s[i] == '+':
#         next_char()
#         E()

# def T():
#     F()
#     if i < len(s) and s[i] == '*':
#         next_char()
#         T()

# def F():
#     if s[i] == 'i':
#         next_char()
#     elif s[i] == '(':
#         next_char()
#         E()
#         if s[i] == ')':
#             next_char()
#         else:
#             error()
#     else:
#         error()

# def next_char():
#     global i
#     i += 1

# def error():
#     print("Rejected")
#     exit()

# E()

# if s[i] == '$':
#     print("Accepted")
# else:
    # print("Rejected")





# def parse(s):
#     try:
#         # Step 1: check allowed symbols
#         for ch in s:
#             if ch not in ['i', '+', '*', '(', ')', ' ']:
#                 return "Rejected"
        
#         # Step 2: replace i → 1
#         expr = s.replace('i', '1')
        
#         # Step 3: try evaluation
#         eval(expr)
#         return "Accepted"
    
#     except:
#         return "Error"

# # Driver
# inp = input("Enter expression: ")
# print(parse(inp))





# import ply.lex as lex
# import ply.yacc as yacc

# # Tokens
# tokens = ('NUM', 'PLUS', 'MUL')

# t_PLUS = r'\+'
# t_MUL  = r'\*'
# t_ignore = ' \t'

# def t_NUM(t):
#     r'\d+'
#     t.value = int(t.value)
#     return t

# def t_error(t):
#     t.lexer.skip(1)

# lex.lex()

# # Grammar
# def p_expr_plus(p):
#     'expr : expr PLUS term'
#     p[0] = p[1] + p[3]

# def p_expr_term(p):
#     'expr : term'
#     p[0] = p[1]

# def p_term_mul(p):
#     'term : term MUL NUM'
#     p[0] = p[1] * p[3]

# def p_term_num(p):
#     'term : NUM'
#     p[0] = p[1]

# def p_error(p):
#     print("Error")

# parser = yacc.yacc()

# # Input
# print(parser.parse("3+4*2"))




# s = "i+i+i$"
# i = 0

# def E():
#     global i
#     T()
#     if s[i] == '+':
#         i += 1
#         E()

# def T():
#     global i
#     F()
#     if s[i] == '*':
#         i += 1
#         T()

# def F():
#     global i
#     if s[i] == 'i':
#         i += 1
#     else:
#         print("Rejected"); exit()

# E()

# if s[i] == '$':
#     print("Accepted")
# else:
#     print("Rejected")



# stack = []
# inp = "id+id*id$"

# rules = {"id":"E", "E+E":"E", "E*E":"E", "(E)":"E"}

# def reduce():
#     s = "".join(stack)
#     for r in rules:
#         if r in s:
#             i = s.find(r)
#             for _ in r:
#                 stack.pop(i)
#             stack.insert(i, rules[r])
#             print("Reduce:", r, "-> E")
#             return True
#     return False

# i = 0
# print("Stack\tInput\tAction")

# while i < len(inp):
#     stack.append(inp[i])
#     i += 1
#     print("".join(stack), "\t", inp[i:], "\tShift")

#     while reduce():
#         print("Stack:", stack)

# if stack == ['E']:
#     print("Accepted")
# else:
#     print("Rejected")


import ply.lex as lex
import ply.yacc as yacc

# TOKENS
tokens = ('NUM','PLUS','MUL')

t_PLUS = r'\+'
t_MUL  = r'\*'
t_ignore = ' \t'

def t_NUM(t):
    r'\d+'
    t.value = int(t.value)
    return t

def t_error(t):
    t.lexer.skip(1)

lexer = lex.lex()

# GRAMMAR RULES (FIXED)
def p_e_plus(p):
    'e : e PLUS t'
    p[0] = p[1] + p[3]

def p_e_t(p):
    'e : t'
    p[0] = p[1]

def p_t_mul(p):
    't : t MUL NUM'
    p[0] = p[1] * p[3]

def p_t_num(p):
    't : NUM'
    p[0] = p[1]

def p_error(p):
    print("Error")

parser = yacc.yacc()

# INPUT
print(parser.parse("3+4*2"))