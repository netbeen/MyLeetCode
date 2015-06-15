#shell编程题：
#要求给定一个文件file.txt，现实该文件的第十行。
#首先用sed工具，-n是安静模式，即不输出其他行，10p是输出第10行的命令。
sed -n 10p file.txt
