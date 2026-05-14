import os, subprocess

if __name__ == "__main__":
    n = 5
    if n > 0:
        if os.path.exists("Sully_5.py"):
            n -= 1
        file = "Sully_" + str(n) + ".py"
        quine = "import os, subprocess{0}{0}if __name__ == {1}__main__{1}:{0}{2}n = {4}{0}{2}if n > 0:{0}{2}{2}if os.path.exists({1}Sully_5.py{1}):{0}{2}{2}{2}n -= 1{0}{2}{2}file = {1}Sully_{1} + str(n) + {1}.py{1}{0}{2}{2}quine = {1}{3}{1}{0}{2}{2}quine = quine.format(str(chr(10)), str(chr(34)), str(chr(32)) * 4, quine, n){0}{2}{2}try:{0}{2}{2}{2}with open (file, {1}w{1}) as f:{0}{2}{2}{2}{2}f.write(quine){0}{2}{2}{2}subprocess.run([{1}python3{1}, file]){0}{2}{2}except Exception as e:{0}{2}{2}{2}print({1}An error occurred:{1}, e)"
        quine = quine.format(str(chr(10)), str(chr(34)), str(chr(32)) * 4, quine, n)
        try:
            with open (file, "w") as f:
                f.write(quine)
            subprocess.run(["python3", file])
        except Exception as e:
            print("An error occurred:", e)