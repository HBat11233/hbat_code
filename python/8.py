from tkinter import *
import tkinter.messagebox

class SudokuGUI:
    def __init__(self):
        window = Tk() #创建窗口
        window.title("Check Sudoku Solution")
        frame = Frame(window) #创建容器
        frame.pack() #放置容器
        #初始化数独的值，以二维列表放置数独的值，需要输入的数字先置0
        self.cells = [[5,3,0,0,7,0,0,0,0],
                      [6,0,0,1,9,5,0,0,0],
                      [0,9,8,0,0,0,0,6,0],
                      [8,0,0,0,6,0,0,0,3],
                      [4,0,0,8,0,3,0,0,1],
                      [7,0,0,0,2,0,0,0,6],
                      [0,6,0,0,0,0,2,8,0],
                      [0,0,0,4,1,9,0,0,5],
                      [0,0,0,0,8,0,0,7,9]
                      ]
        #讲数独的值映射到GUI界面上，以grid(row=,colum=)方式放置，表示放置某行某列
        for i in range(9):
            for j in range(9):
                if self.cells[i][j]==0: #如果该值需要用户输入，映射到输入框
                    #将映射到输入框的列表项类型转换为字符变量型
                    self.cells[i][j]= StringVar()
                    Entry(frame,width = 2,textvariable = self.cells[i][j]).grid(row = i,column = j)
                else: #如果该值不需要用户输入，映射到标签框
                    Label(frame,width = 2,text = self.cells[i][j]).grid(row = i,column = j)
        #设置按钮，并以validate为调用命令
        Button(window,text = "Validate",command = self.validate).pack()
        window.mainloop() #进入消息循环

    def validate(self):
        #初始化列表，用于作为数独判断的列表，其中[0]*9可得到9个0的列表
        '''
        values = []
        for i in range(9):
           values.append([0]*9)

        for i in range(9):
            for j in range(9):
                #判断列表中值的类型，如果是int型，直接赋值到values列表
                if type(self.cells[i][j]) == type(1):
                    values[i][j]= self.cells[i][j]
                else: #如果不是int型，先获得该字符变量值再转化为int型
                    values[i][j]= int(self.cells[i][j].get())
        #可注释上方values,用下方values做测试
        '''
        values = [[5,3,4,6,7,8,9,1,2],
                      [6,7,2,1,9,5,3,4,8],
                      [1,9,8,3,4,2,5,6,7],
                      [8,5,9,7,6,1,4,2,3],
                      [4,2,6,8,5,3,7,9,1],
                      [7,1,3,9,2,4,8,5,6],
                      [9,6,1,5,3,7,2,8,4],
                      [2,8,7,4,1,9,6,3,5],
                      [3,4,5,2,8,6,1,7,9]
                      ]
                      
        #如果数独是有效的则输出为有效，否则输出为无效
        if self.isValid(values):
            tkinter.messagebox.showinfo("check sudoku solution","the solution is valid")
        else:
            tkinter.messagebox.showinfo("check sudoku solution","the solution is invalid")
    #判断数独是否有效的方法，无效返回False,有效返回True
    def isValid(self,grid):
        fo=[False]*10
        for i in range(9):
            for j in range(9):
                if fo[grid[i][j]]:
                    return False
                else:
                    fo[grid[i][j]]=True
        fo=[False]*10
        for j in range(9):
            for i in range(9):
                if fo[grid[i][j]]:
                    return False
                else:
                    fo[grid[i][j]]=True
        for i in range(0,9,3):
            for j in range(0,9,3):
                fo=[False]*10
                for x in range(3):
                    for y in range(3):
                        if fo[grid[i+x][j+y]]:
                            return False
                        else:
                            fo[grid[i+x][j+y]]=True
        return True
     #检查grid[i][j]是否有效, 无效返回False,有效返回True
    def isValidAt(self,i,j,grid):
        pass
    
SudokuGUI()
