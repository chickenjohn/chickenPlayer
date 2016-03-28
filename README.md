#Chicken Player v1.0
-----------
##What is Chicken Player
Chicken Player is a simple shell for MPlayer developed by Qt 5.5. This simple program can run under the Qt environment in Windows. By using MPlayer slave mood, a wide range of formats are supported well. 

To get more information about Qt and MPlayer, please visit following websites:

>Qt: [http://www.qt.io](http://www.qt.io "qt")

>MPlayer: [http://www.mplayerhq.hu/design7/news.html](http://www.mplayerhq.hu/design7/news.html "mplayer")

##How to use it?
Once you run the program, what you'll see might looks like the picture below:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/index.png)

###Open a file
Open a file from the menu bar:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/openfile.PNG)

Then you may use it like using most media players.
###Adding a subtitle
Use "Tools" selection to load a subtitle. The coding format of it must be GB2312. Add a subtitle like this:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/sub.PNG)

###Show the terminal
Since the MPlayer is working in the background, you may check what it is printing out by using a Terminal:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/ter.PNG)

Turing on the Terminal by:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/ter_choose.PNG)

**NOTICE: YOU MAY RUN THE TERMINAL ONLY AFTER YOU LOAD A VIDEO**

##Dependence
Most of the dependence have been embraced in the local directory. You may check this. The program is mainly depends on:

>Qt 5.5 for Windows

>MinGW

>OpenGL

>MPlayer 

However, there are some chances that you get this while running:

![](https://github.com/chickenjohn/chickenPlayer/blob/master/pics/wrong.PNG)

If any part of the player is getting green, it means that MPlayer is not working under the OpenGL mode. You might check if OpenGL is installed on your PC. It mainly happens while you are running on Windows 7 or later version of Windows.

##More to say
It might make no sense to develop such a rough, simple GUI shell for MPlayer, but I guess it is more like being a sample of Qt or Muitimedia application. Maybe this will help you if you are an entirely fresh man to Qt or programming. 

##Get more info
To fetch more information about this little thing, you may contact me:

>Email: chickenjohn93@hust.edu.cn
