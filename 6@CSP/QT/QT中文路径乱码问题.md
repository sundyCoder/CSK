# Sundy

### QT中文路径乱码问题

1. 先将QString转换为GBK格式的QByteArray字符数组
2. 再拿到char *
3. 如下方式：

	`//解决中文路径不能解析的问题 `
	`QString dir_ = "xxx中文路径";`
	`QByteArray gbk_s = QTextCodec::codecForName("gbk")->fromUnicode(dir_);`
	`std::string dataDir = gbk_s.data();`

	![](https://i.imgur.com/VTdcjLu.png)