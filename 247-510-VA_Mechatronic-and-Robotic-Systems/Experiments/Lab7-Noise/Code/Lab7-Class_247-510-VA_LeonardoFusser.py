class Car:

    def __init__(self):
        self.direction_mode = 'S'
        self.car_number = Car()
        print('Car Initialized!')
    def Forward(self):
        self.direction_mode = 'F'
    def Backward(self):
        self.direction_mode = 'B'
    def Left(self):
        self.direction_mode = 'L'
    def Right(self):
        self.direction_mode = 'R'
    def Stop(self):
        self.direction_mode = 'S'
    def Move(self):
        if self.direction_mode == 'F':
            print('%d Forwards'%self.car_number)
        elif self.direction_mode == 'B':
            print('%d Backwards'%self.car_number)
        elif self.direction_mode == 'L':
            print('&d Left'%self.car_number)
        elif self.direction_mode == 'R':
            print('%d Right'%self.car_number)
        elif self.direction_mode == 'S':
            print('%d Stop'%self.car_number)
        else:
            print('Unknown')


class Fleet:
    def __init__(self, ncars=10):
       self.N = ncars
       self.Fleet = []
       for c in range(self.N):
           self.Fleet.append(Car(cnum=c))
    def Car_Forward(self, car_number):
       self.Fleet[car_number].Forward()
       self.Fleet[car_number].Move()
    def Car_Stop(self, car_number):
       self.Fleet[car_number].Stop()
       self.Fleet[car_number].Move()
    def getCarNum(self):
       return self.N


if __name__ == '__main__':
    Company = [Fleet() for f in range(10)]
