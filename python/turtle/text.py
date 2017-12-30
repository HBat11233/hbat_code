from turtle import *
from time import *

def watch():
    wc=Turtle()
    wc.hideturtle()
    tracer(False)
    wc.up()
    wc.goto(0,-150)
    wc.down()
    #wc.circle(150)
    wc.up()
    wc.goto(0,0)
    wc.down()
    for i in range(0,361):
        wc.up()
        wc.forward(150)
        wc.down()
        if(i%90==0):
            wc.width(5)
            wc.forward(30)
        elif(i%45==0):
            wc.width(2.5)
            wc.forward(20)
        elif(i%5==0):
            wc.width(1.5)
            wc.forward(10)
        wc.left(1)
        wc.up()
        wc.goto(0,0)
        wc.down()
        wc.width(1)
    tracer(True)

def hi(a):
    a.reset()
    t=asctime()
    t=t.split()
    t=t[3].split(':')
    htime=((int(t[0])*3600+int(t[1])*60+int(t[2]))/(3600*12))*360
    tracer(False)
    a.left(90)
    a.right(htime)
    a.up()
    a.forward(120)
    a.down()
    a.width(7)
    a.forward(20)
    tracer(True)

def mi(a):
    a.reset()
    t=asctime()
    t=t.split()
    t=t[3].split(':')
    htime=((int(t[0])*3600+int(t[1])*60+int(t[2]))/(3600))*360
    tracer(False)
    a.left(90)
    a.right(htime)
    a.up()
    a.forward(100)
    a.down()
    a.width(5)
    a.forward(40)
    tracer(True)

def si(a):
    a.reset()
    t=asctime()
    t=t.split()
    t=t[3].split(':')
    htime=((int(t[0])*3600+int(t[1])*60+int(t[2]))/(60))*360
    tracer(False)
    a.left(90)
    a.right(htime)
    a.up()
    a.forward(80)
    a.down()
    a.width(4)
    a.forward(60)
    tracer(True)

def sleeps(lenth):
    time1=clock()
    time2=clock()
    while(time2-time1<lenth):
        time2=clock()
watch()
ha=Turtle()
ma=Turtle()
sa=Turtle()
while True:
    ha.hideturtle()
    ma.hideturtle()
    sa.hideturtle()
    sleeps(1)
    hi(ha)
    mi(ma)
    si(sa)
s=Screen()
s.exitonclick()