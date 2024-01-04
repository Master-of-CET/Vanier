###################################################################################################
#                                                                                                 #
# Name: Leonardo Fusser (1946995)                                                                 #
# Mechatronics & Robotic Systems (247-510-VA)                                                     #
# John F. N. Salik                                                                                #
#                                                                                                 #
# Assignment: Web Scraping Project.                                                               #
#                                                                                                 #
# Filename: WebScraping_DataCapture.py                                                            #
#                                                                                                 #
# Description: code to capture gas prices and data captured is stored in four seperate excel      #
#              files. Each excel file has the list of gas prices for one location in Quebec.      #
#              Over the period of four days, the excel files get overwritten and new data for the #
#              captured day gets written. Before this occurs, all the captured data in the four   #
#              seperate excel files gets copied into one big excel file and keeps getting updated #
#              over the course of four days. Gas price data is retrieved from four websites.      #
#              The excel files are located in the same directory as this python file.             #
#                                                                                                 #
###################################################################################################


# region Dependencies required included below.
import requests
from bs4 import BeautifulSoup
import pandas as pd
# endregion

# region Retrieve the web page.
url1 = r'https://www.gasbuddy.com/gasprices/quebec/montreal'    #Location #1.
url2 = r'https://www.gasbuddy.com/gasprices/quebec/laval'       #Location #2.
url3 = r'https://www.gasbuddy.com/gasprices/quebec/kirkland'    #Location #3.
url4 = r'https://www.gasbuddy.com/gasprices/quebec/la-prairie'  #Location #4.

#[Identifier used when communicating with websites that restrict access to certain communication requests]
hdr = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36 Edg/94.0.992.50'}

web_request1 = requests.get(url1, headers=hdr)  #Applies the identifier when requesting website communication for location #1 (url1).
web_request2 = requests.get(url2, headers=hdr)  #Applies the identifier when requesting website communication for location #2 (url2).
web_request3 = requests.get(url3, headers=hdr)  #Applies the identifier when requesting website communciation for location #3 (url3).
web_request4 = requests.get(url4, headers=hdr)  #Applies the identifier when requesting website communication for location #4 (url4).

#[Website communication request status check - 200 is good 403 is bad]
if web_request1.status_code or web_request2.status_code or web_request3.status_code or web_request4 == 200:
    print('Accessed web page!')             #Web request returns code 200.
else:
    print('Web page access forbidden!')     #Web request returns code 403 or any other error.

HTML1 = web_request1.text   #Convert captured website for location #1 (url1) into text.
HTML2 = web_request2.text   #Convert captured website for location #2 (url2) into text.
HTML3 = web_request3.text   #Convert captured website for location #3 (url3) into text.
HTML4 = web_request4.text   #Convert captured website for location #4 (url4) into text.
# endregion

# region Reading the web page: parsing the HTML.
webPage1 = BeautifulSoup(HTML1, 'html.parser')  #Parses the retrieved website for location #1 (url1).
webPage2 = BeautifulSoup(HTML2, 'html.parser')  #Parses the retrieved website for location #2 (url2).
webPage3 = BeautifulSoup(HTML3, 'html.parser')  #Parses the retrieved website for location #3 (url3).
webPage4 = BeautifulSoup(HTML4, 'html.parser')  #Parses the retrieved website for location #4 (url4).

pageTitle1 = webPage1.find('h1').text   #Retrieves website title for location #1 (url1).
pageTitle2 = webPage2.find('h1').text   #Retrieves website title for location #2 (url2).
pageTitle3 = webPage3.find('h1').text   #Retrieves website title for location #3 (url3).
pageTitle4 = webPage4.find('h1').text   #Retrieves website title for location #4 (url4).
# endregion

# region Get pricing data from all captured locations.
#[Retrieves gas prices from all four locations - location #1 (url1), location #2 (url2), location #3 (url3), location #4 (url4)]
priceTags1 = webPage1.findAll('span', {'class': 'text__xl___2MXGo text__left___1iOw3 StationDisplayPrice-module__price___3rARL'})
priceTags2 = webPage2.findAll('span', {'class': 'text__xl___2MXGo text__left___1iOw3 StationDisplayPrice-module__price___3rARL'})
priceTags3 = webPage3.findAll('span', {'class': 'text__xl___2MXGo text__left___1iOw3 StationDisplayPrice-module__price___3rARL'})
priceTags4 = webPage4.findAll('span', {'class': 'text__xl___2MXGo text__left___1iOw3 StationDisplayPrice-module__price___3rARL'})

priceList1 = [] #Creates empty array of gas prices for location #1 (url1).
priceList2 = [] #Creates empty array of gas prices for location #2 (url2).
priceList3 = [] #Creates empty array of gas prices for location #3 (url3).
priceList4 = [] #Creates empty array of gas prices for location #4 (url4).

#[Appends all the gas prices found in location #1 (url1) and stores them in an array]
for p in priceTags1:
    priceText1 = p.text.replace('Â', '').replace('¢', '')   #Clears garbage and cents values.
    priceList1.append(float(priceText1))                    #Appends.

#[Appends all the gas prices found in location #2 (url2) and stores them in an array]
for p in priceTags2:
    priceText2 = p.text.replace('Â', '').replace('¢', '')   #Clears garbage and cents values.
    priceList2.append(float(priceText2))                    #Appends.

#[Appends all the gas prices found in location #3 (url3) and stores them in an array]
for p in priceTags3:
    priceText3 = p.text.replace('Â', '').replace('¢', '')   #Clears garbage and cents values.
    priceList3.append(float(priceText3))                    #Appends.

#[Appends all the gas prices found in location #4 (url4) and stores them in an array]
for p in priceTags4:
    priceText4 = p.text.replace('Â', '').replace('¢', '')   #Clears garbage and cents values.
    priceList4.append(float(priceText4))                    #Appends.

# endregion

# region Store the data into an Excel sheet.
df1 = pd.DataFrame(priceList1, columns=['Price']) #Convert the LIST of prices for location #1 (url1) to a DataFrame.
df2 = pd.DataFrame(priceList2, columns=['Price']) #Convert the LIST of prices for location #2 (url2) to a DataFrame.
df3 = pd.DataFrame(priceList3, columns=['Price']) #Convert the LIST of prices for location #3 (url3) to a DataFrame.
df4 = pd.DataFrame(priceList4, columns=['Price']) #Convert the LIST of prices for location #4 (url4) to a DataFrame.

df1.to_excel('GasPrices-1.xlsx', index=False)   #Writes DataFrame to a newly created excel file.
df2.to_excel('GasPrices-2.xlsx', index=False)   #" ".
df3.to_excel('GasPrices-3.xlsx', index=False)   #" ".
df4.to_excel('GasPrices-4.xlsx', index=False)   #" ".
# endregion
