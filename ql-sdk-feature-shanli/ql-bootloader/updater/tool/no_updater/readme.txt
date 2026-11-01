1606L支持使用无updater分区的方案，此方案为将updater.bin压缩后放置于差分包的第一个包中，下载后再运行updater的功能。
采用此方案时，使用的adiff工具必须是verion: 5.6 , Dec  2 2022 / 10:32:17或更高的版本，使用的命令为：
          adiff.exe system_old.img system_new.img old_new.bin -u updater.bin

或者同样需要升级app时，指令为：
          adiff.exe system_old.img system_new.img old_new.bin -a1 customer customer_app.bin -u updater.bin

同之前有updater分区的方案相比，命令中需要增加 -u updater.bin；且adiff工具的同级目录下需要有对应的updater.bin，也就是本目录提供的bin
