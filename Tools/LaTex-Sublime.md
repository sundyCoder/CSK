# ![](http://i.imgur.com/S7xBFja.png)Sundy #
## ![](http://i.imgur.com/S7xBFja.png)LaTex + ST3 Windows环境配置 ##

### 1.Sublime Text3 ###
**Sublime Text3**: [http://appnee.com/sublime-text-3-universal-license-keys-collection-for-win-mac-linux/](http://appnee.com/sublime-text-3-universal-license-keys-collection-for-win-mac-linux/)

**MiKTeX**:一款 Windows 平台下的 LaTeX 工具套件，包含了 TeX 以及相关的程序。
[http://www.miktex.org/download](http://www.miktex.org/download)

**Sumatra PDF** 一款免费的 PDF 阅读器，LaTeXTools 默认使用它来预览生成的 PDF。[http://www.sumatrapdfreader.org/download-free-pdf-viewer.html](http://www.sumatrapdfreader.org/download-free-pdf-viewer.html)

复制期中的任意一个License激活ST3

	—– BEGIN LICENSE —–
	Anthony Sansone
	Single User License
	EA7E-878563
	28B9A648 42B99D8A F2E3E9E0 16DE076E
	E218B3DC F3606379 C33C1526 E8B58964
	B2CB3F63 BDF901BE D31424D2 082891B5
	F7058694 55FA46D8 EFC11878 0868F093
	B17CAFE7 63A78881 86B78E38 0F146238
	BAE22DBB D4EC71A1 0EC2E701 C7F9C648
	5CF29CA3 1CB14285 19A46991 E9A98676
	14FD4777 2D8A0AB6 A444EE0D CA009B54
	—— END LICENSE ——
	 
	—– BEGIN LICENSE —–
	Alexey Plutalov
	Single User License
	EA7E-860776
	3DC19CC1 134CDF23 504DC871 2DE5CE55
	585DC8A6 253BB0D9 637C87A2 D8D0BA85
	AAE574AD BA7D6DA9 2B9773F2 324C5DEF
	17830A4E FBCF9D1D 182406E9 F883EA87
	E585BBA1 2538C270 E2E857C2 194283CA
	7234FF9E D0392F93 1D16E021 F1914917
	63909E12 203C0169 3F08FFC8 86D06EA8
	73DDAEF0 AC559F30 A6A67947 B60104C6
	—— END LICENSE ——
### 2.Install Package Contro l###
方法:[https://packagecontrol.io/installation#st3](https://packagecontrol.io/installation#st3)
打开ST3,按快捷键Ctrl +｀，输入

	import urllib.request,os,hashlib; h = '2915d1851351e5ee549c20394736b442' + '8bc59f460fa1548d1514676163dafc88'; pf = 'Package Control.sublime-package'; ipp = sublime.installed_packages_path(); urllib.request.install_opener( urllib.request.build_opener( urllib.request.ProxyHandler()) ); by = urllib.request.urlopen( 'http://packagecontrol.io/' + pf.replace(' ', '%20')).read(); dh = hashlib.sha256(by).hexdigest(); print('Error validating download (got %s instead of %s), please try manual install' % (dh, h)) if dh != h else open(os.path.join( ipp, pf), 'wb' ).write(by)
然后回车即可，等待Package Control安装好之后，如下图:
![](http://i.imgur.com/66RPzWd.png)

### 3.安装LaTeXTools插件
安装好 Package Control 之后，按组合键 Ctrl+Shift+P，然后再输入 install，选择 Package Control: install package。进入库后，搜索所需的包，然后选择安装就好了。我们需要使用的包是 LaTeXTools。
![](http://i.imgur.com/Q0kguAx.png)

### 4.配置LaTeXTools
打开 Sublime Text，按下快捷键 Ctrl+Shift+P，调出 Package Control，搜索“LaTeXTools: Reconfigure and migrate settings”并回车即可。这一步实际上在User目录下创建了名为“LaTeXTools.sublime-settings”的配置文件。（Very Important！！！）
### 5.配置编译器 ###
将前面的LaTeXTools.sublime-settings文件用Sublime Text 2打开，配置"texpath"选项，将MikTex的路径添加进去就可以了，如下图所示。"sumatra"选项不用配置，添加到系统PATH中更方便。

### 6.配置SumatraPDF ###
1. ：将 SumatraPDF 的主程序目录添加到环境变量PATH，这一步很重要，否则下一步会无法进行。
	
	在系统环境变量中加入: C:\Program Files\SumatraPDF
3. ：打开命令提示符，执行以下命令：（将其中的安装路径替换成你实际的安装路径）
	
	sumatrapdf.exe -inverse-search "\"C:\Program Files\Sublime Text 3\sublime_text.exe\" \"%f:%l\""

### 7.使用 ###
进行到现在，理论上应该就已经配置好了。以后就可以用 Sublime Text 写 LaTeX 了。写完之后保存（新建的文件一定要先保存，否则 build 是无效的），然后按下快捷键 Ctrl+B，Sublime Text 就会自动调用 LaTeXTools 的 build 系统来进行编译，然后自动打开 SumatraPDF 进行预览。之后每次修改后只要 Ctrl+B 一下，SumatraPDF 里的内容就会自动更新。
同时在SumatraPDF 中双击相应的内容，会调到Sublime Text 2中对应的位置。

### 8.插件的安装 ###
Ctrl + Shift + P回车，输入pi,然后选择Package Control: Install Package回车,然后输入自己需要安装的插件即可，常用的插件有

1. Markdown(当然我个人还是喜欢单独用Markdown Pad2，非常方便)

