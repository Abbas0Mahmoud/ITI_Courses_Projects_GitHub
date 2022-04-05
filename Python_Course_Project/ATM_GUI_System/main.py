from tkinter import *

#########################################################################################
Bank_Clients_DataBase = {}
#########################################################################################
Clients_ID = [215321701332,
              203659302214,
              126355700193,
              201455998011,
              201122369851,
              201356788002,
              203366789564,
              201236787812]
#########################################################################################
Clients_Name = ['Ahmed Abdelrazek Mohamed',
                'Salma Mohamed Foaad',
                'Adel Khaled Abdelrahman',
                'Saeed Amin Elsawy',
                'Amir Salama Elgendy',
                'Wael Mohamed khairy',
                'Mina Sameh Bishoy',
                'Omnia Ahmed Awad']
#########################################################################################
Clients_Password = [1783,
                    1390,
                    1214,
                    2001,
                    8935,
                    3420,
                    1179,
                    1430]
#########################################################################################
Clients_Balance = [3500166,
                   520001,
                   111000,
                   1200,
                   178933,
                   55000,
                   18000,
                   180350]
#########################################################################################
DataBase_LoopCounter = 0
Max_DataBase_LoopCounter = len(Clients_ID) - 1
while DataBase_LoopCounter <= Max_DataBase_LoopCounter:
    Clients_Data = {'Name': str(Clients_Name[DataBase_LoopCounter]),
                    'Password': int(Clients_Password[DataBase_LoopCounter]),
                    'Balance': int(Clients_Balance[DataBase_LoopCounter])}
    Temp_Dict_1 = {int(Clients_ID[DataBase_LoopCounter]): Clients_Data}
    Bank_Clients_DataBase.update(Temp_Dict_1)
    DataBase_LoopCounter += 1
#########################################################################################
# Auxiliary Dict
Clients_ID_Password_Trials = {}
Auxiliary_Dict_LoopCounter = 0
MAx_Auxiliary_Dict_LoopCounter = len(Clients_ID) - 1
while Auxiliary_Dict_LoopCounter <= MAx_Auxiliary_Dict_LoopCounter:
    Temp_Dict_2 = {Clients_ID[Auxiliary_Dict_LoopCounter]: {'Trials': 0}}
    Clients_ID_Password_Trials.update(Temp_Dict_2)
    Auxiliary_Dict_LoopCounter += 1

########################################################################################################################
# Login Window Function Block (HomePage) Parameters
########################################################################################################################
global Login_Window
global Login_Window_Account_Number_Entry
global Login_Window_Enter_Button
global Login_Window_Password_Entry
global Login_Window_Password_Enter_Button
########################################################################################################################

########################################################################################################################
# Login Window Account Number Enter Button Block Parameters
########################################################################################################################
Client_Account_Number = 0
########################################################################################################################

########################################################################################################################
# Login Window Account Password Enter Button Block
########################################################################################################################
Trials_Flag = 0
Trials_Counter = 0
########################################################################################################################

########################################################################################################################
# Options Window Call Function Block Parameters
########################################################################################################################
global Options_Window
########################################################################################################################

########################################################################################################################
# Cash Withdraw Function Block Parameters
########################################################################################################################
global Cash_Withdraw_Window
global Cash_Withdraw_Window_Money_To_Withdraw_Entry
global Cash_Withdraw_Window_Enter_Button
Client_Balance = 0
Max_Withdraw_Per_Transaction = 5000
########################################################################################################################

########################################################################################################################
# Balance Inquiry Function Block Parameters
########################################################################################################################
global Balance_Inquiry_Window
########################################################################################################################

########################################################################################################################
# Password Change Function Block Parameters
########################################################################################################################
global Password_Change_Window
global Password_Change_Window_Client_Name_Entry
global Password_Change_Window_Password_Enter_Entry
global Password_Change_Window_Password_Re_Enter_Entry
global Password_Change_Window_Password_Confirm_Button
########################################################################################################################

########################################################################################################################
# Fawry Service Function Block Parameters
########################################################################################################################
global Fawry_Service_Window
########################################################################################################################

########################################################################################################################
# Orange Recharge Function Block Parameters
########################################################################################################################
global Orange_Recharge_Window
global Orange_Recharge_Window_Phone_Number_Entry
global Orange_Recharge_Window_Recharge_Amount_Entry
global Orange_Recharge_Window_Recharge_Button
global Orange_Recharge_Window_Exit_Button
########################################################################################################################

########################################################################################################################
# Etisalat Recharge Function Block Parameters
########################################################################################################################
global Etisalat_Recharge_Window
global Etisalat_Recharge_Window_Phone_Number_Entry
global Etisalat_Recharge_Window_Recharge_Amount_Entry
global Etisalat_Recharge_Window_Recharge_Button
global Etisalat_Recharge_Window_Exit_Button
########################################################################################################################

########################################################################################################################
# Vodafone Recharge Function Block Parameters
########################################################################################################################
global Vodafone_Recharge_Window
global Vodafone_Recharge_Window_Phone_Number_Entry
global Vodafone_Recharge_Window_Recharge_Amount_Entry
global Vodafone_Recharge_Window_Recharge_Button
global Vodafone_Recharge_Window_Exit_Button
########################################################################################################################

########################################################################################################################
# We Recharge Function Block Parameters
########################################################################################################################
global We_Recharge_Window
global We_Recharge_Window_Phone_Number_Entry
global We_Recharge_Window_Recharge_Amount_Entry
global We_Recharge_Window_Recharge_Button
global We_Recharge_Window_Exit_Button


########################################################################################################################

# ______________________________________________________________________________________________________________________#
# Exit Function Block Start
# ______________________________________________________________________________________________________________________#
def Exit_Func():
    Options_Window.destroy()
    Login_Window_Func()


# ______________________________________________________________________________________________________________________#
# Exit Function Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Fawry Service Block Start
# ______________________________________________________________________________________________________________________#
def Fawry_Service_Func():
    #########################################################################################
    Options_Window.destroy()
    #########################################################################################
    global Fawry_Service_Window
    Fawry_Service_Window = Tk()
    Fawry_Service_Window.geometry("800x500")
    Fawry_Service_Window.config(background="#1D212E")
    Fawry_Service_Window.title("Password_Change_Window")
    Fawry_Service_Window_Label = Label(Fawry_Service_Window,
                                       text="Fawry_Service_Window",
                                       background="#1D212E",
                                       foreground="white",
                                       font=('Arial', 30, 'bold'))
    Fawry_Service_Window_Label.place(x=180, y=40)
    #########################################################################################
    Fawry_Service_Window_Orange_RButton = Radiobutton(Fawry_Service_Window,
                                                      text="Orange Recharge",
                                                      font=('Arial', 14, 'bold'),
                                                      background="white",
                                                      foreground="black",
                                                      relief=RAISED,
                                                      width=15,
                                                      padx=10,
                                                      pady=10,
                                                      indicatoron=0,
                                                      command=Orange_Recharge_Func)
    Fawry_Service_Window_Orange_RButton.place(x=80, y=250)
    #########################################################################################
    Fawry_Service_Window_Etisalat_RButton = Radiobutton(Fawry_Service_Window,
                                                        text="Etisalat Recharge",
                                                        font=('Arial', 14, 'bold'),
                                                        background="white",
                                                        foreground="black",
                                                        relief=RAISED,
                                                        width=15,
                                                        padx=10,
                                                        pady=10,
                                                        indicatoron=0,
                                                        command=Etisalat_Recharge_Func)
    Fawry_Service_Window_Etisalat_RButton.place(x=80, y=350)
    #########################################################################################
    Fawry_Service_Window_Vodafone_RButton = Radiobutton(Fawry_Service_Window,
                                                        text="Vodafone Recharge",
                                                        font=('Arial', 14, 'bold'),
                                                        background="white",
                                                        foreground="black",
                                                        relief=RAISED,
                                                        width=15,
                                                        padx=10,
                                                        pady=10,
                                                        indicatoron=0,
                                                        command=Vodafone_Recharge_Func)
    Fawry_Service_Window_Vodafone_RButton.place(x=520, y=250)
    #########################################################################################
    Fawry_Service_Window_We_RButton = Radiobutton(Fawry_Service_Window,
                                                  text="We Recharge",
                                                  font=('Arial', 14, 'bold'),
                                                  background="white",
                                                  foreground="black",
                                                  relief=RAISED,
                                                  width=15,
                                                  padx=10,
                                                  pady=10,
                                                  indicatoron=0,
                                                  command=We_Recharge_Func)
    Fawry_Service_Window_We_RButton.place(x=520, y=350)
    #########################################################################################
    Fawry_Service_Window.mainloop()


########################################################################################################################
# Orange Recharge Function Block Start
########################################################################################################################
def Orange_Recharge_Func():
    Fawry_Service_Window.destroy()
    #########################################################################################
    global Orange_Recharge_Window
    Orange_Recharge_Window = Tk()
    Orange_Recharge_Window.geometry("800x500")
    Orange_Recharge_Window.config(background="#1D212E")
    Orange_Recharge_Window.title("Password_Change_Window")
    Orange_Recharge_Window_Label = Label(Orange_Recharge_Window,
                                         text="Orange Recharge Window",
                                         background="#1D212E",
                                         foreground="white",
                                         font=('Arial', 30, 'bold'))
    Orange_Recharge_Window_Label.place(x=150, y=40)
    #########################################################################################
    Orange_Recharge_Window_Phone_Number_Entry_Label = Label(Orange_Recharge_Window,
                                                            text="Enter Phone Number",
                                                            background="#1D212E",
                                                            foreground="white",
                                                            font=('Arial', 14))
    Orange_Recharge_Window_Phone_Number_Entry_Label.place(x=50, y=180)
    #########################################################################################
    global Orange_Recharge_Window_Phone_Number_Entry
    Orange_Recharge_Window_Phone_Number_Entry = Entry(Orange_Recharge_Window,
                                                      font=('Arial', 14))
    Orange_Recharge_Window_Phone_Number_Entry.place(x=280, y=180)
    #########################################################################################
    Orange_Recharge_Window_Recharge_Amount_Entry_Label = Label(Orange_Recharge_Window,
                                                               text="Enter Recharge Amount",
                                                               background="#1D212E",
                                                               foreground="white",
                                                               font=('Arial', 14))
    Orange_Recharge_Window_Recharge_Amount_Entry_Label.place(x=50, y=220)
    #########################################################################################
    global Orange_Recharge_Window_Recharge_Amount_Entry
    Orange_Recharge_Window_Recharge_Amount_Entry = Entry(Orange_Recharge_Window,
                                                         font=('Arial', 14))
    Orange_Recharge_Window_Recharge_Amount_Entry.place(x=280, y=220)
    #########################################################################################
    global Orange_Recharge_Window_Recharge_Button
    Orange_Recharge_Window_Recharge_Button = Button(Orange_Recharge_Window,
                                                    text="Recharge",
                                                    font=('Arial', 10, 'bold'),
                                                    background="white",
                                                    foreground="black",
                                                    relief=RAISED,
                                                    width=20,
                                                    command=Orange_Recharge_Window_Recharge_Button_Func)
    Orange_Recharge_Window_Recharge_Button.place(x=540, y=221)

    #########################################################################################
    #########################################################################################
    def Orange_Recharge_Window_Exit_Button_Func():
        Orange_Recharge_Window.destroy()
        Login_Window_Func()

    #########################################################################################
    global Orange_Recharge_Window_Exit_Button
    Orange_Recharge_Window_Exit_Button = Button(Orange_Recharge_Window,
                                                text='Exit',
                                                font=('Arial', 10, 'bold'),
                                                background="white",
                                                foreground="black",
                                                relief=RAISED,
                                                width=20,
                                                command=Orange_Recharge_Window_Exit_Button_Func)
    Orange_Recharge_Window_Exit_Button.place(x=540, y=450)
    Orange_Recharge_Window_Exit_Button.config(state=DISABLED)
    #########################################################################################
    Orange_Recharge_Window.mainloop()


########################################################################################################################
def Orange_Recharge_Window_Recharge_Button_Func():
    Orange_Recharge_Window_Phone_Number_Entry.config(state=DISABLED)
    Orange_Recharge_Window_Recharge_Amount_Entry.config(state=DISABLED)
    Orange_Recharge_Window_Recharge_Button.config(state=DISABLED)
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    print(Client_Account_Number_Cast)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    Recharge_Amount = Orange_Recharge_Window_Recharge_Amount_Entry.get()
    Phone_Number = Orange_Recharge_Window_Phone_Number_Entry.get()
    #########################################################################################
    if len(Phone_Number) == 11 and str(Phone_Number).startswith("012"):
        #########################################################################################
        if int(Recharge_Amount) <= Client_Balance:
            #########################################################################################
            Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance'] = Client_Balance - int(Recharge_Amount)
            #########################################################################################
            Recharge_Done_Label = Label(Orange_Recharge_Window,
                                        background="#1D212E",
                                        foreground="white",
                                        text="Recharge is Done",
                                        font=('Arial', 18, 'bold'))
            Recharge_Done_Label.place(x=260, y=350)
            Orange_Recharge_Window_Exit_Button.config(state=NORMAL)
        else:
            Insufficient_Balance_Label = Label(Orange_Recharge_Window,
                                               background="#1D212E",
                                               foreground="white",
                                               text="No Sufficient Balance",
                                               font=('Arial', 18, 'bold'))
            Insufficient_Balance_Label.place(x=260, y=350)
            Orange_Recharge_Window_Exit_Button.config(state=NORMAL)

    else:
        #########################################################################################

        Invalid_Phone_Number_Window = Toplevel()
        Invalid_Phone_Number_Window.geometry("500x200")
        Invalid_Phone_Number_Window.config(background="white")
        Invalid_Phone_Number_Window.title("Invalid_Phone_Number_Window")
        Invalid_Phone_Number_Window_Label = Label(Invalid_Phone_Number_Window,
                                                  text="Invalid Phone Number",
                                                  background="white",
                                                  foreground="#1D212E",
                                                  font=('Arial', 20, 'bold'))
        Invalid_Phone_Number_Window_Label.pack()
        #########################################################################################
        Invalid_Phone_Number_Window.after(2000, Invalid_Phone_Number_Window.destroy)
        #########################################################################################
        Orange_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Orange_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Orange_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Orange_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Orange_Recharge_Window_Recharge_Amount_Entry.delete(0, END)

        #########################################################################################
        """
        Invalid_Phone_Number_Window_Label = Label(Orange_Recharge_Window,
                                                  text="Error Message: Invalid Phone Number",
                                                  background="#1D212E",
                                                  foreground="white",
                                                  font=('Arial', 18, 'bold'))
        Invalid_Phone_Number_Window_Label.place(x=180, y=320)
        Orange_Recharge_Window.after(2500, Invalid_Phone_Number_Window_Label.destroy)
        Orange_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Orange_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Orange_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Orange_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Orange_Recharge_Window_Recharge_Amount_Entry.delete(0, END)
        """
        #########################################################################################


########################################################################################################################
# Orange Recharge Function Block END
########################################################################################################################

########################################################################################################################
# Etisalat Recharge Function Block Start
########################################################################################################################
def Etisalat_Recharge_Func():
    Fawry_Service_Window.destroy()
    #########################################################################################
    global Etisalat_Recharge_Window
    Etisalat_Recharge_Window = Tk()
    Etisalat_Recharge_Window.geometry("800x500")
    Etisalat_Recharge_Window.config(background="#1D212E")
    Etisalat_Recharge_Window.title("Password_Change_Window")
    Etisalat_Recharge_Window_Label = Label(Etisalat_Recharge_Window,
                                           text="Etisalat Recharge Window",
                                           background="#1D212E",
                                           foreground="white",
                                           font=('Arial', 30, 'bold'))
    Etisalat_Recharge_Window_Label.place(x=150, y=40)
    #########################################################################################
    Etisalat_Recharge_Window_Phone_Number_Entry_Label = Label(Etisalat_Recharge_Window,
                                                              text="Enter Phone Number",
                                                              background="#1D212E",
                                                              foreground="white",
                                                              font=('Arial', 14))
    Etisalat_Recharge_Window_Phone_Number_Entry_Label.place(x=50, y=180)
    #########################################################################################
    global Etisalat_Recharge_Window_Phone_Number_Entry
    Etisalat_Recharge_Window_Phone_Number_Entry = Entry(Etisalat_Recharge_Window,
                                                        font=('Arial', 14))
    Etisalat_Recharge_Window_Phone_Number_Entry.place(x=280, y=180)
    #########################################################################################
    Etisalat_Recharge_Window_Recharge_Amount_Entry_Label = Label(Etisalat_Recharge_Window,
                                                                 text="Enter Recharge Amount",
                                                                 background="#1D212E",
                                                                 foreground="white",
                                                                 font=('Arial', 14))
    Etisalat_Recharge_Window_Recharge_Amount_Entry_Label.place(x=50, y=220)
    #########################################################################################
    global Etisalat_Recharge_Window_Recharge_Amount_Entry
    Etisalat_Recharge_Window_Recharge_Amount_Entry = Entry(Etisalat_Recharge_Window,
                                                           font=('Arial', 14))
    Etisalat_Recharge_Window_Recharge_Amount_Entry.place(x=280, y=220)
    #########################################################################################
    global Etisalat_Recharge_Window_Recharge_Button
    Etisalat_Recharge_Window_Recharge_Button = Button(Etisalat_Recharge_Window,
                                                      text="Recharge",
                                                      font=('Arial', 10, 'bold'),
                                                      background="white",
                                                      foreground="black",
                                                      relief=RAISED,
                                                      width=20,
                                                      command=Etisalat_Recharge_Window_Recharge_Button_Func)
    Etisalat_Recharge_Window_Recharge_Button.place(x=540, y=221)

    #########################################################################################
    #########################################################################################
    def Etisalat_Recharge_Window_Exit_Button_Func():
        Etisalat_Recharge_Window.destroy()
        Login_Window_Func()

    #########################################################################################
    global Etisalat_Recharge_Window_Exit_Button
    Etisalat_Recharge_Window_Exit_Button = Button(Etisalat_Recharge_Window,
                                                  text='Exit',
                                                  font=('Arial', 10, 'bold'),
                                                  background="white",
                                                  foreground="black",
                                                  relief=RAISED,
                                                  width=20,
                                                  command=Etisalat_Recharge_Window_Exit_Button_Func)
    Etisalat_Recharge_Window_Exit_Button.place(x=540, y=450)
    Etisalat_Recharge_Window_Exit_Button.config(state=DISABLED)
    #########################################################################################
    Etisalat_Recharge_Window.mainloop()


########################################################################################################################
def Etisalat_Recharge_Window_Recharge_Button_Func():
    Etisalat_Recharge_Window_Phone_Number_Entry.config(state=DISABLED)
    Etisalat_Recharge_Window_Recharge_Amount_Entry.config(state=DISABLED)
    Etisalat_Recharge_Window_Recharge_Button.config(state=DISABLED)
    #########################################################################################
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    print(Client_Account_Number_Cast)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    Recharge_Amount = Etisalat_Recharge_Window_Recharge_Amount_Entry.get()
    Phone_Number = Etisalat_Recharge_Window_Phone_Number_Entry.get()
    #########################################################################################
    if len(Phone_Number) == 11 and str(Phone_Number).startswith("014"):
        #########################################################################################
        if int(Recharge_Amount) <= Client_Balance:
            #########################################################################################
            Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance'] = Client_Balance - int(Recharge_Amount)
            #########################################################################################
            Recharge_Done_Label = Label(Etisalat_Recharge_Window,
                                        background="#1D212E",
                                        foreground="white",
                                        text="Recharge is Done",
                                        font=('Arial', 18, 'bold'))
            Recharge_Done_Label.place(x=260, y=350)
            Etisalat_Recharge_Window_Exit_Button.config(state=NORMAL)
        else:
            Insufficient_Balance_Label = Label(Etisalat_Recharge_Window,
                                               background="#1D212E",
                                               foreground="white",
                                               text="No Sufficient Balance",
                                               font=('Arial', 18, 'bold'))
            Insufficient_Balance_Label.place(x=260, y=350)
            Etisalat_Recharge_Window_Exit_Button.config(state=NORMAL)

    else:
        #########################################################################################

        Invalid_Phone_Number_Window = Toplevel()
        Invalid_Phone_Number_Window.geometry("500x200")
        Invalid_Phone_Number_Window.config(background="white")
        Invalid_Phone_Number_Window.title("Invalid_Phone_Number_Window")
        Invalid_Phone_Number_Window_Label = Label(Invalid_Phone_Number_Window,
                                                  text="Invalid Phone Number",
                                                  background="white",
                                                  foreground="#1D212E",
                                                  font=('Arial', 20, 'bold'))
        Invalid_Phone_Number_Window_Label.pack()
        #########################################################################################
        Invalid_Phone_Number_Window.after(2000, Invalid_Phone_Number_Window.destroy)
        #########################################################################################
        Etisalat_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Etisalat_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Etisalat_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Etisalat_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Etisalat_Recharge_Window_Recharge_Amount_Entry.delete(0, END)

        #########################################################################################
        """
        Invalid_Phone_Number_Window_Label = Label(Etisalat_Recharge_Window,
                                                  text="Error Message: Invalid Phone Number",
                                                  background="#1D212E",
                                                  foreground="white",
                                                  font=('Arial', 18, 'bold'))
        Invalid_Phone_Number_Window_Label.place(x=180, y=320)
        Etisalat_Recharge_Window.after(2500, Invalid_Phone_Number_Window_Label.destroy)
        Etisalat_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Etisalat_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Etisalat_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Etisalat_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Etisalat_Recharge_Window_Recharge_Amount_Entry.delete(0, END)
        """
        #########################################################################################


########################################################################################################################
# Etisalat Recharge Function Block END
########################################################################################################################

########################################################################################################################
# Vodafone Recharge Function Block Start
########################################################################################################################
def Vodafone_Recharge_Func():
    Fawry_Service_Window.destroy()
    #########################################################################################
    global Vodafone_Recharge_Window
    Vodafone_Recharge_Window = Tk()
    Vodafone_Recharge_Window.geometry("800x500")
    Vodafone_Recharge_Window.config(background="#1D212E")
    Vodafone_Recharge_Window.title("Password_Change_Window")
    Vodafone_Recharge_Window_Label = Label(Vodafone_Recharge_Window,
                                           text="Vodafone Recharge Window",
                                           background="#1D212E",
                                           foreground="white",
                                           font=('Arial', 30, 'bold'))
    Vodafone_Recharge_Window_Label.place(x=150, y=40)
    #########################################################################################
    Vodafone_Recharge_Window_Phone_Number_Entry_Label = Label(Vodafone_Recharge_Window,
                                                              text="Enter Phone Number",
                                                              background="#1D212E",
                                                              foreground="white",
                                                              font=('Arial', 14))
    Vodafone_Recharge_Window_Phone_Number_Entry_Label.place(x=50, y=180)
    #########################################################################################
    global Vodafone_Recharge_Window_Phone_Number_Entry
    Vodafone_Recharge_Window_Phone_Number_Entry = Entry(Vodafone_Recharge_Window,
                                                        font=('Arial', 14))
    Vodafone_Recharge_Window_Phone_Number_Entry.place(x=280, y=180)
    #########################################################################################
    Vodafone_Recharge_Window_Recharge_Amount_Entry_Label = Label(Vodafone_Recharge_Window,
                                                                 text="Enter Recharge Amount",
                                                                 background="#1D212E",
                                                                 foreground="white",
                                                                 font=('Arial', 14))
    Vodafone_Recharge_Window_Recharge_Amount_Entry_Label.place(x=50, y=220)
    #########################################################################################
    global Vodafone_Recharge_Window_Recharge_Amount_Entry
    Vodafone_Recharge_Window_Recharge_Amount_Entry = Entry(Vodafone_Recharge_Window,
                                                           font=('Arial', 14))
    Vodafone_Recharge_Window_Recharge_Amount_Entry.place(x=280, y=220)
    #########################################################################################
    global Vodafone_Recharge_Window_Recharge_Button
    Vodafone_Recharge_Window_Recharge_Button = Button(Vodafone_Recharge_Window,
                                                      text="Recharge",
                                                      font=('Arial', 10, 'bold'),
                                                      background="white",
                                                      foreground="black",
                                                      relief=RAISED,
                                                      width=20,
                                                      command=Vodafone_Recharge_Window_Recharge_Button_Func)
    Vodafone_Recharge_Window_Recharge_Button.place(x=540, y=221)

    #########################################################################################
    #########################################################################################
    def Vodafone_Recharge_Window_Exit_Button_Func():
        Vodafone_Recharge_Window.destroy()
        Login_Window_Func()

    #########################################################################################
    global Vodafone_Recharge_Window_Exit_Button
    Vodafone_Recharge_Window_Exit_Button = Button(Vodafone_Recharge_Window,
                                                  text='Exit',
                                                  font=('Arial', 10, 'bold'),
                                                  background="white",
                                                  foreground="black",
                                                  relief=RAISED,
                                                  width=20,
                                                  command=Vodafone_Recharge_Window_Exit_Button_Func)
    Vodafone_Recharge_Window_Exit_Button.place(x=540, y=450)
    Vodafone_Recharge_Window_Exit_Button.config(state=DISABLED)
    #########################################################################################
    Vodafone_Recharge_Window.mainloop()


########################################################################################################################
def Vodafone_Recharge_Window_Recharge_Button_Func():
    Vodafone_Recharge_Window_Phone_Number_Entry.config(state=DISABLED)
    Vodafone_Recharge_Window_Recharge_Amount_Entry.config(state=DISABLED)
    Vodafone_Recharge_Window_Recharge_Button.config(state=DISABLED)
    #########################################################################################
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    print(Client_Account_Number_Cast)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    Recharge_Amount = Vodafone_Recharge_Window_Recharge_Amount_Entry.get()
    Phone_Number = Vodafone_Recharge_Window_Phone_Number_Entry.get()
    #########################################################################################
    if len(Phone_Number) == 11 and str(Phone_Number).startswith("010"):
        #########################################################################################
        if int(Recharge_Amount) <= Client_Balance:
            #########################################################################################
            Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance'] = Client_Balance - int(Recharge_Amount)
            #########################################################################################
            Recharge_Done_Label = Label(Vodafone_Recharge_Window,
                                        background="#1D212E",
                                        foreground="white",
                                        text="Recharge is Done",
                                        font=('Arial', 18, 'bold'))
            Recharge_Done_Label.place(x=260, y=350)
            Vodafone_Recharge_Window_Exit_Button.config(state=NORMAL)
        else:
            Insufficient_Balance_Label = Label(Vodafone_Recharge_Window,
                                               background="#1D212E",
                                               foreground="white",
                                               text="No Sufficient Balance",
                                               font=('Arial', 18, 'bold'))
            Insufficient_Balance_Label.place(x=260, y=350)
            Vodafone_Recharge_Window_Exit_Button.config(state=NORMAL)

    else:
        #########################################################################################

        Invalid_Phone_Number_Window = Toplevel()
        Invalid_Phone_Number_Window.geometry("500x200")
        Invalid_Phone_Number_Window.config(background="white")
        Invalid_Phone_Number_Window.title("Invalid_Phone_Number_Window")
        Invalid_Phone_Number_Window_Label = Label(Invalid_Phone_Number_Window,
                                                  text="Invalid Phone Number",
                                                  background="white",
                                                  foreground="#1D212E",
                                                  font=('Arial', 20, 'bold'))
        Invalid_Phone_Number_Window_Label.pack()
        #########################################################################################
        Invalid_Phone_Number_Window.after(2000, Invalid_Phone_Number_Window.destroy)
        Vodafone_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Vodafone_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Vodafone_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Vodafone_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Vodafone_Recharge_Window_Recharge_Amount_Entry.delete(0, END)

        #########################################################################################
        """
        Invalid_Phone_Number_Window_Label = Label(Vodafone_Recharge_Window,
                                                  text="Error Message: Invalid Phone Number",
                                                  background="#1D212E",
                                                  foreground="white",
                                                  font=('Arial', 18, 'bold'))
        Invalid_Phone_Number_Window_Label.place(x=180, y=320)
        Vodafone_Recharge_Window.after(2500, Invalid_Phone_Number_Window_Label.destroy)
        Vodafone_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        Vodafone_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        Vodafone_Recharge_Window_Recharge_Button.config(state=NORMAL)
        Vodafone_Recharge_Window_Phone_Number_Entry.delete(0, END)
        Vodafone_Recharge_Window_Recharge_Amount_Entry.delete(0, END)
        """
        #########################################################################################


########################################################################################################################
# Vodafone Recharge Function Block END
########################################################################################################################

########################################################################################################################
# We Recharge Function Block Start
########################################################################################################################
def We_Recharge_Func():
    Fawry_Service_Window.destroy()
    #########################################################################################
    global We_Recharge_Window
    We_Recharge_Window = Tk()
    We_Recharge_Window.geometry("800x500")
    We_Recharge_Window.config(background="#1D212E")
    We_Recharge_Window.title("Password_Change_Window")
    We_Recharge_Window_Label = Label(We_Recharge_Window,
                                     text="We Recharge Window",
                                     background="#1D212E",
                                     foreground="white",
                                     font=('Arial', 30, 'bold'))
    We_Recharge_Window_Label.place(x=150, y=40)
    #########################################################################################
    We_Recharge_Window_Phone_Number_Entry_Label = Label(We_Recharge_Window,
                                                        text="Enter Phone Number",
                                                        background="#1D212E",
                                                        foreground="white",
                                                        font=('Arial', 14))
    We_Recharge_Window_Phone_Number_Entry_Label.place(x=50, y=180)
    #########################################################################################
    global We_Recharge_Window_Phone_Number_Entry
    We_Recharge_Window_Phone_Number_Entry = Entry(We_Recharge_Window,
                                                  font=('Arial', 14))
    We_Recharge_Window_Phone_Number_Entry.place(x=280, y=180)
    #########################################################################################
    We_Recharge_Window_Recharge_Amount_Entry_Label = Label(We_Recharge_Window,
                                                           text="Enter Recharge Amount",
                                                           background="#1D212E",
                                                           foreground="white",
                                                           font=('Arial', 14))
    We_Recharge_Window_Recharge_Amount_Entry_Label.place(x=50, y=220)
    #########################################################################################
    global We_Recharge_Window_Recharge_Amount_Entry
    We_Recharge_Window_Recharge_Amount_Entry = Entry(We_Recharge_Window,
                                                     font=('Arial', 14))
    We_Recharge_Window_Recharge_Amount_Entry.place(x=280, y=220)
    #########################################################################################
    global We_Recharge_Window_Recharge_Button
    We_Recharge_Window_Recharge_Button = Button(We_Recharge_Window,
                                                text="Recharge",
                                                font=('Arial', 10, 'bold'),
                                                background="white",
                                                foreground="black",
                                                relief=RAISED,
                                                width=20,
                                                command=We_Recharge_Window_Recharge_Button_Func)
    We_Recharge_Window_Recharge_Button.place(x=540, y=221)

    #########################################################################################
    #########################################################################################
    def We_Recharge_Window_Exit_Button_Func():
        We_Recharge_Window.destroy()
        Login_Window_Func()

    #########################################################################################
    global We_Recharge_Window_Exit_Button
    We_Recharge_Window_Exit_Button = Button(We_Recharge_Window,
                                            text='Exit',
                                            font=('Arial', 10, 'bold'),
                                            background="white",
                                            foreground="black",
                                            relief=RAISED,
                                            width=20,
                                            command=We_Recharge_Window_Exit_Button_Func)
    We_Recharge_Window_Exit_Button.place(x=540, y=450)
    We_Recharge_Window_Exit_Button.config(state=DISABLED)
    #########################################################################################
    We_Recharge_Window.mainloop()


########################################################################################################################
def We_Recharge_Window_Recharge_Button_Func():
    We_Recharge_Window_Phone_Number_Entry.config(state=DISABLED)
    We_Recharge_Window_Recharge_Amount_Entry.config(state=DISABLED)
    We_Recharge_Window_Recharge_Button.config(state=DISABLED)
    #########################################################################################
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    print(Client_Account_Number_Cast)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    Recharge_Amount = We_Recharge_Window_Recharge_Amount_Entry.get()
    Phone_Number = We_Recharge_Window_Phone_Number_Entry.get()
    #########################################################################################
    if len(Phone_Number) == 11 and str(Phone_Number).startswith("015"):
        #########################################################################################
        if int(Recharge_Amount) <= Client_Balance:
            Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance'] = Client_Balance - int(Recharge_Amount)
            Recharge_Done_Label = Label(We_Recharge_Window,
                                        background="#1D212E",
                                        foreground="white",
                                        text="Recharge is Done",
                                        font=('Arial', 18, 'bold'))
            Recharge_Done_Label.place(x=260, y=350)
            We_Recharge_Window_Exit_Button.config(state=NORMAL)
        else:
            Insufficient_Balance_Label = Label(We_Recharge_Window,
                                               background="#1D212E",
                                               foreground="white",
                                               text="No Sufficient Balance",
                                               font=('Arial', 18, 'bold'))
            Insufficient_Balance_Label.place(x=260, y=350)
            We_Recharge_Window_Exit_Button.config(state=NORMAL)

    else:
        #########################################################################################

        Invalid_Phone_Number_Window = Toplevel()
        Invalid_Phone_Number_Window.geometry("500x200")
        Invalid_Phone_Number_Window.config(background="white")
        Invalid_Phone_Number_Window.title("Invalid_Phone_Number_Window")
        Invalid_Phone_Number_Window_Label = Label(Invalid_Phone_Number_Window,
                                                  text="Invalid Phone Number",
                                                  background="white",
                                                  foreground="#1D212E",
                                                  font=('Arial', 20, 'bold'))
        Invalid_Phone_Number_Window_Label.pack()
        #########################################################################################
        Invalid_Phone_Number_Window.after(2000, Invalid_Phone_Number_Window.destroy)
        We_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        We_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        We_Recharge_Window_Recharge_Button.config(state=NORMAL)
        We_Recharge_Window_Phone_Number_Entry.delete(0, END)
        We_Recharge_Window_Recharge_Amount_Entry.delete(0, END)

        #########################################################################################
        """
        Invalid_Phone_Number_Window_Label = Label(We_Recharge_Window,
                                                  text="Error Message: Invalid Phone Number",
                                                  background="#1D212E",
                                                  foreground="white",
                                                  font=('Arial', 18, 'bold'))
        Invalid_Phone_Number_Window_Label.place(x=180, y=320)
        We_Recharge_Window.after(2500, Invalid_Phone_Number_Window_Label.destroy)
        We_Recharge_Window_Phone_Number_Entry.config(state=NORMAL)
        We_Recharge_Window_Recharge_Amount_Entry.config(state=NORMAL)
        We_Recharge_Window_Recharge_Button.config(state=NORMAL)
        We_Recharge_Window_Phone_Number_Entry.delete(0, END)
        We_Recharge_Window_Recharge_Amount_Entry.delete(0, END)
        """
        #########################################################################################


########################################################################################################################
# We Recharge Function Block END
########################################################################################################################

# ______________________________________________________________________________________________________________________#
# Fawry Service Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Password Change Block Start
# ______________________________________________________________________________________________________________________#
def Password_Change_Func():
    print("Password_Change_Func():")
    Options_Window.destroy()
    #########################################################################################
    global Password_Change_Window
    Password_Change_Window = Tk()
    Password_Change_Window.geometry("800x500")
    Password_Change_Window.config(background="#1D212E")
    Password_Change_Window.title("Password_Change_Window")
    #########################################################################################
    Password_Change_Window_Label = Label(Password_Change_Window,
                                         text="Password_Change_Window",
                                         background="#1D212E",
                                         foreground="white",
                                         font=('Arial', 25, 'bold'))
    Password_Change_Window_Label.place(x=180, y=40)
    #########################################################################################
    Password_Change_Window_Client_Name_Entry_Label = Label(Password_Change_Window,
                                                           background="#1D212E",
                                                           foreground="white",
                                                           text="Enter User Name",
                                                           font=('Arial', 14))
    Password_Change_Window_Client_Name_Entry_Label.place(x=70, y=180)
    #########################################################################################
    global Password_Change_Window_Client_Name_Entry
    Password_Change_Window_Client_Name_Entry = Entry(Password_Change_Window,
                                                     font=('Arial', 16))
    Password_Change_Window_Client_Name_Entry.place(x=270, y=180)
    #########################################################################################
    Password_Change_Window_Client_Name_Entry_Button = Button(Password_Change_Window,
                                                             text="Enter",
                                                             font=('Arial', 10, 'bold'),
                                                             background="white",
                                                             foreground="black",
                                                             relief=RAISED,
                                                             width=20,
                                                             command=Password_Change_Window_Client_Name_Entry_Button_Func)
    Password_Change_Window_Client_Name_Entry_Button.place(x=540, y=181)
    #########################################################################################
    Password_Change_Window_Password_Enter_Entry_Label = Label(Password_Change_Window,
                                                              text="Enter New Password",
                                                              background="#1D212E",
                                                              foreground="white",
                                                              font=('Arial', 14))
    Password_Change_Window_Password_Enter_Entry_Label.place(x=70, y=300)
    #########################################################################################
    global Password_Change_Window_Password_Enter_Entry
    Password_Change_Window_Password_Enter_Entry = Entry(Password_Change_Window,
                                                        text="Enter New Password",
                                                        font=('Arial', 16))
    Password_Change_Window_Password_Enter_Entry.place(x=270, y=300)
    #########################################################################################
    Password_Change_Window_Password_Re_Enter_Entry_Label = Label(Password_Change_Window,
                                                                 text="Re-Enter Password",
                                                                 background="#1D212E",
                                                                 foreground="white",
                                                                 font=('Arial', 14))
    Password_Change_Window_Password_Re_Enter_Entry_Label.place(x=70, y=420)
    #########################################################################################
    global Password_Change_Window_Password_Re_Enter_Entry
    Password_Change_Window_Password_Re_Enter_Entry = Entry(Password_Change_Window,
                                                           font=('Arial', 16))
    Password_Change_Window_Password_Re_Enter_Entry.place(x=270, y=420)
    #########################################################################################
    global Password_Change_Window_Password_Confirm_Button
    Password_Change_Window_Password_Confirm_Button = Button(Password_Change_Window,
                                                            text="Confirm",
                                                            font=('Arial', 10, 'bold'),
                                                            background="white",
                                                            foreground="black",
                                                            relief=RAISED,
                                                            width=20,
                                                            command=Password_Change_Window_Client_Password_Confirm_Button_Func)
    Password_Change_Window_Password_Confirm_Button.place(x=540, y=421)
    #########################################################################################
    Password_Change_Window_Password_Enter_Entry.config(state=DISABLED)
    Password_Change_Window_Password_Re_Enter_Entry.config(state=DISABLED)
    Password_Change_Window_Password_Confirm_Button.config(state=DISABLED)
    Password_Change_Window.mainloop()


########################################################################################################################
def Password_Change_Window_Client_Name_Entry_Button_Func():
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)

    Client_Name = Bank_Clients_DataBase[Client_Account_Number_Cast]['Name']

    Client_Name_get = Password_Change_Window_Client_Name_Entry.get()
    Client_Name_get = Client_Name_get.title()

    if Client_Name == Client_Name_get:

        Password_Change_Window_Password_Enter_Entry.config(state=NORMAL)
        Password_Change_Window_Password_Re_Enter_Entry.config(state=NORMAL)
        Password_Change_Window_Password_Confirm_Button.config(state=NORMAL)
    else:
        Password_Change_Window_Client_Name_Entry.delete(0, END)
        ErrorMessage_Window = Toplevel()
        ErrorMessage_Window.geometry("500x200")
        ErrorMessage_Window.config(background="white")
        ErrorMessage_Window.title("Error Message Window")
        ErrorMessage_Window_Label = Label(ErrorMessage_Window,
                                          text="Error Message Window \n\n Invalid User Name",
                                          background="white",
                                          foreground="#1D212E",
                                          font=('Arial', 20, 'bold'))
        ErrorMessage_Window_Label.pack()
        ErrorMessage_Window.after(3000, ErrorMessage_Window.destroy)


########################################################################################################################
def Password_Change_Window_Client_Password_Confirm_Button_Func():
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    #########################################################################################
    New_Password = Password_Change_Window_Password_Enter_Entry.get()
    New_Password_Confirm = Password_Change_Window_Password_Re_Enter_Entry.get()
    New_Password_Length = len(New_Password)
    if New_Password_Length == 4:
        if New_Password == New_Password_Confirm:
            Bank_Clients_DataBase[Client_Account_Number_Cast]['Password'] = New_Password
            #########################################################################################
            Password_Updated_Window = Tk()
            Password_Updated_Window.geometry("500x200")
            Password_Updated_Window.config(background="white")
            Password_Updated_Window.title("Password Updated Window")
            Password_Updated_Window_Label = Label(Password_Updated_Window,
                                                  text="Password Updated Successfully",
                                                  background="white",
                                                  foreground="#1D212E",
                                                  font=('Arial', 20, 'bold'))
            Password_Updated_Window_Label.pack()

            #########################################################################################
            def Password_Change_Window_Exit_Button_Func():
                Password_Change_Window.destroy()
                Password_Updated_Window.destroy()
                Login_Window_Func()

            #########################################################################################
            Password_Change_Window_Exit_Button = Button(Password_Updated_Window,
                                                        text='Exit',
                                                        font=('Arial', 10, 'bold'),
                                                        background="white",
                                                        foreground="black",
                                                        relief=RAISED,
                                                        width=20,
                                                        command=Password_Change_Window_Exit_Button_Func)
            Password_Change_Window_Exit_Button.place(x=300, y=150)
            #########################################################################################
            Password_Updated_Window.mainloop()

        else:
            Password_Change_Window_Password_Enter_Entry.delete(0, END)
            Password_Change_Window_Password_Re_Enter_Entry.delete(0, END)
            #########################################################################################
            Password_Re_Enter_Window = Toplevel()
            Password_Re_Enter_Window.geometry("500x200")
            Password_Re_Enter_Window.config(background="white")
            Password_Re_Enter_Window.title("Password Re_Enter Window")
            Password_Re_Enter_Window_Label = Label(Password_Re_Enter_Window,
                                                   text="Passwords aren't Matched",
                                                   background="white",
                                                   foreground="#1D212E",
                                                   font=('Arial', 20, 'bold'))
            Password_Re_Enter_Window_Label.pack()
            #########################################################################################
            Password_Re_Enter_Window.after(3000, Password_Re_Enter_Window.destroy)
    else:
        Password_Change_Window_Password_Enter_Entry.delete(0, END)
        Password_Change_Window_Password_Re_Enter_Entry.delete(0, END)
        #########################################################################################
        Password_Re_Enter_Window = Toplevel()
        Password_Re_Enter_Window.geometry("500x500")
        Password_Re_Enter_Window.config(background="white")
        Password_Re_Enter_Window.title("Password_Re_Enter_Window")
        Password_Re_Enter_Window_Label = Label(Password_Re_Enter_Window,
                                               text="Password Must Be 4 Digits Number",
                                               background="white",
                                               foreground="#1D212E",
                                               font=('Arial', 20, 'bold'))
        Password_Re_Enter_Window_Label.pack()
        #########################################################################################
        Password_Re_Enter_Window.after(3000, Password_Re_Enter_Window.destroy)


# ______________________________________________________________________________________________________________________#
# Password Change Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Balance Inquiry Block Start
# ______________________________________________________________________________________________________________________#
def Balance_Inquiry_Func():
    Options_Window.destroy()
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    global Balance_Inquiry_Window
    Balance_Inquiry_Window = Tk()
    Balance_Inquiry_Window.geometry("800x500")
    Balance_Inquiry_Window.config(background="#1D212E")
    Balance_Inquiry_Window.title("Balance_Inquiry_Window")
    Balance_Inquiry_Window_Label = Label(Balance_Inquiry_Window,
                                         text="Balance Inquiry Window",
                                         background="#1D212E",
                                         foreground="white",
                                         font=('Arial', 25, 'bold'))
    Balance_Inquiry_Window_Label.place(x=230, y=40)
    #########################################################################################
    Balance_Inquiry_Window_Client_Name_Label = Label(Balance_Inquiry_Window,
                                                     text="User Name : " +
                                                          Bank_Clients_DataBase[Client_Account_Number_Cast]['Name'],
                                                     background="#1D212E",
                                                     foreground="white",
                                                     font=('Arial', 18, 'bold'))
    Balance_Inquiry_Window_Client_Name_Label.place(x=220, y=200)
    #########################################################################################
    Balance_Inquiry_Window_Client_Balance_Label = Label(Balance_Inquiry_Window,
                                                        text="Balance is : " + str(Client_Balance),
                                                        background="#1D212E",
                                                        foreground="white",
                                                        font=('Arial', 18, 'bold'))
    Balance_Inquiry_Window_Client_Balance_Label.place(x=220, y=250)
    #########################################################################################
    Balance_Inquiry_Window_OK_Button = Button(Balance_Inquiry_Window,
                                              text="OK",
                                              font=('Arial', 10, 'bold'),
                                              background="white",
                                              foreground="black",
                                              relief=RAISED,
                                              width=20,
                                              command=Balance_Inquiry_Window_OK_Button_Func)
    Balance_Inquiry_Window_OK_Button.place(x=600, y=400)
    Balance_Inquiry_Window.mainloop()


########################################################################################################################
def Balance_Inquiry_Window_OK_Button_Func():
    Balance_Inquiry_Window.destroy()
    # To go back to homepage
    # Login_Window_Func()
    # to go back to options window
    Options_Window_Call_Func()


# ______________________________________________________________________________________________________________________#
# Balance Inquiry Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Cash Withdraw Block Start
# ______________________________________________________________________________________________________________________#
def Cash_Withdraw_Func():
    global Max_Withdraw_Per_Transaction
    global Cash_Withdraw_Window
    #########################################################################################
    Cash_Withdraw_Window = Tk()
    Cash_Withdraw_Window.geometry("800x500")
    Cash_Withdraw_Window.config(background="#1D212E")
    Cash_Withdraw_Window.title("Cash_Withdraw_Window")
    Cash_Withdraw_Window_Label = Label(Cash_Withdraw_Window,
                                       background="#1D212E",
                                       foreground="white",
                                       text="Cash Withdraw Window",
                                       font=('Arial', 25, 'bold'))
    Cash_Withdraw_Window_Label.place(x=210, y=40)
    #########################################################################################
    Cash_Withdraw_Window_Money_To_Withdraw_Entry_Label = Label(Cash_Withdraw_Window,
                                                               background="#1D212E",
                                                               foreground="white",
                                                               text="Enter Amount of Money",
                                                               font=('Arial', 14))
    Cash_Withdraw_Window_Money_To_Withdraw_Entry_Label.place(x=50, y=180)
    #########################################################################################
    global Cash_Withdraw_Window_Money_To_Withdraw_Entry
    Cash_Withdraw_Window_Money_To_Withdraw_Entry = Entry(Cash_Withdraw_Window,
                                                         font=('Arial', 16))
    Cash_Withdraw_Window_Money_To_Withdraw_Entry.place(x=270, y=180)
    #########################################################################################
    global Cash_Withdraw_Window_Enter_Button
    Cash_Withdraw_Window_Enter_Button = Button(Cash_Withdraw_Window,
                                               text='Enter',
                                               font=('Arial', 10, 'bold'),
                                               background="white",
                                               foreground="black",
                                               relief=RAISED,
                                               width=20,
                                               command=Cash_Withdraw_Window_Enter_Button_Func)
    Cash_Withdraw_Window_Enter_Button.place(x=540, y=181)
    #########################################################################################
    Options_Window.destroy()
    Cash_Withdraw_Window.mainloop()


########################################################################################################################
def Cash_Withdraw_Window_Enter_Button_Func():
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    global Max_Withdraw_Per_Transaction
    Client_Withdraw_Money = Cash_Withdraw_Window_Money_To_Withdraw_Entry.get()
    Client_Withdraw_Money_Check = int(Client_Withdraw_Money)
    if Client_Withdraw_Money_Check > Max_Withdraw_Per_Transaction:
        Cash_Withdraw_Window_Money_To_Withdraw_Entry.delete(0, END)
        #########################################################################################
        Max_Withdraw_Window = Toplevel()
        Max_Withdraw_Window.geometry("600x100")
        Max_Withdraw_Window.config(background="")
        Max_Withdraw_Window.title("Max_Withdraw_Window")
        Max_Withdraw_Window_Label = Label(Max_Withdraw_Window,
                                          text="Maximum allowed value per transaction \n is 5000 L.E",
                                          background="white",
                                          foreground="#1D212E",
                                          font=('Arial', 20, 'bold'))
        Max_Withdraw_Window_Label.pack()
        #########################################################################################
        Max_Withdraw_Window.after(10000, Max_Withdraw_Window.destroy)
        #########################################################################################
    elif (Client_Withdraw_Money_Check % 100) != 0:
        Cash_Withdraw_Window_Money_To_Withdraw_Entry.delete(0, END)
        #########################################################################################
        Multiple_100_Window = Toplevel()
        Multiple_100_Window.geometry("600x100")
        Multiple_100_Window.config(background="white")
        Multiple_100_Window.title("Multiple_100_Window")
        Multiple_100_Window_Label = Label(Multiple_100_Window,
                                          text="The allowed Values are multiple of 100L.E \n Re-Enter Amount of Money",
                                          background="white",
                                          foreground="#1D212E",
                                          font=('Arial', 20, 'bold'))
        Multiple_100_Window_Label.pack()
        #########################################################################################
        Multiple_100_Window.after(10000, Multiple_100_Window.destroy)
        #########################################################################################
    elif Client_Withdraw_Money_Check > Client_Balance:
        Cash_Withdraw_Window_Money_To_Withdraw_Entry.config(state=DISABLED)
        Cash_Withdraw_Window_Enter_Button.config(state=DISABLED)
        #########################################################################################
        Insufficient_Balance_Label = Label(Cash_Withdraw_Window,
                                           background="#1D212E",
                                           foreground="white",
                                           text="No Sufficient Balance",
                                           font=('Arial', 18, 'bold'))
        Insufficient_Balance_Label.place(x=260, y=350)

        #########################################################################################
        def Cash_Withdraw_Window_Exit_Button_Func():
            Cash_Withdraw_Window.destroy()
            Login_Window_Func()

        #########################################################################################
        Cash_Withdraw_Window_Exit_Button = Button(Cash_Withdraw_Window,
                                                  text='Exit',
                                                  font=('Arial', 10, 'bold'),
                                                  background="white",
                                                  foreground="black",
                                                  relief=RAISED,
                                                  width=20,
                                                  command=Cash_Withdraw_Window_Exit_Button_Func)
        Cash_Withdraw_Window_Exit_Button.place(x=600, y=400)
    else:
        Cash_Withdraw_Window_ATM_Actuator_Out()
        Cash_Withdraw_Window.destroy()
        Login_Window_Func()


########################################################################################################################
def Cash_Withdraw_Window_ATM_Actuator_Out():
    print("Cash_Withdraw_Window_ATM_Actuator_Out")
    global Client_Account_Number
    Client_Account_Number_Cast = int(Client_Account_Number)
    global Client_Balance
    Client_Balance = Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance']
    Client_Withdraw_Money = Cash_Withdraw_Window_Money_To_Withdraw_Entry.get()
    Bank_Clients_DataBase[Client_Account_Number_Cast]['Balance'] = Client_Balance - int(Client_Withdraw_Money)
    Cash_Withdraw_Window.destroy()
    Login_Window_Func()


# ______________________________________________________________________________________________________________________#
# Cash Withdraw Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Options Withdraw Block Start
# ______________________________________________________________________________________________________________________#
def Options_Window_Call_Func():
    global Options_Window
    Options_Window = Tk()
    Options_Window.geometry("800x500")
    Options_Window.config(background="#1D212E")
    Options_Window.title("Options_Window")
    Options_Window_Label = Label(Options_Window,
                                 background="#1D212E",
                                 foreground="white",
                                 text="Options Window",
                                 font=('Arial', 30, 'bold'))
    Options_Window_Label.place(x=250, y=40)
    #########################################################################################
    Cash_Withdraw_RButton = Radiobutton(Options_Window,
                                        text="Cash Withdraw",
                                        font=('Arial', 14, 'bold'),
                                        background="white",
                                        foreground="black",
                                        relief=RAISED,
                                        width=15,
                                        padx=10,
                                        pady=10,
                                        indicatoron=0,
                                        command=Cash_Withdraw_Func)
    Cash_Withdraw_RButton.place(x=80, y=200)
    #########################################################################################
    Balance_Inquiry_RButton = Radiobutton(Options_Window,
                                          text="Balance Inquiry",
                                          font=('Arial', 14, 'bold'),
                                          background="white",
                                          foreground="black",
                                          relief=RAISED,
                                          width=15,
                                          padx=10,
                                          pady=10,
                                          indicatoron=0,
                                          command=Balance_Inquiry_Func)
    Balance_Inquiry_RButton.place(x=80, y=300)
    #########################################################################################
    Password_Change_RButton = Radiobutton(Options_Window,
                                          text="Password Change",
                                          font=('Arial', 14, 'bold'),
                                          background="white",
                                          foreground="black",
                                          relief=RAISED,
                                          width=15,
                                          padx=10,
                                          pady=10,
                                          indicatoron=0,
                                          command=Password_Change_Func)
    Password_Change_RButton.place(x=80, y=400)
    #########################################################################################
    Fawry_Service_RButton = Radiobutton(Options_Window,
                                        text="Fawry Service",
                                        font=('Arial', 14, 'bold'),
                                        background="white",
                                        foreground="black",
                                        relief=RAISED,
                                        width=15,
                                        padx=10,
                                        pady=10,
                                        indicatoron=0,
                                        command=Fawry_Service_Func)
    Fawry_Service_RButton.place(x=520, y=200)
    #########################################################################################
    Exit_Rbutton = Radiobutton(Options_Window,
                               text="Exit",
                               font=('Arial', 14, 'bold'),
                               background="white",
                               foreground="black",
                               relief=RAISED,
                               width=15,
                               padx=10,
                               pady=10,
                               indicatoron=0,
                               command=Exit_Func)
    Exit_Rbutton.place(x=520, y=300)
    #########################################################################################
    Login_Window.destroy()
    Options_Window.mainloop()


# ______________________________________________________________________________________________________________________#
# Options Withdraw Block END
# ______________________________________________________________________________________________________________________#

# ______________________________________________________________________________________________________________________#
# Login Window Function Block (HomePage) Start
# ______________________________________________________________________________________________________________________#
def Login_Window_Func():
    global Login_Window
    Login_Window = Tk()
    Login_Window.geometry("800x500")
    Login_Window.config(background="#1D212E")
    Login_Window.title("Login_Window")
    Login_Window_Label = Label(Login_Window,
                               background="#1D212E",
                               foreground="white",
                               text="Log In Window",
                               font=('Arial', 25, 'bold'))
    Login_Window_Label.place(x=280, y=40)
    #########################################################################################
    Login_Window_Account_Number_Entry_Label = Label(Login_Window,
                                                    background="#1D212E",
                                                    foreground="white",
                                                    text="Account Number",
                                                    font=('Arial', 14))
    Login_Window_Account_Number_Entry_Label.place(x=70, y=180)
    #########################################################################################
    global Login_Window_Account_Number_Entry
    Login_Window_Account_Number_Entry = Entry(Login_Window,
                                              font=('Arial', 16))
    Login_Window_Account_Number_Entry.place(x=270, y=180)
    #########################################################################################
    global Login_Window_Enter_Button
    Login_Window_Enter_Button = Button(Login_Window,
                                       text='Enter',
                                       font=('Arial', 10, 'bold'),
                                       background="white",
                                       foreground="black",
                                       relief=RAISED,
                                       width=20,
                                       command=Login_Window_Enter_Button_Func)
    Login_Window_Enter_Button.place(x=540, y=181)
    #########################################################################################
    Login_Window_Password_Entry_Label = Label(Login_Window,
                                              background="#1D212E",
                                              foreground="white",
                                              text="Account Password",
                                              font=('Arial', 14))
    Login_Window_Password_Entry_Label.place(x=70, y=300)
    #########################################################################################
    global Login_Window_Password_Entry
    Login_Window_Password_Entry = Entry(Login_Window,
                                        font=('Arial', 16),
                                        show='*')

    Login_Window_Password_Entry.place(x=270, y=300)
    #########################################################################################
    global Login_Window_Password_Enter_Button
    Login_Window_Password_Enter_Button = Button(Login_Window,
                                                text='Enter',
                                                font=('Arial', 10, 'bold'),
                                                background="white",
                                                foreground="black",
                                                relief=RAISED,
                                                width=20,
                                                command=Login_Window_Password_Enter_Button_Func)
    # Login_Window_Password_Enter_Button.pack()
    Login_Window_Password_Enter_Button.place(x=540, y=300)
    #########################################################################################
    Login_Window_Password_Entry.config(state=DISABLED)
    Login_Window_Password_Enter_Button.config(state=DISABLED)
    #########################################################################################
    Login_Window.mainloop()


########################################################################################################################
# Login Window Account Number Enter Button Block
########################################################################################################################
def Login_Window_Enter_Button_Func():
    global Client_Account_Number
    Client_Account_Number = Login_Window_Account_Number_Entry.get()
    Client_Account_Number_Cast = int(Client_Account_Number)
    if Client_Account_Number_Cast not in Clients_ID:
        Login_Window_Account_Number_Entry.delete(0, END)
        ErrorMessage_Window = Toplevel()
        ErrorMessage_Window.geometry("500x200")
        ErrorMessage_Window.config(background="white")
        ErrorMessage_Window.title("Error Message Window")
        ErrorMessage_Window_Label = Label(ErrorMessage_Window,
                                          background="white",
                                          foreground="#1D212E",
                                          text="Error Message Window \n\n Invalid Account Number",
                                          font=('Arial', 20, 'bold'))
        ErrorMessage_Window_Label.pack()
        ErrorMessage_Window.after(5000, ErrorMessage_Window.destroy)
    else:
        if Clients_ID_Password_Trials[Client_Account_Number_Cast]['Trials'] > 2:
            Login_Window_Account_Number_Entry.delete(0, END)
            Login_Window_Password_Entry.delete(0, END)
            GotoBrunchMessage_Window = Toplevel()
            GotoBrunchMessage_Window.geometry("500x200")
            GotoBrunchMessage_Window.config(background="white")
            GotoBrunchMessage_Window.title("Go To Brunch Message")
            GotoBrunchMessage_Window_Label = Label(GotoBrunchMessage_Window,
                                                   background="white",
                                                   foreground="#1D212E",
                                                   text="This Account is Locked \n Please, Go To Brunch",
                                                   font=('Arial', 20, 'bold'))
            GotoBrunchMessage_Window_Label.pack()
            GotoBrunchMessage_Window.after(5000, GotoBrunchMessage_Window.destroy)
        else:
            """
            time.time()
            ValidMessage_Window = Toplevel()
            ValidMessage_Window.geometry("500x200")
            ValidMessage_Window.config(background="white")
            ValidMessage_Window.title("Valid Message Window")
            ValidMessage_Window_Label = Label(ValidMessage_Window,
                                              background="white",
                                              foreground="#1D212E",
                                              text="Valid Account Number \n Enter Password",
                                              font=('Arial', 20, 'bold'))
            #ValidMessage_Window_Label.pack()
            ValidMessage_Window_Label.place(x=100,y=50)
            ValidMessage_Window.after(1000,ValidMessage_Window.destroy)
            """
            Login_Window_Password_Entry.config(state=NORMAL)
            Login_Window_Password_Enter_Button.config(state=NORMAL)


########################################################################################################################
# Login Window Account Password Enter Button Block
########################################################################################################################
def Login_Window_Password_Enter_Button_Func():
    global Trials_Flag
    global Trials_Counter
    global Client_Account_Number
    Client_Account_Number = Login_Window_Account_Number_Entry.get()
    Client_Account_Number_Cast = int(Client_Account_Number)
    if 0 <= Clients_ID_Password_Trials[Client_Account_Number_Cast]['Trials'] <= 2 and Trials_Flag == 0:
        Client_Account_Password = Login_Window_Password_Entry.get()
        Trials_Counter += 1
        Client_Account_Password_Check = Bank_Clients_DataBase[Client_Account_Number_Cast]['Password']
        if int(Client_Account_Password) == int(Client_Account_Password_Check):
            Clients_ID_Password_Trials[Client_Account_Number_Cast]['Trials'] = 0
            Trials_Flag = 1
            Login_Window_Account_Number_Entry.config(state=DISABLED)
            Login_Window_Enter_Button.config(state=DISABLED)
            Login_Window_Password_Entry.config(state=DISABLED)
            Login_Window_Password_Enter_Button.config(state=DISABLED)
            Trials_Flag = 0
            Options_Window_Call_Func()
        else:
            Clients_ID_Password_Trials[Client_Account_Number_Cast]['Trials'] = Trials_Counter
            Login_Window_Password_Entry.delete(0, END)
            Wrong_Password_Window = Toplevel()
            Wrong_Password_Window.geometry("500x200")
            Wrong_Password_Window.config(background="white")
            Wrong_Password_Window.title("Wrong Password Message")
            GotoBrunchMessage_Window_Label = Label(Wrong_Password_Window,
                                                   background="white",
                                                   foreground="#1D212E",
                                                   text="Wrong Password \n Re-Enter The Password",
                                                   font=('Arial', 20, 'bold'))
            GotoBrunchMessage_Window_Label.pack()
            Wrong_Password_Window.after(5000, Wrong_Password_Window.destroy)
    else:
        Login_Window_Account_Number_Entry.delete(0, END)
        Login_Window_Password_Entry.delete(0, END)
        GotoBrunchMessage_Window = Toplevel()
        GotoBrunchMessage_Window.geometry("500x200")
        GotoBrunchMessage_Window.config(background="white")
        GotoBrunchMessage_Window.title("Go To Brunch Message")
        GotoBrunchMessage_Window_Label = Label(GotoBrunchMessage_Window,
                                               background="white",
                                               foreground="#1D212E",
                                               text="This Account is Locked \n Please, Go To Brunch",
                                               font=('Arial', 20, 'bold'))
        GotoBrunchMessage_Window_Label.pack()
        GotoBrunchMessage_Window.after(5000, GotoBrunchMessage_Window.destroy)


# ______________________________________________________________________________________________________________________#
# Login Window Function Block (HomePage) END
# ______________________________________________________________________________________________________________________#
try:
    Login_Window_Func()
except:
    print("error happened")
