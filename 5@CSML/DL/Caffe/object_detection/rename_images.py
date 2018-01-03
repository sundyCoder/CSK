import os
import argparse as ap


def rename(path, num, start_index):
    filelist = os.listdir(path)
    filelist = sorted(filelist)
    print filelist
    img = start_index
    Newdir = os.path.join(path, '../JPEGImages')
    if not os.path.exists(Newdir):
        os.makedirs(Newdir)
    for files in filelist:
        Olddir = os.path.join(path, files)
        if os.path.isdir(Olddir):
            continue
        filename = os.path.splitext(files)[0]
        filetype = os.path.splitext(files)[1]
        print filename, img
        if str(img).zfill(num) == filename:
            img = img + 1
            continue
        New_name = str(img).zfill(num) + filetype
        os.system("cp " + Olddir + ' ' + os.path.join(Newdir, New_name))
        img = img + 1


if __name__ == "__main__":
    # Argument Parser
    parser = ap.ArgumentParser()
    parser.add_argument("--images", help="Path to images",
                        default="tmp/")
    parser.add_argument("--start", help="Path to images",
                        default=1)
    args = vars(parser.parse_args())
    images_path = args["images"]
    start_index = args["start"]
    rename(images_path, 6, start_index)
