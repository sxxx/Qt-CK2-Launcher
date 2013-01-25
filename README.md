Qt-CK2-Launcher
===============

This is open source launcher for Crusader Kings 2 based on QT4.

Thread on Paradox Plaza:
http://forum.paradoxplaza.com/forum/showthread.php?660805-Qt-Alternative-CK2-Launcher


Screenshot:
![Main Windows](https://github.com/sxxx/Qt-CK2-Launcher/blob/master/screenshot.png?raw=true)


## How to Install
On Ubuntu 12.04:

#### 1. Compile launcher:
```no-highlight
sudo apt-get install git build-essential libqt4-dev qt4-qmake
git clone https://github.com/sxxx/Qt-CK2-Launcher.git
cd Qt-CK2-Launcher
qmake
make
```
#### 2. Edit qtck2launcher.ini:
There is lot of people who probably want to change **gamepath** and **runBinary** values.
Lot of people have Steam games installed to
>~/.local/share/Steam/SteamApps/common/
Not like my default:
>~/Steam/SteamApps/common/

#### 3. Move files:
Move qtck2launcher and qtck2launcher.ini to "_/Steam/SteamApps/common/Crusader Kings II_" directory.

#### 4. Use launcher with Steam:
If you want to use launcher with Steam you need to rename original "ck2" executable and update **runBinary** value inside ini file. 
>runBinary=./ck2original
Than you need to rename (or make symlink/hardlink) qtck2launcher to "ck2".

Now you could run game though Steam and you will see launcher.
After you press "Start CK2 button" game will start like on Windows, Steam overlay will be fully functionaly.

