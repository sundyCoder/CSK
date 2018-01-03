#!/usr/bin/env python
# encoding: utf-8
"""
@version: 2.7
@author: hyzhan
@time: 17-5-2 上午12:00
"""
import os
import argparse as ap
import re


if __name__ == "__main__":
    #  Argument Parser
    parser = ap.ArgumentParser()
    parser.add_argument("--image", help="Path to images",   
                        default="image/")
    parser.add_argument("--input", help="Path to xml files",  
                        default="dataset/")
    parser.add_argument("--output", help="Path to xml files",  
                        default="output/")
    args = vars(parser.parse_args())
    txt_path = os.path.join(args["input"], 'labels')
    output_path = os.path.join(args["input"], args["output"])
    if not os.path.isdir(output_path):
        os.makedirs(output_path)
    for root, root_dir_names, root_file_names in os.walk(txt_path):
        if len(root_file_names) > 0:
            res = r"^0\s+\d\.\d+\s+\d\.\d+\s+\d\.\d+\s+\d\.\d+.*$"
            processed_num = 0
            for txtfile in root_file_names:
                # print root,xmlfile
                txtfile_path = os.path.join(root, txtfile)
                data = open(txtfile_path).readlines()
                fid = open(os.path.join(output_path, txtfile), 'w')
                del_num = 0
                for line in data:
                    if len(re.findall(res, line)) == 0:
                        fid.write(line)
                    else:
                        del_num += 1
                fid.close()
                if del_num > 0:
                    processed_num += 1
                    print "file: %s , have %d lines, del %d lines" % (txtfile, len(data), del_num)
            print "files num: %d, processed: %d files" % (len(root_file_names), processed_num)
