What is the difference between **access key** and the **acceleration key**?

**Notes**: The accelearation key also alias as the **shorcut** usually.

The access key will usually shown as use `Alt+key` to quickly selected some menu item, 

访问键能够利用Alt+指定key快速调出并选中某个菜单项，显示上表现为在菜单项之后的一个带有下划线的字母key，利用Alt+key调用. 访问键通常不需要编写代码实现.

加速键能够利用指定键位组合立刻执行某个菜单项的功能，通常会显示在菜单项文本之后，在Windows SDK中需要通过代码实现，在wx中则不需要.



不需要. 只需要在菜单项文本之后加上\t并添加指定键位组合即可，例如"&Copy\tCtrl-C"即可建立加速键Ctrl+C实现菜单项中Copy的功能.

可以用位置表示(MF_BYPOSITION)或用id表示(MF_BYCOMMAND)

