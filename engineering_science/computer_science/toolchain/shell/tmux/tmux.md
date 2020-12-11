# Tmux

### 1. Introduction

Tmux is a screen manager tool for shell. With the help of this, we can create multiple sessions, windows, split windows to panes, and jump between windows/panes with a convenient shortcut, and make each sessions a different workspace.



### 2. Basic Usage

You can always use `<prefix> ?` to get the full list of tmux key bindings.



##### # Session

Session is a context with multiple windows, to create a new session with name, use

```shell
tmux new-session -s [session_name]
tmux new -s [session_name]
```

If NAME is not provided, a number will be allocated to it.

After create the session you can enter it by:


```shell
tmux attach -t [session_name]
```

Type a simple `tmux` will automatically create a session(with number assigned as name) and enter it.

Normally we won't need nested session. The variable set by current tmux instance named `$TMUX` must be unset to add nested session if you intend to. We strongly not recommand this since there can be confusing behaviours in nested sessions.

To create a new parallel session, use `:new-session -s [session_name]` in the tmux command line (by first press <prefix> key).

`<prefix> d`: detach from the session. The session will run in backgound.

`<prefix> s`: toggle among sessions. Type the number listed before the session name you'll be sent to where you want to be.



##### # Window

`<prefix> c`: create new window, the newly created window will be assigned as the least unused natural number.

`<prefix> <num>`: jump to window with corresponding number.

`<prefix> w`: display and toggle among all windows (of all sessions).

`<prefix> &`: kill the active window. If the window is the only window of the session, the session will be killed.



##### # Pane

`<prefix> %`: split active pane horizontally and `<prefix>"` to split the active pane vertically.

`<prefix> x`: kill the active pane. If the active pane is the only pane of the window, the window will be killed.

`<prefix> z`: zoom in/out the pane. This can be quite useful when you want to copy something from the pane.

`<prefix> !`: send the active pane to a new window.



##### # Layout

`<prefix> M-[Up|Down|Left|Right]`: resize the active pane.

`<prefix> M-[1|2|3|4|5]`: use the built-in layout configuration:

1. even-horizontal layout
2. even-vertical layout
3. main-horizontal layout
4. main-vertical layout
5. tiled layout



##### # Copy Mode

Note that we can not allowed to scoll up/down in tmux as we usually do outside it, and copy text can be extremely hard since text from other parallel vertical panes will also be selected. Copy mode is provided as a solution. Use `<prefix> [` to enter the copy mode.

The copy mode is similar to vim selection mode. We are able to use the vim-style cursor moving (`hjkl` and `Ctrl+[Arrow]`) and selection method (`Ctrl+v`) to navigate and copy the output history. After selected, use `Enter` to copy the selected text to register and exit copy mode, and use `Ctrl+]` to paste.







### 3. Tmux Configuration

The default tmux configuration file is placed in `~/.tmux.conf`. The most useful configuration that must be done by all vim users is to remap the arrow key when navigating panes to `hjkl`:

```
bind h select-pane -L
bind j select-pane -D
bind k select-pane -U
bind l select-pane -R
```
