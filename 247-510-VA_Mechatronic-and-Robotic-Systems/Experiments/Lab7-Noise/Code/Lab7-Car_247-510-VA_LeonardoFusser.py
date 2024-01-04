def Forward():
    direction_mode = 'F'

def Reverse():
    direction_mode = 'B'

def Left():
    direction_mode = 'L'

def Right():
    direction_mode = 'R'

def Move():
    if direction_mode == 'F':
        print('Forward')
    elif direction_mode == 'B':
        print('Backward')
    elif direction_mode == 'L':
        print('Left')
    elif direction_mode == 'R':
        print('Right')


if __name__ == '__main__':
    #Initially set the direction mode forward.
    direction_mode = ''

    #Move the car.
    Move()
