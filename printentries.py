import pathlib
import os
import sys

os.chdir("hats")

files = list(pathlib.Path("").rglob("*.*"))

for file in files:
    file_name = str(file)
    
    print('AddEntry("rbxasset://fonts/'+file_name+'", "rbxasset://retros/hats/'+file_name+'");')
