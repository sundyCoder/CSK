#Sundy
###插值的方法(Interpolation Methods)
###1.Introduction
Interpolation  is  the  process  of  determining  the  values  of  a  function  at 
positions lying between its samples. It achieves this process by fitting a continuous 
function  through  the  discrete  input  samples.

The  interpolation  techniques  are  divided  into  two  categories,  **deterministic**  and 
**statistical interpolation** techniques. The diference is that deterministic interpolation 
techniques assume a certain variability between the sample points, such as linearity 
in  case  of  linear  interpolation.  Statistical  interpolation  methods  approximate  the 
signal by minimizing the estimation error. This approximation process may result 
in  original  sample  values  not  being  replicated

###Deterministic interpolation techniques
Several  interpolation  techniques  have  been  developed  and  can  be  found  in  the 
literature. The most commonly used methods are the **nearest neighbor**, **linear** and 
**spline**  interpolation  techniques.  Less  common  are  the  polynomial  and  Lagrange 
interpolation methods.

1.   'linear'   (default) linear interpolation
1.   'nearest'  nearest neighbor interpolation
1.   'next'     next neighbor interpolation
1.   'previous' previous neighbor interpolation
1.   'spline'   piecewise cubic spline interpolation (SPLINE)
1.   'pchip'    shape-preserving piecewise cubic interpolation
1.   'cubic'    same as 'pchip'
1.   'v5cubic'  the cubic interpolation from MATLAB 5, which does not extrapolate and uses 'spline' if X is not equally spaced.  

Example:

	x = 0:10; 
	y = sin(x); 
	xi = 0:.25:10; 
	% yi = interp1(x,y,xi,'linear'); 
	% yi = interp1(x,y,xi,'nearest'); 
	% yi = interp1(x,y,xi,'next'); 
	% yi = interp1(x,y,xi,'previous'); 
	% yi = interp1(x,y,xi,'spline'); 
	% yi = interp1(x,y,xi,'cubic'); 
	% yi = interp1(x,y,xi,'v5cubic'); 
	plot(x,y,'o',xi,yi)
 
###2.Nearest Neighbor
![](http://i.imgur.com/LyQsvKz.jpg)

![](http://i.imgur.com/Ws2ew3Z.png)

![](http://i.imgur.com/zJzLSWY.png)

###3.Linear Interpolation
![](http://i.imgur.com/r7W8Hog.jpg)

![](http://i.imgur.com/DuosHJ2.png)

![](http://i.imgur.com/bm8ycIc.png)

###4.Cubic
![](http://i.imgur.com/YJNJYbu.jpg)

![](http://i.imgur.com/xasknZS.png)

###5.Spline
![](http://i.imgur.com/GMP2YQX.jpg)
![](http://i.imgur.com/6B5rWRv.png)

![](http://i.imgur.com/57hoaFS.png)
![](http://i.imgur.com/fanXpFz.png)

