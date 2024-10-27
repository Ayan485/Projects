from tkinter import *

def click(event):
    global scval
    text = event.widget.cget("text")

    if text == '=':
        if scval.get().isdigit():
            value = int(scval.get())
        else:
            try:
                value = eval(screen.get())
            
            except Exception as e:
                value = "Error"

        scval.set(value)
        screen.update()

    elif text == 'C':
        scval.set("")
        screen.update()
    else:
        scval.set(scval.get()+text)
        screen.update()  

calc = Tk()
calc.geometry("455x480")
calc.title("Calculator")
calc.config(bg="#B6DBE6")
  

scval = StringVar()
scval.set("")
screen = Entry(calc, textvariable= scval, font= "Ariel 30 normal",bg="#1E80C1", border= 0)
screen.grid(row = 0,column=0, padx= 5, pady= 16, columnspan=4,)


list1 = ['%', '/', '**', 'C',  '7', '8', '9','*', '4', '5', '6', '-',  '1', '2', '3','+', '0', '00', '.', '=']

r=1
col=0
for item in list1:

    b = Button(calc, text= item, bg = '#4682B4', font='ComicSans 25 normal')
    b.grid(row=r, column= col, sticky= "ew",padx=2, pady= 5)
    b.bind("<Button-1>", click)

    col+=1
    
    if col==4:
        r +=1
        col = 0

calc.mainloop()