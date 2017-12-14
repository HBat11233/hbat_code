from turtle import *
import turtle
import math

t=turtle.Turtle()
def tuan():
    r=200
    t.penup()
    dx=[1,1,-1,-1]
    dy=[1,-1,-1,1]
    t.penup()
    t.goto(r,0)
    t.pendown()
    for z in range(4):
        for i in range(r,-1,-1):
            a=r**2-i**2#r=100
            y=math.sqrt(a)
            j=y
            i=int(i*dx[z])
            j=int(j*dy[z])
            if(z%2):
                temp=i
                i=j
                j=temp
            t.goto(i,j)
            print((i,j))
t.speed(1)
#tuan()
t.circle(100,steps=5)
s=Screen()
s.exitonclick()
