Qt-CK2-Launcher
===============

This is open source launcher for Crusader Kings 2 based on QT4.

Thread on Paradox Plaza:
http://forum.paradoxplaza.com/forum/showthread.php?660805-Qt-Alternative-CK2-Launcher

## How to Install
You could get pre-compiled deb/rpm packages from openSUSE Build Service.
Both x86 and x86_64 builds available for these distibutions:
* Ubuntu 12.10 "Quantal", 12.04 "Precise", 11.10 "Oneiric", 11.04 "Natty", 10.04 "Lucid"
* Debian 6.0 "Squeeze"
* Fedora: 18 "Spherical Cow", 17 "Beefy Miracle", 16 "Verne"
* Mandriva: 2011, 2010.1, 2010
* openSUSE: Factory, 12.2, 12.1, 11.4
* SLE 11: SP2, SP1

Page with links and inststucions:
http://software.opensuse.org/download.html?project=home:sxxxx&package=qtck2launcher

Extra information about builds could be forund here:
https://build.opensuse.org/package/show?package=qtck2launcher&project=home%3Asxxxx

I cant test all these builds, so if something not working let me know.

## Compile on Ubuntu 12.04:
```no-highlight
sudo apt-get install git build-essential libqt4-dev qt4-qmake libqtwebkit-dev
git clone https://github.com/sxxx/Qt-CK2-Launcher.git
cd Qt-CK2-Launcher
qmake
make
```

## Use launcher with Steam:
Launcher is fully compitable with Steam overlay and DLC activation.

If you want to use launcher with Steam there is how-to:
1. Run Steam and open "Library" window.
2. Right click on CK2 in game list.
3. Click on "Properties"
4. Push "Set launch options..." button
5. Input "qtck2launcher %command%" and push "Ok"
6. Now launcher will work like in Windows version.

## Nice screenshot:
![Main Window](https://github.com/sxxx/Qt-CK2-Launcher/blob/master/screenshot.png?raw=true)
