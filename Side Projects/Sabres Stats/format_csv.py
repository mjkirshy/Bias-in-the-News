def format():
    import glob
    path = "c:/Users/Ryan/Coding/Side Projects/Sabres Stats/Games/*.csv"
    for file_name in glob.glob(path):
        print(file_name)

def main():
    format()
    print("finished executing main")

if __name__ == "__main__":
    main()