def Filter1():
    print('Filter 1')
def Filter2():
    print('Filter 2')
def Filter3():
    print('Filter 3')
def Filter4():
    print('Filter 4')


if __name__ == '__main__':
    while True:
        print('Start.')
        Pipeline = [Filter1, Filter2, Filter3, Filter4]
        Pipeline = [Filter4]
        for fn in Pipeline:
            fn()
        print('End.')
