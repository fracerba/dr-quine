# this comment is outside a function

def get_quine ():
    return [
        "# this comment is outside a function",
        "",
        "def get_quine ():",
        "    return [",
        "    ]",
        "",
        "if __name__ == __main__:",
        "    # this comment is inside main",
        "    lst = get_quine()",
        "    quote = str(chr(34))",
        "    comma = str(chr(44))",
        "    spaces = str(chr(32)) * 8",
        "    for x in range(len(lst)):",
        "        if x == 4:",
        "            for y in range(len(lst)):",
        "                print(spaces + quote + lst[y] + quote + comma)",
        "        if x == 6:",
        "            print(lst[x][:15] + quote + lst[x][15:23] + quote + lst[x][23:])",
        "        else:",
        "            print(lst[x])",
    ]

if __name__ == "__main__":
    # this comment is inside main
    lst = get_quine()
    quote = str(chr(34))
    comma = str(chr(44))
    spaces = str(chr(32)) * 8
    for x in range(len(lst)):
        if x == 4:
            for y in range(len(lst)):
                print(spaces + quote + lst[y] + quote + comma)
        if x == 6:
            print(lst[x][:15] + quote + lst[x][15:23] + quote + lst[x][23:])
        else:
            print(lst[x])
