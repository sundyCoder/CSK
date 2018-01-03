#!/usr/bin/env python
# encoding: utf-8
"""
@version: 2.7
@author: hyzhan
@file: addData.py
@time: 17-5-2 上午10:00
"""
import os
import argparse as ap
import shutil

# 程序用法 python addData.py, 程序会将xml文件夹下的xml文件对应image文件夹下同名的图片分别保存
# Annotations和JPEGImages文件夹下，文件结构大致如下：
# .
# ├── Annotations
# ├── image
# ├── ImageSets
# │   └── Main
# ├── JPEGImages
# └── xml


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
    outputImage_path = os.path.join(os.getcwd(), args["outputImage"])
    outputXML_path = os.path.join(os.getcwd(), args["outputXML"])
    if not os.path.isdir(outputImage_path):
            os.mkdir(outputImage_path)
    if not os.path.isdir(outputXML_path):
            os.mkdir(outputXML_path)
    dataLen = args["dataLen"]
    preImage_list = os.listdir(outputImage_path)
    currentIndex = len(preImage_list) + 1   # 在已有图片基础上计算文件名
    xmlPath_dict = {}
    imagePath_dict = {}
    for root, root_dir_names, root_file_names in os.walk(xml_path):
        if len(root_file_names) > 0:
            for xmlfile in root_file_names:
                tmp_file_name = os.path.splitext(xmlfile)[0]
                xmlPath_dict[tmp_file_name] = os.path.join(root, xmlfile)  # 文件名-xml路径对应字典
    for root, root_dir_names, root_file_names in os.walk(images_path):
        if len(root_file_names) > 0:
            for imagefile in root_file_names:
                tmp_file_name = os.path.splitext(imagefile)[0]
                imagePath_dict[tmp_file_name] = os.path.join(root, imagefile)  # 文件名-图片路径对应字典
    for xmlfile in xmlPath_dict:
        newXMLPath = os.path.join(outputXML_path, str(currentIndex).zfill(dataLen)+'.xml')  # 输出XML文件路径
        newImagePath = os.path.join(outputImage_path, str(currentIndex).zfill(dataLen)+'.jpg')  # 输出图片路径
        # print xmlPath_dict[xmlfile],newXMLPath
        # print imagePath_dict[xmlfile],newImagePath
        shutil.copyfile(xmlPath_dict[xmlfile], newXMLPath)  # 移动或复制XML文件，并改名
        shutil.copyfile(imagePath_dict[xmlfile], newImagePath)  # 移动或复制图片，并改名
        # os.system("cp "+str(xmlPath_dict[xmlfile])+" "+newXMLPath)
        # os.system("cp "+str(imagePath_dict[xmlfile])+" "+newImagePath)
        currentIndex += 1
    # os.system("rm -r "+xml_path+"*")  # 为了避免重复添加可删除已添加的XML文件，该功能尚未测试
    # os.system("rm -r "+images_path+"*")  # 为了避免重复添加可删除已添加的图片，该功能尚未测试




