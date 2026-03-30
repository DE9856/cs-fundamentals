#program to back up a directory into a zip file


import os
import zipfile
zf = zipfile.ZipFile("zipfile location","w")
for dirname,subdirs,files in os.walk("directory to zip"):
    zf.write(dirname)
    for filename in files:
        zf.write(os.path.join(dirname,filename))
zf.close()
