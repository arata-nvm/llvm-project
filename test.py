import re
import os
import glob

INCLUDE_DIRS = [
    "./mlir/include",
    "./llvm/include",
    "./clang/include",
    # "./libc",
    # "./llvm/test/TableGen/Common",
    # "./build/include",
    # "./flang/include",
    # "./build/tools/mlir/include",
    # "./mlir/examples/toy/Ch7/include",
    # "./mlir/examples/standalone/include",
]
RE_INCLUDE = re.compile('include "(.+)"')

with open("out.dot", "w") as f:
    f.write("digraph G {\n")
    for file_path in glob.glob("./mlir/**/*.td", recursive=True):
        print(f"[*] check: {file_path}")
        with open(file_path, "r") as f2:
            content = f2.read()

        for include_path in RE_INCLUDE.findall(content):
            current_dir = os.path.dirname(file_path)
            for include_dir in INCLUDE_DIRS + [current_dir]:
                path = os.path.join(include_dir, include_path)
                if os.path.exists(path):
                    print(f"    [+] found include: {path}")
                    f.write(
                        f'"{os.path.basename(file_path)}" -> "{os.path.basename(path)}"\n'
                    )
                    break
            else:
                print(f"    [-] not found include: {path}")
    f.write("}\n")
