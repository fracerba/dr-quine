FILE = "Grace_kid.py"
STR = "FILE = {0}{2}{0}{1}STR = {0}{3}{0}{1}MAIN = STR.format(str(chr(34)), str(chr(10)), FILE, STR){1}{1}#this program is a quine, it self-replicates its own source code when executed.{1}{1}try:{1}    with open (FILE, {0}w{0}) as f:{1}        f.write(MAIN){1}except Exception as e:{1}    print({0}An error occurred:{0}, e)"
MAIN = STR.format(str(chr(34)), str(chr(10)), FILE, STR)

#this program is a quine, it self-replicates its own source code when executed.

try:
    with open (FILE, "w") as f:
        f.write(MAIN)
except Exception as e:
    print("An error occurred:", e)