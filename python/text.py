from tkinter import *
def hello():
    print("hello world!")
tk=Tk()
btn = Button(tk,text="click me",command=hello)
btn.pack()