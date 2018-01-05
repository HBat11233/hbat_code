from tkinter import *
class sierpinski_triangle:
    def __init__(self):
        self.window=Tk()
        self.window.title('Sierpinski triangle')
        self.width=800
        self.height=600
        self.canvas=Canvas(self.window,width=self.width,height=self.height)
        self.canvas.pack()
        self.frame1=Frame(self.window)
        self.frame1.pack(side=LEFT)
        self.label1=Label(self.frame1,text="Enter n:")
        self.label1.pack(side=LEFT)
        self.n=StringVar()
        self.entry=Entry(self.frame1,textvariable = self.n)
        self.entry.pack(side=LEFT)
        self.button=Button(self.frame1,text="Display Sierpinski triangle",command=self._dis)
        self.button.pack(side=LEFT)

    def _dis(self):
        self.canvas.delete("line")
        self._mad(int(self.n.get()),0,self.width/2,10,10,self.height-10,self.width-10,self.height-10)
        return 0

    def _mad(self,n,jk=0,a1=200,a2=50,b1=330,b2=175,c1=70,c2=175):
        if(n>0):
            p=[(a1+b1)/2,(a2+b2)/2]
            k=[(a1+c1)/2,(a2+c2)/2]
            h=[(c1+b1)/2,(c2+b2)/2]
            if(jk==0):
                self.canvas.create_line(a1,a2,b1,b2,tags="line")
                self.canvas.create_line(a1,a2,c1,c2,tags="line")
                self.canvas.create_line(c1,c2,b1,b2,tags="line")
                n-=1
            if(jk%2==0 and (n-1>=0 or jk!=0)):
                jk+=1
                n-=1
                self.canvas.create_line(p[0],p[1],k[0],k[1],tags="line")
                self.canvas.create_line(k[0],k[1],h[0],h[1],tags="line")
                self.canvas.create_line(p[0],p[1],h[0],h[1],tags="line")
            if(jk%2==1 and n>0):
                self._mad(n,jk+1,p[0],p[1],k[0],k[1],a1,a2)
                self._mad(n,jk+1,p[0],p[1],h[0],h[1],b1,b2)
                self._mad(n,jk+1,h[0],h[1],k[0],k[1],c1,c2)
        return 0

    def _mainloop(self):
        self.window.mainloop()
        return 0

def _main():
    a=sierpinski_triangle()
    a._mainloop()

_main()
