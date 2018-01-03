#!/usr/bin/env python
# encoding: utf-8

"""
@version: 2.7
@author: hyzhan
@file: delete_file_firstRow.py
@time: 17-2-8 上午10:12
"""

import os
import argparse as ap


def delete_file_row(path):
    filelist = os.listdir(path)
    filelist = sorted(filelist)
    Newdir = os.path.join(path, '../Annotations')
    if not os.path.exists(Newdir):
        os.makedirs(Newdir)
    for files in filelist:
        Olddir = os.path.join(path, files)
        if os.path.isdir(Olddir):
            continue
        old_file = open(Olddir, 'r').readlines()
        new_file = open(os.path.join(Newdir, files), 'w')
        new_file.writelines(old_file[1:])


if __name__ == "__main__":
    # Argument Parser
    parser = ap.ArgumentParser()
    parser.add_argument("--file", help="Path to file", default="xml")
    args = vars(parser.parse_args())
    file_path = args["file"]
    delete_file_row(file_path)
