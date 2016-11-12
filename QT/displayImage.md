###QT中使用OpenCV在空间中显示图片

作者：TY Sun
链接：https://zhuanlan.zhihu.com/p/23612980
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

本文与QImage和QPixmap无关。
一般来说将OpenCV的图片显示在QT控件上，需要转成QImage和QPixmap，但是在图片尺寸较大时，转换的过程可能比较慢。下面是不通过QT的图片类，直接在控件上显示cv::Mat的方法。

title是std::string，可以认为是一个自定义的窗口名字。

        cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
        HWND hWnd = (HWND)cvGetWindowHandle(title.c_str());
        HWND hParent = GetParent(hWnd);
        SetParent(hWnd, new_hParent);
        ShowWindow(hParent, SW_HIDE);
上面的代码是创建一个标题是title的窗口，并更换这个窗口的父对象为HWND new_hParent代表的对象，同时隐藏原来的父对象。之后只要记住这个title，用cv::imshow(title, mat)就可以在其上显示图片了。

那么如何获得一个QT控件的HWND呢？只要用(HWND)widget->winId()就可以了