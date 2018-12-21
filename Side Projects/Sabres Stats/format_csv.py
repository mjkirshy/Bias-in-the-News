import glob
import csv
import math
import os.path


def player_db(filename):
    ## trims the Sabres roster to active players ##
    ## and grabs their player name & number ##
    file = filename
    dict = {}
    with open(file, 'r') as f:
        reader = csv.reader(f)
        for row in reader:
            ## how to clean up escape characters? ##
            dict.update({row[1]: row[0]})
    return dict


def format_game_csv(playerDB, path):
    ## reads all csv's in Games/ ##
    ## reads relevant data to a list ##
    ## writers to csv based on the period ##
    temp_list = []
    for x in glob.glob(path):
        with open(x, 'r') as f:
            reader = csv.reader(f)
            next(reader)  # skips first row #
            period = x[x.find('.') + 1]
            for row in reader:
                i = 0
                while i < len(row):
                    checker = row[i]
                    if i == 0:  ## gets player num
                        fullName = row[i]
                        full = fullName[-5:]
                        temp_list.append(getPlayerNum(full, playerDB))
                    elif i == 2 or i == 3 or i == 4 or i == 7 or i == 8 or i == 11 or i == 12 or i == 15 or i == 16 or i == 19 or i == 20 or i == 23 or i == 24:
                        if i == 2:  ## gets TOI
                            temp_list = padder(int(period), temp_list, time_conversion(float(row[i])))
                        else:
                            temp_list = padder(int(period), temp_list, row[i])  ## gets shot metrics ##
                        if i == 24:
                            break  ## 24 is last COL, HDCA ##
                    i += 1
                writeList(temp_list)
                del temp_list[:]


def time_conversion(input):
    ## takes a decimal and returns total seconds ##
    seconds = math.ceil(input * 3600) / 60
    return int(seconds)


def getPlayerNum(name, playerDB):
    ## takes player name returns their jersey number ##
    for key, value in playerDB.items():
        if name in key:
            return value


def padder(period, temp_list, input_value):
    ## formats game data based on what period the csv is ##
    if period == 1:
        temp_list.append(input_value)
        temp_list.append(0);
        temp_list.append(0);
    elif period == 2:
        temp_list.append(0)
        temp_list.append(input_value)
        temp_list.append(0)
    else:
        temp_list.append(0)
        temp_list.append(0)
        temp_list.append(input_value)
    return temp_list


def writeList(tList):
    ## simple write function -- checks if file does not exist ##
    ## if it doesn't, write a user-defined header ##
    filename = playerPath + str(tList[0]) + ".csv"
    # create new function #
    if not os.path.exists(filename):
        with open(filename, 'a') as o:
            wr = csv.writer(o, delimiter=' ')
            wr.writerow(fileHeader)
    with open(filename, 'a') as o:
        wr = csv.writer(o, delimiter=' ')
        wr.writerow(tList)


## global variables ##
team_roster = "roster.csv"
gmPath = "Games/*.csv"
playerPath = "Individual Player Stats/"  ## user defined directory for individual player stats
fileHeader = ["PNum", "TOI:1", "TOI:2", "TOI:3", "CF:1", "CF:2", "CF:3", "CA:1", "CA:2", "CA:3", "FF:1", "FF:2", "FF:3",
              "FA:1", "FA:2", "FA:3", "SF:1", "SF:2", "SF:3", "SA:1", "SA:2", "SA:3", "GF:1", "GF:2", "GF:3", "GA:1",
              "GA:2", "GA:3", "SCF:1", "SCF:2", "SCF:3", "SCA:1", "SCA:2", "SCA:3", "HCDF:1", "HCDF:2", "HCDF:3",
              "HCDA:1", "HCDA:2", "HCDA:3"]


## end ##

def main():
    print("---------SABRES STAT MAKERRRRR------------")
    player_dict = player_db(team_roster)  # creates player DB
    format_game_csv(player_dict, gmPath)  # need to take game data and create a csv of it
    print("--------finished executing main-----------")


if __name__ == "__main__":
    main()
