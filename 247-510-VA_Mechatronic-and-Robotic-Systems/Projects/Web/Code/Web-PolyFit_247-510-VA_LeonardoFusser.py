###################################################################################################
#                                                                                                 #
# Name: Leonardo Fusser (1946995)                                                                 #
# Mechatronics & Robotic Systems (247-510-VA)                                                     #
# John F. N. Salik                                                                                #
#                                                                                                 #
# Assignment: Web Scraping Project.                                                               #
#                                                                                                 #
# Filename: WebScraping_Polyfit.py                                                                #
#                                                                                                 #
# Description: code to create a graph for the captured gas price data. Data is retrieved from an  #
#              excel spreadsheet that is located in the same directory as this python file. Using #
#              the matplotlib library, the real captured gas price data is plotted on a graph     #
#              along with predicted gas price data (done using polynomial fit).                   #
#                                                                                                 #
###################################################################################################


# region Dependencies required included below.
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
# endregion

# region Get data from excel spreadsheet and store data as lists.
day1 = pd.read_excel(r'Data.xlsx', "Day1")  #Gets gas price data from sheet 1 in excel file.
day2 = pd.read_excel(r'Data.xlsx', "Day2")  #Gets gas price data from sheet 2 in excel file.
day3 = pd.read_excel(r'Data.xlsx', "Day3")  #Gets gas price data from sheet 3 in excel file.
day4 = pd.read_excel(r'Data.xlsx', "Day4")  #Gets gas price data from sheet 4 in excel file.

#[Print statements for debugging]
#print(day1)   #Prints captured gas price data from sheet 1 in excel file.
#print(day2)   #Prints captured gas price data from sheet 2 in excel file.
#print(day3)   #Prints captured gas price data from sheet 3 in excel file.
#print(day4)   #Prints captured gas price data from sheet 4 in excel file.

#[Takes captured gas price data from sheet 1 in excel file and stores all elements in one list]
gasPriceDay1_montreal = day1['Montreal'].tolist()       #Takes all gas prices from Montreal column in excel sheet 1 and stores result as a list.
gasPriceDay1_laval = day1['Laval'].tolist()             #Takes all gas prices from Laval column in excel sheet 1 and stores result as a list.
gasPriceDay1_kirkland = day1['Kirkland'].tolist()       #Takes all gas prices from Kirkland column in excel sheet 1 and stores result as a list.
gasPriceDay1_LaPrairie = day1['La Prairie'].tolist()    #Takes all gas prices from La Prairie column in excel sheet 1 and stores result as a list.
gasPriceDay1 = gasPriceDay1_montreal + gasPriceDay1_laval + gasPriceDay1_kirkland + gasPriceDay1_kirkland + gasPriceDay1_LaPrairie  #Creates large gas price list for day 1.

#[Takes captured gas price data from sheet 2 in excel file and stores all elements in one list]
gasPriceDay2_montreal = day2['Montreal'].tolist()       #Takes all gas prices from Montreal column in excel sheet 2 and stores result as a list.
gasPriceDay2_laval = day2['Laval'].tolist()             #Takes all gas prices from Laval column in excel sheet 2 and stores result as a list.
gasPriceDay2_kirkland = day2['Kirkland'].tolist()       #Takes all gas prices from Kirkland column in excel sheet 2 and stores result as a list.
gasPriceDay2_LaPrairie = day2['La Prairie'].tolist()    #Takes all gas prices from La Prairie column in excel sheet 2 and stores result as a list.
gasPriceDay2 = gasPriceDay2_montreal + gasPriceDay2_laval + gasPriceDay2_kirkland + gasPriceDay2_kirkland + gasPriceDay2_LaPrairie  #Creates large gas price list for day 2.

#[Takes captured gas price data from sheet 3 in excel file and stores all elements in one list]
gasPriceDay3_montreal = day3['Montreal'].tolist()       #Takes all gas prices from Montreal column in excel sheet 3 and stores result as a list.
gasPriceDay3_laval = day3['Laval'].tolist()             #Takes all gas prices from Laval column in excel sheet 3 and stores result as a list.
gasPriceDay3_kirkland = day3['Kirkland'].tolist()       #Takes all gas prices from Kirkland column in excel sheet 3 and stores result as a list.
gasPriceDay3_LaPrairie = day3['La Prairie'].tolist()    #Takes all gas prices from La Prairie column in excel sheet 3 and stores result as a list.
gasPriceDay3 = gasPriceDay3_montreal + gasPriceDay3_laval + gasPriceDay3_kirkland + gasPriceDay3_kirkland + gasPriceDay3_LaPrairie  #Creates large gas price list for day 3.

#[Takes captured gas price data from sheet 4 in excel file and stores all elements in one list]
gasPriceDay4_montreal = day4['Montreal'].tolist()       #Takes all gas prices from Montreal column in excel sheet 4 and stores result as a list.
gasPriceDay4_laval = day4['Laval'].tolist()             #Takes all gas prices from Laval column in excel sheet 4 and stores result as a list.
gasPriceDay4_kirkland = day4['Kirkland'].tolist()       #Takes all gas prices from Kirkland column in excel sheet 4 and stores result as a list.
gasPriceDay4_LaPrairie = day4['La Prairie'].tolist()    #Takes all gas prices from La Prairie column in excel sheet 4 and stores result as a list.
gasPriceDay4 = gasPriceDay4_montreal + gasPriceDay4_laval + gasPriceDay4_kirkland + gasPriceDay4_kirkland + gasPriceDay4_LaPrairie  #Creates large gas price list for day 4.

#[Print statements for debugging]
#print(gasPriceDay1)    #Prints list of gas prices from day 1.
#print(gasPriceDay2)    #Prints list of gas prices from day 2.
#print(gasPriceDay3)    #Prints list of gas prices from day 3.
#print(gasPriceDay4)    #Prints list of gas prices from day 4.
# endregion

# region Calculates gas price averages for all captured days and store result as list.
AvgDay1 = np.nanmean(gasPriceDay1)  #Calculates the average for all the gas prices from day 1 (ignores empty cells in captured data).
AvgDay2 = np.nanmean(gasPriceDay2)  #Calculates the average for all the gas prices from day 2 (ignores empty cells in captured data).
AvgDay3 = np.nanmean(gasPriceDay3)  #Calculates the average for all the gas prices from day 3 (ignores empty cells in captured data).
AvgDay4 = np.nanmean(gasPriceDay4)  #Calculates the average for all the gas prices from day 4 (ignores empty cells in captured data).

#[Print statements for debugging]
#print(AvgDay1) #Prints calcualted gas price average for day 1.
#print(AvgDay2) #Prints calculated gas price average for day 2.
#print(AvgDay3) #Prints calculated gas price average for day 3.
#print(AvgDay4) #Prints calculated gas price average for day 4.

totalAvg = [AvgDay1, AvgDay2, AvgDay3, AvgDay4] #Adds all calculated gas price averages from all captured days into a list.

#[Print statements for debugging]
#print(totalAvg)    #Prints all the calculated gas price averages from all captured days.
# endregion

# region Takes captured gas price data and converts it into X and Y values.
x_data = [1, 2, 3, 4]   #X-values (days).
y_data = totalAvg       #Y-values (prices).

#[Print statements for debugging]
#print(x_data)
#print(y_data)
# endregion

# region Find optimal coefficients for the polynomial using NumPy.
polyOrder = 3                               #Polynomial order variable.
a = np.polyfit(x_data, y_data, polyOrder)   #Performs a polynomial fit operation based off of the gas price data captured.
y_model = np.poly1d(a)                      #" ".
MSE = np.sum((y_data-y_model(x_data))**2)   #Calculates region of error (MSE).
x_interp = np.linspace(1, 4, 200)           #Predicts gas price data.
# endregion

# region Plot the captured and predicted gas price data as a graph using MatplotLib.
plt.plot(x_data, y_data, 'c.')                                                          #Plots gas price data (real).
plt.plot(x_interp, y_model(x_interp), 'r--')                                            #Plots gas price data (prediction).
plt.xlabel('[Days captured]')                                                           #Label for X-axis on graph.
plt.ylabel('[Gas prices]')                                                              #Label for Y-axis on graph.
plt.title('Error (MSE) = %4.2f' %MSE)                                                   #Subtitle for graph (displays MSE).
plt.suptitle('Gas prices obtained from 4 regions in Quebec over a period of 4 days')    #Title for graph.
plt.show()                                                                              #Show graph.
# endregion
