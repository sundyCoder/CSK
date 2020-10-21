# linux command
## 1. Edit binary files

 vim data.bin
 
 %!xxd    -> to edit the binary
 
 %!xxd -r -> convert to binary
 
 :wq      -> save and quite.
  
## 2. find and rm

 eg: find all the exe and remove them. 
 
 find . -name "*.exe" -exec rm '{}' \\\;

