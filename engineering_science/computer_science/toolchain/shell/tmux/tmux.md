# Tmux

### 1. Introduction

Tmux is a screen manager tool for shell. With the help of this, we can create multiple sessions, windows, split windows to panes, and jump between windows/panes with a convenient shortcut, and make each sessions a different workspace.



### 2. Basic Usage

##### # Session

Session is a context with multiple windows, to create a new session with name, use

```shell
tmux new-session -s [session_name]
tmux new -s [session_name]
```

If NAME is not provided, a number will be allocated to it.

After create the session you can enter it by the attach command:


```shell
tmux attach -t [session_name]
```

Type a simple `tmux` will automatically create a session(with default number name) and enter it.

Notice that since tmux holds that the session should be nested with care, so when you already inside a session you have to unset a variable set by current tmux instance named `$TMUX` to add nested session. We strongly not recommand you nest the session since in practice there're some confusing behaviours.

If you're not intentionally create nested session but a paralleled one, you can use the `:new -s [session_name]` command in the tmux command line(by first press <prefix> key) just like what you've done in the command line.

If you want to quit current session, use `<prefix>d`. This will not kill the session, but only exit and it will be kept in the session list so you'll able to return to it later.

If you want to toggle among sessions, there's no need for quit and attach again, instead you can use the `<prefix>s` to quick toggle. Type the number listed before the session name you'll be sent to where you want to be.




##### # Window

Inside a session you can create window, use `<prefix>c`, and you'll be bring to the new window instantly. Each window will be marked as a number, when you need to jump to another window, use `<prefix><num>` to jump.

 

##### # Pane

Use `<prefix>%` to split new pane vertically and `<prefix>"` to split new pane horzantally.

Notice that if there's no specific reason, you should not use pane to do the function of split inside vim, the inner split solution provides more convient way to act together. Take care about whather a split window is split by the editor or by window-manager like tmux. 







