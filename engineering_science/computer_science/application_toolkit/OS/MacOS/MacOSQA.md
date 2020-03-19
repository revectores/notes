# MacOS QA

##### # How to upgrade `bash` macOS on  to `bash 4.0`?

Notices that apple official won't update it to 4.0 because of the restriction of `GPLv3` protocol which applied to `bash 4.0`. While you can still install it by youself through yourself. See the solutions:

>  https://apple.stackexchange.com/questions/193411/update-bash-to-version-4-0-on-osx

Update: Newest MacOS Catalina had reset the default command line program into `zsh` instead of `bash` because of this restriction.



##### # What's the different between macOS Terminal and Linux's command line?

It's based on the shell you chose. As we know macOS based on darwin, which is a branch of Unix. Through there're lots of differences between Unix and Linux, you should notice that a POSIX shell(bash for linux and macOS before 10.14, and zsh for macOS after 10.15) is chosen as the default shell both (while you can still change the shell to others), so it's dependend on the types of command, if we're talking about the default shell, then all the command standardized by the POSIX must be common in both system. 



##### # How to check the device information?

Click the apple logo on the lefttop, and press <kbd>Option</kbd> key, the "About This Mac" choice will be replaced as "System Information", this is the entrance for more specific device information.



