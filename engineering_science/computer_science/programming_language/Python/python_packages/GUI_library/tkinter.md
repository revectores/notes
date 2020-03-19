# tkinter

### 1. Window Control

##### # `mainloop`

`tkinter` is the bulit-in GUI library for Python. Here is how to create a root window:

```python
from tkinter import Tk
root = Tk()
root.mainloop()
```

We initialize an instance `root` from class `Tk`, which represents a window, and then use `mainloop` to keep it shown.



##### # Window Property

The title and size of the window can be reset by the `title` and `geometry` method of `Tk` object:

```python
root.title('window example')
root.geometry("500x200")
```

Notice that the parameter of the size of window is a **string**, which is absoluately a strange old-fashion design.



##### # Event bind

If you want to track the IO event over the window, use `bind` to active a callback function:

```python
def show_click_cord(event):
	print(event.x, event.y)

def show_key(event):
	print(event.char)


root.bind('<Button-1>', show_click_cord)
root.bind('<Key>', show_key)
# Notice that the since the function is passed as a parameter, do not add tailing brackets () otherwise it will be executed.
```

Here we bind a left-click event(`<Button-1>`) and keypress event(`<Key>`) to function show_click_cord and show_key respectively, which receive a argument event that containing the information about the event, i.e. (x,y) coordinate for click event and key value for keyboard event.

Here the 1 inside `<Button-1>` indicates the left-click, and 2 for middle, 3 for right respectively.

There're some more event like

- `<B1-Motion>`: the movement and hold down of left-click.

- `<ButtonRelease-1>`: the release of left-click.

- `<Enter>`: the cursor enter the widget. Notice this doesn't mean the `Enter` key is pressed, the `Enter` key is represented by `<Return>` instead!

There're more events, which cloud be referred in ==todo: url==.


