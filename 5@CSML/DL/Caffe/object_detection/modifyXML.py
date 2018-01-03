#!/usr/bin/env python
# encoding: utf-8
"""
@version: 2.7
@author: hyzhan
@file: modifyXML.py
@time: 17-5-2 上午12:00
"""
import os
import argparse as ap
import xml.etree.ElementTree as ET


if __name__ == "__main__":
    # Argument Parser
    parser = ap.ArgumentParser()
    parser.add_argument("--image", help="Path to images",    # 打标签用的图片
                        default="image/")
    parser.add_argument("--xml", help="Path to xml files",   # 标签xml文件夹
                        default="xml/")
    parser.add_argument("--outputImage", help="Path to outputImage",  # 输出图片文件夹
                        default="JPEGImages/")
    parser.add_argument("--outputXML", help="Path to outputXML",   # 输出XML文件夹
                        default="Annotations/")
    parser.add_argument("--dataLen", help="data name len",   # 文件名长度，如000001.jpg
                        default=6)
    args = vars(parser.parse_args())
    images_path = args["image"]
    xml_path = args["xml"]
    for root, root_dir_names, root_file_names in os.walk(xml_path):
        if len(root_file_names) > 0:
            for xmlfile in root_file_names:
                # print root,xmlfile
                xmlfile_path = os.path.join(root, xmlfile)
                tree = ET.parse(xmlfile_path)     # 打开xml文档
                rootNode = tree.getroot()         # 获得root节点
                for country in rootNode.findall('object'):
                    rank = country.find('name').text
                    if rank == 'frence':
                        country.find('name').text = 'france'   # 修改XML文件中object节点name的text为frence的为france
                        print xmlfile
                tree.write(xmlfile_path)


